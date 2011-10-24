<?php
#(C) Copyright 2009-2011 Nicholas Paun. All Rights Reserved.
#MintPhoto: a simple photo gallery

/* mintphoto ver4 rev3 */

require('config/index.mint'); #Load index file
require('page.inc'); #Load page header/footer functions
require('gallery.inc'); #Gallery, photo and index functions

function gallery_switch($_INDEX,$_MINT)
 {
  //This function switches galleries on user request
  $gallery = $_SERVER['PATH_INFO']; #Get gallery based on path
  $gallery = ltrim($gallery,'/'); #Remove initial slashes /* Allow slashes in URL: 2010-10-16*/
   
  if (empty($gallery))
   return($_MINT); #Use index settings

  if (count($_INDEX) != count($_INDEX, COUNT_RECURSIVE)) #Check if array needs to be flattened
   $_INDEX = call_user_func_array("array_merge", $_INDEX); #Flatten it

  if (in_array($gallery,$_INDEX)) #Exploit prevention
   {
    unset($_MINT); #Remov index settings
    require("config/$gallery.mint"); #Load gallery
    return($_MINT);
   }
  else
   {
    //TODO: Redirect user to index page 
    die("Error [2]: Invalid gallery selected."); #Stop directory traversal exploit.
   }
  }

function main($_MINT,$_INDEX)
 {
  //This is the function that processes user requests
  $show = $_GET['show'];
  page_header($_MINT);
  
  switch($_MINT['photodir']) #Switch on page mode
   {
    case "/": #If the configuration file specifies photos from /, do an index
     content_index($_INDEX,$_MINT);
    break;

   case !isset($show) || empty($show): #If no photos to view are specified, show the gallery 
    content_gallery($_MINT);
   break;

   default: #Show a single photo
    content_photo($show,$_MINT);
   break;
  }
  page_footer($_MINT);
 }

$_MINT = gallery_switch($_INDEX,$_MINT);
main($_MINT,$_INDEX);
?>
