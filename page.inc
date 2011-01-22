<?php
#(C) Copyright 2009-2010 Nicholas Paun. All Rights Reserved.
#mintPhoto: simple photo gallery
 
#Page header and footer functions for MintPhoto

function gallery_header($_MINT)
 {
  //This function prints headers
  $title = $_MINT['title'];
  $REQUEST_URI = $_SERVER['SCRIPT_NAME']; 
  $stylesheet = dirname($REQUEST_URI)."/".$_MINT['stylesheet']; #Prevents PATH_INFO screwing
  
  echo <<<HEADER
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<!--
#(C) Copyright 2009-2010 Nicholas Paun

#THIS IS A ALPHA VERSION!!!
#(USE WITH CAUTION FOR PRODUCTION)

 #THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
-->
<title>$title</title>
<link rel="stylesheet" href="$stylesheet" />
</head>
<body>
 <h1 class="mintphoto-title">$title</h1>
 <div class="mintphoto-content">
  <br />
HEADER;
}

function gallery_footer($_MINT)
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
