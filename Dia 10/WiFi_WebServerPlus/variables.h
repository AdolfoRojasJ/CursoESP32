//WiFi
#define ssid "CD_UNAM"
#define pass "MegaChidoLiro"

//GPIO
#define led 2
bool led_sta = false;   //Variable que se enviará

//HTTP
const char* PARAM_INPUT = "value";

//PWM
#define pwm_pin 23
#define pwm_res 12
#define pwm_fre 8000
#define pwm_max 4095
unsigned int ct=0;
String pwm_ct="0";

//ADC
#define pot 36
#define ldr 39
float adc;  //Variable que se enviará
#define adc_max 4095

//Tiempo
uint32_t t_anterior = 0;
uint32_t t_sensado = 1000;
