//(C) Copyright 2009-2012 Nicholas Paun. All Rights Reserved.
//Javascript functions for MintPhoto

function slideshowKeys(e)
 {
  var prev = document.getElementById('nav-prev').getAttribute('href');
  var next = document.getElementById('nav-next').getAttribute('href');

  if (e)
   {
    var keyID = (window.event) ? event.keyCode : e.keyCode;
    if (keyID == 37) window.location.href = prev;
    if (keyID == 39) window.location.href = next;
   }
 }

document.onkeydown = slideshowKeys;

