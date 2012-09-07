<?php

/**
 * @file
 * twitter pull class implementation
 */

class twitter_puller {

  var $twitkey;
  var $num_items;
  var $tweets;

  /**
  * @param $twitkey
  *     Twitter key, which can be a username (prepended with @) or hashtag (prepended with #)
  * @param $num_items
  *     maximum number of tweets to pull from Twitter.
  */
  function __construct($twitkey, $num_items) {

    $this->twitkey = $twitkey;
    $this->num_items = $num_items;

    $this->check_arguments();

  }

  function check_arguments() {

    if (empty($this->twitkey) || drupal_strlen($this->twitkey) < 2) {
      throw new Exception(t('Twitter key may not be empty.'));
    }

    $num = intval($this->num_items);
    if ($num <= 0 || $num > 200) {
      throw new Exception(t('Number of Twitter items to pull must be a positive integer less than or equal to 200.'));
    }

  }

  function get_items() {

    $prefix = drupal_substr($this->twitkey, 0, 1);
    $slash = strpos($this->twitkey, '/', 1);
    $num = intval($this->num_items);

    // lists have the format @username/listname
    if ($prefix == '@' && $slash !== FALSE) {
      $username = drupal_substr($this->twitkey, 1, $slash - 1);
      $listname = drupal_substr($this->twitkey, $slash + 1);
      $url = 'http://api.twitter.com/1/' . urlencode($username) . '/lists/' . urlencode($listname) . '/statuses.json?per_page=' . $num;
    }
    // if the first character is @, then consider the key a username
    elseif ($prefix == "@") {
      $key = drupal_substr($this->twitkey, 1);
      $url = 'http://api.twitter.com/1/statuses/user_timeline.json?screen_name='. urlencode($key) .'&include_rts=true&count='. $num;
    }
    // if the first character is ~, then consider the key a favorites feed
    elseif ($prefix == "~") {
      $key = drupal_substr($this->twitkey, 1);
      $url = 'http://api.twitter.com/1/favorites/'.urlencode($key).'.json?count='.$num;   
    }
    // otherwise, use the key as a search term
    else {
      if ($num > 100) {
        $num = 100;
      }
      $url = 'http://search.twitter.com/search.json?q=' . urlencode($this->twitkey) . '&rpp=' . $num;
    }

    $ret = drupal_http_request($url, array('timeout' => 2));

    if ($ret->code < 200 || $ret->code > 399) {
      $errmsg = t('An unknown error occurred.');
      if (isset($ret->error) && !empty($ret->error)) {
        $errmsg = check_plain($ret->error);
      }
      elseif (isset($ret->data) && !empty($ret->data)) {
        $errdata = json_decode($ret->data);
        if (isset($errdata->error) && !empty($errdata->error)) {
          $errmsg = check_plain($errmsg->error);
        }
      }
      if ($ret->code == 400) {
        $errmsg .= ' ' . t('This site may be subject to rate limiting. For more information, see: http://apiwiki.twitter.com/Rate-limiting');
      }
      throw new Exception(t('Could not retrieve data from Twitter.') . ' ' . $errmsg);
    }

    $items = json_decode($ret->data);
    $this->parse_items($items);

  }

  function parse_items($items) {
    $tweets = array();

    //-- If search response then items are one level lower.
    if (isset($items->results) && is_array($items->results)) {
      $items = $items->results;
    }

    if (is_array($items)) {
      $items = array_slice($items, 0, $this->num_items);
      foreach ($items as $item) {
        $obj = new stdClass();
        if (isset($item->retweeted_status)) {
          $obj->id = $item->retweeted_status->id_str;
          $obj->username = (isset($item->retweeted_status->user) && !empty($item->retweeted_status->user->screen_name)) ? $item->retweeted_status->user->screen_name : $item->retweeted_status->from_user;
            $obj->username = check_plain($obj->username);
          $obj->userphoto = (isset($item->retweeted_status->user) && !empty($item->retweeted_status->user->profile_image_url)) ? $item->retweeted_status->user->profile_image_url : $item->retweeted_status->profile_image_url;
            $obj->userphoto = check_plain($obj->userphoto);
          $obj->text = filter_xss($item->retweeted_status->text);
          //-- Convert date to unix timestamp so themer can easily work with it.
          $obj->timestamp = strtotime($item->retweeted_status->created_at);
        }
        else {
          $obj->id = $item->id_str;
          $obj->username = (isset($item->user) && !empty($item->user->screen_name)) ? $item->user->screen_name : $item->from_user;
            $obj->username = check_plain($obj->username);
          $obj->userphoto = (isset($item->user) && !empty($item->user->profile_image_url)) ? $item->user->profile_image_url : $item->profile_image_url;
            $obj->userphoto = check_plain($obj->userphoto);
          $obj->text = filter_xss($item->text);
          //-- Convert date to unix timestamp so themer can easily work with it.
          $obj->timestamp = strtotime($item->created_at);
        }
        $tweets[] = $obj;
      }
    }

    $this->tweets = $tweets;
  }

}
