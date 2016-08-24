const char PAGE_Style_css[] PROGMEM = R"=====(

body {
  font-family: 'Handlee', cursive;
  color: white;
  background-color: #282b2f;
}

.icon {
    display: inline-block;
    width: 1em;
    height: 1em;
    stroke-width: 1;
    stroke: chocolate;
    fill: #282b2f;
    color: #282b2f;
    font-size: 50px;
}
.icon-spaceinvaders {
    width: 1.03125em;
}

.block-25 {
  display: inline-block;
  float: left;
  height:5em;
  font-size:2em;
  text-align:center;
  vertical-align:middle;
  width:25%;
  color:Black;
  border-radius: 10px
}

.block-100 {

}

/* ----------------------------------- */
<!-- #########  ANIMATION  ######### -->
/* ----------------------------------- */
#anirainbow {
    -webkit-animation-name: example; /* Chrome, Safari, Opera */
    -webkit-animation-duration: 10s; /* Chrome, Safari, Opera */
    animation-name: example;
    animation-duration: 10s;
    animation-iteration-count: infinite;
}

/* Chrome, Safari, Opera */
@-webkit-keyframes example {
    0%   {background-color: magenta;}
    25%  {background-color: blue;}
    50%  {background-color: green;}
    75% {background-color: yellow;}
    100% {background-color: red;}
}

/* Standard syntax */
@keyframes example {
    0%   {background-color: magenta;}
    25%  {background-color: blue;}
    50%  {background-color: green;}
    75% {background-color: yellow;}
    100% {background-color: red;}
}
/* -------------------------------------- */
<!-- #########  FIN ANIMATION  ######### -->
/* -------------------------------------- */
#footer_wrap {
    background: #212121;
}
.outer {
  width: 100%;
}
.inner {
  position: relative;
  max-width: 640px;
  padding: 20px 10px;
  margin: 0 auto;
}

#rainbow {
  width: 95%;
  height: 80px;
  &:hover {
    cursor: crosshair;
  }
}

.color-sample {
  width: 40px;
  height: 40px;
}
.result {
  width: 100%;
  font-family: 'Istok Web', sans-serif;
  font-size: 1em;
}

.rangeslider,
.rangeslider__fill {
  display: block;
  -moz-box-shadow: inset 0px 1px 3px rgba(0, 0, 0, 0.3);
  -webkit-box-shadow: inset 0px 1px 3px rgba(0, 0, 0, 0.3);
  box-shadow: inset 0px 1px 3px rgba(0, 0, 0, 0.3);
  -moz-border-radius: 10px;
  -webkit-border-radius: 10px;
  border-radius: 10px;
}

.rangeslider {
  background: #204972;
  position: relative;
}

.rangeslider--horizontal {
  height: 20px;
  width: 100%;
}

.rangeslider--vertical {
  width: 20px;
  min-height: 150px;
  max-height: 100%;
}

.rangeslider__fill {
  background: #59A85A;
  position: absolute;
}
.rangeslider--horizontal .rangeslider__fill {
  top: 0;
  height: 100%;
}
.rangeslider--vertical .rangeslider__fill {
  bottom: 0;
  width: 100%;
}

.rangeslider__handle {
  background: white;
  border: 1px solid #ccc;
  cursor: pointer;
  display: inline-block;
  width: 60px;
  height: 60px;
  position: absolute;
  background-image: url('data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0idXRmLTgiPz4gPHN2ZyB2ZXJzaW9uPSIxLjEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyI+PGRlZnM+PGxpbmVhckdyYWRpZW50IGlkPSJncmFkIiBncmFkaWVudFVuaXRzPSJvYmplY3RCb3VuZGluZ0JveCIgeDE9IjAuNSIgeTE9IjAuMCIgeDI9IjAuNSIgeTI9IjEuMCI+PHN0b3Agb2Zmc2V0PSIwJSIgc3RvcC1jb2xvcj0iI2ZmZmZmZiIgc3RvcC1vcGFjaXR5PSIwLjAiLz48c3RvcCBvZmZzZXQ9IjEwMCUiIHN0b3AtY29sb3I9IiMwMDAwMDAiIHN0b3Atb3BhY2l0eT0iMC4xIi8+PC9saW5lYXJHcmFkaWVudD48L2RlZnM+PHJlY3QgeD0iMCIgeT0iMCIgd2lkdGg9IjEwMCUiIGhlaWdodD0iMTAwJSIgZmlsbD0idXJsKCNncmFkKSIgLz48L3N2Zz4g');
  background-size: 100%;
  background-image: -webkit-gradient(linear, 50% 0%, 50% 100%, color-stop(0%, rgba(255, 255, 255, 0)), color-stop(100%, rgba(0, 0, 0, 0.1)));
  background-image: -moz-linear-gradient(rgba(255, 255, 255, 0), rgba(0, 0, 0, 0.1));
  background-image: -webkit-linear-gradient(rgba(255, 255, 255, 0), rgba(0, 0, 0, 0.1));
  background-image: linear-gradient(rgba(255, 255, 255, 0), rgba(0, 0, 0, 0.1));
  -moz-box-shadow: 0 0 8px rgba(0, 0, 0, 0.3);
  -webkit-box-shadow: 0 0 8px rgba(0, 0, 0, 0.3);
  box-shadow: 0 0 8px rgba(0, 0, 0, 0.3);
  -moz-border-radius: 50%;
  -webkit-border-radius: 50%;
  border-radius: 50%;
}
.rangeslider__handle:after {
  content: "";
  display: block;
  width: 18px;
  height: 18px;
  margin: auto;
  position: absolute;
  top: 0;
  right: 0;
  bottom: 0;
  left: 0;
  background-image: url('data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0idXRmLTgiPz4gPHN2ZyB2ZXJzaW9uPSIxLjEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyI+PGRlZnM+PGxpbmVhckdyYWRpZW50IGlkPSJncmFkIiBncmFkaWVudFVuaXRzPSJvYmplY3RCb3VuZGluZ0JveCIgeDE9IjAuNSIgeTE9IjAuMCIgeDI9IjAuNSIgeTI9IjEuMCI+PHN0b3Agb2Zmc2V0PSIwJSIgc3RvcC1jb2xvcj0iIzAwMDAwMCIgc3RvcC1vcGFjaXR5PSIwLjEzIi8+PHN0b3Agb2Zmc2V0PSIxMDAlIiBzdG9wLWNvbG9yPSIjZmZmZmZmIiBzdG9wLW9wYWNpdHk9IjAuMCIvPjwvbGluZWFyR3JhZGllbnQ+PC9kZWZzPjxyZWN0IHg9IjAiIHk9IjAiIHdpZHRoPSIxMDAlIiBoZWlnaHQ9IjEwMCUiIGZpbGw9InVybCgjZ3JhZCkiIC8+PC9zdmc+IA==');
  background-size: 100%;
  background-image: -webkit-gradient(linear, 50% 0%, 50% 100%, color-stop(0%, rgba(0, 0, 0, 0.13)), color-stop(100%, rgba(255, 255, 255, 0)));
  background-image: -moz-linear-gradient(rgba(0, 0, 0, 0.13), rgba(255, 255, 255, 0));
  background-image: -webkit-linear-gradient(rgba(0, 0, 0, 0.13), rgba(255, 255, 255, 0));
  background-image: linear-gradient(rgba(0, 0, 0, 0.13), rgba(255, 255, 255, 0));
  -moz-border-radius: 50%;
  -webkit-border-radius: 50%;
  border-radius: 50%;
}
.rangeslider__handle:active {
  background-image: url('data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0idXRmLTgiPz4gPHN2ZyB2ZXJzaW9uPSIxLjEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyI+PGRlZnM+PGxpbmVhckdyYWRpZW50IGlkPSJncmFkIiBncmFkaWVudFVuaXRzPSJvYmplY3RCb3VuZGluZ0JveCIgeDE9IjAuNSIgeTE9IjAuMCIgeDI9IjAuNSIgeTI9IjEuMCI+PHN0b3Agb2Zmc2V0PSIwJSIgc3RvcC1jb2xvcj0iIzAwMDAwMCIgc3RvcC1vcGFjaXR5PSIwLjEiLz48c3RvcCBvZmZzZXQ9IjEwMCUiIHN0b3AtY29sb3I9IiMwMDAwMDAiIHN0b3Atb3BhY2l0eT0iMC4xMiIvPjwvbGluZWFyR3JhZGllbnQ+PC9kZWZzPjxyZWN0IHg9IjAiIHk9IjAiIHdpZHRoPSIxMDAlIiBoZWlnaHQ9IjEwMCUiIGZpbGw9InVybCgjZ3JhZCkiIC8+PC9zdmc+IA==');
  background-size: 100%;
  background-image: -webkit-gradient(linear, 50% 0%, 50% 100%, color-stop(0%, rgba(0, 0, 0, 0.1)), color-stop(100%, rgba(0, 0, 0, 0.12)));
  background-image: -moz-linear-gradient(rgba(0, 0, 0, 0.1), rgba(0, 0, 0, 0.12));
  background-image: -webkit-linear-gradient(rgba(0, 0, 0, 0.1), rgba(0, 0, 0, 0.12));
  background-image: linear-gradient(rgba(0, 0, 0, 0.1), rgba(0, 0, 0, 0.12));
}
.rangeslider--horizontal .rangeslider__handle {
  top: -20px;
  touch-action: pan-y;
  -ms-touch-action: pan-y;
}
.rangeslider--vertical .rangeslider__handle {
  left: -10px;
  touch-action: pan-x;
  -ms-touch-action: pan-x;
}

input[type="range"]:focus + .rangeslider .rangeslider__handle {
  -moz-box-shadow: 0 0 8px rgba(255, 0, 255, 0.9);
  -webkit-box-shadow: 0 0 8px rgba(255, 0, 255, 0.9);
  box-shadow: 0 0 8px rgba(255, 0, 255, 0.9);
}
)=====";
