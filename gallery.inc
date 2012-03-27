<?php
#(C) Copyright 2009-2012 Nicholas Paun. All Rights Reserved.
#MintPhoto: Simple Photo Gallery

#Gallery functions for MintPhoto

function exif_get_comment($photo)
 {
  //This function gets the EXIF comment for a picture
  $data = exif_read_data($photo);
  $comment = $data['COMMENT'][0];

  if (!isset($comment))
   $comment = "";

  $comment = htmlspecialchars(strip_tags($comment),ENT_QUOTES); #Clean HTML
  return($comment);
 }

function content_gallery($_MINT)
 {
  //This function generates the gallery page
  $photodir = $_MINT['photodir'];
  $script = parse_url($_SERVER['REQUEST_URI'],PHP_URL_PATH); #Remove query string
  $glob = glob($_SERVER['DOCUMENT_ROOT'].$photodir."*");

  foreach ($glob as $photo)
   {
    $photo = basename($photo);
    $thumb = $_MINT['thumbdir']."thumb_$photo";
    $caption = exif_get_comment($_SERVER['DOCUMENT_ROOT'].$photodir.$photo); #Lookup captions

echo <<<EOF
   <div class='mintphoto-imagepreview'>
    <a href='$script?show=$photo' class='mintphoto-anchor'> 
     <img src='$thumb' title='$caption' alt='$caption' class='mintphoto-thumb' />
    </a>
    <p class='mintphoto-caption-small'>
     <a class='mintphoto-caption-link' href='$script?show=$photo'>$caption</a>
    </p>
   </div>
EOF;
  }
 }

function content_photo($photo,$_MINT)
 {
  //This function displays a single image
  $photodir = $_MINT['photodir'];
  $caption = exif_get_comment($_SERVER['DOCUMENT_ROOT'].$photodir.$photo); #Lookup captions

  $script = parse_url($_SERVER['REQUEST_URI'],PHP_URL_PATH); #Remove query string  

  $glob = glob($_SERVER['DOCUMENT_ROOT'].$photodir."*");
  $current = array_search($_SERVER['DOCUMENT_ROOT'].$photodir.$photo,$glob);
  $previous = basename($glob[$current-1]);
  $next = basename($glob[$current+1]);
  
echo <<<EOF
   <p class='mintphoto-imageviewer'>
    <a href='$photodir$photo' class='mintphoto-anchor'>
     <img src='$photodir$photo' title='$caption' alt='$caption' class='mintphoto-image' />
    </a>
   </p>
   <p class='mintphoto-caption'><a href='$script?show=$previous' class='mintphoto-nav' title='Previous' id='nav-prev'>&larr;</a> $caption <a href='$script?show=$next' class='mintphoto-nav' title='Next' id='nav-next'>&rarr;</a></p>
EOF;
 }

function content_index($_INDEX)
 {
  //This function list all galleries
  $script = parse_url($_SERVER['REQUEST_URI'],PHP_URL_PATH); #Remove query string

  foreach($_INDEX as $section => $galleries)
   {
    $id = strtolower(str_replace(" ","-",$section));
    echo("<br style='clear: both;'/><h2 class='mintphoto-section' id='$id'> $section </h2>");
    
    foreach ($galleries as $gallery)
     {
      $gallery = ltrim($gallery,'/');

      if (strpos(basename($gallery),'.') === 0) #Support hiding a gallery
       continue;

      require("config/$gallery.mint");

      $icon = $_MINT['thumbdir']."thumb_".$_MINT['icon'];
      $title = $_MINT['title'];
      $title = htmlspecialchars(strip_tags($title),ENT_QUOTES); #Clean HTML


 echo <<<EOF
      <div class='mintphoto-imagepreview'>
       <a href='$script$gallery' class='mintphoto-anchor'>
        <img src='$icon' title='$title' alt='$title' class='mintphoto-thumb' />
       </a>
      <p class='mintphoto-caption-small mintphoto-caption-index'>
       <a class='mintphoto-caption-link' href='$script$gallery'>$title</a>
      </p>
     </div>
EOF;
      unset($_MINT); #Make sure old settings don't conflict with new ones
   }
  }
 }


?>
