const char notfound_page[] PROGMEM = R"=====(
Not Found
  }
)=====";

const char main_page[] PROGMEM = R"=====(
<html>
<head>
<meta charset='utf-8'>
<title>Fi-Del</title>
<script src="SendAll.js"></script>
</head>
<body style='background-color: rgb(12, 24, 36)'>
<span style='display:block; width:100%; font-size:2em; font-family:Verdana; text-align:center; color:white'>Fi-Del</span>
<br/>
<a href='/color?couleur=%23000000&vitesse=0'><span style='display:block; float: left; background-color:Black; width:100%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:White'>BLACKOUT</span></a>
<br>
<a href='/neige'><span style='display:block; float: left; background-color:white; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Neige</span></a>
<a href='/Gyro'><span style='display:block; float: left; background-color:red; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Gyro</span></a>
<a href='/rainbow'><span style='display:block; float: left; background-color:Orange; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Rainbow</span></a>
<a href='/theatre'><span style='display:block; float: left; background-color:pink; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Rainbow Strobe</span></a>
<br>
<a href='/color?couleur=%23FFFFFF&vitesse=50'><span style='display:block; float: left; background-color:white; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 50ms</span></a>
<a href='/color?couleur=%23FFFFFF&vitesse=75'><span style='display:block; float: left; background-color:white; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 75ms</span></a>
<a href='/color?couleur=%23FFFFFF&vitesse=100'><span style='display:block; float: left; background-color:white; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 100ms</span></a>
<a href='/color?couleur=%23FFFFFF&vitesse=0'><span style='display:block; float: left; background-color:white; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>BLANC</span></a>

<a href='/color?couleur=%230000FF&vitesse=50'><span style='display:block; float: left; background-color:blue; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 50ms</span></a>
<a href='/color?couleur=%230000FF&vitesse=75'><span style='display:block; float: left; background-color:blue; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 75ms</span></a>
<a href='/color?couleur=%230000FF&vitesse=100'><span style='display:block; float: left; background-color:blue; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 100ms</span></a>
<a href='/color?couleur=%230000FF&vitesse=0'><span style='display:block; float: left; background-color:blue; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>BLEU</span></a>

<a href='/color?couleur=%23FF0000&vitesse=50'><span style='display:block; float: left; background-color:Red; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 50ms</span></a>
<a href='/color?couleur=%23FF0000&vitesse=75'><span style='display:block; float: left; background-color:Red; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 75ms</span></a>
<a href='/color?couleur=%23FF0000&vitesse=100'><span style='display:block; float: left; background-color:Red; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 100ms</span></a>
<a href='/color?couleur=%23FF0000&vitesse=0'><span style='display:block; float: left; background-color:Red; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>ROUGE</span></a>

<a href='/color?couleur=%2300FF00&vitesse=50'><span style='display:block; float: left; background-color:green; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 50ms</span></a>
<a href='/color?couleur=%2300FF00&vitesse=75'><span style='display:block; float: left; background-color:green; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 75ms</span></a>
<a href='/color?couleur=%2300FF00&vitesse=100'><span style='display:block; float: left; background-color:green; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 100ms</span></a>
<a href='/color?couleur=%2300FF00&vitesse=0'><span style='display:block; float: left; background-color:green; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>VERT</span></a>

<br/>
<center>
<form action='/color' method='get'>
<input type='color' style='width:50%;height:6em' name='couleur' value=#ffffff>
<br>
<br>
<button>envoye</button>
<h1 style='color:white'>Vitesse</h1>
<br>
<br>
<input type='range' value='0' max='250' min='0' step='50' style='width:90%;height:6em' name='vitesse'>
</form>
</center>
</body>
</html>
  }
)=====";
