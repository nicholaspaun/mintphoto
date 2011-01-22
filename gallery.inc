<?php
#(C) Copyright 2009-2010 Nicholas Paun. All Rights Reserved.
#mintPhoto: Simple Photo Gallery

#Gallery functions for mintPhoto
function caption_check($exif)
{
  foreach ($exif as $key => $section) 
   {
    foreach ($section as $name => $val) 
     {
      echo "$key.$name: $val<br />\n";
     }
   }
}

function exif_get_comment($photo)
 {
  //This function gets the EXIF comment for a picture
  $data = exif_read_data($photo);
  $comment = $data['COMMENT'][0];
  //caption_check($data);
  if (!isset($comment))
   $comment = "";

  return($comment);
 }

function gallery_main_content($_MINT)
 {
  //This function generates the gallery page
  $photodir = $_MINT['photodir'];
  $script = $_SERVER['PHP_SELF'];
  $glob = glob($photodir."*");

  foreach ($glob as $photo)
   {
    $photo = basename($photo);
    $thumb = $_MINT['thumbdir']."thumb_$photo";
    $caption = exif_get_comment($photodir.$photo); #Lookup captions

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

function gallery_photo_content($photo,$_MINT)
 {
  //This function displays a single image
  $photodir = $_MINT['photodir'];
  $caption = exif_get_comment($photodir.$photo); #Lookup captions

  $doc_root = $_SERVER['DOCUMENT_ROOT'];
  $path = str_replace($doc_root,'',$photodir);

echo <<<EOF
   <p class='mintphoto-imageviewer'>
    <a href='$path$photo' class='mintphoto-anchor'>
     <img src='$path$photo' title='$caption' alt='$caption' class='mintphoto-image' />
    </a>
   </p>
   <p class='mintphoto-caption'>$caption</p>
EOF;
 }
?>
