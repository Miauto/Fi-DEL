///////////////////////////////   PAGE CONFIG START
  const char config_page[] PROGMEM = R"=====(
<html>
<head>
<link rel="icon" type="image/x-icon" href="data:image/x-icon;base64,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" />
<meta charset="utf-8">
  <link rel="stylesheet" href="Style.css" type="text/css" />
  <title>Fi-Del</title>
  <!-- <script src="SendAll.js"></script> -->

  <script src="//ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
  <!-- <script src="rangeslider.min.js"></script> -->

  <svg style="position: absolute; width: 0; height: 0; overflow: hidden;" version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink">
<defs>
<symbol id="icon-cog" viewBox="0 0 32 32">
<title>cog</title>
<path class="path1" d="M29.181 19.070c-1.679-2.908-0.669-6.634 2.255-8.328l-3.145-5.447c-0.898 0.527-1.943 0.829-3.058 0.829-3.361 0-6.085-2.742-6.085-6.125h-6.289c0.008 1.044-0.252 2.103-0.811 3.070-1.679 2.908-5.411 3.897-8.339 2.211l-3.144 5.447c0.905 0.515 1.689 1.268 2.246 2.234 1.676 2.903 0.672 6.623-2.241 8.319l3.145 5.447c0.895-0.522 1.935-0.82 3.044-0.82 3.35 0 6.067 2.725 6.084 6.092h6.289c-0.003-1.034 0.259-2.080 0.811-3.038 1.676-2.903 5.399-3.894 8.325-2.219l3.145-5.447c-0.899-0.515-1.678-1.266-2.232-2.226zM16 22.479c-3.578 0-6.479-2.901-6.479-6.479s2.901-6.479 6.479-6.479c3.578 0 6.479 2.901 6.479 6.479s-2.901 6.479-6.479 6.479z"></path>
</symbol>
<symbol id="icon-reply" viewBox="0 0 32 32">
<title>reply</title>
<path class="path1" d="M4.687 11.119l9.287 8.933v-5.412c2.813 0 9.973 0.062 9.973 7.426 0 3.855-2.734 7.072-6.369 7.816 5.842-0.792 10.359-5.747 10.359-11.806 0-11.256-12.026-11.352-13.963-11.352v-4.606l-9.287 9.001z"></path>
</symbol>
<symbol id="icon-spaceinvaders" viewBox="0 0 33 32">
<title>spaceinvaders</title>
<path class="path1" d="M29.963 24.982v-5.947h-2.91v5.969h-3.037v2.953h-7.048v-2.975h7.048v-2.972h-14.991v2.973l6.030 0.021v2.973h-6.051v-2.951h-3.036v-6.010h-2.911v5.947h-3.057v-9.004h2.995v-2.891h2.973v-3.057h3.057v-2.994h2.994v3.003l8.983 0.024v-3.027h2.994v3.036h3.057v2.974h2.953v2.973h3.014v8.982h-3.057zM12.019 13.005h-2.994v2.995h2.994v-2.995zM23.996 13.005h-2.994v2.995h2.994v-2.995zM5.968 4.023h3.057v2.994h-3.057v-2.994zM27.053 4.023v2.994h-3.057v-2.994h3.057z"></path>
</symbol>
</defs></svg>
  </head>
  <body>
  <a href="/"><svg class="icon icon-reply" Style="position:fixed left:5px top:5px"><use xlink:href="#icon-reply"></use></svg></a>
<br>
Parametres Wifi
  <br>
  <form method='get' action='setting'><label>SSID: </label><input name='ssid' length=32><label> MDP: </label><input name='pass' length=64><input type='submit'></form>
  <br>
Nombre de LEDs:
    <br>
  <form method='get' action='setting'><label>Compris entre 1-99</label><input name='numled' length=1><input type='submit'></form>
  <br>
    <br>
  <form action="/update">
  <input type="submit"  value="Mise a Jour" >
  </form>
    </body>
</html>
  )=====";
///////////////////////////////   PAGE CONFIG END


///////////////////////////////   PAGE MAIN START
const char main_page[] PROGMEM = R"=====(
  <html>
  <head>
<link rel="icon" type="image/x-icon" href="data:image/x-icon;base64,AAABAAEAICAAAAEAIACoEAAAFgAAACgAAAAgAAAAQAAAAAEAIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIAAAACAAAAAgAAAAIAAAACAAAAAgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIAAAAEAAAACAAAAA4AAAAWAAAAIgAAADQAAABIAQEAXCsiC3JHNRF+TDYSgDQkC3QHBAFeAAAASAAAADQAAAAiAAAAFgAAAA4AAAAIAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAEAAAACgAAABQAAAAkAAAANgAAAFIVFAuGZmA1yJOGROyvmUf8s5U9/7OMN/+1iTr/uIpD/66CQvyGXinqUi8KxAsFAIIAAABQAAAANgAAACQAAAAUAAAACgAAAAIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAYAAAAOAAAAHAAAAC4XFg9ImpdnrMfAffbHvnT/xrdm/8KtWP++okr/u5c+/7eKMv+zfif/tHQf/7h3Kv+1di7/qWAY8ng7CJ4GAwBEAAAALgAAABwAAAAOAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAgAAAAYAAAAOlJJxPtbUnNy5vm7/n6hG/5KZMP+RlCr/nJcu/6+fN//IqkP/z6NA/8KNMv+8fif/tm8d/7ZmFf+3YhT/tVwP/61UCsxiLwUwAAAADAAAAAYAAAACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAOTmtjqtx27ucqYt/3WvQP+JpS7/h5gR/46ZEv+TmBP/k5MS/46JEv+hkR7/z6Q2/82QM//Efij/u24d/7hjFf+4Ww7/t1kL/7dYCuK0VwomAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADa/TwQ2vEgqN7pBWDe6QYY3ukG0QrxH8kG9Sv9byWT/f9iG/6DAP/+juhX/sMAX/7zFGP/IyRnowsAZqLWzGYiopReS1LAvztaSNP/JfCj/vmwd/7lgFf+4Ww7/uFkL/7hZC964WQsWAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAARcZgaDi+Tfw3ukP/N7pB/ze6Qf84ukL/SMBR/2XMbf+M3JL/p8w1/7LOGP/L4BrA5PEdSvP6HwIAAAAAAAAAAAAAAAAAAAAA8LNAXteNNPzLeCf/vmgd/7pfFP+4Ww3/uFkL/7hZC7a2WQ0AuFkLMrtaCzIAAAAAAAAAAAAAAAAAAAAAQcJXWja8R/83ukH/N7pB/zu7Rf9Qwln/b9B2/5ngnv+v2S3YxOgaSAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA76hEgNGDMv/KdCf/vGUc/7pfFP+4Wg3/uFkL/7hZC+a4WQv/uFkLMAAAAAAAAAAAAAAAAAAAAAA1wFNoNr1L/ze6Q/83ukH/QL1J/1nFYf951ID/peSq/6ThfA4AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADcp0kG45lB2M18Mf/BbSb/vWQc/7pfE/+4Wg3/uFkL/7hZC9IAAAAAAAAAAAAAAAAAAAAAM8dmADTDW9Y1v1D/NrxH/ze6Qv9Hv1D/Yslq/4PXif+s5rD4AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADPtm0E161lQtGdV5THi0jqwn48/8F0MP+/ayX/vWQb/7peE/+4Wg3/uFkLdgAAAAAAAAAAAAAAAAAAAAAyyGsuM8Vi/zXBVv82vUv/Or1H/0/EWP9szHP/jduT/7TouOQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAOrdgwzw03ya3rBn/9KZVf/Kikj/xHw8/8JyMP+/aiX/vGQb/7peE/y4Ww4eAAAAAAAAAAAAAAAAAAAAADLLc2wzx2n/NMNc/zW/UP9BxVH/W85k/4PWifSX3pz/ueq91gAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAD01HtG6Lhq4teZVv/QiUj/xns7/8JxL/+/aiT/x2pB9O2l2wYAAAAAAAAAAAAAAAAAAAAAMc58ljLKcP8zxWL/NsJX/0jLXf992Ibwq+WvIKXjqbLB7MTAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADszHQQ8L5snt+dWP/UiUj/yns7/8JxLv/ITVv/7pPUPgAAAAAAAAAAAAAAAAAAAAAx0oSuNc56/zPHaf84yGH/UNBp/5vipYYAAAAAqeWuBMPtx1YAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA+XmPnuqYYf/YiUf/zno8/8I3c//ffsNuAAAAAAAAAAAAAAAAAAAAADbYjrI+1Yf/Mspw/z3Oa/9o2IP/rOi5JgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAD8QbuO8DyT/+h9bf/TbVj/tzuA/9Jwu4oAAAAAAAAAAAAAAAAAAAAAPd2Xok3clf8yzHj/Q9N4/3famPwdzLwMAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAPtJzpLvOaP/zzCL/7QwdP+xSJH/yWS4kgAAAAAAAAAAAAAAAAAAAABB4Zx+ZuWn/zPPgP9K2IT/adKb/xS2oToAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA903ZoOg8qv+/MYr/nShx/7ZWrf+8WLSGAAAAAAAAAAAAAAAAAAAAADvhnEZ87bb/NtOK/1LbkP9hzJv/Ha6ZpAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADrT9S+0jul/6YtgP+mPpf/pEyo/7BNsmYAAAAAAAAAAAAAAAAAAAAANuGaCoPxu/JB2Jf/Wt6b/2fPoP8bqpX/TcrFVgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA9Gn0BNVKw+6wNZL/lTCC/6pNvP+WQaT/qEW1MgAAAAAAAAAAAAAAAAAAAAAAAAAAdvCynF7iqv9j36X/e9qt/w6fiv8xwsP4ft3lWAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACpheEC2anzFgAAAAAAAAAAAAAAAAAAAADKWcpGsDyi/5Mwhf+lScT/jT2s/4s3peanRrsCAAAAAAAAAAAAAAAAAAAAAAAAAABR6KEmZeev9mzhr/+U67//G5uD/xOytf81yt//i+DykrPq+QoAAAAAAAAAAAAAAACxlukC16r6VL6S8dCyhuxUAAAAAAAAAAAAAAAA22fbAqhFpsSYOJv/nEbM/4Y6t/9/M6r/fi6tjAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAD7piwBe5q94duW6/5jqxP9VuJ3/EKCc/xW4z/8fwOj/adHy4LTl+Fa2rPAE0K77WriV89Sffej/lHHf/5Zu4x4AAAAAAAAAAMNawwSsTbmWnEfI/4tC1f96Nb7/cy6u/3kyvvhzI8IiAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAGvouQKF6cWwoOvM/6Tlyf8Slor/EaOz/xSu1/8YsOj/dbby/7Wf9vCaf+z/kHTk/4ps2v+GZtf4s379ZKxz/GqfY/eKllTp1IVG3/90OM7/bTC//2cpsv94Osj/ejPZjGsV5AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAJnx0Qqr8NW8uvDX/2vDrv8Plp7/U6XX/5qb8/+Wgu//jXfo/4dw3/+AaNf/e2DU/3lZ2P94U+D/dErd/29C2P9rOtT/ZjLK/18rvf9cJbb/cjjI/4FA4shtH9gKAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAK/z2Qi989yavfDW/02yqP86jML/invs/4V04/9/bNz/eWTZ/3Rc1v9uVNP/akzU/2ZE1f9hPNH/XDTK/1ctwv9UJr7/UyK7/243z/94ONzSYRzKFAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADA89pKvvHW1mO9uv9Ff8r/eGne/3Jh2/9sWdn/ZlDW/2BI0v9aP8//VTfM/1EvyP9NKcX/SiLC/0wgwv9dKMz/XiPNvFIYwBIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACj7MICxvLXTJLUy6Z1gNfoZVXb/15M2P9YRNX/UjvS/0wzz/9HK8z/QyXJ/0Aexv9AGsT/RBjF8EQVwnRGFb8EAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAFxN2wZXSNrAUEDY/0o31f9EL9L/PyjP/zohzP83G8n/NRbH2jYUxH43EsIUAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAEk82RJCNNfaPCvV/zcl0sg1IM9yMhrMVjAWyiQrD8gAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADYp1iYuINXsLBzVbgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACQX1EAkFuI0AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA////////v///4AH//8AA//+AAH//AAA/+AAAH+AD+A/wD/gD8B/8A+Af+AfgH/AH4B/8B8Cf/gfA//8Hwf//A8H//wPh//8D4P//B+D//wfgf/8H8B++B/gOPA/4ADAP/AAAH/4AAD//gAB//+AB///4B////H////7///////8=" />
  <meta charset="utf-8">
  <link rel="stylesheet" href="Style.css" type="text/css" />
  <title>Fi-Del</title>
  <!-- <script src="SendAll.js"></script> -->

  <script src="//ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
  <!-- <script src="rangeslider.min.js"></script> -->

  <svg style="position: absolute; width: 0; height: 0; overflow: hidden;" version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink">
<defs>
<symbol id="icon-cog" viewBox="0 0 32 32">
<title>cog</title>
<path class="path1" d="M29.181 19.070c-1.679-2.908-0.669-6.634 2.255-8.328l-3.145-5.447c-0.898 0.527-1.943 0.829-3.058 0.829-3.361 0-6.085-2.742-6.085-6.125h-6.289c0.008 1.044-0.252 2.103-0.811 3.070-1.679 2.908-5.411 3.897-8.339 2.211l-3.144 5.447c0.905 0.515 1.689 1.268 2.246 2.234 1.676 2.903 0.672 6.623-2.241 8.319l3.145 5.447c0.895-0.522 1.935-0.82 3.044-0.82 3.35 0 6.067 2.725 6.084 6.092h6.289c-0.003-1.034 0.259-2.080 0.811-3.038 1.676-2.903 5.399-3.894 8.325-2.219l3.145-5.447c-0.899-0.515-1.678-1.266-2.232-2.226zM16 22.479c-3.578 0-6.479-2.901-6.479-6.479s2.901-6.479 6.479-6.479c3.578 0 6.479 2.901 6.479 6.479s-2.901 6.479-6.479 6.479z"></path>
</symbol>
<symbol id="icon-reply" viewBox="0 0 32 32">
<title>reply</title>
<path class="path1" d="M4.687 11.119l9.287 8.933v-5.412c2.813 0 9.973 0.062 9.973 7.426 0 3.855-2.734 7.072-6.369 7.816 5.842-0.792 10.359-5.747 10.359-11.806 0-11.256-12.026-11.352-13.963-11.352v-4.606l-9.287 9.001z"></path>
</symbol>
<symbol id="icon-spaceinvaders" viewBox="0 0 33 32">
<title>spaceinvaders</title>
<path class="path1" d="M29.963 24.982v-5.947h-2.91v5.969h-3.037v2.953h-7.048v-2.975h7.048v-2.972h-14.991v2.973l6.030 0.021v2.973h-6.051v-2.951h-3.036v-6.010h-2.911v5.947h-3.057v-9.004h2.995v-2.891h2.973v-3.057h3.057v-2.994h2.994v3.003l8.983 0.024v-3.027h2.994v3.036h3.057v2.974h2.953v2.973h3.014v8.982h-3.057zM12.019 13.005h-2.994v2.995h2.994v-2.995zM23.996 13.005h-2.994v2.995h2.994v-2.995zM5.968 4.023h3.057v2.994h-3.057v-2.994zM27.053 4.023v2.994h-3.057v-2.994h3.057z"></path>
</symbol>
</defs>
</svg>


  </head>
  <body>
  <a href="/Config"><svg class="icon icon-spaceinvaders" Style="position:fixed left:5px top:5px"><use xlink:href="#icon-spaceinvaders"></use></svg></a>
  <div style="display:block; width:100%; font-size:2em; text-align:center; color:white">Fi-Del</div>
  <br>
  <a href="/Blackout"><div class="block-25" style='background-color:Black; width:100%; color:White'>BLACKOUT</div></a>

  <a href="/Neige"><div class="block-25" style='background-color:Snow'>Neige</div></a>
  <a href="/Gyro"><div class="block-25" style='background-color:red'>Gyro</div></a>
  <a href="/Rainbow"><div class="block-25" id="anirainbow" style="background-color:orange">Rainbow</div></a>
  <a href="/RainbowCycle"><div class="block-25" style='background-color:pink'>Rainbow Cycle</div></a>

  <a href="/Fire"><div class="block-25" style='background-color:Orange'>Fire</div></a>
  <a href="/Confetti"><div class="block-25" style='background-color:LimeGreen'>Confetti</div></a>
  <a href="/Nuage"><div class="block-25" style='background-color:Turquoise'>Nuage</div></a>
  <a href="/RainbowWithGlitter"><div class="block-25" style='background-color:Snow'>Rainbow + Glitter</div></a>

  <a href="/TwinkleRandom"><div class="block-25" style='background-color:OldLace'>TwinkleRandom</div></a>
  <a href="/Juggle"><div class="block-25" style='background-color:SeaGreen'>Juggle</div></a>
  <a href="/Bpm"><div class="block-25" style='background-color:grey'>Bpm</div></a>
  <a href="/Ripple"><div class="block-25" style='background-color:grey'>Ripple</div></a>

  <a href="/color?vitesse=50"><div class="block-25" style='background-color:white'>Strobe 50ms</div></a>
  <a href="/color?vitesse=75"><div class="block-25" style='background-color:white'>Strobe 75ms</div></a>
  <a href='/color?vitesse=100'><div class="block-25" style='background-color:white'>Strobe 100ms</div></a>
  <a href='/color?vitesse=0'><div class="block-25" style='background-color:white'>Fixe</div></a>

 <center>
 <form action="/color" method="get" oninput="x.value=parseInt(vitesse.value)">
   <h1>Vitesse:  <output name="x" for="vitesse">0</output></h1>
  <input type="range" max="500" min="0" step="50" name="vitesse" data-rangeslider>
  <br>
  <button style="width:50%;height:6em;border-radius:10px">envoyer</button>
  </form>

  <form action="/color" method="get" oninput="y.value=parseInt(Hue.value)">
    <h1>Hue:  <output name="y" for="Hue">0</output></h1>
  <div class="block-hue" style="background-color:red"></div>
  <div class="block-hue" style="background-color:orange"></div>
  <div class="block-hue" style="background-color:yellow"></div>
  <div class="block-hue" style="background-color:green"></div>
  <div class="block-hue" style="background-color:aqua"></div>
  <div class="block-hue" style="background-color:blue"></div>
  <div class="block-hue" style="background-color:purple"></div>
  <div class="block-hue" style="background-color:pink"></div>
  <div class="block-hue" style="background-color:red"></div>
  <br>
    <input type="range" max="255" min="0" step="1" name="Hue" data-rangeslider>
  <br>
    <button style="width:50%;height:6em;border-radius:10px">envoyer</button>
  </form>
  </center>

  <a href='/color?couleur=%230000FF'><div class="block-25" style='background-color:Blue'>Bleu</div></a>
  <a href='/color?couleur=%23FF0000'><div class="block-25" style='background-color:Red'>Rouge</div></a>
  <a href='/color?couleur=%2300FF00'><div class="block-25" style='background-color:Green'>Vert</div></a>
  <a href='/color?couleur=%23FFFF00'><div class="block-25" style='background-color:Yellow'>Jaune</div></a>

  <a href='/color?couleur=%23DA70D6'><div class="block-25" style='background-color:#DA70D6'>Orchid</div></a>
  <a href='/color?couleur=%23FFD700'><div class="block-25" style='background-color:#FFD700'>Or</div></a>
  <a href='/color?couleur=%23E6E6FA'><div class="block-25" style='background-color:#E6E6FA'>Lavande</div></a>
  <a href='/color?couleur=%23808000'><div class="block-25" style='background-color:#808000'>Olive</div></a>

  <a href='/color?couleur=%23800080'><div class="block-25" style='background-color:#800080'>Violet</div></a>
  <a href='/color?couleur=%23CC5533'><div class="block-25" style='background-color:#CC5533'>Plaid</div></a>
  <a href='/color?couleur=%23FA8072'><div class="block-25" style='background-color:#FA8072'>Saumon</div></a>
  <a href='/color?couleur=%2340E0D0'><div class="block-25" style='background-color:#40E0D0'>Turquoise</div></a>

  <br/>

  <center>
  <form action="/color" method="get" oninput="x.value=parseInt(vitesse.value)">
  <input type="color" style="width:50%;height:6em;border-radius:10px" name="couleur" value=#ffffff>
  <button style="width:50%;height:6em;border-radius:10px">envoyer</button>
  </form>

  </center>

  <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
  <script src="/rangeslider.min.js"></script>
  <script>
    $(function() {

        var $document = $(document);
        var selector = '[data-rangeslider]';
        var $element = $(selector);

        // For ie8 support
        var textContent = ('textContent' in document) ? 'textContent' : 'innerText';

        // Example functionality to demonstrate a value feedback
        function valueOutput(element) {
            var value = element.value;
            var output = element.parentNode.getElementsByTagName('output')[0] || element.parentNode.parentNode.getElementsByTagName('output')[0];
            output[textContent] = value;
        }

        $document.on('input', 'input[type="range"], ' + selector, function(e) {
            valueOutput(e.target);
        });

        // Example functionality to demonstrate disabled functionality
        $document .on('click', '#js-example-disabled button[data-behaviour="toggle"]', function(e) {
            var $inputRange = $(selector, e.target.parentNode);

            if ($inputRange[0].disabled) {
                $inputRange.prop("disabled", false);
            }
            else {
                $inputRange.prop("disabled", true);
            }
            $inputRange.rangeslider('update');
        });

        // Example functionality to demonstrate programmatic value changes
        $document.on('click', '#js-example-change-value button', function(e) {
            var $inputRange = $(selector, e.target.parentNode);
            var value = $('input[type="number"]', e.target.parentNode)[0].value;

            $inputRange.val(value).change();
        });

        // Example functionality to demonstrate programmatic attribute changes
        $document.on('click', '#js-example-change-attributes button', function(e) {
            var $inputRange = $(selector, e.target.parentNode);
            var attributes = {
                    min: $('input[name="min"]', e.target.parentNode)[0].value,
                    max: $('input[name="max"]', e.target.parentNode)[0].value,
                    step: $('input[name="step"]', e.target.parentNode)[0].value
                };

            $inputRange.attr(attributes);
            $inputRange.rangeslider('update', true);
        });

        // Example functionality to demonstrate destroy functionality
        $document
            .on('click', '#js-example-destroy button[data-behaviour="destroy"]', function(e) {
                $(selector, e.target.parentNode).rangeslider('destroy');
            })
            .on('click', '#js-example-destroy button[data-behaviour="initialize"]', function(e) {
                $(selector, e.target.parentNode).rangeslider({ polyfill: false });
            });

        // Example functionality to test initialisation on hidden elements
        $document
            .on('click', '#js-example-hidden button[data-behaviour="toggle"]', function(e) {
                var $container = $(e.target.previousElementSibling);
                $container.toggle();
            });

        // Basic rangeslider initialization
        $element.rangeslider({

            // Deactivate the feature detection
            polyfill: false,

            // Callback function
            onInit: function() {
                valueOutput(this.$element[0]);
            },

            // Callback function
            onSlide: function(position, value) {
                console.log('onSlide');
                console.log('position: ' + position, 'value: ' + value);
            },

            // Callback function
            onSlideEnd: function(position, value) {
                console.log('onSlideEnd');
                console.log('position: ' + position, 'value: ' + value);
            }
        });

    });
    </script>
    <div id="footer_wrap" class="outer">
      <footer class="inner">
        <p class="copyright">Fi-del maintained by <a href="https://github.com/Miauto">Miauto</a></p>
      </footer>
    </div>
  </body>
  </html>

)=====";
