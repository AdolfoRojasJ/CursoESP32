# Curso ESP32
**Basic C++ Codes for Arduino IDE**
<div align="center">
  <img src="./.Resources/ESP32.png" alt="ESP32" width="500" />
</div>

# Codes for ESP32 
These are codes developed on the "ESP32 Programming and Wireless Conectivity" 10 days course, presented by [Ulises Martin Peñuelas Rivas](https://www.paginaspersonales.unam.mx/app/webroot/index.php/academicos/datosContacto/alias:ulisesmartinpeNuelas).
Most codes tested on a [Dual-MCU Development Board](https://uelectronics.com/producto/unit-dualmcu-esp32-rp2040-tarjeta-de-desarrollo/) by [UNIT ELECTRONICS](https://github.com/UNIT-Electronics).
<br><br>
<div align="center">
  <img src="./.Resources/Pinout.jpg" alt="DUALMCU" width="1000" />
</div>

# Week 1:
* [Day 1](./Dia%201/)
    * [1.1 Led Blink](./Dia%201/Blink/)
    * [1.2 Led Blink v2](./Dia%201/Blinkv2/)
* [Day 2](./Dia%202/)
    * [2.1 UART Echo](./Dia%202/Echo/)
    * [2.2 Knight Rider Leds](./Dia%202/KnightRider/)
    * [2.3 UART Serial Communication](./Dia%202/SerialCOM/)
    * [2.4 UART Blink Led](./Dia%202/UARTBlink/)
* [Day 3](./Dia%203/)
    * [3.1 Bluetooth Connection](./Dia%203/Bluetooth/)
    * [3.2 Button Input](./Dia%203/Boton/)
    * [3.3 Basic Interruption](./Dia%203/Interrupcion/)
    * [3.4 Interruption w Led](./Dia%203/Interrupcion_con_LED/)
* [Day 4](./Dia%204/)
    * [4.1 PWM Led Control](./Dia%204/led_PWM/)
    * [4.2 PWM Led Control by UART](./Dia%204/led_PWM_Serie/)
    * [4.3 RGB Led Control by UART](./Dia%204/led_PWM_UART_BT/)
* [Day 5](./Dia%205/)
    * [5.1 Basic ADC](./Dia%205/ADC_1/)
    * [5.2 Basic ADC using conversion factor](./Dia%205/ADC_1_Conversion_Fact/)
    * [5.3 RGB Led Control by Bluetooth](./Dia%205/RGB_Bluetooth/)
    * [5.4 Touch Sensor](./Dia%205/Touch/)

## Day 1:
### Led Blink:
Basic Led blinking for 500 ms.
### Led Blink v2:
Same blinking for 500 ms, but using definitions on the code.
## Day 2:
### UART Echo:
Delivers the same key that you are pressing on the Serial Monitor.
### Knight Rider Leds:
Knight Rider Led secquence-like.
<br><br>

![Knight Rider Secquence](./.Resources/Knight.gif)
### UART Serial Communication:
Basic Serial communication code lines.
### UART Blink Led:
Led's delay control using UART Communication.
## Day 3:
### Bluetooth Connection:
Communication between [Bluetooth Serial Terminal Android App](https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&hl=es_MX&gl=US&pli=1) and the ESP32.
### Button Input:
Basic button pressed counter.
### Basic Interruption:
Button pressed counter using different interruption triggers.
### Interruption with Led:
Blinky Led + Button counter handled by interruption.
## Day 4:
### PWM Led Control:
Led Brightness control using a PWM Signal.
### PWM Led Control by UART:
PWM Signal control by UART Protocol.
### RGB Led Control by UART:
Serial communication control for a RGB Led.
## Day 5:
### Basic ADC:
Using ESP32's ADC to read voltage values using a Potenciometer.
### Basic ADC using conversion factor:
Same ADC Read Voltage but using a conversion calculated factor to obtain the voltage.
### RGB Led Control by Bluetooth:
RGB Led Control using the [Bluetooth Serial Terminal Android App](https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&hl=es_MX&gl=US&pli=1) 
### Touch Sensor 
Basic Touch Sensor code for the ESP32.
# Week 2:
* [Day 6](./Dia%206/)
    * [6.1 Basic DAC](./Dia%206/DAC/)
    * [6.2 Basic DAC Harmonic Function and Trigonometrical Function Plotting](./Dia%206/DAC2/)
    * [6.3 I2C Address Finder](./Dia%206/I2CAddress)
* [Day 7](./Dia%207/)
    * [7.1 WiFi Library](./Dia%207/WiFi_Library/)
    * [7.2 WiFi Scanner](./Dia%207/WiFi_Scanner/)
    * [7.3 ESP32 WiFI Station](./Dia%207/WiFi_Station/)
* [Day 8](./Dia%208/)
    * [8.1 WiFi Time](./Dia%208/ESP32_Hora_WiFi/)
* [Day 9](./Dia%209/)
    * [9.1 WiFi Time V2](./Dia%209/ESP32_Hora_WiFi_V2/)
    * [9.2 WiFi TCP Cient](./Dia%209/WiFi_TCP_Client/)
    * [9.3 WiFi TCP Server](./Dia%209/WiFi_TCP_Server/)
* [Day 10](./Dia%2010/)
    * [10.1 Bidirectional UDP Communication](./Dia%2010/UDP_BIDI/)
    * [10.2 UDP Led Control](./Dia%2010/UDP_Leds/)
    * [10.3 UDP UART Control](./Dia%2010/UDP_UART/)
## Day 6:
### Basic DAC:
Connection between one of the ESP32's ADC to the DAC, use the Serial Plotter to watch the Graphic behavior.
> **Note:** This Code didn't work on the Dual MCU due it doesn't have DAC Pin. Try using another ESP32 DevKit.
### Basic DAC Harmonic Function and Trigonometrical Function Plotting:
Connection between one of the ESP32's ADC to the DAC, including a trigonometrical and a harmonic function, use the Serial Plotter to watch the Graphic behavior.
> **Note:** This Code didn't work on the Dual MCU due it doesn't have DAC Pin. Try using another ESP32 DevKit.
### I2C Addres Finder:
Basic code that prints the slave's address of any i2c peripherical to the Serial Monitor.
## Day 7:
### WiFi Library:
Creation of a WiFi Library to handle the ESP32 as a WiFi Station.
### WiFi Scanner:
Simple code that prints all the 2.4 GHz WiFi Connections available.
### ESP32 WiFi Station:
Use the ESP32 to create a WiFi Station that could connect to a given WiFi Network.
## Day 8:
Code by [Daredliuth](https://github.com/daredliuth)
### WiFi Time:
Obtaining the current time via NTP Service.
## Day 9:
### WiFi Time V2:
Updating the Serial Print in order to change the format.
### WiFi Time Client:
Basic TCP Client.
### WiFi TCP Server:
Basic TCP Server.
## Day 10:
### Bidirectional UDP Communication:
### UDP Led Control:
Control 4 Leds using UDP Connection.
> **Note:** In order to send the UDP Message I used [Termux](https://play.google.com/store/apps/details?id=com.termux&hl=en-US), and then:  
> **Note:** pkg install netcat-openbsd  
> **Note:** echo "UNO" | nc -u 192.168.0.56 123 ← Example
### UDP UART Control:
UART Message sending by UDP Connection.
> **Note:** In order to send the UDP Message I used [Termux](https://play.google.com/store/apps/details?id=com.termux&hl=en-US), and then:  
> **Note:** ifconfig (To obtain the remote IP of the phone)  
> **Note:** nc -u -l -p 60518
