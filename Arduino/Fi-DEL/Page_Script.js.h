
const char PAGE_SendAll_js[] PROGMEM = R"=====(
var nodes = [
    'http://espe0c2f1',
//    'http://192.168.1.24',
    'http://espe0bfad',
    'http://esp001507',
    'http://espe0c786',
    'http://esp104d81',
]
function sendReq(path, params) {
    var oReq = new XMLHttpRequest();
    if(params) {
        var query = objToWWWEncoded(params);
        path += '?' + query;
    }
    oReq.open('GET', path);
    oReq.send();
}
function objToWWWEncoded(obj) {
   var str = '';

   for(prop in obj) {
     if(str) {
       str += '&';
     }
     str += prop + '=' + encodeURIComponent(obj[prop]);
   }
   return str;
}
function formToObj(form) {
    var obj = {};
    var inputs = form.getElementsByTagName('input');
    for(input of inputs) {
       obj[input.name] = input.value;
    }
    return obj;
}
function submitForm(form) {
   var obj = formToObj(form);
      for(node of nodes) {
       sendReq(node + form.getAttribute('action'), obj);
   }
}
function submitLink(a) {
   for(node of nodes) {
       sendReq(node + a.getAttribute('href'));
   }
}
function submitButton(a) {
   for(node of nodes) {
       sendReq(node + a.dataset.target);
   }
}
document.addEventListener('DOMContentLoaded', function(event) {
    var forms = document.getElementsByTagName('form');
    var as = document.getElementsByTagName('a');
    var buttons = document.getElementsByTagName('button');
    for(element of forms) {
        element.addEventListener('submit', function(e) {
            e.preventDefault();
            submitForm(e.currentTarget);
        });
    }
    for(element of as) {
        element.addEventListener('click', function(e) {
            e.preventDefault();
            submitLink(e.currentTarget);
        });
    }
    for(element of buttons) {
        element.addEventListener('click', function(e) {
            e.preventDefault();
            submitLink(e.currentTarget);
        });
    }
});

)=====";
