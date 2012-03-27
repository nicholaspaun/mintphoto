<?php
#(C) Copyright 2009-2012 Nicholas Paun. All Rights Reserved.
#MintPhoto: a simple photo gallery
 
#Page header and footer functions for MintPhoto

function page_header($_MINT)
 {
  //This function prints headers
  $title = $_MINT['title'];
  $C_title = htmlspecialchars(strip_tags($title),ENT_QUOTES); #Clean HTML
  $icon = $_MINT['thumbdir'].$_MINT['icon'];

  $script_path = dirname($_SERVER['SCRIPT_NAME']); 
  $stylesheet = $script_path."/style/".$_MINT['stylesheet']."/style.css"; #Prevents PATH_INFO screwing
  
  if (constant('JS'))
   $script = "<script src='".$script_path."/script.js"."'></script>";
  else
   $script = "";
  echo <<<HEADER

<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<!-- Powered by MintPhoto 0.43 -->
<title>$C_title</title>
<link rel="stylesheet" href="$stylesheet" />
<link rel="icon" href="$icon" />
$script
</head>
<body>
 <h1 class="mintphoto-title">$title</h1>
 <div class="mintphoto-content">
  <br />
HEADER;
}

function page_footer($_MINT)
 {
  //This function ends the HTML
  echo("   <br /><br />\n");
  echo <<<FOOTER
  </div>
 </body>
</html>
FOOTER;
}
?>
