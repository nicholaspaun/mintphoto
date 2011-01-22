<?php
#(C) Copyright 2009-2010 Nicholas Paun. All Rights Reserved.
#mintPhoto: simple photo gallery

/* mintphoto ver4 rev2 */
 
#Main functions for MintPhoto
require('config/index.mint');

function gallery_switch($_INDEX)
 {
  //This function switches galleries on user request
  $gallery = $_SERVER['PATH_INFO']; #Get gallery based on path
  $gallery = str_replace('/','',$gallery); #Remove initial slashes
   
  if (empty($gallery))
    die("Error [1]: No gallery selected."); #Prevent displaying nothing

  if (in_array($gallery,$_INDEX)) #Exploit prevention
   {
    require("config/$gallery.mint"); #Load gallery
    return($_MINT);
   }
  else
   {
    //TODO: Redirect user to index page 
    die("Error [2]: Invalid gallery selected."); #Stop directory traversal exploit.
   }
  }

require('page.inc'); //Writes HTML header and footer
require('gallery.inc'); //Displays gallery and images

function main($_MINT)
 {
  //This is the function that processes user requests
  $show = $_GET['show'];
  gallery_header($_MINT);
  
 if (!isset($show)) #If user did not select a picture to show, display everything
   {  
    gallery_main_content($_MINT);
   }
 else
  {
   gallery_photo_content($show,$_MINT); #User selected something, display only it
  }

  gallery_footer($_MINT);
 }

$_MINT = gallery_switch($_INDEX);
main($_MINT);
?>
