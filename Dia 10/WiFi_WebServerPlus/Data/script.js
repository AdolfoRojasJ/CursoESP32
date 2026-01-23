//Crea eventos para la lectura de los sensores
if (!!window.EventSource) {
  var source = new EventSource('/events');

  source.addEventListener('open', function(e) {
    console.log("Events Connected");
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "/nuevo", true);
    console.log("Solicitud de valores iniciales");
    xhr.send();
  }, false);

  source.addEventListener('error', function(e) {
    if (e.target.readyState != EventSource.OPEN) {
      console.log("Events Disconnected");
    }
  }, false);

  source.addEventListener('perro_salchicha', function(e) {
    console.log("perro_salchicha", e.data);
    var obj = JSON.parse(e.data);
    document.getElementById("iPot").innerHTML = obj.Pot;
    document.getElementById("iLDR").innerHTML = obj.LDR;
    document.getElementById("iCT").innerHTML = obj.CT;
    document.getElementById("led_sta").innerHTML = obj.led_sta;
    document.getElementById("pwmSlider").value = obj.CT;
  }, false);
}

/*
  source.addEventListener('adc_reading', function(e) {
    console.log("adc_reading", e.data);
    document.getElementById("adc").innerHTML = e.data;
  }, false);
*/
//Envío por presión del botón
function toggleBoton(element){
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/"+element.id, true);
  console.log(element.id);
  xhr.send();
}
//Envío por cambio en el Slider
function updateSliderPWM(element) {
  var sliderValue = document.getElementById("pwmSlider").value;
  document.getElementById("iCT").innerHTML = sliderValue;
  console.log(sliderValue);
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/slider?value="+sliderValue, true);
  xhr.send();
}
