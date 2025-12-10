// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using std::isnan;
using std::min;
using std::max;
using namespace binary_sensor;
using namespace light;
using namespace switch_;
using namespace display;
using namespace time;
logger::Logger *logger_logger_id;
web_server_base::WebServerBase *web_server_base_webserverbase_id;
captive_portal::CaptivePortal *captive_portal_captiveportal_id;
wifi::WiFiComponent *wifi_wificomponent_id;
mdns::MDNSComponent *mdns_mdnscomponent_id;
http_request::OtaHttpRequestComponent *http_request_otahttprequestcomponent_id;
esphome::ESPHomeOTAComponent *esphome_esphomeotacomponent_id;
web_server::WebServerOTAComponent *web_server_webserverotacomponent_id;
safe_mode::SafeModeComponent *safe_mode_safemodecomponent_id;
Automation<> *automation_id_2;
StatelessLambdaAction<> *lambdaaction_id_6;
api::APIServer *api_apiserver_id;
using namespace api;
StartupTrigger *startuptrigger_id;
Automation<> *automation_id;
using namespace i2c;
i2c::ArduinoI2CBus *i2c_arduinoi2cbus_id;
using namespace json;
using namespace uart;
uart::ESP8266UartComponent *uart_esp8266uartcomponent_id;
esphome::esp8266::ESP8266GPIOPin *esphome_esp8266_esp8266gpiopin_id;
esphome::esp8266::ESP8266GPIOPin *esphome_esp8266_esp8266gpiopin_id_2;
dfplayer::DFPlayer *dfp;
gpio::GPIOBinarySensor *ui_next;
binary_sensor::PressTrigger *binary_sensor_presstrigger_id;
Automation<> *automation_id_3;
gpio::GPIOBinarySensor *ui_select;
binary_sensor::PressTrigger *binary_sensor_presstrigger_id_2;
Automation<> *automation_id_4;
binary::BinaryLightOutput *binary_binarylightoutput_id;
light::LightState *builtin_led;
gpio::GPIOSwitch *external_relay;
esphome::esp8266::ESP8266GPIOPin *esphome_esp8266_esp8266gpiopin_id_5;
restart::RestartSwitch *_restart;
using namespace output;
gpio::GPIOBinaryOutput *led_output;
esphome::esp8266::ESP8266GPIOPin *esphome_esp8266_esp8266gpiopin_id_6;
http_request::HttpRequestArduino *http_request_httprequestarduino_id;
ssd1306_i2c::I2CSSD1306 *oled;
esphome::esp8266::ESP8266GPIOPin *esphome_esp8266_esp8266gpiopin_id_7;
font::Font *font1;
sntp::SNTPComponent *sntp_time;
time::CronTrigger *time_crontrigger_id;
Automation<> *automation_id_6;
script::RestartScript<> *refresh_prayer_times_if_needed;
script::SingleScript<> *make_athan;
script::SingleScript<> *perform_update;
script::SingleScript<> *test_script;
script::SingleScript<> *check_update_remote;
script::SingleScript<> *run_quyam;
script::SingleScript<> *change_location_handler;
script::RestartScript<> *load_prayer_times;
script::RestartScript<> *log_prayers;
script::RestartScript<> *Jump_to_next_prayer;
script::RestartScript<> *compute_coming_prayer;
script::RestartScript<> *update_display;
Automation<> *automation_id_8;
interval::IntervalTrigger *interval_intervaltrigger_id;
Automation<> *automation_id_23;
preferences::IntervalSyncer *preferences_intervalsyncer_id;
StatelessLambdaCondition<> *lambdacondition_id;
WaitUntilAction<> *waituntilaction_id_2;
script::ScriptExecuteAction<script::Script<>> *script_scriptexecuteaction_id_2;
script::ScriptExecuteAction<script::Script<>> *script_scriptexecuteaction_id_4;
globals::GlobalsComponent<bool> *prayer_times_refreshed_at_least_once;
globals::GlobalsComponent<bool> *loaded_prayer_times_once;
globals::RestoringGlobalsComponent<int> *volume_level;
globals::RestoringGlobalsComponent<int> *athan_file_index;
globals::RestoringGlobalsComponent<int> *htick_file_index;
globals::GlobalsComponent<bool> *athan_playing;
globals::GlobalsComponent<int> *ui_mode;
globals::GlobalsComponent<int> *ui_menu_index;
globals::GlobalsComponent<int> *athan_index;
globals::GlobalsComponent<int> *htick_index;
globals::GlobalsComponent<int> *location_index;
globals::RestoringGlobalsComponent<int> *selected_location_index;
globals::RestoringGlobalStringComponent<std::string, 64> *selected_location_tz;
globals::GlobalsComponent<bool> *time_zone_changed_at_boot;
globals::GlobalsComponent<int> *ui_last_activity;
globals::GlobalsComponent<int> *current_athan_prayer_index;
globals::RestoringGlobalsComponent<int[7]> *prayer_hours;
globals::RestoringGlobalsComponent<int[7]> *prayer_minutes;
globals::RestoringGlobalsComponent<int> *prayer_times_day;
globals::RestoringGlobalsComponent<int> *prayer_times_year;
globals::RestoringGlobalsComponent<int> *next_prayer_index;
globals::RestoringGlobalsComponent<int> *next_prayer_hour;
globals::RestoringGlobalsComponent<int> *next_prayer_minute;
globals::RestoringGlobalsComponent<int> *quyam_next_hour;
globals::RestoringGlobalsComponent<int> *quyam_next_minute;
globals::GlobalsComponent<bool> *quyam_triggered;
globals::RestoringGlobalsComponent<bool> *q_flag;
globals::GlobalsComponent<int> *q_select_count;
globals::GlobalsComponent<int> *update_latest_version;
globals::GlobalsComponent<int> *update_check_state;
globals::GlobalsComponent<std::string> *update_url;
StatelessLambdaAction<> *lambdaaction_id_13;
Automation<> *automation_id_9;
StatelessLambdaAction<> *lambdaaction_id_14;
StatelessLambdaAction<> *lambdaaction_id_15;
light::LightControlAction<> *light_lightcontrolaction_id_10;
DelayAction<> *delayaction_id_9;
light::LightControlAction<> *light_lightcontrolaction_id_11;
StatelessLambdaAction<> *lambdaaction_id_16;
Automation<> *automation_id_10;
StatelessLambdaAction<> *lambdaaction_id_17;
http_request::OtaHttpRequestComponentFlashAction<> *http_request_otahttprequestcomponentflashaction_id;
StatelessLambdaAction<> *lambdaaction_id_18;
Automation<> *automation_id_11;
StatelessLambdaAction<> *lambdaaction_id_19;
Automation<> *automation_id_13;
StatelessLambdaAction<> *lambdaaction_id_20;
http_request::HttpRequestSendAction<> *http_request_httprequestsendaction_id;
Automation<std::shared_ptr<http_request::HttpContainer>> *automation_id_12;
StatelessLambdaAction<std::shared_ptr<http_request::HttpContainer>> *lambdaaction_id_21;
Automation<> *automation_id_14;
StatelessLambdaAction<> *lambdaaction_id_22;
StatelessLambdaCondition<> *lambdacondition_id_3;
IfAction<> *ifaction_id_2;
StatelessLambdaAction<> *lambdaaction_id_23;
switch_::TurnOnAction<> *switch__turnonaction_id_2;
StatelessLambdaAction<> *lambdaaction_id_24;
DelayAction<> *delayaction_id_10;
switch_::TurnOffAction<> *switch__turnoffaction_id;
StatelessLambdaAction<> *lambdaaction_id_25;
Automation<> *automation_id_16;
StatelessLambdaAction<> *lambdaaction_id_26;
http_request::HttpRequestSendAction<> *http_request_httprequestsendaction_id_2;
Automation<std::shared_ptr<http_request::HttpContainer>> *automation_id_15;
StatelessLambdaAction<std::shared_ptr<http_request::HttpContainer>> *lambdaaction_id_27;
StatelessLambdaAction<> *lambdaaction_id_28;
Automation<> *automation_id_18;
http_request::HttpRequestSendAction<> *http_request_httprequestsendaction_id_3;
Automation<std::shared_ptr<http_request::HttpContainer>> *automation_id_17;
StatelessLambdaAction<std::shared_ptr<http_request::HttpContainer>> *lambdaaction_id_29;
Automation<> *automation_id_19;
StatelessLambdaAction<> *lambdaaction_id_30;
Automation<> *automation_id_20;
StatelessLambdaAction<> *lambdaaction_id_31;
Automation<> *automation_id_21;
StatelessLambdaAction<> *lambdaaction_id_32;
Automation<> *automation_id_22;
StatelessLambdaAction<> *lambdaaction_id_33;
StatelessLambdaAction<> *lambdaaction_id_34;
interval::IntervalTrigger *interval_intervaltrigger_id_2;
Automation<> *automation_id_24;
StatelessLambdaAction<> *lambdaaction_id_35;
StatelessLambdaAction<> *lambdaaction_id;
binary_sensor::BinarySensorCondition<> *binary_sensor_binarysensorcondition_id;
binary_sensor::BinarySensorCondition<> *binary_sensor_binarysensorcondition_id_2;
AndCondition<> *andcondition_id;
IfAction<> *ifaction_id;
StatelessLambdaAction<> *lambdaaction_id_2;
wifi::WiFiConnectedCondition<> *wifi_wificonnectedcondition_id;
WaitUntilAction<> *waituntilaction_id;
StatelessLambdaAction<> *lambdaaction_id_3;
light::LightControlAction<> *light_lightcontrolaction_id;
DelayAction<> *delayaction_id;
light::LightControlAction<> *light_lightcontrolaction_id_2;
DelayAction<> *delayaction_id_2;
light::LightControlAction<> *light_lightcontrolaction_id_3;
DelayAction<> *delayaction_id_3;
light::LightControlAction<> *light_lightcontrolaction_id_4;
DelayAction<> *delayaction_id_4;
light::LightControlAction<> *light_lightcontrolaction_id_5;
StatelessLambdaAction<> *lambdaaction_id_4;
switch_::TurnOnAction<> *switch__turnonaction_id;
DelayAction<> *delayaction_id_5;
script::ScriptExecuteAction<script::Script<>> *script_scriptexecuteaction_id;
StatelessLambdaAction<> *lambdaaction_id_5;
light::LightControlAction<> *light_lightcontrolaction_id_6;
DelayAction<> *delayaction_id_6;
light::LightControlAction<> *light_lightcontrolaction_id_7;
DelayAction<> *delayaction_id_7;
light::LightControlAction<> *light_lightcontrolaction_id_8;
DelayAction<> *delayaction_id_8;
light::LightControlAction<> *light_lightcontrolaction_id_9;
StatelessLambdaAction<> *lambdaaction_id_7;
esphome::esp8266::ESP8266GPIOPin *esphome_esp8266_esp8266gpiopin_id_3;
StatelessLambdaAction<> *lambdaaction_id_8;
esphome::esp8266::ESP8266GPIOPin *esphome_esp8266_esp8266gpiopin_id_4;
StatelessLambdaAction<> *lambdaaction_id_11;
time::CronTrigger *time_crontrigger_id_2;
Automation<> *automation_id_7;
StatelessLambdaAction<> *lambdaaction_id_12;
time::SyncTrigger *time_synctrigger_id;
Automation<> *automation_id_5;
StatelessLambdaAction<> *lambdaaction_id_9;
script::ScriptExecuteAction<script::Script<>> *script_scriptexecuteaction_id_3;
StatelessLambdaCondition<> *lambdacondition_id_2;
WaitUntilAction<> *waituntilaction_id_3;
StatelessLambdaAction<> *lambdaaction_id_10;
const uint8_t ESPHOME_ESP8266_GPIO_INITIAL_MODE[16] PROGMEM = {255, OUTPUT, OUTPUT, INPUT, 255, 255, 255, 255, 255, 255, 255, 255, INPUT_PULLUP, OUTPUT, INPUT_PULLUP, 255};
const uint8_t ESPHOME_ESP8266_GPIO_INITIAL_LEVEL[16] PROGMEM = {255, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 255, 255};
#define yield() esphome::yield()
#define millis() esphome::millis()
#define micros() esphome::micros()
#define delay(x) esphome::delay(x)
#define delayMicroseconds(x) esphome::delayMicroseconds(x)
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ========== AUTO GENERATED CODE BEGIN ===========
  // esp8266:
  //   board: d1_mini
  //   restore_from_flash: true
  //   framework:
  //     version: 3.1.2
  //     source: ~3.30102.0
  //     platform_version: platformio/espressif8266@4.2.1
  //   early_pin_init: true
  //   board_flash_mode: dout
  esphome::esp8266::setup_preferences();
  // network:
  //   enable_ipv6: false
  //   min_ipv6_addr_count: 0
  // async_tcp:
  //   {}
  // esphome:
  //   name: athan
  //   friendly_name: athan
  //   on_boot:
  //     - then:
  //         - lambda: !lambda |-
  //             ESP_LOGI("tz", "Applying saved timezone on boot: '%s'", id(selected_location_tz).c_str());
  //             id(sntp_time).set_timezone(id(selected_location_tz).c_str());
  //           type_id: lambdaaction_id
  //         - if:
  //             condition:
  //               and:
  //                 - binary_sensor.is_on:
  //                     id: ui_next
  //                   type_id: binary_sensor_binarysensorcondition_id
  //                 - binary_sensor.is_on:
  //                     id: ui_select
  //                   type_id: binary_sensor_binarysensorcondition_id_2
  //               type_id: andcondition_id
  //             then:
  //               - logger.log:
  //                   format: on resetting wifi
  //                   logger_id: logger_logger_id
  //                   tag: main
  //                   level: DEBUG
  //                   args: []
  //                 type_id: lambdaaction_id_2
  //               - wait_until:
  //                   timeout: 5min
  //                   condition:
  //                     wifi.connected: {}
  //                     type_id: wifi_wificonnectedcondition_id
  //                 type_id: waituntilaction_id
  //               - lambda: !lambda |-
  //                   wifi::global_wifi_component->clear_sta();
  //                   wifi::global_wifi_component->save_wifi_sta("doesntexist", "passwordfornonetwork");
  //                 type_id: lambdaaction_id_3
  //               - light.turn_off:
  //                   id: builtin_led
  //                   state: false
  //                 type_id: light_lightcontrolaction_id
  //               - delay: 1s
  //                 type_id: delayaction_id
  //               - light.turn_on:
  //                   id: builtin_led
  //                   state: true
  //                 type_id: light_lightcontrolaction_id_2
  //               - delay: 500ms
  //                 type_id: delayaction_id_2
  //               - light.turn_off:
  //                   id: builtin_led
  //                   state: false
  //                 type_id: light_lightcontrolaction_id_3
  //               - delay: 1s
  //                 type_id: delayaction_id_3
  //               - light.turn_on:
  //                   id: builtin_led
  //                   state: true
  //                 type_id: light_lightcontrolaction_id_4
  //               - delay: 500ms
  //                 type_id: delayaction_id_4
  //               - light.turn_off:
  //                   id: builtin_led
  //                   state: false
  //                 type_id: light_lightcontrolaction_id_5
  //               - logger.log:
  //                   format: resetting
  //                   logger_id: logger_logger_id
  //                   tag: main
  //                   level: DEBUG
  //                   args: []
  //                 type_id: lambdaaction_id_4
  //               - switch.turn_on:
  //                   id: _restart
  //                 type_id: switch__turnonaction_id
  //           type_id: ifaction_id
  //         - delay: 2s
  //           type_id: delayaction_id_5
  //         - script.execute:
  //             id: update_display
  //           type_id: script_scriptexecuteaction_id
  //         - lambda: !lambda |-
  //             int vol = (id(volume_level) * 30 + 50) / 100;
  //             if (vol < 0) vol = 0; if (vol > 30) vol = 30;
  //             id(dfp).set_volume(vol);
  //             ESP_LOGI("boot", "DFPlayer volume initialized to %d (from %d%%)", vol, id(volume_level));
  //           type_id: lambdaaction_id_5
  //         - light.turn_on:
  //             id: builtin_led
  //             state: true
  //           type_id: light_lightcontrolaction_id_6
  //         - delay: 500ms
  //           type_id: delayaction_id_6
  //         - light.turn_off:
  //             id: builtin_led
  //             state: false
  //           type_id: light_lightcontrolaction_id_7
  //         - delay: 500ms
  //           type_id: delayaction_id_7
  //         - light.turn_on:
  //             id: builtin_led
  //             state: true
  //           type_id: light_lightcontrolaction_id_8
  //         - delay: 500ms
  //           type_id: delayaction_id_8
  //         - light.turn_off:
  //             id: builtin_led
  //             state: false
  //           type_id: light_lightcontrolaction_id_9
  //       automation_id: automation_id
  //       trigger_id: startuptrigger_id
  //       priority: 600.0
  //   min_version: 2025.11.1
  //   build_path: build/athan
  //   platformio_options: {}
  //   environment_variables: {}
  //   includes: []
  //   includes_c: []
  //   libraries: []
  //   name_add_mac_suffix: false
  //   debug_scheduler: false
  //   areas: []
  //   devices: []
  App.pre_setup("athan", "athan", "", __DATE__ ", " __TIME__, false);
  // binary_sensor:
  // light:
  // switch:
  // display:
  // time:
  // logger:
  //   level: DEBUG
  //   baud_rate: 0
  //   id: logger_logger_id
  //   tx_buffer_size: 512
  //   deassert_rts_dtr: false
  //   hardware_uart: UART0
  //   logs: {}
  //   runtime_tag_levels: false
  //   esp8266_store_log_strings_in_flash: true
  logger_logger_id = new logger::Logger(0, 512);
  logger_logger_id->set_log_level(ESPHOME_LOG_LEVEL_DEBUG);
  logger_logger_id->set_uart_selection(logger::UART_SELECTION_UART0);
  logger_logger_id->pre_setup();
  logger_logger_id->set_component_source(LOG_STR("logger"));
  App.register_component(logger_logger_id);
  // web_server_base:
  //   id: web_server_base_webserverbase_id
  web_server_base_webserverbase_id = new web_server_base::WebServerBase();
  web_server_base_webserverbase_id->set_component_source(LOG_STR("web_server_base"));
  App.register_component(web_server_base_webserverbase_id);
  web_server_base::global_web_server_base = web_server_base_webserverbase_id;
  // captive_portal:
  //   id: captive_portal_captiveportal_id
  //   web_server_base_id: web_server_base_webserverbase_id
  captive_portal_captiveportal_id = new captive_portal::CaptivePortal(web_server_base_webserverbase_id);
  captive_portal_captiveportal_id->set_component_source(LOG_STR("captive_portal"));
  App.register_component(captive_portal_captiveportal_id);
  // wifi:
  //   ap:
  //     ssid: AthanFallbackHotspot
  //     password: athan404
  //     ap_timeout: 2min
  //     id: wifi_wifiap_id
  //   on_connect:
  //     then:
  //       - logger.log:
  //           format: WiFi connected!
  //           logger_id: logger_logger_id
  //           tag: main
  //           level: DEBUG
  //           args: []
  //         type_id: lambdaaction_id_6
  //       - wait_until:
  //           timeout: 8s
  //           condition:
  //             lambda: !lambda |-
  //               return id(sntp_time).now().is_valid();
  //             type_id: lambdacondition_id
  //         type_id: waituntilaction_id_2
  //       - script.execute:
  //           id: refresh_prayer_times_if_needed
  //         type_id: script_scriptexecuteaction_id_2
  //     trigger_id: trigger_id
  //     automation_id: automation_id_2
  //   id: wifi_wificomponent_id
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: NONE
  //   fast_connect: false
  //   output_power: 20.0
  //   passive_scan: false
  //   enable_on_boot: true
  //   min_auth_mode: WPA
  //   networks:
  //     - ssid: !secret 'wifi_ssid'
  //       password: !secret 'wifi_password'
  //       id: wifi_wifiap_id_2
  //       priority: 0
  //   use_address: athan.local
  wifi_wificomponent_id = new wifi::WiFiComponent();
  wifi_wificomponent_id->set_use_address("athan.local");
  wifi_wificomponent_id->init_sta(1);
  {
  wifi::WiFiAP wifi_wifiap_id_2 = wifi::WiFiAP();
  wifi_wifiap_id_2.set_ssid("MyHomeWiFi");
  wifi_wifiap_id_2.set_password("myHomePassword");
  wifi_wifiap_id_2.set_priority(0);
  wifi_wificomponent_id->add_sta(wifi_wifiap_id_2);
  }
  {
  wifi::WiFiAP wifi_wifiap_id = wifi::WiFiAP();
  wifi_wifiap_id.set_ssid("AthanFallbackHotspot");
  wifi_wifiap_id.set_password("athan404");
  wifi_wificomponent_id->set_ap(wifi_wifiap_id);
  }
  wifi_wificomponent_id->set_ap_timeout(120000);
  wifi_wificomponent_id->set_reboot_timeout(900000);
  wifi_wificomponent_id->set_power_save_mode(wifi::WIFI_POWER_SAVE_NONE);
  wifi_wificomponent_id->set_min_auth_mode(wifi::WIFI_MIN_AUTH_MODE_WPA);
  wifi_wificomponent_id->set_passive_scan(false);
  wifi_wificomponent_id->set_output_power(20.0f);
  wifi_wificomponent_id->set_enable_on_boot(true);
  wifi_wificomponent_id->set_component_source(LOG_STR("wifi"));
  App.register_component(wifi_wificomponent_id);
  // mdns:
  //   id: mdns_mdnscomponent_id
  //   disabled: false
  //   services: []
  mdns_mdnscomponent_id = new mdns::MDNSComponent();
  mdns_mdnscomponent_id->set_component_source(LOG_STR("mdns"));
  App.register_component(mdns_mdnscomponent_id);
  // ota:
  // ota.http_request:
  //   platform: http_request
  //   id: http_request_otahttprequestcomponent_id
  //   http_request_id: http_request_httprequestarduino_id
  http_request_otahttprequestcomponent_id = new http_request::OtaHttpRequestComponent();
  // ota.esphome:
  //   platform: esphome
  //   password: 016f3e8b522050971c70fa58dd26c640
  //   id: esphome_esphomeotacomponent_id
  //   version: 2
  //   port: 8266
  esphome_esphomeotacomponent_id = new esphome::ESPHomeOTAComponent();
  esphome_esphomeotacomponent_id->set_port(8266);
  esphome_esphomeotacomponent_id->set_auth_password("016f3e8b522050971c70fa58dd26c640");
  esphome_esphomeotacomponent_id->set_component_source(LOG_STR("esphome.ota"));
  App.register_component(esphome_esphomeotacomponent_id);
  // ota.web_server:
  //   platform: web_server
  //   id: web_server_webserverotacomponent_id
  web_server_webserverotacomponent_id = new web_server::WebServerOTAComponent();
  // safe_mode:
  //   id: safe_mode_safemodecomponent_id
  //   boot_is_good_after: 1min
  //   disabled: false
  //   num_attempts: 10
  //   reboot_timeout: 5min
  safe_mode_safemodecomponent_id = new safe_mode::SafeModeComponent();
  safe_mode_safemodecomponent_id->set_component_source(LOG_STR("safe_mode"));
  App.register_component(safe_mode_safemodecomponent_id);
  if (safe_mode_safemodecomponent_id->should_enter_safe_mode(10, 300000, 60000)) return;
  http_request_otahttprequestcomponent_id->set_component_source(LOG_STR("http_request.ota"));
  App.register_component(http_request_otahttprequestcomponent_id);
  web_server_webserverotacomponent_id->set_component_source(LOG_STR("web_server.ota"));
  App.register_component(web_server_webserverotacomponent_id);
  automation_id_2 = new Automation<>(wifi_wificomponent_id->get_connect_trigger());
  lambdaaction_id_6 = new StatelessLambdaAction<>([]() -> void {
      ESP_LOGD("main", "WiFi connected!");
  });
  // api:
  //   reboot_timeout: 0s
  //   encryption:
  //     key: jAOYf5QQGoONCqGQnC7fwPhSeb/ZTUTlawp1Lvu63ZI=
  //   id: api_apiserver_id
  //   port: 6053
  //   password: ''
  //   batch_delay: 100ms
  //   custom_services: false
  //   homeassistant_services: false
  //   homeassistant_states: false
  //   listen_backlog: 1
  //   max_connections: 4
  //   max_send_queue: 5
  api_apiserver_id = new api::APIServer();
  api_apiserver_id->set_component_source(LOG_STR("api"));
  App.register_component(api_apiserver_id);
  api_apiserver_id->set_port(6053);
  api_apiserver_id->set_reboot_timeout(0);
  api_apiserver_id->set_batch_delay(100);
  api_apiserver_id->set_listen_backlog(1);
  api_apiserver_id->set_max_connections(4);
  api_apiserver_id->set_noise_psk({140, 3, 152, 127, 148, 16, 26, 131, 141, 10, 161, 144, 156, 46, 223, 192, 248, 82, 121, 191, 217, 77, 68, 229, 107, 10, 117, 46, 251, 186, 221, 146});
  startuptrigger_id = new StartupTrigger(600.0f);
  startuptrigger_id->set_component_source(LOG_STR("esphome.coroutine"));
  App.register_component(startuptrigger_id);
  automation_id = new Automation<>(startuptrigger_id);
  // i2c:
  //   sda: 4
  //   scl: 5
  //   scan: true
  //   id: i2c_arduinoi2cbus_id
  //   frequency: 50000.0
  i2c_arduinoi2cbus_id = new i2c::ArduinoI2CBus();
  i2c_arduinoi2cbus_id->set_component_source(LOG_STR("i2c"));
  App.register_component(i2c_arduinoi2cbus_id);
  i2c_arduinoi2cbus_id->set_sda_pin(4);
  i2c_arduinoi2cbus_id->set_scl_pin(5);
  i2c_arduinoi2cbus_id->set_frequency(50000);
  i2c_arduinoi2cbus_id->set_scan(true);
  // json:
  //   {}
  // substitutions:
  //   current_version: '1'
  // uart:
  //   tx_pin:
  //     number: 1
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //       analog: false
  //     id: esphome_esp8266_esp8266gpiopin_id
  //     inverted: false
  //   rx_pin:
  //     number: 3
  //     mode:
  //       input: true
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //       analog: false
  //     id: esphome_esp8266_esp8266gpiopin_id_2
  //     inverted: false
  //   baud_rate: 9600
  //   id: uart_esp8266uartcomponent_id
  //   rx_buffer_size: 256
  //   stop_bits: 1
  //   data_bits: 8
  //   parity: NONE
  uart_esp8266uartcomponent_id = new uart::ESP8266UartComponent();
  uart_esp8266uartcomponent_id->set_component_source(LOG_STR("uart"));
  App.register_component(uart_esp8266uartcomponent_id);
  uart_esp8266uartcomponent_id->set_baud_rate(9600);
  esphome_esp8266_esp8266gpiopin_id = new esphome::esp8266::ESP8266GPIOPin();
  esphome_esp8266_esp8266gpiopin_id->set_pin(1);
  esphome_esp8266_esp8266gpiopin_id->set_flags(gpio::Flags::FLAG_OUTPUT);
  uart_esp8266uartcomponent_id->set_tx_pin(esphome_esp8266_esp8266gpiopin_id);
  esphome_esp8266_esp8266gpiopin_id_2 = new esphome::esp8266::ESP8266GPIOPin();
  esphome_esp8266_esp8266gpiopin_id_2->set_pin(3);
  esphome_esp8266_esp8266gpiopin_id_2->set_flags(gpio::Flags::FLAG_INPUT);
  uart_esp8266uartcomponent_id->set_rx_pin(esphome_esp8266_esp8266gpiopin_id_2);
  uart_esp8266uartcomponent_id->set_rx_buffer_size(256);
  uart_esp8266uartcomponent_id->set_stop_bits(1);
  uart_esp8266uartcomponent_id->set_data_bits(8);
  uart_esp8266uartcomponent_id->set_parity(uart::UART_CONFIG_PARITY_NONE);
  // dfplayer:
  //   id: dfp
  //   uart_id: uart_esp8266uartcomponent_id
  dfp = new dfplayer::DFPlayer();
  dfp->set_component_source(LOG_STR("dfplayer"));
  App.register_component(dfp);
  dfp->set_uart_parent(uart_esp8266uartcomponent_id);
  // binary_sensor.gpio:
  //   platform: gpio
  //   name: ui_next
  //   id: ui_next
  //   internal: true
  //   pin:
  //     number: 14
  //     mode:
  //       input: true
  //       pullup: true
  //       output: false
  //       open_drain: false
  //       pulldown: false
  //       analog: false
  //     inverted: true
  //     id: esphome_esp8266_esp8266gpiopin_id_3
  //   on_press:
  //     - then:
  //         - lambda: !lambda |-
  //             id(ui_last_activity) = millis();
  //              If not in menu, act as a silence button
  //             if (id(ui_mode) == 0) {
  //               ESP_LOGI("ui","Next pressed (normal) -> silence");
  //               id(dfp).stop();
  //               id(athan_playing) = false;
  //                Run the test script when ui_next pressed in normal mode
  //               id(test_script).execute();
  //               id(update_display).execute();
  //               return;
  //             }
  //              In menu: move forward
  //             ESP_LOGI("ui","Next pressed (menu) -> forward");
  //             if (id(ui_mode) == 1) {
  //               id(ui_menu_index) = (id(ui_menu_index) + 1) % 7;
  //                any navigation breaks consecutive select count for Q
  //               id(q_select_count) = 0;
  //                If navigation lands on the Update item, reset its state
  //               if (id(ui_menu_index) == 3) {
  //                 id(update_check_state) = 0;
  //                 id(update_display).execute();
  //               }
  //                play navigation click only in main menu (not in Athan/Hourly Tick preview menus)
  //             } else if (id(ui_mode) == 2) {
  //               id(athan_index) = (id(athan_index) + 1) % 10;
  //               if (!id(athan_playing)) id(dfp).play_file(1 + id(athan_index));
  //             } else if (id(ui_mode) == 3) {
  //               id(htick_index) = (id(htick_index) + 1) % 11;
  //               if (id(htick_index) == 0) {
  //                 id(dfp).stop();
  //               } else {
  //                 id(dfp).play_file(10 + id(htick_index));
  //               }
  //             } else if (id(ui_mode) == 4) {
  //               id(location_index) = (id(location_index) + 1) % 15;
  //             } else if (id(ui_mode) == 5) {
  //                Volume submenu: decrement by 10%, wrap 10 -> 100
  //               int v = id(volume_level);
  //               if (v <= 10) {
  //                 id(volume_level) = 100;
  //               } else {
  //                 id(volume_level) = v - 10;
  //               }
  //               ESP_LOGI("ui", "Volume changed to %d%%", id(volume_level));
  //                Map percentage (0-100) to DFPlayer volume range (0-30)
  //               int vol = (id(volume_level) * 30 + 50) / 100;
  //               if (vol < 0) vol = 0; if (vol > 30) vol = 30;
  //               id(dfp).set_volume(vol);
  //               ESP_LOGI("ui", "DFPlayer volume set to %d (mapped from %d%%)", vol, id(volume_level));
  //                Play feedback tone so user hears the change at new volume
  //               if (!id(athan_playing)) id(dfp).play_file(22);
  //             }
  //             id(update_display).execute();
  //           type_id: lambdaaction_id_7
  //       automation_id: automation_id_3
  //       trigger_id: binary_sensor_presstrigger_id
  //   disabled_by_default: false
  //   use_interrupt: true
  //   interrupt_type: ANY
  ui_next = new gpio::GPIOBinarySensor();
  App.register_binary_sensor(ui_next);
  ui_next->set_name("ui_next");
  ui_next->set_object_id("ui_next");
  ui_next->set_internal(true);
  ui_next->set_trigger_on_initial_state(false);
  binary_sensor_presstrigger_id = new binary_sensor::PressTrigger(ui_next);
  automation_id_3 = new Automation<>(binary_sensor_presstrigger_id);
  // binary_sensor.gpio:
  //   platform: gpio
  //   name: ui_select
  //   id: ui_select
  //   internal: true
  //   pin:
  //     number: 12
  //     mode:
  //       input: true
  //       pullup: true
  //       output: false
  //       open_drain: false
  //       pulldown: false
  //       analog: false
  //     inverted: true
  //     id: esphome_esp8266_esp8266gpiopin_id_4
  //   on_press:
  //     - then:
  //         - lambda: !lambda |-
  //             id(ui_last_activity) = millis();
  //              If not in menu, enter main menu
  //             if (id(ui_mode) == 0) {
  //               if(id(athan_playing)){
  //                 ESP_LOGI("ui","Select pressed -> silence athan");
  //                 id(dfp).stop();
  //                 id(athan_playing) = false;
  //                 id(update_display).execute();
  //                 return;
  //               }
  //               id(ui_mode) = 1;  main menu
  //               id(ui_menu_index) = 0;
  //                Always reset update-check state when entering the menu
  //               id(update_check_state) = 0;
  //               ESP_LOGI("ui","Select pressed -> Entered menu: index=0");
  //               if (!id(athan_playing)) id(dfp).play_file(23);
  //               id(update_display).execute();
  //               return;
  //             }
  //              If in menu, act as select/confirm
  //             ESP_LOGI("ui","Select pressed in menu index=%d", id(ui_menu_index));
  //             if (!id(athan_playing)) id(dfp).play_file(23);
  //             if (id(ui_mode) == 1) {
  //                main menu: 0=athan,1=htick,2=location,3=update,4=volume,5=cancel,6=Q
  //               if (id(ui_menu_index) == 0) {
  //                 id(ui_mode) = 2;
  //                 id(athan_index) = id(athan_file_index) - 1;
  //                 if (id(athan_index) < 0) id(athan_index) = 0;
  //                 ESP_LOGI("ui","Entered Athan submenu (index=%d)", id(athan_index));
  //                 if (!id(athan_playing)) id(dfp).play_file(1 + id(athan_index));
  //               } else if (id(ui_menu_index) == 1) {
  //                 id(ui_mode) = 3;
  //                 if (id(htick_file_index) == 0) id(htick_index) = 0; else id(htick_index) = id(htick_file_index) - 10;
  //                 ESP_LOGI("ui","Entered Hourly Tick submenu (index=%d)", id(htick_index));
  //                 if (!id(athan_playing) && id(htick_index) > 0) id(dfp).play_file(10 + id(htick_index));
  //               } else if (id(ui_menu_index) == 2) {
  //                 id(ui_mode) = 4;  location menu
  //                  Initialize preview index from the persisted selection so the
  //                  menu opens at the last saved location. `location_index` is
  //                  preview-only while menu is open.
  //                 id(location_index) = id(selected_location_index);
  //                 ESP_LOGI("ui","Entered Location submenu (preview_index=%d)", id(location_index));
  //               } else if (id(ui_menu_index) == 3) {
  //                  Update: first press checks remote latest.json, second press confirms update
  //                 if (id(update_check_state) == 2) {
  //                    Previously found an update and user confirmed -> attempt update
  //                   id(update_check_state) = 4;  attempting
  //                   id(update_display).execute();
  //                   id(perform_update).execute();
  //                 } else {
  //                    Start checking remote latest.json
  //                   id(update_check_state) = 3;  checking
  //                    Refresh the display immediately so the "checking.." text appears
  //                   id(update_display).execute();
  //                   id(check_update_remote).execute();
  //                   id(ui_mode) = 1;  stay in menu
  //                   ESP_LOGI("update", "Checking remote for latest version...");
  //                 }
  //               } else if (id(ui_menu_index) == 4) {
  //                  Enter volume submenu
  //                 id(ui_mode) = 5;
  //                 ESP_LOGI("ui", "Entered Volume submenu (level=%d%%)", id(volume_level));
  //                 if (!id(athan_playing)) id(dfp).play_file(22);
  //               } else if (id(ui_menu_index) == 5) {
  //                  Cancel
  //                 id(ui_mode) = 0;
  //                 ESP_LOGI("ui","Menu cancelled");
  //               } else if (id(ui_menu_index) == 6) {
  //                  Q toggle item: enabling requires 10 consecutive select presses
  //                 if (!id(q_flag)) {
  //                   id(q_select_count) = id(q_select_count) + 1;
  //                   ESP_LOGI("ui","Q select count = %d", id(q_select_count));
  //                   if (id(q_select_count) >= 10) {
  //                     id(q_flag) = true;
  //                     id(q_select_count) = 0;
  //                     ESP_LOGI("ui","Q enabled via 10 presses");
  //                   }
  //                 } else {
  //                    Q is on: a single press turns it off
  //                   id(q_flag) = false;
  //                   id(q_select_count) = 0;
  //                   ESP_LOGI("ui","Q disabled via single press");
  //                 }
  //               } else {
  //                 id(ui_mode) = 0;
  //               }
  //             } else if (id(ui_mode) == 2) {
  //                select athan
  //               id(athan_file_index) = 1 + id(athan_index);
  //               id(dfp).stop();
  //               id(ui_mode) = 0;
  //               ESP_LOGI("ui","Athan %d selected", id(athan_file_index));
  //             } else if (id(ui_mode) == 3) {
  //                select htick (0 = None)
  //               if (id(htick_index) == 0) id(htick_file_index) = 0; else id(htick_file_index) = 10 + id(htick_index);
  //               id(dfp).stop();
  //               id(ui_mode) = 0;
  //               ESP_LOGI("ui","Hourly Tick %d selected", id(htick_file_index));
  //             } else if (id(ui_mode) == 4) {
  //                 if (id(location_index) != id(selected_location_index)) {
  //                    apply the change only if the fetch returns a valid TZ.
  //                   id(change_location_handler).execute();
  //                 } else {
  //                   id(ui_mode) = 0;
  //                 }
  //             } else if (id(ui_mode) == 5) {
  //                confirm volume selection
  //               ESP_LOGI("ui", "Volume selected: %d%%", id(volume_level));
  //               id(ui_mode) = 0;
  //             }
  //             id(update_display).execute();
  //           type_id: lambdaaction_id_8
  //       automation_id: automation_id_4
  //       trigger_id: binary_sensor_presstrigger_id_2
  //   disabled_by_default: false
  //   use_interrupt: true
  //   interrupt_type: ANY
  ui_select = new gpio::GPIOBinarySensor();
  App.register_binary_sensor(ui_select);
  ui_select->set_name("ui_select");
  ui_select->set_object_id("ui_select");
  ui_select->set_internal(true);
  ui_select->set_trigger_on_initial_state(false);
  binary_sensor_presstrigger_id_2 = new binary_sensor::PressTrigger(ui_select);
  automation_id_4 = new Automation<>(binary_sensor_presstrigger_id_2);
  // light.binary:
  //   platform: binary
  //   id: builtin_led
  //   name: Built-in LED
  //   output: led_output
  //   restore_mode: ALWAYS_OFF
  //   internal: true
  //   disabled_by_default: false
  //   output_id: binary_binarylightoutput_id
  binary_binarylightoutput_id = new binary::BinaryLightOutput();
  builtin_led = new light::LightState(binary_binarylightoutput_id);
  App.register_light(builtin_led);
  builtin_led->set_component_source(LOG_STR("light"));
  App.register_component(builtin_led);
  builtin_led->set_name("Built-in LED");
  builtin_led->set_object_id("built-in_led");
  builtin_led->set_internal(true);
  builtin_led->set_restore_mode(light::LIGHT_ALWAYS_OFF);
  builtin_led->add_effects({});
  // switch.gpio:
  //   platform: gpio
  //   id: external_relay
  //   name: External Relay
  //   pin:
  //     number: 13
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //       analog: false
  //     id: esphome_esp8266_esp8266gpiopin_id_5
  //     inverted: false
  //   restore_mode: RESTORE_DEFAULT_OFF
  //   disabled_by_default: false
  //   interlock_wait_time: 0ms
  external_relay = new gpio::GPIOSwitch();
  App.register_switch(external_relay);
  external_relay->set_name("External Relay");
  external_relay->set_object_id("external_relay");
  external_relay->set_restore_mode(switch_::SWITCH_RESTORE_DEFAULT_OFF);
  external_relay->set_component_source(LOG_STR("gpio.switch"));
  App.register_component(external_relay);
  esphome_esp8266_esp8266gpiopin_id_5 = new esphome::esp8266::ESP8266GPIOPin();
  esphome_esp8266_esp8266gpiopin_id_5->set_pin(13);
  esphome_esp8266_esp8266gpiopin_id_5->set_flags(gpio::Flags::FLAG_OUTPUT);
  external_relay->set_pin(esphome_esp8266_esp8266gpiopin_id_5);
  // switch.restart:
  //   platform: restart
  //   id: _restart
  //   internal: true
  //   disabled_by_default: false
  //   restore_mode: ALWAYS_OFF
  //   entity_category: config
  //   icon: mdi:restart
  //   name: _restart
  _restart = new restart::RestartSwitch();
  App.register_switch(_restart);
  _restart->set_name("_restart");
  _restart->set_object_id("_restart");
  _restart->set_internal(true);
  _restart->set_icon("mdi:restart");
  _restart->set_entity_category(::ENTITY_CATEGORY_CONFIG);
  _restart->set_restore_mode(switch_::SWITCH_ALWAYS_OFF);
  _restart->set_component_source(LOG_STR("restart.switch"));
  App.register_component(_restart);
  // output:
  // output.gpio:
  //   platform: gpio
  //   id: led_output
  //   pin:
  //     number: 2
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //       analog: false
  //     id: esphome_esp8266_esp8266gpiopin_id_6
  //     inverted: false
  //   inverted: true
  led_output = new gpio::GPIOBinaryOutput();
  led_output->set_inverted(true);
  led_output->set_component_source(LOG_STR("gpio.output"));
  App.register_component(led_output);
  esphome_esp8266_esp8266gpiopin_id_6 = new esphome::esp8266::ESP8266GPIOPin();
  esphome_esp8266_esp8266gpiopin_id_6->set_pin(2);
  esphome_esp8266_esp8266gpiopin_id_6->set_flags(gpio::Flags::FLAG_OUTPUT);
  led_output->set_pin(esphome_esp8266_esp8266gpiopin_id_6);
  // http_request:
  //   useragent: esphome-device
  //   timeout: 10s
  //   verify_ssl: false
  //   id: http_request_httprequestarduino_id
  //   follow_redirects: true
  //   redirect_limit: 3
  //   esp8266_disable_ssl_support: false
  http_request_httprequestarduino_id = new http_request::HttpRequestArduino();
  http_request_httprequestarduino_id->set_timeout(10000);
  http_request_httprequestarduino_id->set_useragent("esphome-device");
  http_request_httprequestarduino_id->set_follow_redirects(true);
  http_request_httprequestarduino_id->set_redirect_limit(3);
  http_request_httprequestarduino_id->set_component_source(LOG_STR("http_request"));
  App.register_component(http_request_httprequestarduino_id);
  // display.ssd1306_i2c:
  //   platform: ssd1306_i2c
  //   id: oled
  //   model: SSD1306_128X64
  //   reset_pin:
  //     number: 16
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //       analog: false
  //     id: esphome_esp8266_esp8266gpiopin_id_7
  //     inverted: false
  //   address: 0x3C
  //   auto_clear_enabled: unspecified
  //   brightness: 1.0
  //   contrast: 1.0
  //   flip_x: true
  //   flip_y: true
  //   offset_x: 0
  //   offset_y: 0
  //   invert: false
  //   update_interval: 1s
  //   i2c_id: i2c_arduinoi2cbus_id
  oled = new ssd1306_i2c::I2CSSD1306();
  oled->set_update_interval(1000);
  oled->set_component_source(LOG_STR("display"));
  App.register_component(oled);
  oled->set_auto_clear(false);
  oled->set_model(ssd1306_base::SSD1306_MODEL_128_64);
  esphome_esp8266_esp8266gpiopin_id_7 = new esphome::esp8266::ESP8266GPIOPin();
  esphome_esp8266_esp8266gpiopin_id_7->set_pin(16);
  esphome_esp8266_esp8266gpiopin_id_7->set_flags(gpio::Flags::FLAG_OUTPUT);
  oled->set_reset_pin(esphome_esp8266_esp8266gpiopin_id_7);
  oled->init_brightness(1.0f);
  oled->init_contrast(1.0f);
  oled->init_flip_x(true);
  oled->init_flip_y(true);
  oled->init_offset_x(0);
  oled->init_offset_y(0);
  oled->init_invert(false);
  oled->set_i2c_bus(i2c_arduinoi2cbus_id);
  oled->set_i2c_address(0x3C);
  // font:
  //   file:
  //     family: Roboto
  //     weight: 400
  //     italic: false
  //     refresh: 1d
  //     type: gfonts
  //   id: font1
  //   size: 20
  //   glyphs:
  //     - ' '
  //     - '!'
  //     - '"'
  //     - '#'
  //     - $
  //     - '%'
  //     - '&'
  //     - ''''
  //     - (
  //     - )
  //     - '*'
  //     - +
  //     - ','
  //     - '-'
  //     - .
  //     - /
  //     - '0'
  //     - '1'
  //     - '2'
  //     - '3'
  //     - '4'
  //     - '5'
  //     - '6'
  //     - '7'
  //     - '8'
  //     - '9'
  //     - ':'
  //     - ;
  //     - <
  //     - '='
  //     - '>'
  //     - '?'
  //     - '@'
  //     - A
  //     - B
  //     - C
  //     - D
  //     - E
  //     - F
  //     - G
  //     - H
  //     - I
  //     - J
  //     - K
  //     - L
  //     - M
  //     - N
  //     - O
  //     - P
  //     - Q
  //     - R
  //     - S
  //     - T
  //     - U
  //     - V
  //     - W
  //     - X
  //     - Y
  //     - Z
  //     - '['
  //     - 
  //     - ']'
  //     - ^
  //     - _
  //     - '`'
  //     - a
  //     - b
  //     - c
  //     - d
  //     - e
  //     - f
  //     - g
  //     - h
  //     - i
  //     - j
  //     - k
  //     - l
  //     - m
  //     - n
  //     - o
  //     - p
  //     - q
  //     - r
  //     - s
  //     - t
  //     - u
  //     - v
  //     - w
  //     - x
  //     - y
  //     - z
  //     - '{'
  //     - '|'
  //     - '}'
  //     - '~'
  //     -  
  //     - ¢
  //     - £
  //     - ¥
  //     - ©
  //     - ®
  //     - °
  //     - ·
  //     - ×
  //     - ÷
  //     - –
  //     - —
  //     - ‘
  //     - ’
  //     - “
  //     - ”
  //     - •
  //     - …
  //     - €
  //     - ™
  //     - −
  //   glyphsets: []
  //   ignore_missing_glyphs: false
  //   bpp: 1
  //   extras: []
  //   raw_data_id: uint8_t_id
  //   raw_glyph_id: font_glyphdata_id
  static const uint8_t uint8_t_id[] PROGMEM = {0x00, 0xFE, 0xAA, 0xA0, 0xF0, 0xDD, 0xDD, 0x90, 0x0C, 0xC1, 0x98, 0x22, 0x04, 0x47, 0xFE, 0x33, 0x06, 0x60, 0x88, 0x11, 0x1F, 0xF8, 0xCC, 0x19, 0x82, 0x20, 0x44, 0x00, 0x0C, 0x06, 0x0F, 0x8F, 0xE6, 0x1A, 0x0D, 0x86, 0xC0, 0x3C, 0x07, 0x80, 0xE0, 0x3C, 0x1E, 0x0D, 0xFC, 0x7C, 0x08, 0x04, 0x00, 0x78, 0x06, 0x40, 0x23, 0x11, 0x19, 0x08, 0xD8, 0x64, 0x81, 0xE8, 0x00, 0xDE, 0x05, 0x90, 0x48, 0xC6, 0x46, 0x22, 0x31, 0x19, 0x00, 0x78, 0x1E, 0x06, 0xE1, 0x8C, 0x31, 0x86, 0x30, 0x7C, 0x06, 0x03, 0xE3, 0xE6, 0x58, 0xFB, 0x0F, 0x60, 0xC7, 0xFC, 0x7C, 0xC0, 0xF8, 0x08, 0xC4, 0x66, 0x31, 0x88, 0xC6, 0x31, 0x8C, 0x21, 0x8C, 0x61, 0x84, 0x30, 0x80, 0x41, 0x02, 0x0C, 0x10, 0x61, 0x82, 0x08, 0x30, 0xC3, 0x08, 0x21, 0x86, 0x10, 0xC2, 0x10, 0x40, 0x08, 0x08, 0x49, 0xFF, 0x1C, 0x3C, 0x26, 0x22, 0x0C, 0x03, 0x00, 0xC0, 0x30, 0xFF, 0xFF, 0xF0, 0xC0, 0x30, 0x0C, 0x03, 0x00, 0xC0, 0x6D, 0xA4, 0xF8, 0xEC, 0x02, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x08, 0x18, 0x10, 0x30, 0x30, 0x20, 0x60, 0x40, 0xC0, 0x3E, 0x3B, 0x98, 0x78, 0x3C, 0x1E, 0x0F, 0x07, 0x83, 0xC1, 0xE0, 0xF0, 0x6C, 0x37, 0xF1, 0xF0, 0x1B, 0xF6, 0x31, 0x8C, 0x63, 0x18, 0xC6, 0x31, 0x8C, 0x3E, 0x1D, 0xCC, 0x1B, 0x06, 0x01, 0x80, 0x40, 0x30, 0x18, 0x0C, 0x06, 0x03, 0x01, 0x80, 0xC0, 0x3F, 0xF0, 0x3E, 0x3B, 0xB0, 0x78, 0x30, 0x18, 0x18, 0x3C, 0x3C, 0x03, 0x00, 0xF0, 0x78, 0x37, 0xF1, 0xF0, 0x03, 0x01, 0xC0, 0xF0, 0x2C, 0x1B, 0x0C, 0xC2, 0x31, 0x8C, 0xC3, 0x30, 0xCF, 0xFC, 0x0C, 0x03, 0x00, 0xC0, 0x3F, 0x9F, 0xD8, 0x0C, 0x06, 0x03, 0xF1, 0xFE, 0x43, 0x01, 0x80, 0x50, 0x2C, 0x37, 0xF8, 0xF0, 0x0E, 0x0F, 0x0C, 0x0C, 0x04, 0x02, 0xF3, 0xFD, 0xC3, 0xC1, 0xE0, 0xD0, 0x6C, 0x33, 0xF0, 0xF0, 0xFF, 0x80, 0xC0, 0x60, 0x20, 0x30, 0x10, 0x18, 0x08, 0x0C, 0x06, 0x06, 0x03, 0x03, 0x01, 0x80, 0x3E, 0x3B, 0x98, 0x78, 0x36, 0x1B, 0xB8, 0xF8, 0xC6, 0xC1, 0xE0, 0xF0, 0x78, 0x37, 0xF1, 0xF0, 0x3E, 0x3F, 0xB0, 0xD8, 0x3C, 0x1E, 0x0F, 0x06, 0xFF, 0x3D, 0x80, 0xC0, 0xC0, 0x63, 0xE1, 0xC0, 0xD8, 0x00, 0x00, 0x1B, 0x00, 0x6C, 0x00, 0x00, 0x0D, 0xB6, 0x80, 0x01, 0x07, 0x3C, 0xF0, 0xC0, 0xF0, 0x3C, 0x07, 0x01, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x80, 0x78, 0x0F, 0x01, 0xE0, 0x18, 0x78, 0xF1, 0xE0, 0x80, 0x00, 0x3C, 0x7E, 0xC3, 0xC3, 0x03, 0x06, 0x0C, 0x18, 0x18, 0x10, 0x00, 0x00, 0x10, 0x10, 0x03, 0xE0, 0x0E, 0x38, 0x18, 0x04, 0x20, 0x06, 0x61, 0xE2, 0x43, 0x23, 0x46, 0x21, 0xC4, 0x21, 0xC4, 0x21, 0xCC, 0x21, 0xCC, 0x63, 0xCC, 0x62, 0xC6, 0xE6, 0x47, 0xBC, 0x60, 0x00, 0x30, 0x00, 0x1C, 0x20, 0x07, 0xE0, 0x03, 0x00, 0x38, 0x01, 0x40, 0x1B, 0x00, 0xD8, 0x04, 0x40, 0x63, 0x03, 0x18, 0x3F, 0xE1, 0xFF, 0x08, 0x08, 0xC0, 0x66, 0x03, 0x60, 0x0C, 0xFE, 0x7F, 0xB0, 0x78, 0x3C, 0x1F, 0xFB, 0xFD, 0x83, 0xC1, 0xE0, 0xF0, 0x78, 0x3F, 0xF7, 0xF0, 0x1F, 0x07, 0xF9, 0x83, 0x30, 0x3C, 0x07, 0x80, 0x30, 0x06, 0x00, 0xC0, 0x18, 0x0D, 0x81, 0xB0, 0x63, 0xFC, 0x3E, 0x00, 0xFC, 0x3F, 0xCC, 0x1B, 0x06, 0xC0, 0xF0, 0x3C, 0x0F, 0x03, 0xC0, 0xF0, 0x3C, 0x1B, 0x06, 0xFF, 0x3F, 0x00, 0xFF, 0xFF, 0xF0, 0x18, 0x0C, 0x06, 0x03, 0xFD, 0xFE, 0xC0, 0x60, 0x30, 0x18, 0x0F, 0xFF, 0xFC, 0xFF, 0xFF, 0xC0, 0xC0, 0xC0, 0xC0, 0xFF, 0xFF, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x1F, 0x87, 0xF9, 0x81, 0xB0, 0x3C, 0x01, 0x80, 0x30, 0xFE, 0x1F, 0xC0, 0x78, 0x0D, 0x81, 0xB8, 0x33, 0xFE, 0x1F, 0x00, 0xC0, 0x78, 0x0F, 0x01, 0xE0, 0x3C, 0x07, 0x80, 0xFF, 0xFF, 0xFF, 0xC0, 0x78, 0x0F, 0x01, 0xE0, 0x3C, 0x07, 0x80, 0xC0, 0xFF, 0xFF, 0xFF, 0xF0, 0x01, 0x80, 0xC0, 0x60, 0x30, 0x18, 0x0C, 0x06, 0x03, 0x01, 0x80, 0xE0, 0x58, 0x6F, 0xF1, 0xE0, 0xC1, 0xD8, 0x73, 0x0C, 0x63, 0x0C, 0xC1, 0xB0, 0x3E, 0x07, 0xE0, 0xCC, 0x18, 0xC3, 0x0C, 0x61, 0xCC, 0x19, 0x81, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xFF, 0xFF, 0xC0, 0x1F, 0x80, 0x7E, 0x03, 0xEC, 0x0F, 0xB0, 0x2E, 0x41, 0xB9, 0x86, 0xE6, 0x33, 0xCC, 0xCF, 0x32, 0x3C, 0x58, 0xF1, 0xC3, 0xC7, 0x0F, 0x0C, 0x30, 0xC0, 0x7C, 0x0F, 0x81, 0xF8, 0x3F, 0x87, 0xB0, 0xF3, 0x1E, 0x73, 0xC6, 0x78, 0x6F, 0x0F, 0xE0, 0xFC, 0x0F, 0x81, 0xC0, 0x1F, 0x03, 0xFC, 0x60, 0xE6, 0x06, 0xC0, 0x6C, 0x03, 0xC0, 0x3C, 0x03, 0xC0, 0x3C, 0x06, 0x60, 0x66, 0x0E, 0x3F, 0xC1, 0xF0, 0xFE, 0x3F, 0xEC, 0x1B, 0x03, 0xC0, 0xF0, 0x3C, 0x1F, 0xFE, 0xFF, 0x30, 0x0C, 0x03, 0x00, 0xC0, 0x30, 0x00, 0x1F, 0x03, 0xFC, 0x60, 0xE6, 0x06, 0xC0, 0x6C, 0x02, 0xC0, 0x3C, 0x03, 0xC0, 0x2C, 0x06, 0x60, 0x66, 0x0E, 0x3F, 0xC1, 0xFC, 0x00, 0xE0, 0x02, 0xFE, 0x3F, 0xEC, 0x1B, 0x06, 0xC1, 0xB0, 0x6F, 0xF3, 0xF8, 0xC6, 0x30, 0xCC, 0x33, 0x06, 0xC1, 0xB0, 0x30, 0x1F, 0x1F, 0xEE, 0x0F, 0x03, 0xC0, 0x18, 0x03, 0xC0, 0x3E, 0x01, 0xC0, 0x3C, 0x0F, 0x03, 0x7F, 0x8F, 0xC0, 0xFF, 0xFF, 0xFC, 0x18, 0x03, 0x00, 0x60, 0x0C, 0x01, 0x80, 0x30, 0x06, 0x00, 0xC0, 0x18, 0x03, 0x00, 0x60, 0x0C, 0x00, 0xC0, 0x78, 0x0F, 0x01, 0xE0, 0x3C, 0x07, 0x80, 0xF0, 0x1E, 0x03, 0xC0, 0x78, 0x0F, 0x01, 0xB0, 0x67, 0xF8, 0x3E, 0x00, 0xE0, 0x36, 0x03, 0x60, 0x33, 0x06, 0x30, 0x63, 0x0C, 0x18, 0xC1, 0x8C, 0x19, 0x80, 0xD8, 0x0D, 0x80, 0x70, 0x07, 0x00, 0x60, 0xC1, 0x83, 0xC1, 0x83, 0xC3, 0x83, 0xC3, 0xC2, 0x63, 0xC6, 0x62, 0x46, 0x66, 0x66, 0x66, 0x64, 0x24, 0x2C, 0x3C, 0x2C, 0x3C, 0x3C, 0x38, 0x38, 0x18, 0x18, 0x18, 0x18, 0xC0, 0xEC, 0x19, 0x86, 0x19, 0xC1, 0xB0, 0x3C, 0x03, 0x80, 0x70, 0x1E, 0x07, 0x60, 0xC6, 0x30, 0xC6, 0x0D, 0x81, 0xC0, 0xE0, 0x76, 0x06, 0x30, 0xC3, 0x0C, 0x19, 0x81, 0x98, 0x0F, 0x00, 0xF0, 0x06, 0x00, 0x60, 0x06, 0x00, 0x60, 0x06, 0x00, 0x60, 0xFF, 0xFF, 0xF0, 0x18, 0x0C, 0x03, 0x01, 0x80, 0xC0, 0x70, 0x18, 0x0C, 0x06, 0x01, 0x80, 0xFF, 0xFF, 0xF0, 0xFC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xF0, 0x40, 0x60, 0x60, 0x30, 0x30, 0x10, 0x18, 0x18, 0x08, 0x0C, 0x04, 0x06, 0x06, 0x02, 0x03, 0xF3, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0xF0, 0x30, 0x60, 0xE3, 0x44, 0xD9, 0xB1, 0x00, 0xFF, 0x80, 0xC6, 0x20, 0x3E, 0x3B, 0xB0, 0xC0, 0x23, 0xF3, 0x0B, 0x05, 0x82, 0xC3, 0x3F, 0x8F, 0x60, 0xC0, 0x60, 0x30, 0x18, 0x0D, 0xE7, 0xFB, 0x87, 0x83, 0xC1, 0xE0, 0xF0, 0x78, 0x3E, 0x1F, 0xFB, 0x78, 0x3E, 0x3B, 0xB0, 0x78, 0x3C, 0x06, 0x03, 0x01, 0x83, 0xC1, 0x3F, 0x8F, 0x80, 0x01, 0x80, 0xC0, 0x60, 0x33, 0xDB, 0xFF, 0x87, 0x83, 0xC1, 0xE0, 0xF0, 0x78, 0x36, 0x1B, 0xFC, 0xF6, 0x1E, 0x3B, 0x98, 0x58, 0x3C, 0x1F, 0xFF, 0x01, 0x80, 0xE1, 0x3F, 0x8F, 0x80, 0x1C, 0xF6, 0x18, 0xF9, 0x86, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x00, 0x3D, 0xBF, 0xF8, 0x78, 0x3C, 0x1E, 0x0F, 0x07, 0x83, 0x61, 0xBF, 0xCF, 0x60, 0x34, 0x1B, 0xB8, 0xF8, 0xC0, 0x60, 0x30, 0x18, 0x0D, 0xE7, 0xFB, 0x87, 0x83, 0xC1, 0xE0, 0xF0, 0x78, 0x3C, 0x1E, 0x0F, 0x06, 0xC8, 0x04, 0x92, 0x49, 0x24, 0x90, 0x33, 0x00, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3F, 0xE0, 0xC0, 0x60, 0x30, 0x18, 0x0C, 0x36, 0x33, 0x31, 0xB8, 0xF8, 0x7C, 0x3B, 0x19, 0xCC, 0x66, 0x1B, 0x06, 0xFF, 0xFE, 0xDE, 0x3D, 0xFF, 0xFF, 0x06, 0x1E, 0x0C, 0x3C, 0x18, 0x78, 0x30, 0xF0, 0x61, 0xE0, 0xC3, 0xC1, 0x87, 0x83, 0x0F, 0x06, 0x18, 0xDE, 0x7F, 0xB8, 0x78, 0x3C, 0x1E, 0x0F, 0x07, 0x83, 0xC1, 0xE0, 0xF0, 0x60, 0x1E, 0x1D, 0xC6, 0x1B, 0x06, 0xC0, 0xB0, 0x3C, 0x0B, 0x06, 0x61, 0x9F, 0xC1, 0xE0, 0xDE, 0x7F, 0xB8, 0x78, 0x3C, 0x1E, 0x0F, 0x07, 0x83, 0xC1, 0xFF, 0xB7, 0x98, 0x0C, 0x06, 0x03, 0x00, 0x3D, 0xBB, 0xF8, 0x78, 0x3C, 0x1E, 0x0F, 0x07, 0x83, 0xE1, 0xBF, 0xCF, 0x60, 0x30, 0x18, 0x0C, 0x06, 0xDF, 0xF9, 0x8C, 0x63, 0x18, 0xC6, 0x30, 0x3C, 0x77, 0xC3, 0xC0, 0x70, 0x3E, 0x07, 0x03, 0xC3, 0x7F, 0x3E, 0x30, 0xCF, 0xCC, 0x30, 0xC3, 0x0C, 0x30, 0xC3, 0x0F, 0x1C, 0xC1, 0xE0, 0xF0, 0x78, 0x3C, 0x1E, 0x0F, 0x07, 0x83, 0x43, 0xBF, 0xCF, 0x60, 0x41, 0xB0, 0xD8, 0x44, 0x63, 0x31, 0x90, 0x58, 0x3C, 0x1C, 0x06, 0x03, 0x00, 0x41, 0x04, 0xC7, 0x19, 0x8E, 0x33, 0x14, 0x62, 0x6C, 0x86, 0xDB, 0x0D, 0x16, 0x0A, 0x28, 0x1C, 0x70, 0x30, 0x60, 0x60, 0xC0, 0x61, 0xB1, 0x8C, 0xC3, 0xC1, 0xE0, 0x60, 0x78, 0x3C, 0x33, 0x30, 0xD8, 0x60, 0xC1, 0xB0, 0xD8, 0x4C, 0x63, 0x31, 0x90, 0x58, 0x3C, 0x1C, 0x06, 0x03, 0x01, 0x01, 0x83, 0x81, 0x80, 0xFF, 0x03, 0x06, 0x0C, 0x0C, 0x18, 0x30, 0x60, 0x60, 0xC0, 0xFF, 0x08, 0x63, 0x0C, 0x30, 0xC3, 0x08, 0x63, 0x8C, 0x18, 0x20, 0xC3, 0x0C, 0x30, 0xC1, 0x82, 0xFF, 0xFF, 0x80, 0xC1, 0x83, 0x0C, 0x30, 0xC3, 0x0C, 0x30, 0x60, 0xC6, 0x30, 0xC3, 0x0C, 0x30, 0xC6, 0x30, 0x38, 0x2F, 0x87, 0x1F, 0xE1, 0xE0, 0x00, 0x0C, 0x06, 0x07, 0x8E, 0xE6, 0x1E, 0x0F, 0x01, 0x80, 0xC0, 0x60, 0xD8, 0x6F, 0xE3, 0xE0, 0x60, 0x30, 0x1F, 0x0F, 0xE3, 0x0D, 0x83, 0x60, 0x18, 0x0F, 0xC3, 0xF0, 0x20, 0x08, 0x02, 0x01, 0x80, 0xFF, 0xFF, 0xF0, 0xE0, 0xD8, 0x36, 0x18, 0xC6, 0x13, 0x06, 0x80, 0xE1, 0xFE, 0x0C, 0x03, 0x07, 0xF8, 0x30, 0x0C, 0x03, 0x00, 0x0F, 0x80, 0x61, 0x86, 0x01, 0x11, 0xE6, 0xCC, 0xCA, 0x63, 0x39, 0x80, 0x66, 0x01, 0x98, 0xCF, 0x33, 0x24, 0x79, 0x98, 0x04, 0x18, 0x60, 0x3E, 0x00, 0x0F, 0x80, 0xE1, 0x86, 0x01, 0x13, 0xE6, 0xC8, 0xCA, 0x23, 0x38, 0x8C, 0x63, 0xE1, 0x88, 0xCF, 0x23, 0x24, 0x8D, 0x98, 0x04, 0x18, 0x60, 0x3E, 0x00, 0x76, 0x63, 0x97, 0x00, 0x6C, 0x41, 0x71, 0x9D, 0x87, 0x81, 0x81, 0xE1, 0x99, 0x86, 0x41, 0x00, 0x0C, 0x06, 0x00, 0x00, 0x0F, 0xFF, 0xFC, 0x00, 0x00, 0x0C, 0x06, 0x00, 0xFF, 0x80, 0xFF, 0xF8, 0x4B, 0x6C, 0x6D, 0xB4, 0x49, 0x2D, 0xB6, 0xD8, 0x4A, 0x77, 0xB9, 0x00, 0x7F, 0xF7, 0x66, 0x6C, 0xCC, 0x0F, 0x8F, 0xCC, 0x06, 0x03, 0x07, 0xF0, 0xC1, 0xFC, 0x30, 0x18, 0x0C, 0x06, 0x01, 0xF8, 0x7C, 0xF4, 0xD3, 0x34, 0xB5, 0x2D, 0x49, 0x40, 0xFF};
  static const font::GlyphData font_glyphdata_id[] = {font::GlyphData{
    .a_char = (const uint8_t *)" ",
    .data = uint8_t_id + 0,
    .advance = 5,
    .offset_x = 0,
    .offset_y = 18,
    .width = 1,
    .height = 1,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"!",
    .data = uint8_t_id + 1,
    .advance = 5,
    .offset_x = 2,
    .offset_y = 5,
    .width = 2,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\042",
    .data = uint8_t_id + 5,
    .advance = 6,
    .offset_x = 1,
    .offset_y = 4,
    .width = 4,
    .height = 5,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"#",
    .data = uint8_t_id + 8,
    .advance = 12,
    .offset_x = 1,
    .offset_y = 5,
    .width = 11,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"$",
    .data = uint8_t_id + 28,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 3,
    .width = 9,
    .height = 18,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"%",
    .data = uint8_t_id + 49,
    .advance = 15,
    .offset_x = 1,
    .offset_y = 5,
    .width = 13,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"&",
    .data = uint8_t_id + 72,
    .advance = 12,
    .offset_x = 1,
    .offset_y = 5,
    .width = 11,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"'",
    .data = uint8_t_id + 92,
    .advance = 4,
    .offset_x = 1,
    .offset_y = 4,
    .width = 1,
    .height = 5,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"(",
    .data = uint8_t_id + 93,
    .advance = 7,
    .offset_x = 1,
    .offset_y = 3,
    .width = 5,
    .height = 21,
  }, font::GlyphData{
    .a_char = (const uint8_t *)")",
    .data = uint8_t_id + 107,
    .advance = 7,
    .offset_x = 0,
    .offset_y = 3,
    .width = 6,
    .height = 21,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"*",
    .data = uint8_t_id + 123,
    .advance = 9,
    .offset_x = 0,
    .offset_y = 5,
    .width = 8,
    .height = 8,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"+",
    .data = uint8_t_id + 131,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 7,
    .width = 10,
    .height = 11,
  }, font::GlyphData{
    .a_char = (const uint8_t *)",",
    .data = uint8_t_id + 145,
    .advance = 4,
    .offset_x = 0,
    .offset_y = 17,
    .width = 3,
    .height = 5,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"-",
    .data = uint8_t_id + 147,
    .advance = 6,
    .offset_x = 0,
    .offset_y = 13,
    .width = 5,
    .height = 1,
  }, font::GlyphData{
    .a_char = (const uint8_t *)".",
    .data = uint8_t_id + 148,
    .advance = 5,
    .offset_x = 1,
    .offset_y = 17,
    .width = 3,
    .height = 2,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"/",
    .data = uint8_t_id + 149,
    .advance = 8,
    .offset_x = 0,
    .offset_y = 5,
    .width = 8,
    .height = 15,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"0",
    .data = uint8_t_id + 164,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 5,
    .width = 9,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"1",
    .data = uint8_t_id + 180,
    .advance = 11,
    .offset_x = 2,
    .offset_y = 5,
    .width = 5,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"2",
    .data = uint8_t_id + 189,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 5,
    .width = 10,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"3",
    .data = uint8_t_id + 207,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 5,
    .width = 9,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"4",
    .data = uint8_t_id + 223,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 5,
    .width = 10,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"5",
    .data = uint8_t_id + 241,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 5,
    .width = 9,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"6",
    .data = uint8_t_id + 257,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 5,
    .width = 9,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"7",
    .data = uint8_t_id + 273,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 5,
    .width = 9,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"8",
    .data = uint8_t_id + 289,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 5,
    .width = 9,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"9",
    .data = uint8_t_id + 305,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 5,
    .width = 9,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)":",
    .data = uint8_t_id + 321,
    .advance = 5,
    .offset_x = 1,
    .offset_y = 8,
    .width = 3,
    .height = 11,
  }, font::GlyphData{
    .a_char = (const uint8_t *)";",
    .data = uint8_t_id + 326,
    .advance = 4,
    .offset_x = 0,
    .offset_y = 8,
    .width = 3,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"<",
    .data = uint8_t_id + 332,
    .advance = 10,
    .offset_x = 1,
    .offset_y = 8,
    .width = 8,
    .height = 9,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"=",
    .data = uint8_t_id + 341,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 9,
    .width = 9,
    .height = 7,
  }, font::GlyphData{
    .a_char = (const uint8_t *)">",
    .data = uint8_t_id + 349,
    .advance = 10,
    .offset_x = 1,
    .offset_y = 8,
    .width = 9,
    .height = 9,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"?",
    .data = uint8_t_id + 360,
    .advance = 9,
    .offset_x = 1,
    .offset_y = 5,
    .width = 8,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"@",
    .data = uint8_t_id + 374,
    .advance = 18,
    .offset_x = 1,
    .offset_y = 5,
    .width = 16,
    .height = 18,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"A",
    .data = uint8_t_id + 410,
    .advance = 13,
    .offset_x = 0,
    .offset_y = 5,
    .width = 13,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"B",
    .data = uint8_t_id + 433,
    .advance = 12,
    .offset_x = 2,
    .offset_y = 5,
    .width = 9,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"C",
    .data = uint8_t_id + 449,
    .advance = 13,
    .offset_x = 1,
    .offset_y = 5,
    .width = 11,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"D",
    .data = uint8_t_id + 469,
    .advance = 13,
    .offset_x = 2,
    .offset_y = 5,
    .width = 10,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"E",
    .data = uint8_t_id + 487,
    .advance = 11,
    .offset_x = 2,
    .offset_y = 5,
    .width = 9,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"F",
    .data = uint8_t_id + 503,
    .advance = 11,
    .offset_x = 2,
    .offset_y = 5,
    .width = 8,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"G",
    .data = uint8_t_id + 517,
    .advance = 14,
    .offset_x = 1,
    .offset_y = 5,
    .width = 11,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"H",
    .data = uint8_t_id + 537,
    .advance = 14,
    .offset_x = 2,
    .offset_y = 5,
    .width = 11,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"I",
    .data = uint8_t_id + 557,
    .advance = 5,
    .offset_x = 2,
    .offset_y = 5,
    .width = 2,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"J",
    .data = uint8_t_id + 561,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 5,
    .width = 9,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"K",
    .data = uint8_t_id + 577,
    .advance = 13,
    .offset_x = 2,
    .offset_y = 5,
    .width = 11,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"L",
    .data = uint8_t_id + 597,
    .advance = 11,
    .offset_x = 2,
    .offset_y = 5,
    .width = 8,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"M",
    .data = uint8_t_id + 611,
    .advance = 17,
    .offset_x = 2,
    .offset_y = 5,
    .width = 14,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"N",
    .data = uint8_t_id + 636,
    .advance = 14,
    .offset_x = 2,
    .offset_y = 5,
    .width = 11,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"O",
    .data = uint8_t_id + 656,
    .advance = 14,
    .offset_x = 1,
    .offset_y = 5,
    .width = 12,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"P",
    .data = uint8_t_id + 677,
    .advance = 13,
    .offset_x = 2,
    .offset_y = 5,
    .width = 10,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"Q",
    .data = uint8_t_id + 695,
    .advance = 14,
    .offset_x = 1,
    .offset_y = 5,
    .width = 12,
    .height = 16,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"R",
    .data = uint8_t_id + 719,
    .advance = 12,
    .offset_x = 2,
    .offset_y = 5,
    .width = 10,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"S",
    .data = uint8_t_id + 737,
    .advance = 12,
    .offset_x = 1,
    .offset_y = 5,
    .width = 10,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"T",
    .data = uint8_t_id + 755,
    .advance = 12,
    .offset_x = 0,
    .offset_y = 5,
    .width = 11,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"U",
    .data = uint8_t_id + 775,
    .advance = 13,
    .offset_x = 1,
    .offset_y = 5,
    .width = 11,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"V",
    .data = uint8_t_id + 795,
    .advance = 13,
    .offset_x = 0,
    .offset_y = 5,
    .width = 12,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"W",
    .data = uint8_t_id + 816,
    .advance = 18,
    .offset_x = 1,
    .offset_y = 5,
    .width = 16,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"X",
    .data = uint8_t_id + 844,
    .advance = 13,
    .offset_x = 1,
    .offset_y = 5,
    .width = 11,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"Y",
    .data = uint8_t_id + 864,
    .advance = 12,
    .offset_x = 0,
    .offset_y = 5,
    .width = 12,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"Z",
    .data = uint8_t_id + 885,
    .advance = 12,
    .offset_x = 1,
    .offset_y = 5,
    .width = 10,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"[",
    .data = uint8_t_id + 903,
    .advance = 5,
    .offset_x = 1,
    .offset_y = 3,
    .width = 4,
    .height = 19,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\134",
    .data = uint8_t_id + 913,
    .advance = 8,
    .offset_x = 0,
    .offset_y = 5,
    .width = 8,
    .height = 15,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"]",
    .data = uint8_t_id + 928,
    .advance = 5,
    .offset_x = 0,
    .offset_y = 3,
    .width = 4,
    .height = 19,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"^",
    .data = uint8_t_id + 938,
    .advance = 8,
    .offset_x = 1,
    .offset_y = 5,
    .width = 7,
    .height = 7,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"_",
    .data = uint8_t_id + 945,
    .advance = 9,
    .offset_x = 0,
    .offset_y = 19,
    .width = 9,
    .height = 1,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"`",
    .data = uint8_t_id + 947,
    .advance = 6,
    .offset_x = 1,
    .offset_y = 4,
    .width = 4,
    .height = 3,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"a",
    .data = uint8_t_id + 949,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 8,
    .width = 9,
    .height = 11,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"b",
    .data = uint8_t_id + 962,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 4,
    .width = 9,
    .height = 15,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"c",
    .data = uint8_t_id + 979,
    .advance = 10,
    .offset_x = 1,
    .offset_y = 8,
    .width = 9,
    .height = 11,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"d",
    .data = uint8_t_id + 992,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 4,
    .width = 9,
    .height = 15,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"e",
    .data = uint8_t_id + 1009,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 8,
    .width = 9,
    .height = 11,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"f",
    .data = uint8_t_id + 1022,
    .advance = 7,
    .offset_x = 1,
    .offset_y = 4,
    .width = 6,
    .height = 15,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"g",
    .data = uint8_t_id + 1034,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 8,
    .width = 9,
    .height = 15,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"h",
    .data = uint8_t_id + 1051,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 4,
    .width = 9,
    .height = 15,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"i",
    .data = uint8_t_id + 1068,
    .advance = 5,
    .offset_x = 1,
    .offset_y = 4,
    .width = 3,
    .height = 15,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"j",
    .data = uint8_t_id + 1074,
    .advance = 5,
    .offset_x = -1,
    .offset_y = 4,
    .width = 4,
    .height = 19,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"k",
    .data = uint8_t_id + 1084,
    .advance = 10,
    .offset_x = 1,
    .offset_y = 4,
    .width = 9,
    .height = 15,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"l",
    .data = uint8_t_id + 1101,
    .advance = 5,
    .offset_x = 2,
    .offset_y = 4,
    .width = 1,
    .height = 15,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"m",
    .data = uint8_t_id + 1103,
    .advance = 18,
    .offset_x = 1,
    .offset_y = 8,
    .width = 15,
    .height = 11,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"n",
    .data = uint8_t_id + 1124,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 8,
    .width = 9,
    .height = 11,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"o",
    .data = uint8_t_id + 1137,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 8,
    .width = 10,
    .height = 11,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"p",
    .data = uint8_t_id + 1151,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 8,
    .width = 9,
    .height = 15,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"q",
    .data = uint8_t_id + 1168,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 8,
    .width = 9,
    .height = 15,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"r",
    .data = uint8_t_id + 1185,
    .advance = 7,
    .offset_x = 1,
    .offset_y = 8,
    .width = 5,
    .height = 11,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"s",
    .data = uint8_t_id + 1192,
    .advance = 10,
    .offset_x = 1,
    .offset_y = 8,
    .width = 8,
    .height = 11,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"t",
    .data = uint8_t_id + 1203,
    .advance = 7,
    .offset_x = 0,
    .offset_y = 6,
    .width = 6,
    .height = 13,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"u",
    .data = uint8_t_id + 1213,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 8,
    .width = 9,
    .height = 11,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"v",
    .data = uint8_t_id + 1226,
    .advance = 10,
    .offset_x = 0,
    .offset_y = 8,
    .width = 9,
    .height = 11,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"w",
    .data = uint8_t_id + 1239,
    .advance = 15,
    .offset_x = 0,
    .offset_y = 8,
    .width = 15,
    .height = 11,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"x",
    .data = uint8_t_id + 1260,
    .advance = 10,
    .offset_x = 0,
    .offset_y = 8,
    .width = 9,
    .height = 11,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"y",
    .data = uint8_t_id + 1273,
    .advance = 9,
    .offset_x = 0,
    .offset_y = 8,
    .width = 9,
    .height = 15,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"z",
    .data = uint8_t_id + 1290,
    .advance = 10,
    .offset_x = 1,
    .offset_y = 8,
    .width = 8,
    .height = 11,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"{",
    .data = uint8_t_id + 1301,
    .advance = 7,
    .offset_x = 1,
    .offset_y = 3,
    .width = 6,
    .height = 20,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"|",
    .data = uint8_t_id + 1316,
    .advance = 5,
    .offset_x = 2,
    .offset_y = 5,
    .width = 1,
    .height = 17,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"}",
    .data = uint8_t_id + 1319,
    .advance = 7,
    .offset_x = 0,
    .offset_y = 3,
    .width = 6,
    .height = 20,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"~",
    .data = uint8_t_id + 1334,
    .advance = 14,
    .offset_x = 1,
    .offset_y = 11,
    .width = 11,
    .height = 4,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\302\240",
    .data = uint8_t_id + 1340,
    .advance = 5,
    .offset_x = 0,
    .offset_y = 18,
    .width = 1,
    .height = 1,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\302\242",
    .data = uint8_t_id + 1341,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 6,
    .width = 9,
    .height = 15,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\302\243",
    .data = uint8_t_id + 1358,
    .advance = 12,
    .offset_x = 1,
    .offset_y = 5,
    .width = 10,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\302\245",
    .data = uint8_t_id + 1376,
    .advance = 11,
    .offset_x = 0,
    .offset_y = 5,
    .width = 10,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\302\251",
    .data = uint8_t_id + 1394,
    .advance = 16,
    .offset_x = 1,
    .offset_y = 5,
    .width = 14,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\302\256",
    .data = uint8_t_id + 1419,
    .advance = 16,
    .offset_x = 1,
    .offset_y = 5,
    .width = 14,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\302\260",
    .data = uint8_t_id + 1444,
    .advance = 7,
    .offset_x = 1,
    .offset_y = 5,
    .width = 5,
    .height = 5,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\302\267",
    .data = uint8_t_id + 1448,
    .advance = 5,
    .offset_x = 1,
    .offset_y = 11,
    .width = 3,
    .height = 2,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\303\227",
    .data = uint8_t_id + 1449,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 8,
    .width = 9,
    .height = 9,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\303\267",
    .data = uint8_t_id + 1460,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 7,
    .width = 9,
    .height = 10,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\342\200\223",
    .data = uint8_t_id + 1472,
    .advance = 13,
    .offset_x = 2,
    .offset_y = 12,
    .width = 9,
    .height = 1,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\342\200\224",
    .data = uint8_t_id + 1474,
    .advance = 16,
    .offset_x = 1,
    .offset_y = 12,
    .width = 13,
    .height = 1,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\342\200\230",
    .data = uint8_t_id + 1476,
    .advance = 4,
    .offset_x = 1,
    .offset_y = 4,
    .width = 3,
    .height = 5,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\342\200\231",
    .data = uint8_t_id + 1478,
    .advance = 4,
    .offset_x = 0,
    .offset_y = 4,
    .width = 3,
    .height = 5,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\342\200\234",
    .data = uint8_t_id + 1480,
    .advance = 7,
    .offset_x = 1,
    .offset_y = 4,
    .width = 6,
    .height = 5,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\342\200\235",
    .data = uint8_t_id + 1484,
    .advance = 7,
    .offset_x = 1,
    .offset_y = 4,
    .width = 5,
    .height = 5,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\342\200\242",
    .data = uint8_t_id + 1488,
    .advance = 7,
    .offset_x = 1,
    .offset_y = 10,
    .width = 4,
    .height = 4,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\342\200\246",
    .data = uint8_t_id + 1490,
    .advance = 13,
    .offset_x = 1,
    .offset_y = 17,
    .width = 11,
    .height = 2,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\342\202\254",
    .data = uint8_t_id + 1493,
    .advance = 11,
    .offset_x = 1,
    .offset_y = 5,
    .width = 9,
    .height = 14,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\342\204\242",
    .data = uint8_t_id + 1509,
    .advance = 13,
    .offset_x = 1,
    .offset_y = 5,
    .width = 10,
    .height = 5,
  }, font::GlyphData{
    .a_char = (const uint8_t *)"\342\210\222",
    .data = uint8_t_id + 1516,
    .advance = 11,
    .offset_x = 2,
    .offset_y = 12,
    .width = 8,
    .height = 1,
  }};
  font1 = new font::Font(font_glyphdata_id, 116, 19, 23, 5, 11, 14, 1);
  // time.sntp:
  //   platform: sntp
  //   id: sntp_time
  //   timezone: PST8PDT,M3.2.0,M11.1.0
  //   on_time_sync:
  //     - then:
  //         - lambda: !lambda |-
  //             if (!id(time_zone_changed_at_boot)) {
  //               ESP_LOGI("tz", "Applying persisted timezone after time sync: '%s'", id(selected_location_tz).c_str());
  //               id(sntp_time).set_timezone(id(selected_location_tz).c_str());
  //               id(sntp_time).update();
  //               id(time_zone_changed_at_boot) = true;
  //             }
  //           type_id: lambdaaction_id_9
  //         - script.execute:
  //             id: update_display
  //           type_id: script_scriptexecuteaction_id_3
  //         - wait_until:
  //             timeout: 8s
  //             condition:
  //               lambda: !lambda |-
  //                 return id(sntp_time).now().is_valid();
  //               type_id: lambdacondition_id_2
  //           type_id: waituntilaction_id_3
  //         - lambda: !lambda |-
  //             id(update_display).execute();
  //             if (!id(prayer_times_refreshed_at_least_once)) {
  //               id(compute_coming_prayer).execute();
  //             }
  //           type_id: lambdaaction_id_10
  //       automation_id: automation_id_5
  //       trigger_id: time_synctrigger_id
  //   on_time:
  //     - minutes:
  //         - 0
  //       seconds:
  //         - 0
  //       then:
  //         - script.execute:
  //             id: refresh_prayer_times_if_needed
  //           type_id: script_scriptexecuteaction_id_4
  //         - lambda: !lambda |-
  //             if (!id(athan_playing) && id(htick_file_index) > 0) {
  //                 id(dfp).play_file(id(htick_file_index));
  //             }
  //           type_id: lambdaaction_id_11
  //       automation_id: automation_id_6
  //       trigger_id: time_crontrigger_id
  //     - seconds:
  //         - 0
  //       then:
  //         - lambda: !lambda |-
  //             id(update_display).execute();
  //             if (!id(prayer_times_refreshed_at_least_once)){
  //               id(refresh_prayer_times_if_needed).execute();
  //             }
  //             return;
  //           type_id: lambdaaction_id_12
  //       automation_id: automation_id_7
  //       trigger_id: time_crontrigger_id_2
  //   update_interval: 15min
  //   servers:
  //     - 0.pool.ntp.org
  //     - 1.pool.ntp.org
  //     - 2.pool.ntp.org
  sntp_time = new sntp::SNTPComponent({"0.pool.ntp.org", "1.pool.ntp.org", "2.pool.ntp.org"});
  sntp_time->set_update_interval(900000);
  sntp_time->set_component_source(LOG_STR("sntp.time"));
  App.register_component(sntp_time);
  sntp_time->set_timezone("PST8PDT,M3.2.0,M11.1.0");
  time_crontrigger_id = new time::CronTrigger(sntp_time);
  time_crontrigger_id->add_seconds({0});
  time_crontrigger_id->add_minutes({0});
  time_crontrigger_id->add_hours({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23});
  time_crontrigger_id->add_days_of_month({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31});
  time_crontrigger_id->add_months({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  time_crontrigger_id->add_days_of_week({1, 2, 3, 4, 5, 6, 7});
  time_crontrigger_id->set_component_source(LOG_STR("time"));
  App.register_component(time_crontrigger_id);
  automation_id_6 = new Automation<>(time_crontrigger_id);
  // script:
  //   - id: refresh_prayer_times_if_needed
  //     mode: restart
  //     then:
  //       - lambda: !lambda |-
  //           auto now = id(sntp_time).now();
  //           if (!now.is_valid()) {
  //            return;
  //           }
  //           if (!id(loaded_prayer_times_once)) {
  //             ESP_LOGI("prayer","Prayer times never loaded yet — loading now");
  //             id(load_prayer_times).execute();
  //           }
  //           int current_day = now.day_of_year;
  //           int current_year = now.year;
  //           if (id(prayer_times_day) != current_day || id(prayer_times_year) != current_year) {
  //             ESP_LOGI("prayer","Prayer times are outdated, reloading...");
  //             id(loaded_prayer_times_once) = false;
  //             id(prayer_times_refreshed_at_least_once) = false;
  //             id(load_prayer_times).execute();
  //           } else {
  //             id(prayer_times_refreshed_at_least_once) = true;
  //           }
  //           id(compute_coming_prayer).execute();
  //           id(log_prayers).execute();
  //           id(update_display).execute();
  //         type_id: lambdaaction_id_13
  //     trigger_id: trigger_id_2
  //     automation_id: automation_id_8
  //     parameters: {}
  //   - id: make_athan
  //     mode: single
  //     then:
  //       - logger.log:
  //           format: Athan Calling!
  //           logger_id: logger_logger_id
  //           tag: main
  //           level: DEBUG
  //           args: []
  //         type_id: lambdaaction_id_14
  //       - lambda: !lambda |-
  //           id(athan_playing) = true;
  //           id(dfp).stop();
  //           delay(250);
  //           id(dfp).play_file(id(athan_file_index));
  //         type_id: lambdaaction_id_15
  //       - light.turn_on:
  //           id: builtin_led
  //           state: true
  //         type_id: light_lightcontrolaction_id_10
  //       - delay: 5min
  //         type_id: delayaction_id_9
  //       - light.turn_off:
  //           id: builtin_led
  //           state: false
  //         type_id: light_lightcontrolaction_id_11
  //       - lambda: !lambda |-
  //           id(athan_playing) = false;
  //         type_id: lambdaaction_id_16
  //     trigger_id: trigger_id_3
  //     automation_id: automation_id_9
  //     parameters: {}
  //   - id: perform_update
  //     mode: single
  //     then:
  //       - lambda: !lambda |-
  //            If we don't have a cached update URL, fail immediately
  //           if (id(update_url).empty()) {
  //             ESP_LOGE("update", "No update_url cached, aborting perform_update");
  //             id(update_check_state) = 0;
  //             id(update_display).execute();
  //             id(ui_mode) = 0;
  //             return;
  //           }
  //            indicate attempting state while OTA runs
  //           id(update_check_state) = 4;
  //           id(update_display).execute();
  //         type_id: lambdaaction_id_17
  //       - ota.http_request.flash:
  //           url: !lambda |-
  //             std::string base = id(update_url);
  //             return  base + ".bin";
  //           md5_url: !lambda |-
  //             std::string base = id(update_url);
  //             return base + ".md5";
  //           id: http_request_otahttprequestcomponent_id
  //         type_id: http_request_otahttprequestcomponentflashaction_id
  //       - lambda: !lambda |-
  //            Clear attempting state after OTA attempt so menu doesn't remain showing "attempting .."
  //           id(update_check_state) = 0;
  //           id(ui_mode) = 0;
  //           id(update_display).execute();
  //         type_id: lambdaaction_id_18
  //     trigger_id: trigger_id_4
  //     automation_id: automation_id_10
  //     parameters: {}
  //   - id: test_script
  //     mode: single
  //     then:
  //       - lambda: !lambda |-
  //           ESP_LOGI("test","Waving from test..");
  //           return;
  //         type_id: lambdaaction_id_19
  //     trigger_id: trigger_id_5
  //     automation_id: automation_id_11
  //     parameters: {}
  //   - id: check_update_remote
  //     mode: single
  //     then:
  //       - logger.log:
  //           format: Starting remote update check
  //           logger_id: logger_logger_id
  //           tag: main
  //           level: DEBUG
  //           args: []
  //         type_id: lambdaaction_id_20
  //       - http_request.get:
  //           url: http:raw.githack.com/et7ad/esp_athan/master/docs/firmwareinfo/latest.json
  //           capture_response: false
  //           max_response_buffer_size: 1024
  //           on_response:
  //             then:
  //               - lambda: !lambda |-
  //                   ESP_LOGI("update", "Reading latest.json response...");
  //                   std::string json_text;
  //                   char buf[128];
  //                   int len;
  //                   int total_bytes = 0;
  //                   const int max_bytes = 1024;
  //                   while ((len = response->read((uint8_t*)buf, sizeof(buf))) > 0) {
  //                     if (total_bytes + len > max_bytes) len = max_bytes - total_bytes;
  //                     json_text.append(buf, len);
  //                     total_bytes += len;
  //                     if (total_bytes >= max_bytes) break;
  //                   }
  //   
  //                   if (total_bytes == 0) {
  //                     ESP_LOGE("update", "Empty latest.json response");
  //                     id(update_check_state) = 0;
  //                     id(update_display).execute();
  //                     return;
  //                   }
  //   
  //                   int start = json_text.find('{');
  //                   if (start > 0) json_text.erase(0, start);
  //                   int end = json_text.rfind('}');
  //                   if (end != -1 && end + 1 < json_text.size()) json_text.erase(end + 1);
  //   
  //                   JsonDocument doc;
  //                   auto err = deserializeJson(doc, json_text);
  //                   if (err) {
  //                     ESP_LOGE("update", "JSON parse failed: %s", err.c_str());
  //                     id(update_check_state) = 0;
  //                     id(update_display).execute();
  //                     return;
  //                   }
  //   
  //                   if (!doc["latest_version"].is<int>()) {
  //                     ESP_LOGE("update", "latest_version missing or not an int in JSON");
  //                     id(update_check_state) = 0;
  //                     id(update_display).execute();
  //                     return;
  //                   }
  //   
  //                   int latest = doc["latest_version"].as<int>();
  //                   id(update_latest_version) = latest;
  //                   if (latest <= 1) {
  //                     id(update_check_state) = 1;  up-to-date
  //                     ESP_LOGI("update", "Device up-to-date: %d", latest);
  //                     id(update_display).execute();
  //                     return;
  //                   }
  //                    Attempt to read optional firmware URL field
  //                   std::string fw_url;
  //                   if (!doc["url"].is<const char*>()) {
  //                     ESP_LOGE("update", "No url provided in latest.json");
  //                     id(update_check_state) = 0;
  //                     id(update_display).execute();
  //                     id(ui_mode) = 0;
  //                     return;
  //                   }
  //                   fw_url = doc["url"].as<const char*>();
  //                   if (fw_url.empty()) {
  //                     ESP_LOGE("update", "Empty url in latest.json");
  //                     id(update_check_state) = 0;
  //                     id(update_display).execute();
  //                     id(ui_mode) = 0;
  //                     return;
  //                   }
  //                   id(update_url) = fw_url;
  //                   id(update_check_state) = 2;  update available
  //                   ESP_LOGI("update", "Update available: %d -> %d, url=%s", 1, latest, fw_url.c_str());
  //                   id(update_display).execute();
  //                 type_id: lambdaaction_id_21
  //             trigger_id: trigger_id_6
  //             automation_id: automation_id_12
  //           id: http_request_httprequestarduino_id
  //           method: GET
  //         type_id: http_request_httprequestsendaction_id
  //     trigger_id: trigger_id_7
  //     automation_id: automation_id_13
  //     parameters: {}
  //   - id: run_quyam
  //     mode: single
  //     then:
  //       - lambda: !lambda |-
  //           id(quyam_triggered) = true;
  //         type_id: lambdaaction_id_22
  //       - if:
  //           condition:
  //             lambda: !lambda |-
  //               return id(q_flag);
  //             type_id: lambdacondition_id_3
  //           then:
  //             - logger.log:
  //                 format: Quyam starting (Q flag is ON)
  //                 logger_id: logger_logger_id
  //                 tag: main
  //                 level: DEBUG
  //                 args: []
  //               type_id: lambdaaction_id_23
  //             - switch.turn_on:
  //                 id: external_relay
  //               type_id: switch__turnonaction_id_2
  //             - lambda: !lambda |-
  //                 id(dfp).play_file(25);
  //               type_id: lambdaaction_id_24
  //             - delay: 15min
  //               type_id: delayaction_id_10
  //             - switch.turn_off:
  //                 id: external_relay
  //               type_id: switch__turnoffaction_id
  //           else:
  //             - logger.log:
  //                 format: Q flag is OFF — skipping Quyam actions
  //                 logger_id: logger_logger_id
  //                 tag: main
  //                 level: DEBUG
  //                 args: []
  //               type_id: lambdaaction_id_25
  //         type_id: ifaction_id_2
  //     trigger_id: trigger_id_8
  //     automation_id: automation_id_14
  //     parameters: {}
  //   - id: change_location_handler
  //     mode: single
  //     then:
  //       - logger.log:
  //           format: Attempting to fetch timezone for previewed location
  //           logger_id: logger_logger_id
  //           tag: main
  //           level: DEBUG
  //           args: []
  //         type_id: lambdaaction_id_26
  //       - http_request.get:
  //           url: !lambda |-
  //             char u[256];
  //             static const char* locs[15] = {"davis","santaclara","sacramento","cairo","masjid5","masjid6","masjid7","masjid8","masjid9","masjid10","masjid11","masjid12","masjid13","masjid14","masjid15"};
  //             int li = id(location_index);
  //             if (li < 0 || li > 14) li = 0;
  //             const char* loc = locs[li];
  //             snprintf(u, sizeof(u),
  //               "http:raw.githack.com/et7ad/esp_athan/master/docs/timezones/%s.json",
  //               loc);
  //             ESP_LOGI("tz", "TZ URL = %s", u);
  //             return std::string(u);
  //           capture_response: false
  //           max_response_buffer_size: 512
  //           on_response:
  //             then:
  //               - lambda: !lambda |-
  //                   ESP_LOGI("tz", "Reading timezone response...");
  //   
  //                   std::string json_text;
  //                   char buf[128];
  //                   int len;
  //                   int total_bytes = 0;
  //                   const int max_bytes = 512;
  //   
  //                   while ((len = response->read((uint8_t*)buf, sizeof(buf))) > 0) {
  //                     if (total_bytes + len > max_bytes) len = max_bytes - total_bytes;
  //                     json_text.append(buf, len);
  //                     total_bytes += len;
  //                     if (total_bytes >= max_bytes) break;
  //                   }
  //   
  //                   if (total_bytes == 0) {
  //                     ESP_LOGE("tz", "Empty timezone response");
  //                     id(ui_mode) = 0;
  //                     id(update_display).execute();
  //                     return;
  //                   }
  //   
  //                   int start = json_text.find('{');
  //                   if (start > 0) json_text.erase(0, start);
  //                   int end = json_text.rfind('}');
  //                   if (end != -1 && end + 1 < json_text.size()) json_text.erase(end + 1);
  //   
  //                   JsonDocument doc;
  //                   auto err = deserializeJson(doc, json_text);
  //                   if (err) {
  //                     ESP_LOGE("tz", "JSON parse failed: %s", err.c_str());
  //                     id(ui_mode) = 0;
  //                     id(update_display).execute();
  //                     return;
  //                   }
  //   
  //                   if (!doc["TZ"].is<const char*>()) {
  //                     ESP_LOGE("tz", "TZ key missing or invalid");
  //                     id(ui_mode) = 0;
  //                     id(update_display).execute();
  //                     return;
  //                   }
  //   
  //                   std::string tz(doc["TZ"].as<const char*>());
  //                   if (tz.size() == 0) {
  //                     ESP_LOGE("tz", "TZ value empty");
  //                     id(ui_mode) = 0;
  //                     id(update_display).execute();
  //                     return;
  //                   }
  //   
  //                    success: apply new timezone value and update selected index
  //                   id(selected_location_tz) = tz;
  //                    Set system/ESP timezone immediately so SNTP/time functions use it
  //                   ESP_LOGI("tz", "Setting system timezone to '%s'", id(selected_location_tz).c_str());
  //                   id(sntp_time).set_timezone(id(selected_location_tz).c_str());
  //                   id(sntp_time).update();
  //                   id(selected_location_index) = id(location_index);
  //                   id(prayer_times_day) = -1;
  //                   id(loaded_prayer_times_once) = false;
  //                   id(prayer_times_refreshed_at_least_once) = false;
  //                   id(refresh_prayer_times_if_needed).execute();
  //                   ESP_LOGI("tz", "Applied new timezone '%s' and location index %d", tz.c_str(), id(selected_location_index));
  //                   id(update_display).execute();
  //                 type_id: lambdaaction_id_27
  //             trigger_id: trigger_id_9
  //             automation_id: automation_id_15
  //           id: http_request_httprequestarduino_id
  //           method: GET
  //         type_id: http_request_httprequestsendaction_id_2
  //       - lambda: !lambda |-
  //           id(ui_mode) = 0;
  //           id(update_display).execute();
  //         type_id: lambdaaction_id_28
  //     trigger_id: trigger_id_10
  //     automation_id: automation_id_16
  //     parameters: {}
  //   - id: load_prayer_times
  //     mode: restart
  //     then:
  //       - http_request.get:
  //           url: !lambda |-
  //             auto now = id(sntp_time).now();
  //             int year = now.year;
  //             int day  = now.day_of_year;
  //   
  //             char u[256];
  //             static const char* locs[15] = {"davis","santaclara","sacramento","cairo","masjid5","masjid6","masjid7","masjid8","masjid9","masjid10","masjid11","masjid12","masjid13","masjid14","masjid15"};
  //             int li = id(selected_location_index);
  //             if (li < 0 || li > 14) li = 0;
  //             const char* loc = locs[li];
  //             snprintf(u, sizeof(u),
  //               "http:raw.githack.com/et7ad/esp_athan/master/docs/athantimes/%s/%d/%03d.json",
  //               loc, year, day);
  //   
  //             ESP_LOGI("prayer", "URL = %s", u);
  //             return std::string(u);
  //           capture_response: false
  //           max_response_buffer_size: 4096
  //           on_response:
  //             then:
  //               - lambda: !lambda |-
  //                   ESP_LOGI("prayer", "Reading response safely...");
  //   
  //                   std::string json_text;
  //                   char buf[128];
  //                   int len;
  //                   int total_bytes = 0;
  //                   const int max_bytes = 4096;   safety limit
  //   
  //                    Loop until no more data or max_bytes reached
  //                   while ((len = response->read((uint8_t*)buf, sizeof(buf))) > 0) {
  //                      Append only up to max_bytes
  //                     if (total_bytes + len > max_bytes) {
  //                       len = max_bytes - total_bytes;
  //                     }
  //                     json_text.append(buf, len);
  //                     total_bytes += len;
  //   
  //                     if (total_bytes >= max_bytes) {
  //                       ESP_LOGW("prayer", "Reached max read bytes (%d), stopping", max_bytes);
  //                       break;
  //                     }
  //                   }
  //   
  //                   ESP_LOGI("prayer", "JSON size = %d bytes", total_bytes);
  //   
  //                   if (total_bytes == 0) {
  //                     ESP_LOGE("prayer", "No data received, skipping parse");
  //                     return;
  //                   }
  //   
  //                    Strip everything before the first '{'
  //                   int start = json_text.find('{');
  //                   if (start > 0) json_text.erase(0, start);
  //   
  //                    Strip everything after the last '}'
  //                   int end = json_text.rfind('}');
  //                   if (end != -1 && end + 1 < json_text.size())
  //                     json_text.erase(end + 1);
  //   
  //                   JsonDocument doc;   adjust size if needed
  //                   auto err = deserializeJson(doc, json_text);
  //                   if (err) {
  //                     ESP_LOGE("prayer", "JSON parse failed: %s", err.c_str());
  //                     return;
  //                   }
  //   
  //                    Fajr (always AM)
  //                   {
  //                     std::string s(doc["fajr"].as<const char*>());   "06:06 "
  //                     s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
  //                     int h = std::stoi(s.substr(0,2));
  //                     int m = std::stoi(s.substr(3,2));
  //                     id(prayer_hours)[0] = h;     Fajr hour
  //                     id(prayer_minutes)[0] = m;   Fajr minute
  //                   }
  //   
  //                    Shrouk (always AM)
  //                   {
  //                     std::string s(doc["sunrise"].as<const char*>());
  //                     s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
  //                     int h = std::stoi(s.substr(0,2));
  //                     int m = std::stoi(s.substr(3,2));
  //                     id(prayer_hours)[1] = h;
  //                     id(prayer_minutes)[1] = m;
  //                   }
  //   
  //                    Doha (always AM) -- inserted after Sunrise; this is exempt from making athan
  //                   {
  //                     std::string s(doc["doha"].as<const char*>());
  //                     s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
  //                     int h = std::stoi(s.substr(0,2));
  //                     int m = std::stoi(s.substr(3,2));
  //                     id(prayer_hours)[2] = h;
  //                     id(prayer_minutes)[2] = m;
  //                   }
  //   
  //                    Dhuhr (special logic: PM if hour < 9, AM if hour > 9)
  //                   {
  //                     std::string s(doc["dhuhar"].as<const char*>());
  //                     s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
  //                     int h = std::stoi(s.substr(0,2));
  //                     int m = std::stoi(s.substr(3,2));
  //                     if (h < 9) h += 12;   PM adjustment
  //                     id(prayer_hours)[3] = h;
  //                     id(prayer_minutes)[3] = m;
  //                   }
  //   
  //                    Asr (always PM)
  //                   {
  //                     std::string s(doc["asr"].as<const char*>());
  //                     s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
  //                     int h = std::stoi(s.substr(0,2));
  //                     int m = std::stoi(s.substr(3,2));
  //                     if (h < 12) h += 12;
  //                     id(prayer_hours)[4] = h;
  //                     id(prayer_minutes)[4] = m;
  //                   }
  //   
  //                    Maghrib (always PM)
  //                   {
  //                     std::string s(doc["maghrib"].as<const char*>());
  //                     s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
  //                     int h = std::stoi(s.substr(0,2));
  //                     int m = std::stoi(s.substr(3,2));
  //                     if (h < 12) h += 12;
  //                     id(prayer_hours)[5] = h;
  //                     id(prayer_minutes)[5] = m;
  //                   }
  //   
  //                    Isha (always PM)
  //                   {
  //                     std::string s(doc["isha"].as<const char*>());
  //                     s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
  //                     int h = std::stoi(s.substr(0,2));
  //                     int m = std::stoi(s.substr(3,2));
  //                     if (h < 12) h += 12;
  //                     id(prayer_hours)[6] = h;
  //                     id(prayer_minutes)[6] = m;
  //                   }
  //   
  //                   auto now = id(sntp_time).now();
  //                   id(prayer_times_day) = now.day_of_year;
  //                   id(prayer_times_year) = now.year;
  //   
  //                   ESP_LOGI("prayer", "prayer times loaded from json");
  //                   id(log_prayers).execute();
  //                    Indicate that prayer times were successfully loaded at least once
  //                   id(loaded_prayer_times_once) = true;
  //                   ESP_LOGI("prayer", "loaded_prayer_times_once = true");
  //                 type_id: lambdaaction_id_29
  //             trigger_id: trigger_id_11
  //             automation_id: automation_id_17
  //           id: http_request_httprequestarduino_id
  //           method: GET
  //         type_id: http_request_httprequestsendaction_id_3
  //     trigger_id: trigger_id_12
  //     automation_id: automation_id_18
  //     parameters: {}
  //   - id: log_prayers
  //     mode: restart
  //     then:
  //       - lambda: !lambda |-
  //           ESP_LOGI("prayer","Prayer times for today:");
  //           ESP_LOGI("prayer","Fajr: %02d:%02d", id(prayer_hours)[0], id(prayer_minutes)[0]);
  //           ESP_LOGI("prayer","Shrouk: %02d:%02d", id(prayer_hours)[1], id(prayer_minutes)[1]);
  //           ESP_LOGI("prayer","Doha: %02d:%02d", id(prayer_hours)[2], id(prayer_minutes)[2]);
  //           ESP_LOGI("prayer","Dhuhr: %02d:%02d", id(prayer_hours)[3], id(prayer_minutes)[3]);
  //           ESP_LOGI("prayer","Asr: %02d:%02d", id(prayer_hours)[4], id(prayer_minutes)[4]);
  //           ESP_LOGI("prayer","Maghrib: %02d:%02d", id(prayer_hours)[5], id(prayer_minutes)[5]);
  //           ESP_LOGI("prayer","Isha: %02d:%02d", id(prayer_hours)[6], id(prayer_minutes)[6]);
  //         type_id: lambdaaction_id_30
  //     trigger_id: trigger_id_13
  //     automation_id: automation_id_19
  //     parameters: {}
  //   - id: Jump_to_next_prayer
  //     mode: restart
  //     then:
  //       - lambda: !lambda "auto now = id(sntp_time).now();\nif (!now.is_valid()) {\n return;\n
  //           }\nint h = now.hour;\nint m = now.minute;\n Find first prayer time still
  //           \ in the future\nfor (int i = 0; i < 7; i++) {\n  int ph = id(prayer_hours)[i];\n
  //           \  int pm = id(prayer_minutes)[i];\n  if ( (h < ph) || (h == ph && m < pm)
  //           \ ) {\n    id(next_prayer_index) = i;\n    id(next_prayer_hour)  = ph;\n 
  //           \   id(next_prayer_minute)= pm;\n    ESP_LOGI(\"prayer\", \"Next prayer: index=%d
  //           \ at %02d:%02d\", \n      i, ph, pm);\n     If the next prayer is Fajr (index
  //           \ 0), schedule \"quyam\"\n    if (i == 0) {\n      int total = ph * 60 + pm
  //           \ - 25;  25 minutes before fajr\n      if (total < 0) total += 24 * 60;\n
  //           \      id(quyam_next_hour) = total / 60;\n      id(quyam_next_minute) = total
  //           \ % 60;\n      id(quyam_triggered) = false;\n      ESP_LOGI(\"quyam\", \"
  //           Quyam scheduled at %02d:%02d (25min before fajr)\", id(quyam_next_hour), id(quyam_next_minute));\n
  //           \    }\n    return;\n  }\n}\n All prayers passed → tomorrow Fajr\nid(next_prayer_index)
  //           \ = 0;\nid(next_prayer_hour)  = id(prayer_hours)[0];\nid(next_prayer_minute)=
  //           \ id(prayer_minutes)[0];\nESP_LOGI(\"prayer\", \"Next prayer: TOMORROW FAJR
  //           \ at %02d:%02d\",\n  id(next_prayer_hour), id(next_prayer_minute));\n Schedule
  //           \ quyam 25 minutes before tomorrow's fajr\n{\n  int ph = id(next_prayer_hour);\n
  //           \  int pm = id(next_prayer_minute);\n  int total = ph * 60 + pm - 25;\n  if
  //           \ (total < 0) total += 24 * 60;\n  id(quyam_next_hour) = total / 60;\n  id(quyam_next_minute)
  //           \ = total % 60;\n  id(quyam_triggered) = false;\n  ESP_LOGI(\"quyam\", \"
  //           Quyam scheduled at %02d:%02d (25min before fajr)\", id(quyam_next_hour), id(quyam_next_minute));\n
  //           }"
  //         type_id: lambdaaction_id_31
  //     trigger_id: trigger_id_14
  //     automation_id: automation_id_20
  //     parameters: {}
  //   - id: compute_coming_prayer
  //     mode: restart
  //     then:
  //       - lambda: !lambda "auto now = id(sntp_time).now();\nif (!now.is_valid()) {\n return;\n
  //           }\nint h = now.hour;\nint m = now.minute;\n Find first prayer time still
  //           \ in the future\nfor (int i = 0; i < 7; i++) {\n  int ph = id(prayer_hours)[i];\n
  //           \  int pm = id(prayer_minutes)[i];\n  if ( (h < ph) || (h == ph && m <= pm)
  //           \ ) {\n    id(next_prayer_index) = i;\n    id(next_prayer_hour)  = ph;\n 
  //           \   id(next_prayer_minute)= pm;\n    ESP_LOGI(\"prayer\", \"Next prayer: index=%d
  //           \ at %02d:%02d\", \n      i, ph, pm);\n     If the next prayer is Fajr (index
  //           \ 0), schedule \"quyam\"\n    if (i == 0) {\n      int total = ph * 60 + pm
  //           \ - 25;  25 minutes before fajr\n      if (total < 0) total += 24 * 60;\n
  //           \      id(quyam_next_hour) = total / 60;\n      id(quyam_next_minute) = total
  //           \ % 60;\n      id(quyam_triggered) = false;\n      ESP_LOGI(\"quyam\", \"
  //           Quyam scheduled at %02d:%02d (25min before fajr)\", id(quyam_next_hour), id(quyam_next_minute));\n
  //           \    }\n    return;\n  }\n}\n All prayers passed → tomorrow Fajr\nid(next_prayer_index)
  //           \ = 0;\nid(next_prayer_hour)  = id(prayer_hours)[0];\nid(next_prayer_minute)=
  //           \ id(prayer_minutes)[0];\nESP_LOGI(\"prayer\", \"Next prayer: TOMORROW FAJR
  //           \ at %02d:%02d\",\n  id(next_prayer_hour), id(next_prayer_minute));\n Schedule
  //           \ quyam 25 minutes before tomorrow's fajr\n{\n  int ph = id(next_prayer_hour);\n
  //           \  int pm = id(next_prayer_minute);\n  int total = ph * 60 + pm - 25;\n  if
  //           \ (total < 0) total += 24 * 60;\n  id(quyam_next_hour) = total / 60;\n  id(quyam_next_minute)
  //           \ = total % 60;\n  id(quyam_triggered) = false;\n  ESP_LOGI(\"quyam\", \"
  //           Quyam scheduled at %02d:%02d (25min before fajr)\", id(quyam_next_hour), id(quyam_next_minute));\n
  //           }"
  //         type_id: lambdaaction_id_32
  //     trigger_id: trigger_id_15
  //     automation_id: automation_id_21
  //     parameters: {}
  //   - id: update_display
  //     mode: restart
  //     then:
  //       - lambda: !lambda |-
  //           id(oled).clear();
  //           auto now = id(sntp_time).now();
  //           if (!now.is_valid() && id(ui_mode)==0) {
  //             id(oled).line(0, 11, 127, 11); crossline1
  //             id(oled).line(0, 33, 127, 33); crossline2
  //             id(oled).line(0, 55, 127, 55); crossline3
  //           }
  //   
  //           if (!id(prayer_times_refreshed_at_least_once) && id(ui_mode)==0) {
  //             id(oled).line(0, 33, 127, 33); crossline2
  //             id(oled).line(0, 55, 127, 55); crossline3
  //           }
  //   
  //           if (!WiFi.isConnected()){
  //             id(oled).circle(116, 52, 10);
  //             id(oled).printf(107, 41, id(font1), "W");
  //             id(oled).line(105, 43, 125, 63);
  //           }
  //   
  //            Menu timeout: if menu active and no activity for >= 60s, exit menu
  //           if (id(ui_mode) != 0) {
  //             unsigned long last = id(ui_last_activity);
  //             if (last > 0) {
  //               unsigned long diff = millis() - last;
  //               if (diff >= 60000) {
  //                 ESP_LOGI("ui", "Menu timed out after %lu ms, returning to normal", diff);
  //                 id(ui_mode) = 0;
  //                 id(dfp).stop();
  //               }
  //             }
  //           }
  //   
  //           int hour = now.hour;
  //           int minute = now.minute;
  //   
  //           static const char* prayer_names[7] = {"Fajr", "Sunrise", "Doha", "Dhuhr", "Asr", "Maghrib", "Isha"};
  //           const char* next_prayer_name = prayer_names[id(next_prayer_index)];
  //   
  //            Month abbreviations for compact date display (Jan, Feb, ...)
  //           static const char* months[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
  //   
  //           int total_mins_to_next = id(next_prayer_hour)*60 + id(next_prayer_minute) - (hour*60 + minute);
  //           if (total_mins_to_next < 0) total_mins_to_next += 24*60;
  //           int hrs = total_mins_to_next / 60;
  //           int mins = total_mins_to_next % 60;
  //   
  //           char line1[32];
  //           char line2[32];
  //           char line3[32];
  //   
  //            If in menu, render concise menu/submenu UI
  //           if (id(ui_mode) != 0) {
  //             if (id(ui_mode) == 1) {
  //                Main menu: first line fixed, second line shows current item
  //               static const char* menu_items[7] = {"Athan","Hourly Tick","Location","Update","Volume","Cancel","Q"};
  //               id(oled).print(0, 0, id(font1), "Menu:");
  //               if (id(ui_menu_index) == 6) {
  //                 snprintf(line2, sizeof(line2), "Q: %s", (id(q_flag) ? "ON" : "OFF"));
  //               } else {
  //                 snprintf(line2, sizeof(line2), "%s", menu_items[id(ui_menu_index)]);
  //               }
  //               id(oled).print(0, 22, id(font1), line2);
  //                When Update item selected, show version info on third row
  //               if (id(ui_menu_index) == 3) {
  //                 if (id(update_check_state) == 0) {
  //                    Not checked yet: show current version only
  //                   snprintf(line3, sizeof(line3), "V%d", 1);
  //                 } else if (id(update_check_state) == 3) {
  //                   snprintf(line3, sizeof(line3), "V%d checking..", 1);
  //                 } else if (id(update_check_state) == 1) {
  //                   snprintf(line3, sizeof(line3), "V%d uptodate", 1);
  //                 } else if (id(update_check_state) == 2) {
  //                   snprintf(line3, sizeof(line3), "V%d -> V%d ?", 1, id(update_latest_version));
  //                 } else if (id(update_check_state) == 4) {
  //                   snprintf(line3, sizeof(line3), "attempting ..");
  //                 } else {
  //                   snprintf(line3, sizeof(line3), "V%d", 1);
  //                 }
  //                 id(oled).print(0, 44, id(font1), line3);
  //               }
  //             } else if (id(ui_mode) == 2) {
  //               snprintf(line1, sizeof(line1), "Athan:");
  //               id(oled).print(0, 0, id(font1), line1);
  //               snprintf(line2, sizeof(line2), "%d / 10", id(athan_index) + 1);
  //               snprintf(line3, sizeof(line3), "File: %d", 1 + id(athan_index));
  //               id(oled).print(0, 22, id(font1), line2);
  //               id(oled).print(0, 44, id(font1), line3);
  //             } else if (id(ui_mode) == 3) {
  //               snprintf(line1, sizeof(line1), "Hourly Tick:");
  //               id(oled).print(0, 0, id(font1), line1);
  //               if (id(htick_index) == 0) {
  //                 snprintf(line2, sizeof(line2), "None");
  //               } else {
  //                 snprintf(line2, sizeof(line2), "%d / 10", id(htick_index));
  //                 snprintf(line3, sizeof(line3), "File: %d", 10 + id(htick_index));
  //               }
  //               id(oled).print(0, 22, id(font1), line2);
  //               if (id(htick_index) > 0) {
  //                 id(oled).print(0, 44, id(font1), line3);
  //               }
  //             } else if (id(ui_mode) == 4) {
  //               static const char* locs[15] = {"davis","santaclara","sacramento","cairo","masjid5","masjid6","masjid7","masjid8","masjid9","masjid10","masjid11","masjid12","masjid13","masjid14","masjid15"};
  //                Location submenu: short header + location name
  //               id(oled).print(0, 0, id(font1), "Location:");
  //               snprintf(line2, sizeof(line2), "%s", locs[id(location_index)]);
  //               id(oled).print(0, 22, id(font1), line2);
  //             } else if (id(ui_mode) == 5) {
  //                Volume submenu
  //               snprintf(line1, sizeof(line1), "Volume 🔈");
  //               snprintf(line2, sizeof(line2), "%d%%", id(volume_level));
  //               id(oled).print(0, 0, id(font1), line1);
  //               id(oled).print(0, 22, id(font1), line2);
  //             }
  //             id(oled).display();
  //             return;
  //           }
  //   
  //            Normal (not in menu) display — no seconds, update once per minute
  //           if (id(athan_playing)) {
  //             id(oled).print(0, 0, id(font1), "Athan Time:");
  //             snprintf(line1, sizeof(line1), "%s prayer", prayer_names[id(current_athan_prayer_index)]);
  //             id(oled).print(0, 22, id(font1), line1);
  //              Show time and compact date (e.g. "12:34 26 Nov") on the same line
  //             snprintf(line3, sizeof(line3), "%02d:%02d  %02d%s", hour, minute, now.day_of_month, months[now.month - 1]);
  //             id(oled).print(0, 44, id(font1), line3);
  //           } else {
  //              Show time and compact date (e.g. "12:34 26 Nov") on the top line
  //             snprintf(line1, sizeof(line1), "%02d:%02d  %02d%s", hour, minute, now.day_of_month, months[now.month - 1]);
  //             snprintf(line2, sizeof(line2), "%s %02d:%02d", next_prayer_name, id(next_prayer_hour), id(next_prayer_minute));
  //             snprintf(line3, sizeof(line3), "Rem %02d:%02d", hrs, mins);
  //             id(oled).print(0, 0, id(font1), line1);
  //             id(oled).print(0, 22, id(font1), line2);
  //             id(oled).print(0, 44, id(font1), line3);
  //           }
  //   
  //           id(oled).display();
  //         type_id: lambdaaction_id_33
  //     trigger_id: trigger_id_16
  //     automation_id: automation_id_22
  //     parameters: {}
  refresh_prayer_times_if_needed = new script::RestartScript<>();
  refresh_prayer_times_if_needed->set_name(LOG_STR("refresh_prayer_times_if_needed"));
  make_athan = new script::SingleScript<>();
  make_athan->set_name(LOG_STR("make_athan"));
  perform_update = new script::SingleScript<>();
  perform_update->set_name(LOG_STR("perform_update"));
  test_script = new script::SingleScript<>();
  test_script->set_name(LOG_STR("test_script"));
  check_update_remote = new script::SingleScript<>();
  check_update_remote->set_name(LOG_STR("check_update_remote"));
  run_quyam = new script::SingleScript<>();
  run_quyam->set_name(LOG_STR("run_quyam"));
  change_location_handler = new script::SingleScript<>();
  change_location_handler->set_name(LOG_STR("change_location_handler"));
  load_prayer_times = new script::RestartScript<>();
  load_prayer_times->set_name(LOG_STR("load_prayer_times"));
  log_prayers = new script::RestartScript<>();
  log_prayers->set_name(LOG_STR("log_prayers"));
  Jump_to_next_prayer = new script::RestartScript<>();
  Jump_to_next_prayer->set_name(LOG_STR("Jump_to_next_prayer"));
  compute_coming_prayer = new script::RestartScript<>();
  compute_coming_prayer->set_name(LOG_STR("compute_coming_prayer"));
  update_display = new script::RestartScript<>();
  update_display->set_name(LOG_STR("update_display"));
  automation_id_8 = new Automation<>(refresh_prayer_times_if_needed);
  // interval:
  //   - interval: 1s
  //     then:
  //       - lambda: !lambda |-
  //           auto now = id(sntp_time).now();
  //           if (!now.is_valid()) {
  //            return;
  //           }
  //            Ensure persisted timezone is applied once when time becomes valid.
  //           if (!id(time_zone_changed_at_boot)) {
  //             ESP_LOGI("tz", "Applying persisted timezone from 1s tick: '%s'", id(selected_location_tz).c_str());
  //             id(sntp_time).set_timezone(id(selected_location_tz).c_str());
  //             id(sntp_time).update();
  //             id(time_zone_changed_at_boot) = true;
  //           }
  //           if (!id(prayer_times_refreshed_at_least_once)) {
  //             return;
  //           }
  //           int hour = now.hour;
  //           int minute = now.minute;
  //   
  //           int isha_h = id(prayer_hours)[6];
  //           int isha_min = id(prayer_minutes)[6];
  //           bool time_more_than_prayer = (hour > id(next_prayer_hour)) || (hour == id(next_prayer_hour) && minute >= id(next_prayer_minute));
  //           bool less_than_isha = (hour < isha_h) || (hour == isha_h && minute < isha_min);
  //           bool prayer_is_isha = id(next_prayer_index) == 6;
  //   
  //           if ( time_more_than_prayer && (prayer_is_isha || less_than_isha) ) {
  //                Skip making athan for Sunrise (1) and Doha (2)
  //               if (id(next_prayer_index)!=1 && id(next_prayer_index)!=2){
  //                 id(make_athan).execute();
  //                 id(current_athan_prayer_index) = id(next_prayer_index);
  //               }
  //               ESP_LOGI("prayer", "Prayer time reached: index=%d!", id(next_prayer_index));
  //               id(Jump_to_next_prayer).execute();
  //               id(update_display).execute();
  //           }
  //           if (id(q_flag)) {
  //              Only trigger once per scheduled period
  //             if (!id(quyam_triggered)) {
  //               if (id(next_prayer_index) == 0 && hour == id(quyam_next_hour) && minute == id(quyam_next_minute)) {
  //                 ESP_LOGI("quyam", "Quyam time reached -> marking triggered and executing run_quyam");
  //                 id(quyam_triggered) = true;
  //                 id(run_quyam).execute();
  //               }
  //             }
  //           }
  //         type_id: lambdaaction_id_34
  //     trigger_id: trigger_id_17
  //     automation_id: automation_id_23
  //     id: interval_intervaltrigger_id
  //     startup_delay: 0s
  //   - interval: 1min
  //     then:
  //       - lambda: !lambda |-
  //           auto now = id(sntp_time).now();
  //           if (!now.is_valid()) {
  //            id(update_display).execute();
  //           }
  //           return;
  //         type_id: lambdaaction_id_35
  //     trigger_id: trigger_id_18
  //     automation_id: automation_id_24
  //     id: interval_intervaltrigger_id_2
  //     startup_delay: 0s
  interval_intervaltrigger_id = new interval::IntervalTrigger();
  interval_intervaltrigger_id->set_component_source(LOG_STR("interval"));
  App.register_component(interval_intervaltrigger_id);
  automation_id_23 = new Automation<>(interval_intervaltrigger_id);
  // preferences:
  //   id: preferences_intervalsyncer_id
  //   flash_write_interval: 60s
  preferences_intervalsyncer_id = new preferences::IntervalSyncer();
  preferences_intervalsyncer_id->set_write_interval(60000);
  preferences_intervalsyncer_id->set_component_source(LOG_STR("preferences"));
  App.register_component(preferences_intervalsyncer_id);
  // md5:
  // socket:
  //   implementation: lwip_tcp
  // sha256:
  //   {}
  http_request_otahttprequestcomponent_id->set_parent(http_request_httprequestarduino_id);
  lambdacondition_id = new StatelessLambdaCondition<>([]() -> bool {
      #line 90 "/config/athan.yaml"
      return sntp_time->now().is_valid();
  });
  waituntilaction_id_2 = new WaitUntilAction<>(lambdacondition_id);
  waituntilaction_id_2->set_timeout_value(8000);
  waituntilaction_id_2->set_component_source(LOG_STR("wifi"));
  App.register_component(waituntilaction_id_2);
  script_scriptexecuteaction_id_2 = new script::ScriptExecuteAction<script::Script<>>(refresh_prayer_times_if_needed);
  script_scriptexecuteaction_id_2->set_args();
  automation_id_2->add_actions({lambdaaction_id_6, waituntilaction_id_2, script_scriptexecuteaction_id_2});
  binary_binarylightoutput_id->set_output(led_output);
  script_scriptexecuteaction_id_4 = new script::ScriptExecuteAction<script::Script<>>(refresh_prayer_times_if_needed);
  script_scriptexecuteaction_id_4->set_args();
  // globals:
  //   id: prayer_times_refreshed_at_least_once
  //   type: bool
  //   initial_value: 'false'
  //   restore_value: false
  prayer_times_refreshed_at_least_once = new globals::GlobalsComponent<bool>(false);
  prayer_times_refreshed_at_least_once->set_component_source(LOG_STR("globals"));
  App.register_component(prayer_times_refreshed_at_least_once);
  // globals:
  //   id: loaded_prayer_times_once
  //   type: bool
  //   initial_value: 'false'
  //   restore_value: false
  loaded_prayer_times_once = new globals::GlobalsComponent<bool>(false);
  loaded_prayer_times_once->set_component_source(LOG_STR("globals"));
  App.register_component(loaded_prayer_times_once);
  // globals:
  //   id: volume_level
  //   type: int
  //   initial_value: '50'
  //   restore_value: true
  volume_level = new globals::RestoringGlobalsComponent<int>(50);
  volume_level->set_component_source(LOG_STR("globals"));
  App.register_component(volume_level);
  volume_level->set_name_hash(3767731727UL);
  // globals:
  //   id: athan_file_index
  //   type: int
  //   initial_value: '1'
  //   restore_value: true
  athan_file_index = new globals::RestoringGlobalsComponent<int>(1);
  athan_file_index->set_component_source(LOG_STR("globals"));
  App.register_component(athan_file_index);
  athan_file_index->set_name_hash(1537973896);
  // globals:
  //   id: htick_file_index
  //   type: int
  //   initial_value: '11'
  //   restore_value: true
  htick_file_index = new globals::RestoringGlobalsComponent<int>(11);
  htick_file_index->set_component_source(LOG_STR("globals"));
  App.register_component(htick_file_index);
  htick_file_index->set_name_hash(2243663496UL);
  // globals:
  //   id: athan_playing
  //   type: bool
  //   initial_value: 'false'
  //   restore_value: false
  athan_playing = new globals::GlobalsComponent<bool>(false);
  athan_playing->set_component_source(LOG_STR("globals"));
  App.register_component(athan_playing);
  // globals:
  //   id: ui_mode
  //   type: int
  //   initial_value: '0'
  //   restore_value: false
  ui_mode = new globals::GlobalsComponent<int>(0);
  ui_mode->set_component_source(LOG_STR("globals"));
  App.register_component(ui_mode);
  // globals:
  //   id: ui_menu_index
  //   type: int
  //   initial_value: '0'
  //   restore_value: false
  ui_menu_index = new globals::GlobalsComponent<int>(0);
  ui_menu_index->set_component_source(LOG_STR("globals"));
  App.register_component(ui_menu_index);
  // globals:
  //   id: athan_index
  //   type: int
  //   initial_value: '0'
  //   restore_value: false
  athan_index = new globals::GlobalsComponent<int>(0);
  athan_index->set_component_source(LOG_STR("globals"));
  App.register_component(athan_index);
  // globals:
  //   id: htick_index
  //   type: int
  //   initial_value: '0'
  //   restore_value: false
  htick_index = new globals::GlobalsComponent<int>(0);
  htick_index->set_component_source(LOG_STR("globals"));
  App.register_component(htick_index);
  // globals:
  //   id: location_index
  //   type: int
  //   initial_value: '0'
  //   restore_value: false
  location_index = new globals::GlobalsComponent<int>(0);
  location_index->set_component_source(LOG_STR("globals"));
  App.register_component(location_index);
  // globals:
  //   id: selected_location_index
  //   type: int
  //   initial_value: '0'
  //   restore_value: true
  selected_location_index = new globals::RestoringGlobalsComponent<int>(0);
  selected_location_index->set_component_source(LOG_STR("globals"));
  App.register_component(selected_location_index);
  selected_location_index->set_name_hash(1646665982);
  // globals:
  //   id: selected_location_tz
  //   type: std::string
  //   initial_value: '"America/Los_Angeles"'
  //   restore_value: true
  selected_location_tz = new globals::RestoringGlobalStringComponent<std::string, 64>("America/Los_Angeles");
  selected_location_tz->set_component_source(LOG_STR("globals"));
  App.register_component(selected_location_tz);
  selected_location_tz->set_name_hash(2684604028UL);
  // globals:
  //   id: time_zone_changed_at_boot
  //   type: bool
  //   initial_value: 'false'
  //   restore_value: false
  time_zone_changed_at_boot = new globals::GlobalsComponent<bool>(false);
  time_zone_changed_at_boot->set_component_source(LOG_STR("globals"));
  App.register_component(time_zone_changed_at_boot);
  // globals:
  //   id: ui_last_activity
  //   type: int
  //   initial_value: '0'
  //   restore_value: false
  ui_last_activity = new globals::GlobalsComponent<int>(0);
  ui_last_activity->set_component_source(LOG_STR("globals"));
  App.register_component(ui_last_activity);
  // globals:
  //   id: current_athan_prayer_index
  //   type: int
  //   initial_value: '0'
  //   restore_value: false
  current_athan_prayer_index = new globals::GlobalsComponent<int>(0);
  current_athan_prayer_index->set_component_source(LOG_STR("globals"));
  App.register_component(current_athan_prayer_index);
  // globals:
  //   id: prayer_hours
  //   type: int[7]
  //   initial_value: '{5, 6, 7, 12, 15, 17, 18}'
  //   restore_value: true
  prayer_hours = new globals::RestoringGlobalsComponent<int[7]>({5, 6, 7, 12, 15, 17, 18});
  prayer_hours->set_component_source(LOG_STR("globals"));
  App.register_component(prayer_hours);
  prayer_hours->set_name_hash(3565459995UL);
  // globals:
  //   id: prayer_minutes
  //   type: int[7]
  //   initial_value: '{42, 13, 39, 15, 47, 12, 28}'
  //   restore_value: true
  prayer_minutes = new globals::RestoringGlobalsComponent<int[7]>({42, 13, 39, 15, 47, 12, 28});
  prayer_minutes->set_component_source(LOG_STR("globals"));
  App.register_component(prayer_minutes);
  prayer_minutes->set_name_hash(3617028472UL);
  // globals:
  //   id: prayer_times_day
  //   type: int
  //   initial_value: '0'
  //   restore_value: true
  prayer_times_day = new globals::RestoringGlobalsComponent<int>(0);
  prayer_times_day->set_component_source(LOG_STR("globals"));
  App.register_component(prayer_times_day);
  prayer_times_day->set_name_hash(2059803996);
  // globals:
  //   id: prayer_times_year
  //   type: int
  //   initial_value: '0'
  //   restore_value: true
  prayer_times_year = new globals::RestoringGlobalsComponent<int>(0);
  prayer_times_year->set_component_source(LOG_STR("globals"));
  App.register_component(prayer_times_year);
  prayer_times_year->set_name_hash(3754207812UL);
  // globals:
  //   id: next_prayer_index
  //   type: int
  //   initial_value: '0'
  //   restore_value: true
  next_prayer_index = new globals::RestoringGlobalsComponent<int>(0);
  next_prayer_index->set_component_source(LOG_STR("globals"));
  App.register_component(next_prayer_index);
  next_prayer_index->set_name_hash(2604929748UL);
  // globals:
  //   id: next_prayer_hour
  //   type: int
  //   initial_value: '0'
  //   restore_value: true
  next_prayer_hour = new globals::RestoringGlobalsComponent<int>(0);
  next_prayer_hour->set_component_source(LOG_STR("globals"));
  App.register_component(next_prayer_hour);
  next_prayer_hour->set_name_hash(1216597685);
  // globals:
  //   id: next_prayer_minute
  //   type: int
  //   initial_value: '0'
  //   restore_value: true
  next_prayer_minute = new globals::RestoringGlobalsComponent<int>(0);
  next_prayer_minute->set_component_source(LOG_STR("globals"));
  App.register_component(next_prayer_minute);
  next_prayer_minute->set_name_hash(3616451039UL);
  // globals:
  //   id: quyam_next_hour
  //   type: int
  //   initial_value: '0'
  //   restore_value: true
  quyam_next_hour = new globals::RestoringGlobalsComponent<int>(0);
  quyam_next_hour->set_component_source(LOG_STR("globals"));
  App.register_component(quyam_next_hour);
  quyam_next_hour->set_name_hash(1755643533);
  // globals:
  //   id: quyam_next_minute
  //   type: int
  //   initial_value: '0'
  //   restore_value: true
  quyam_next_minute = new globals::RestoringGlobalsComponent<int>(0);
  quyam_next_minute->set_component_source(LOG_STR("globals"));
  App.register_component(quyam_next_minute);
  quyam_next_minute->set_name_hash(2498223180UL);
  // globals:
  //   id: quyam_triggered
  //   type: bool
  //   initial_value: 'false'
  //   restore_value: false
  quyam_triggered = new globals::GlobalsComponent<bool>(false);
  quyam_triggered->set_component_source(LOG_STR("globals"));
  App.register_component(quyam_triggered);
  // globals:
  //   id: q_flag
  //   type: bool
  //   initial_value: 'false'
  //   restore_value: true
  q_flag = new globals::RestoringGlobalsComponent<bool>(false);
  q_flag->set_component_source(LOG_STR("globals"));
  App.register_component(q_flag);
  q_flag->set_name_hash(4241185489UL);
  // globals:
  //   id: q_select_count
  //   type: int
  //   initial_value: '0'
  //   restore_value: false
  q_select_count = new globals::GlobalsComponent<int>(0);
  q_select_count->set_component_source(LOG_STR("globals"));
  App.register_component(q_select_count);
  // globals:
  //   id: update_latest_version
  //   type: int
  //   initial_value: '0'
  //   restore_value: false
  update_latest_version = new globals::GlobalsComponent<int>(0);
  update_latest_version->set_component_source(LOG_STR("globals"));
  App.register_component(update_latest_version);
  // globals:
  //   id: update_check_state
  //   type: int
  //   initial_value: '0'
  //   restore_value: false
  update_check_state = new globals::GlobalsComponent<int>(0);
  update_check_state->set_component_source(LOG_STR("globals"));
  App.register_component(update_check_state);
  // globals:
  //   id: update_url
  //   type: std::string
  //   initial_value: '""'
  //   restore_value: false
  update_url = new globals::GlobalsComponent<std::string>("");
  update_url->set_component_source(LOG_STR("globals"));
  App.register_component(update_url);
  lambdaaction_id_13 = new StatelessLambdaAction<>([]() -> void {
      #line 542 "/config/athan.yaml"
      auto now = sntp_time->now();
      if (!now.is_valid()) {
       return;
      }
      if (!loaded_prayer_times_once->value()) {
        ESP_LOGI("prayer","Prayer times never loaded yet — loading now");
        load_prayer_times->execute();
      }
      int current_day = now.day_of_year;
      int current_year = now.year;
      if (prayer_times_day->value() != current_day || prayer_times_year->value() != current_year) {
        ESP_LOGI("prayer","Prayer times are outdated, reloading...");
        loaded_prayer_times_once->value() = false;
        prayer_times_refreshed_at_least_once->value() = false;
        load_prayer_times->execute();
      } else {
        prayer_times_refreshed_at_least_once->value() = true;
      }
      compute_coming_prayer->execute();
      log_prayers->execute();
      update_display->execute();
  });
  automation_id_8->add_actions({lambdaaction_id_13});
  automation_id_9 = new Automation<>(make_athan);
  lambdaaction_id_14 = new StatelessLambdaAction<>([]() -> void {
      ESP_LOGD("main", "Athan Calling!");
  });
  lambdaaction_id_15 = new StatelessLambdaAction<>([]() -> void {
      #line 568 "/config/athan.yaml"
      athan_playing->value() = true;
      dfp->stop();
      delay(250);
      dfp->play_file(athan_file_index->value());
  });
  light_lightcontrolaction_id_10 = new light::LightControlAction<>(builtin_led);
  light_lightcontrolaction_id_10->set_state(true);
  delayaction_id_9 = new DelayAction<>();
  delayaction_id_9->set_component_source(LOG_STR("script"));
  App.register_component(delayaction_id_9);
  delayaction_id_9->set_delay(300000);
  light_lightcontrolaction_id_11 = new light::LightControlAction<>(builtin_led);
  light_lightcontrolaction_id_11->set_state(false);
  lambdaaction_id_16 = new StatelessLambdaAction<>([]() -> void {
      #line 576 "/config/athan.yaml"
      athan_playing->value() = false;
  });
  automation_id_9->add_actions({lambdaaction_id_14, lambdaaction_id_15, light_lightcontrolaction_id_10, delayaction_id_9, light_lightcontrolaction_id_11, lambdaaction_id_16});
  automation_id_10 = new Automation<>(perform_update);
  lambdaaction_id_17 = new StatelessLambdaAction<>([]() -> void {
      #line 582 "/config/athan.yaml"
       
      if (update_url->value().empty()) {
        ESP_LOGE("update", "No update_url cached, aborting perform_update");
        update_check_state->value() = 0;
        update_display->execute();
        ui_mode->value() = 0;
        return;
      }
       
      update_check_state->value() = 4;
      update_display->execute();
  });
  http_request_otahttprequestcomponentflashaction_id = new http_request::OtaHttpRequestComponentFlashAction<>(http_request_otahttprequestcomponent_id);
  http_request_otahttprequestcomponentflashaction_id->set_md5_url([]() -> std::string {
      #line 598 "/config/athan.yaml"
      std::string base = update_url->value();
      return base + ".md5";
  });
  http_request_otahttprequestcomponentflashaction_id->set_url([]() -> std::string {
      #line 595 "/config/athan.yaml"
      std::string base = update_url->value();
      return  base + ".bin";
  });
  lambdaaction_id_18 = new StatelessLambdaAction<>([]() -> void {
      #line 601 "/config/athan.yaml"
       
      update_check_state->value() = 0;
      ui_mode->value() = 0;
      update_display->execute();
  });
  automation_id_10->add_actions({lambdaaction_id_17, http_request_otahttprequestcomponentflashaction_id, lambdaaction_id_18});
  automation_id_11 = new Automation<>(test_script);
  lambdaaction_id_19 = new StatelessLambdaAction<>([]() -> void {
      #line 610 "/config/athan.yaml"
       
      return;
  });
  automation_id_11->add_actions({lambdaaction_id_19});
  automation_id_13 = new Automation<>(check_update_remote);
  lambdaaction_id_20 = new StatelessLambdaAction<>([]() -> void {
      ESP_LOGD("main", "Starting remote update check");
  });
  http_request_httprequestsendaction_id = new http_request::HttpRequestSendAction<>(http_request_httprequestarduino_id);
  http_request_httprequestsendaction_id->set_url("http://raw.githack.com/et7ad/esp_athan/master/docs/firmwareinfo/latest.json");
  http_request_httprequestsendaction_id->set_method("GET");
  http_request_httprequestsendaction_id->set_max_response_buffer_size(1024);
  automation_id_12 = new Automation<std::shared_ptr<http_request::HttpContainer>>(http_request_httprequestsendaction_id->get_success_trigger());
  lambdaaction_id_21 = new StatelessLambdaAction<std::shared_ptr<http_request::HttpContainer>>([](std::shared_ptr<http_request::HttpContainer> response) -> void {
      #line 623 "/config/athan.yaml"
      ESP_LOGI("update", "Reading latest.json response...");
      std::string json_text;
      char buf[128];
      int len;
      int total_bytes = 0;
      const int max_bytes = 1024;
      while ((len = response->read((uint8_t*)buf, sizeof(buf))) > 0) {
        if (total_bytes + len > max_bytes) len = max_bytes - total_bytes;
        json_text.append(buf, len);
        total_bytes += len;
        if (total_bytes >= max_bytes) break;
      }
      
      if (total_bytes == 0) {
        ESP_LOGE("update", "Empty latest.json response");
        update_check_state->value() = 0;
        update_display->execute();
        return;
      }
      
      int start = json_text.find('{');
      if (start > 0) json_text.erase(0, start);
      int end = json_text.rfind('}');
      if (end != -1 && end + 1 < json_text.size()) json_text.erase(end + 1);
      
      JsonDocument doc;
      auto err = deserializeJson(doc, json_text);
      if (err) {
        ESP_LOGE("update", "JSON parse failed: %s", err.c_str());
        update_check_state->value() = 0;
        update_display->execute();
        return;
      }
      
      if (!doc["latest_version"].is<int>()) {
        ESP_LOGE("update", "latest_version missing or not an int in JSON");
        update_check_state->value() = 0;
        update_display->execute();
        return;
      }
      
      int latest = doc["latest_version"].as<int>();
      update_latest_version->value() = latest;
      if (latest <= 1) {
        update_check_state->value() = 1;  
        ESP_LOGI("update", "Device up-to-date: %d", latest);
        update_display->execute();
        return;
      }
       
      std::string fw_url;
      if (!doc["url"].is<const char*>()) {
        ESP_LOGE("update", "No url provided in latest.json");
        update_check_state->value() = 0;
        update_display->execute();
        ui_mode->value() = 0;
        return;
      }
      fw_url = doc["url"].as<const char*>();
      if (fw_url.empty()) {
        ESP_LOGE("update", "Empty url in latest.json");
        update_check_state->value() = 0;
        update_display->execute();
        ui_mode->value() = 0;
        return;
      }
      update_url->value() = fw_url;
      update_check_state->value() = 2;  
      ESP_LOGI("update", "Update available: %d -> %d, url=%s", 1, latest, fw_url.c_str());
      update_display->execute();
  });
  automation_id_12->add_actions({lambdaaction_id_21});
  automation_id_13->add_actions({lambdaaction_id_20, http_request_httprequestsendaction_id});
  automation_id_14 = new Automation<>(run_quyam);
  lambdaaction_id_22 = new StatelessLambdaAction<>([]() -> void {
      #line 696 "/config/athan.yaml"
      quyam_triggered->value() = true;
  });
  lambdacondition_id_3 = new StatelessLambdaCondition<>([]() -> bool {
      #line 699 "/config/athan.yaml"
      return q_flag->value();
  });
  ifaction_id_2 = new IfAction<>(lambdacondition_id_3);
  lambdaaction_id_23 = new StatelessLambdaAction<>([]() -> void {
      ESP_LOGD("main", "Quyam starting (Q flag is ON)");
  });
  switch__turnonaction_id_2 = new switch_::TurnOnAction<>(external_relay);
  lambdaaction_id_24 = new StatelessLambdaAction<>([]() -> void {
      #line 703 "/config/athan.yaml"
      dfp->play_file(25);
  });
  delayaction_id_10 = new DelayAction<>();
  delayaction_id_10->set_component_source(LOG_STR("script"));
  App.register_component(delayaction_id_10);
  delayaction_id_10->set_delay(900000);
  switch__turnoffaction_id = new switch_::TurnOffAction<>(external_relay);
  ifaction_id_2->add_then({lambdaaction_id_23, switch__turnonaction_id_2, lambdaaction_id_24, delayaction_id_10, switch__turnoffaction_id});
  lambdaaction_id_25 = new StatelessLambdaAction<>([]() -> void {
      ESP_LOGD("main", "Q flag is OFF \342\200\224 skipping Quyam actions");
  });
  ifaction_id_2->add_else({lambdaaction_id_25});
  automation_id_14->add_actions({lambdaaction_id_22, ifaction_id_2});
  automation_id_16 = new Automation<>(change_location_handler);
  lambdaaction_id_26 = new StatelessLambdaAction<>([]() -> void {
      ESP_LOGD("main", "Attempting to fetch timezone for previewed location");
  });
  http_request_httprequestsendaction_id_2 = new http_request::HttpRequestSendAction<>(http_request_httprequestarduino_id);
  http_request_httprequestsendaction_id_2->set_url([]() -> std::string {
      #line 717 "/config/athan.yaml"
      char u[256];
      static const char* locs[15] = {"davis","santaclara","sacramento","cairo","masjid5","masjid6","masjid7","masjid8","masjid9","masjid10","masjid11","masjid12","masjid13","masjid14","masjid15"};
      int li = location_index->value();
      if (li < 0 || li > 14) li = 0;
      const char* loc = locs[li];
      snprintf(u, sizeof(u),
        "http://raw.githack.com/et7ad/esp_athan/master/docs/timezones/%s.json",
        loc);
      ESP_LOGI("tz", "TZ URL = %s", u);
      return std::string(u);
  });
  http_request_httprequestsendaction_id_2->set_method("GET");
  http_request_httprequestsendaction_id_2->set_max_response_buffer_size(512);
  automation_id_15 = new Automation<std::shared_ptr<http_request::HttpContainer>>(http_request_httprequestsendaction_id_2->get_success_trigger());
  lambdaaction_id_27 = new StatelessLambdaAction<std::shared_ptr<http_request::HttpContainer>>([](std::shared_ptr<http_request::HttpContainer> response) -> void {
      #line 732 "/config/athan.yaml"
      ESP_LOGI("tz", "Reading timezone response...");
      
      std::string json_text;
      char buf[128];
      int len;
      int total_bytes = 0;
      const int max_bytes = 512;
      
      while ((len = response->read((uint8_t*)buf, sizeof(buf))) > 0) {
        if (total_bytes + len > max_bytes) len = max_bytes - total_bytes;
        json_text.append(buf, len);
        total_bytes += len;
        if (total_bytes >= max_bytes) break;
      }
      
      if (total_bytes == 0) {
        ESP_LOGE("tz", "Empty timezone response");
        ui_mode->value() = 0;
        update_display->execute();
        return;
      }
      
      int start = json_text.find('{');
      if (start > 0) json_text.erase(0, start);
      int end = json_text.rfind('}');
      if (end != -1 && end + 1 < json_text.size()) json_text.erase(end + 1);
      
      JsonDocument doc;
      auto err = deserializeJson(doc, json_text);
      if (err) {
        ESP_LOGE("tz", "JSON parse failed: %s", err.c_str());
        ui_mode->value() = 0;
        update_display->execute();
        return;
      }
      
      if (!doc["TZ"].is<const char*>()) {
        ESP_LOGE("tz", "TZ key missing or invalid");
        ui_mode->value() = 0;
        update_display->execute();
        return;
      }
      
      std::string tz(doc["TZ"].as<const char*>());
      if (tz.size() == 0) {
        ESP_LOGE("tz", "TZ value empty");
        ui_mode->value() = 0;
        update_display->execute();
        return;
      }
      
       
      selected_location_tz->value() = tz;
       
      ESP_LOGI("tz", "Setting system timezone to '%s'", selected_location_tz->value().c_str());
      sntp_time->set_timezone(selected_location_tz->value().c_str());
      sntp_time->update();
      selected_location_index->value() = location_index->value();
      prayer_times_day->value() = -1;
      loaded_prayer_times_once->value() = false;
      prayer_times_refreshed_at_least_once->value() = false;
      refresh_prayer_times_if_needed->execute();
      ESP_LOGI("tz", "Applied new timezone '%s' and location index %d", tz.c_str(), selected_location_index->value());
      update_display->execute();
  });
  automation_id_15->add_actions({lambdaaction_id_27});
  lambdaaction_id_28 = new StatelessLambdaAction<>([]() -> void {
      #line 797 "/config/athan.yaml"
      ui_mode->value() = 0;
      update_display->execute();
  });
  automation_id_16->add_actions({lambdaaction_id_26, http_request_httprequestsendaction_id_2, lambdaaction_id_28});
  automation_id_18 = new Automation<>(load_prayer_times);
  http_request_httprequestsendaction_id_3 = new http_request::HttpRequestSendAction<>(http_request_httprequestarduino_id);
  http_request_httprequestsendaction_id_3->set_url([]() -> std::string {
      #line 805 "/config/athan.yaml"
      auto now = sntp_time->now();
      int year = now.year;
      int day  = now.day_of_year;
      
      char u[256];
      static const char* locs[15] = {"davis","santaclara","sacramento","cairo","masjid5","masjid6","masjid7","masjid8","masjid9","masjid10","masjid11","masjid12","masjid13","masjid14","masjid15"};
      int li = selected_location_index->value();
      if (li < 0 || li > 14) li = 0;
      const char* loc = locs[li];
      snprintf(u, sizeof(u),
        "http://raw.githack.com/et7ad/esp_athan/master/docs/athantimes/%s/%d/%03d.json",
        loc, year, day);
      
      ESP_LOGI("prayer", "URL = %s", u);
      return std::string(u);
  });
  http_request_httprequestsendaction_id_3->set_method("GET");
  http_request_httprequestsendaction_id_3->set_max_response_buffer_size(4096);
  automation_id_17 = new Automation<std::shared_ptr<http_request::HttpContainer>>(http_request_httprequestsendaction_id_3->get_success_trigger());
  lambdaaction_id_29 = new StatelessLambdaAction<std::shared_ptr<http_request::HttpContainer>>([](std::shared_ptr<http_request::HttpContainer> response) -> void {
      #line 825 "/config/athan.yaml"
      ESP_LOGI("prayer", "Reading response safely...");
      
      std::string json_text;
      char buf[128];
      int len;
      int total_bytes = 0;
      const int max_bytes = 4096;   
      
       
      while ((len = response->read((uint8_t*)buf, sizeof(buf))) > 0) {
         
        if (total_bytes + len > max_bytes) {
          len = max_bytes - total_bytes;
        }
        json_text.append(buf, len);
        total_bytes += len;
      
        if (total_bytes >= max_bytes) {
          ESP_LOGW("prayer", "Reached max read bytes (%d), stopping", max_bytes);
          break;
        }
      }
      
      ESP_LOGI("prayer", "JSON size = %d bytes", total_bytes);
      
      if (total_bytes == 0) {
        ESP_LOGE("prayer", "No data received, skipping parse");
        return;
      }
      
       
      int start = json_text.find('{');
      if (start > 0) json_text.erase(0, start);
      
       
      int end = json_text.rfind('}');
      if (end != -1 && end + 1 < json_text.size())
        json_text.erase(end + 1);
      
      JsonDocument doc;   
      auto err = deserializeJson(doc, json_text);
      if (err) {
        ESP_LOGE("prayer", "JSON parse failed: %s", err.c_str());
        return;
      }
      
       
      {
        std::string s(doc["fajr"].as<const char*>());   
        s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
        int h = std::stoi(s.substr(0,2));
        int m = std::stoi(s.substr(3,2));
        prayer_hours->value()[0] = h;     
        prayer_minutes->value()[0] = m;   
      }
      
       
      {
        std::string s(doc["sunrise"].as<const char*>());
        s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
        int h = std::stoi(s.substr(0,2));
        int m = std::stoi(s.substr(3,2));
        prayer_hours->value()[1] = h;
        prayer_minutes->value()[1] = m;
      }
      
       
      {
        std::string s(doc["doha"].as<const char*>());
        s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
        int h = std::stoi(s.substr(0,2));
        int m = std::stoi(s.substr(3,2));
        prayer_hours->value()[2] = h;
        prayer_minutes->value()[2] = m;
      }
      
       
      {
        std::string s(doc["dhuhar"].as<const char*>());
        s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
        int h = std::stoi(s.substr(0,2));
        int m = std::stoi(s.substr(3,2));
        if (h < 9) h += 12;   
        prayer_hours->value()[3] = h;
        prayer_minutes->value()[3] = m;
      }
      
       
      {
        std::string s(doc["asr"].as<const char*>());
        s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
        int h = std::stoi(s.substr(0,2));
        int m = std::stoi(s.substr(3,2));
        if (h < 12) h += 12;
        prayer_hours->value()[4] = h;
        prayer_minutes->value()[4] = m;
      }
      
       
      {
        std::string s(doc["maghrib"].as<const char*>());
        s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
        int h = std::stoi(s.substr(0,2));
        int m = std::stoi(s.substr(3,2));
        if (h < 12) h += 12;
        prayer_hours->value()[5] = h;
        prayer_minutes->value()[5] = m;
      }
      
       
      {
        std::string s(doc["isha"].as<const char*>());
        s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
        int h = std::stoi(s.substr(0,2));
        int m = std::stoi(s.substr(3,2));
        if (h < 12) h += 12;
        prayer_hours->value()[6] = h;
        prayer_minutes->value()[6] = m;
      }
      
      auto now = sntp_time->now();
      prayer_times_day->value() = now.day_of_year;
      prayer_times_year->value() = now.year;
      
      ESP_LOGI("prayer", "prayer times loaded from json");
      log_prayers->execute();
       
      loaded_prayer_times_once->value() = true;
      ESP_LOGI("prayer", "loaded_prayer_times_once = true");
  });
  automation_id_17->add_actions({lambdaaction_id_29});
  automation_id_18->add_actions({http_request_httprequestsendaction_id_3});
  automation_id_19 = new Automation<>(log_prayers);
  lambdaaction_id_30 = new StatelessLambdaAction<>([]() -> void {
      #line 958 "/config/athan.yaml"
      ESP_LOGI("prayer","Prayer times for today:");
      ESP_LOGI("prayer","Fajr: %02d:%02d", prayer_hours->value()[0], prayer_minutes->value()[0]);
      ESP_LOGI("prayer","Shrouk: %02d:%02d", prayer_hours->value()[1], prayer_minutes->value()[1]);
      ESP_LOGI("prayer","Doha: %02d:%02d", prayer_hours->value()[2], prayer_minutes->value()[2]);
      ESP_LOGI("prayer","Dhuhr: %02d:%02d", prayer_hours->value()[3], prayer_minutes->value()[3]);
      ESP_LOGI("prayer","Asr: %02d:%02d", prayer_hours->value()[4], prayer_minutes->value()[4]);
      ESP_LOGI("prayer","Maghrib: %02d:%02d", prayer_hours->value()[5], prayer_minutes->value()[5]);
      ESP_LOGI("prayer","Isha: %02d:%02d", prayer_hours->value()[6], prayer_minutes->value()[6]);
  });
  automation_id_19->add_actions({lambdaaction_id_30});
  automation_id_20 = new Automation<>(Jump_to_next_prayer);
  lambdaaction_id_31 = new StatelessLambdaAction<>([]() -> void {
      #line 971 "/config/athan.yaml"
      auto now = sntp_time->now();
      if (!now.is_valid()) {
       return;
      }
      int h = now.hour;
      int m = now.minute;
       
      for (int i = 0; i < 7; i++) {
        int ph = prayer_hours->value()[i];
        int pm = prayer_minutes->value()[i];
        if ( (h < ph) || (h == ph && m < pm) ) {
          next_prayer_index->value() = i;
          next_prayer_hour->value()  = ph;
          next_prayer_minute->value()= pm;
          ESP_LOGI("prayer", "Next prayer: index=%d at %02d:%02d", 
            i, ph, pm);
           
          if (i == 0) {
            int total = ph * 60 + pm - 25;  
            if (total < 0) total += 24 * 60;
            quyam_next_hour->value() = total / 60;
            quyam_next_minute->value() = total % 60;
            quyam_triggered->value() = false;
            ESP_LOGI("quyam", "Quyam scheduled at %02d:%02d (25min before fajr)", quyam_next_hour->value(), quyam_next_minute->value());
          }
          return;
        }
      }
       
      next_prayer_index->value() = 0;
      next_prayer_hour->value()  = prayer_hours->value()[0];
      next_prayer_minute->value()= prayer_minutes->value()[0];
      ESP_LOGI("prayer", "Next prayer: TOMORROW FAJR at %02d:%02d",
        next_prayer_hour->value(), next_prayer_minute->value());
       
      {
        int ph = next_prayer_hour->value();
        int pm = next_prayer_minute->value();
        int total = ph * 60 + pm - 25;
        if (total < 0) total += 24 * 60;
        quyam_next_hour->value() = total / 60;
        quyam_next_minute->value() = total % 60;
        quyam_triggered->value() = false;
        ESP_LOGI("quyam", "Quyam scheduled at %02d:%02d (25min before fajr)", quyam_next_hour->value(), quyam_next_minute->value());
      }
  });
  automation_id_20->add_actions({lambdaaction_id_31});
  automation_id_21 = new Automation<>(compute_coming_prayer);
  lambdaaction_id_32 = new StatelessLambdaAction<>([]() -> void {
      #line 1020 "/config/athan.yaml"
      auto now = sntp_time->now();
      if (!now.is_valid()) {
       return;
      }
      int h = now.hour;
      int m = now.minute;
       
      for (int i = 0; i < 7; i++) {
        int ph = prayer_hours->value()[i];
        int pm = prayer_minutes->value()[i];
        if ( (h < ph) || (h == ph && m <= pm) ) {
          next_prayer_index->value() = i;
          next_prayer_hour->value()  = ph;
          next_prayer_minute->value()= pm;
          ESP_LOGI("prayer", "Next prayer: index=%d at %02d:%02d", 
            i, ph, pm);
           
          if (i == 0) {
            int total = ph * 60 + pm - 25;  
            if (total < 0) total += 24 * 60;
            quyam_next_hour->value() = total / 60;
            quyam_next_minute->value() = total % 60;
            quyam_triggered->value() = false;
            ESP_LOGI("quyam", "Quyam scheduled at %02d:%02d (25min before fajr)", quyam_next_hour->value(), quyam_next_minute->value());
          }
          return;
        }
      }
       
      next_prayer_index->value() = 0;
      next_prayer_hour->value()  = prayer_hours->value()[0];
      next_prayer_minute->value()= prayer_minutes->value()[0];
      ESP_LOGI("prayer", "Next prayer: TOMORROW FAJR at %02d:%02d",
        next_prayer_hour->value(), next_prayer_minute->value());
       
      {
        int ph = next_prayer_hour->value();
        int pm = next_prayer_minute->value();
        int total = ph * 60 + pm - 25;
        if (total < 0) total += 24 * 60;
        quyam_next_hour->value() = total / 60;
        quyam_next_minute->value() = total % 60;
        quyam_triggered->value() = false;
        ESP_LOGI("quyam", "Quyam scheduled at %02d:%02d (25min before fajr)", quyam_next_hour->value(), quyam_next_minute->value());
      }
  });
  automation_id_21->add_actions({lambdaaction_id_32});
  automation_id_22 = new Automation<>(update_display);
  lambdaaction_id_33 = new StatelessLambdaAction<>([]() -> void {
      #line 1070 "/config/athan.yaml"
      oled->clear();
      auto now = sntp_time->now();
      if (!now.is_valid() && ui_mode->value()==0) {
        oled->line(0, 11, 127, 11);  
        oled->line(0, 33, 127, 33);  
        oled->line(0, 55, 127, 55);  
      }
      
      if (!prayer_times_refreshed_at_least_once->value() && ui_mode->value()==0) {
        oled->line(0, 33, 127, 33);  
        oled->line(0, 55, 127, 55);  
      }
      
      if (!WiFi.isConnected()){
        oled->circle(116, 52, 10);
        oled->printf(107, 41, font1, "W");
        oled->line(105, 43, 125, 63);
      }
      
       
      if (ui_mode->value() != 0) {
        unsigned long last = ui_last_activity->value();
        if (last > 0) {
          unsigned long diff = millis() - last;
          if (diff >= 60000) {
            ESP_LOGI("ui", "Menu timed out after %lu ms, returning to normal", diff);
            ui_mode->value() = 0;
            dfp->stop();
          }
        }
      }
      
      int hour = now.hour;
      int minute = now.minute;
      
      static const char* prayer_names[7] = {"Fajr", "Sunrise", "Doha", "Dhuhr", "Asr", "Maghrib", "Isha"};
      const char* next_prayer_name = prayer_names[next_prayer_index->value()];
      
       
      static const char* months[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
      
      int total_mins_to_next = next_prayer_hour->value()*60 + next_prayer_minute->value() - (hour*60 + minute);
      if (total_mins_to_next < 0) total_mins_to_next += 24*60;
      int hrs = total_mins_to_next / 60;
      int mins = total_mins_to_next % 60;
      
      char line1[32];
      char line2[32];
      char line3[32];
      
       
      if (ui_mode->value() != 0) {
        if (ui_mode->value() == 1) {
           
          static const char* menu_items[7] = {"Athan","Hourly Tick","Location","Update","Volume","Cancel","Q"};
          oled->print(0, 0, font1, "Menu:");
          if (ui_menu_index->value() == 6) {
            snprintf(line2, sizeof(line2), "Q: %s", (q_flag->value() ? "ON" : "OFF"));
          } else {
            snprintf(line2, sizeof(line2), "%s", menu_items[ui_menu_index->value()]);
          }
          oled->print(0, 22, font1, line2);
           
          if (ui_menu_index->value() == 3) {
            if (update_check_state->value() == 0) {
               
              snprintf(line3, sizeof(line3), "V%d", 1);
            } else if (update_check_state->value() == 3) {
              snprintf(line3, sizeof(line3), "V%d checking..", 1);
            } else if (update_check_state->value() == 1) {
              snprintf(line3, sizeof(line3), "V%d uptodate", 1);
            } else if (update_check_state->value() == 2) {
              snprintf(line3, sizeof(line3), "V%d -> V%d ?", 1, update_latest_version->value());
            } else if (update_check_state->value() == 4) {
              snprintf(line3, sizeof(line3), "attempting ..");
            } else {
              snprintf(line3, sizeof(line3), "V%d", 1);
            }
            oled->print(0, 44, font1, line3);
          }
        } else if (ui_mode->value() == 2) {
          snprintf(line1, sizeof(line1), "Athan:");
          oled->print(0, 0, font1, line1);
          snprintf(line2, sizeof(line2), "%d / 10", athan_index->value() + 1);
          snprintf(line3, sizeof(line3), "File: %d", 1 + athan_index->value());
          oled->print(0, 22, font1, line2);
          oled->print(0, 44, font1, line3);
        } else if (ui_mode->value() == 3) {
          snprintf(line1, sizeof(line1), "Hourly Tick:");
          oled->print(0, 0, font1, line1);
          if (htick_index->value() == 0) {
            snprintf(line2, sizeof(line2), "None");
          } else {
            snprintf(line2, sizeof(line2), "%d / 10", htick_index->value());
            snprintf(line3, sizeof(line3), "File: %d", 10 + htick_index->value());
          }
          oled->print(0, 22, font1, line2);
          if (htick_index->value() > 0) {
            oled->print(0, 44, font1, line3);
          }
        } else if (ui_mode->value() == 4) {
          static const char* locs[15] = {"davis","santaclara","sacramento","cairo","masjid5","masjid6","masjid7","masjid8","masjid9","masjid10","masjid11","masjid12","masjid13","masjid14","masjid15"};
           
          oled->print(0, 0, font1, "Location:");
          snprintf(line2, sizeof(line2), "%s", locs[location_index->value()]);
          oled->print(0, 22, font1, line2);
        } else if (ui_mode->value() == 5) {
           
          snprintf(line1, sizeof(line1), "Volume 🔈");
          snprintf(line2, sizeof(line2), "%d%%", volume_level->value());
          oled->print(0, 0, font1, line1);
          oled->print(0, 22, font1, line2);
        }
        oled->display();
        return;
      }
      
       
      if (athan_playing->value()) {
        oled->print(0, 0, font1, "Athan Time:");
        snprintf(line1, sizeof(line1), "%s prayer", prayer_names[current_athan_prayer_index->value()]);
        oled->print(0, 22, font1, line1);
         
        snprintf(line3, sizeof(line3), "%02d:%02d  %02d%s", hour, minute, now.day_of_month, months[now.month - 1]);
        oled->print(0, 44, font1, line3);
      } else {
         
        snprintf(line1, sizeof(line1), "%02d:%02d  %02d%s", hour, minute, now.day_of_month, months[now.month - 1]);
        snprintf(line2, sizeof(line2), "%s %02d:%02d", next_prayer_name, next_prayer_hour->value(), next_prayer_minute->value());
        snprintf(line3, sizeof(line3), "Rem %02d:%02d", hrs, mins);
        oled->print(0, 0, font1, line1);
        oled->print(0, 22, font1, line2);
        oled->print(0, 44, font1, line3);
      }
      
      oled->display();
  });
  automation_id_22->add_actions({lambdaaction_id_33});
  lambdaaction_id_34 = new StatelessLambdaAction<>([]() -> void {
      #line 1214 "/config/athan.yaml"
      auto now = sntp_time->now();
      if (!now.is_valid()) {
       return;
      }
       
      if (!time_zone_changed_at_boot->value()) {
        ESP_LOGI("tz", "Applying persisted timezone from 1s tick: '%s'", selected_location_tz->value().c_str());
        sntp_time->set_timezone(selected_location_tz->value().c_str());
        sntp_time->update();
        time_zone_changed_at_boot->value() = true;
      }
      if (!prayer_times_refreshed_at_least_once->value()) {
        return;
      }
      int hour = now.hour;
      int minute = now.minute;
      
      int isha_h = prayer_hours->value()[6];
      int isha_min = prayer_minutes->value()[6];
      bool time_more_than_prayer = (hour > next_prayer_hour->value()) || (hour == next_prayer_hour->value() && minute >= next_prayer_minute->value());
      bool less_than_isha = (hour < isha_h) || (hour == isha_h && minute < isha_min);
      bool prayer_is_isha = next_prayer_index->value() == 6;
      
      if ( time_more_than_prayer && (prayer_is_isha || less_than_isha) ) {
           
          if (next_prayer_index->value()!=1 && next_prayer_index->value()!=2){
            make_athan->execute();
            current_athan_prayer_index->value() = next_prayer_index->value();
          }
          ESP_LOGI("prayer", "Prayer time reached: index=%d!", next_prayer_index->value());
          Jump_to_next_prayer->execute();
          update_display->execute();
      }
      if (q_flag->value()) {
         
        if (!quyam_triggered->value()) {
          if (next_prayer_index->value() == 0 && hour == quyam_next_hour->value() && minute == quyam_next_minute->value()) {
            ESP_LOGI("quyam", "Quyam time reached -> marking triggered and executing run_quyam");
            quyam_triggered->value() = true;
            run_quyam->execute();
          }
        }
      }
  });
  automation_id_23->add_actions({lambdaaction_id_34});
  interval_intervaltrigger_id->set_update_interval(1000);
  interval_intervaltrigger_id->set_startup_delay(0);
  interval_intervaltrigger_id_2 = new interval::IntervalTrigger();
  interval_intervaltrigger_id_2->set_component_source(LOG_STR("interval"));
  App.register_component(interval_intervaltrigger_id_2);
  automation_id_24 = new Automation<>(interval_intervaltrigger_id_2);
  lambdaaction_id_35 = new StatelessLambdaAction<>([]() -> void {
      #line 1260 "/config/athan.yaml"
      auto now = sntp_time->now();
      if (!now.is_valid()) {
       update_display->execute();
      }
      return;
  });
  automation_id_24->add_actions({lambdaaction_id_35});
  interval_intervaltrigger_id_2->set_update_interval(60000);
  interval_intervaltrigger_id_2->set_startup_delay(0);
  lambdaaction_id = new StatelessLambdaAction<>([]() -> void {
      #line 10 "/config/athan.yaml"
      ESP_LOGI("tz", "Applying saved timezone on boot: '%s'", selected_location_tz->value().c_str());
      sntp_time->set_timezone(selected_location_tz->value().c_str());
  });
  binary_sensor_binarysensorcondition_id = new binary_sensor::BinarySensorCondition<>(ui_next, true);
  binary_sensor_binarysensorcondition_id_2 = new binary_sensor::BinarySensorCondition<>(ui_select, true);
  andcondition_id = new AndCondition<>({binary_sensor_binarysensorcondition_id, binary_sensor_binarysensorcondition_id_2});
  ifaction_id = new IfAction<>(andcondition_id);
  lambdaaction_id_2 = new StatelessLambdaAction<>([]() -> void {
      ESP_LOGD("main", "on resetting wifi");
  });
  wifi_wificonnectedcondition_id = new wifi::WiFiConnectedCondition<>();
  waituntilaction_id = new WaitUntilAction<>(wifi_wificonnectedcondition_id);
  waituntilaction_id->set_timeout_value(300000);
  waituntilaction_id->set_component_source(LOG_STR("esphome.coroutine"));
  App.register_component(waituntilaction_id);
  lambdaaction_id_3 = new StatelessLambdaAction<>([]() -> void {
      #line 24 "/config/athan.yaml"
      wifi::global_wifi_component->clear_sta();
      wifi::global_wifi_component->save_wifi_sta("doesntexist", "passwordfornonetwork");
  });
  light_lightcontrolaction_id = new light::LightControlAction<>(builtin_led);
  light_lightcontrolaction_id->set_state(false);
  delayaction_id = new DelayAction<>();
  delayaction_id->set_component_source(LOG_STR("esphome.coroutine"));
  App.register_component(delayaction_id);
  delayaction_id->set_delay(1000);
  light_lightcontrolaction_id_2 = new light::LightControlAction<>(builtin_led);
  light_lightcontrolaction_id_2->set_state(true);
  delayaction_id_2 = new DelayAction<>();
  delayaction_id_2->set_component_source(LOG_STR("esphome.coroutine"));
  App.register_component(delayaction_id_2);
  delayaction_id_2->set_delay(500);
  light_lightcontrolaction_id_3 = new light::LightControlAction<>(builtin_led);
  light_lightcontrolaction_id_3->set_state(false);
  delayaction_id_3 = new DelayAction<>();
  delayaction_id_3->set_component_source(LOG_STR("esphome.coroutine"));
  App.register_component(delayaction_id_3);
  delayaction_id_3->set_delay(1000);
  light_lightcontrolaction_id_4 = new light::LightControlAction<>(builtin_led);
  light_lightcontrolaction_id_4->set_state(true);
  delayaction_id_4 = new DelayAction<>();
  delayaction_id_4->set_component_source(LOG_STR("esphome.coroutine"));
  App.register_component(delayaction_id_4);
  delayaction_id_4->set_delay(500);
  light_lightcontrolaction_id_5 = new light::LightControlAction<>(builtin_led);
  light_lightcontrolaction_id_5->set_state(false);
  lambdaaction_id_4 = new StatelessLambdaAction<>([]() -> void {
      ESP_LOGD("main", "resetting");
  });
  switch__turnonaction_id = new switch_::TurnOnAction<>(_restart);
  ifaction_id->add_then({lambdaaction_id_2, waituntilaction_id, lambdaaction_id_3, light_lightcontrolaction_id, delayaction_id, light_lightcontrolaction_id_2, delayaction_id_2, light_lightcontrolaction_id_3, delayaction_id_3, light_lightcontrolaction_id_4, delayaction_id_4, light_lightcontrolaction_id_5, lambdaaction_id_4, switch__turnonaction_id});
  delayaction_id_5 = new DelayAction<>();
  delayaction_id_5->set_component_source(LOG_STR("esphome.coroutine"));
  App.register_component(delayaction_id_5);
  delayaction_id_5->set_delay(2000);
  script_scriptexecuteaction_id = new script::ScriptExecuteAction<script::Script<>>(update_display);
  script_scriptexecuteaction_id->set_args();
  lambdaaction_id_5 = new StatelessLambdaAction<>([]() -> void {
      #line 44 "/config/athan.yaml"
      int vol = (volume_level->value() * 30 + 50) / 100;
      if (vol < 0) vol = 0; if (vol > 30) vol = 30;
      dfp->set_volume(vol);
      ESP_LOGI("boot", "DFPlayer volume initialized to %d (from %d%%)", vol, volume_level->value());
  });
  light_lightcontrolaction_id_6 = new light::LightControlAction<>(builtin_led);
  light_lightcontrolaction_id_6->set_state(true);
  delayaction_id_6 = new DelayAction<>();
  delayaction_id_6->set_component_source(LOG_STR("esphome.coroutine"));
  App.register_component(delayaction_id_6);
  delayaction_id_6->set_delay(500);
  light_lightcontrolaction_id_7 = new light::LightControlAction<>(builtin_led);
  light_lightcontrolaction_id_7->set_state(false);
  delayaction_id_7 = new DelayAction<>();
  delayaction_id_7->set_component_source(LOG_STR("esphome.coroutine"));
  App.register_component(delayaction_id_7);
  delayaction_id_7->set_delay(500);
  light_lightcontrolaction_id_8 = new light::LightControlAction<>(builtin_led);
  light_lightcontrolaction_id_8->set_state(true);
  delayaction_id_8 = new DelayAction<>();
  delayaction_id_8->set_component_source(LOG_STR("esphome.coroutine"));
  App.register_component(delayaction_id_8);
  delayaction_id_8->set_delay(500);
  light_lightcontrolaction_id_9 = new light::LightControlAction<>(builtin_led);
  light_lightcontrolaction_id_9->set_state(false);
  automation_id->add_actions({lambdaaction_id, ifaction_id, delayaction_id_5, script_scriptexecuteaction_id, lambdaaction_id_5, light_lightcontrolaction_id_6, delayaction_id_6, light_lightcontrolaction_id_7, delayaction_id_7, light_lightcontrolaction_id_8, delayaction_id_8, light_lightcontrolaction_id_9});
  lambdaaction_id_7 = new StatelessLambdaAction<>([]() -> void {
      #line 120 "/config/athan.yaml"
      ui_last_activity->value() = millis();
       
      if (ui_mode->value() == 0) {
        ESP_LOGI("ui","Next pressed (normal) -> silence");
        dfp->stop();
        athan_playing->value() = false;
         
        test_script->execute();
        update_display->execute();
        return;
      }
       
      ESP_LOGI("ui","Next pressed (menu) -> forward");
      if (ui_mode->value() == 1) {
        ui_menu_index->value() = (ui_menu_index->value() + 1) % 7;
         
        q_select_count->value() = 0;
         
        if (ui_menu_index->value() == 3) {
          update_check_state->value() = 0;
          update_display->execute();
        }
         
      } else if (ui_mode->value() == 2) {
        athan_index->value() = (athan_index->value() + 1) % 10;
        if (!athan_playing->value()) dfp->play_file(1 + athan_index->value());
      } else if (ui_mode->value() == 3) {
        htick_index->value() = (htick_index->value() + 1) % 11;
        if (htick_index->value() == 0) {
          dfp->stop();
        } else {
          dfp->play_file(10 + htick_index->value());
        }
      } else if (ui_mode->value() == 4) {
        location_index->value() = (location_index->value() + 1) % 15;
      } else if (ui_mode->value() == 5) {
         
        int v = volume_level->value();
        if (v <= 10) {
          volume_level->value() = 100;
        } else {
          volume_level->value() = v - 10;
        }
        ESP_LOGI("ui", "Volume changed to %d%%", volume_level->value());
         
        int vol = (volume_level->value() * 30 + 50) / 100;
        if (vol < 0) vol = 0; if (vol > 30) vol = 30;
        dfp->set_volume(vol);
        ESP_LOGI("ui", "DFPlayer volume set to %d (mapped from %d%%)", vol, volume_level->value());
         
        if (!athan_playing->value()) dfp->play_file(22);
      }
      update_display->execute();
  });
  automation_id_3->add_actions({lambdaaction_id_7});
  ui_next->set_component_source(LOG_STR("gpio.binary_sensor"));
  App.register_component(ui_next);
  esphome_esp8266_esp8266gpiopin_id_3 = new esphome::esp8266::ESP8266GPIOPin();
  esphome_esp8266_esp8266gpiopin_id_3->set_pin(14);
  esphome_esp8266_esp8266gpiopin_id_3->set_inverted(true);
  esphome_esp8266_esp8266gpiopin_id_3->set_flags((gpio::Flags::FLAG_INPUT | gpio::Flags::FLAG_PULLUP));
  ui_next->set_pin(esphome_esp8266_esp8266gpiopin_id_3);
  ui_next->set_interrupt_type(gpio::INTERRUPT_ANY_EDGE);
  lambdaaction_id_8 = new StatelessLambdaAction<>([]() -> void {
      #line 185 "/config/athan.yaml"
      ui_last_activity->value() = millis();
       
      if (ui_mode->value() == 0) {
        if(athan_playing->value()){
          ESP_LOGI("ui","Select pressed -> silence athan");
          dfp->stop();
          athan_playing->value() = false;
          update_display->execute();
          return;
        }
        ui_mode->value() = 1;  
        ui_menu_index->value() = 0;
         
        update_check_state->value() = 0;
        ESP_LOGI("ui","Select pressed -> Entered menu: index=0");
        if (!athan_playing->value()) dfp->play_file(23);
        update_display->execute();
        return;
      }
       
      ESP_LOGI("ui","Select pressed in menu index=%d", ui_menu_index->value());
      if (!athan_playing->value()) dfp->play_file(23);
      if (ui_mode->value() == 1) {
         
        if (ui_menu_index->value() == 0) {
          ui_mode->value() = 2;
          athan_index->value() = athan_file_index->value() - 1;
          if (athan_index->value() < 0) athan_index->value() = 0;
          ESP_LOGI("ui","Entered Athan submenu (index=%d)", athan_index->value());
          if (!athan_playing->value()) dfp->play_file(1 + athan_index->value());
        } else if (ui_menu_index->value() == 1) {
          ui_mode->value() = 3;
          if (htick_file_index->value() == 0) htick_index->value() = 0; else htick_index->value() = htick_file_index->value() - 10;
          ESP_LOGI("ui","Entered Hourly Tick submenu (index=%d)", htick_index->value());
          if (!athan_playing->value() && htick_index->value() > 0) dfp->play_file(10 + htick_index->value());
        } else if (ui_menu_index->value() == 2) {
          ui_mode->value() = 4;  
           
           
           
          location_index->value() = selected_location_index->value();
          ESP_LOGI("ui","Entered Location submenu (preview_index=%d)", location_index->value());
        } else if (ui_menu_index->value() == 3) {
           
          if (update_check_state->value() == 2) {
             
            update_check_state->value() = 4;  
            update_display->execute();
            perform_update->execute();
          } else {
             
            update_check_state->value() = 3;  
             
            update_display->execute();
            check_update_remote->execute();
            ui_mode->value() = 1;  
            ESP_LOGI("update", "Checking remote for latest version...");
          }
        } else if (ui_menu_index->value() == 4) {
           
          ui_mode->value() = 5;
          ESP_LOGI("ui", "Entered Volume submenu (level=%d%%)", volume_level->value());
          if (!athan_playing->value()) dfp->play_file(22);
        } else if (ui_menu_index->value() == 5) {
           
          ui_mode->value() = 0;
          ESP_LOGI("ui","Menu cancelled");
        } else if (ui_menu_index->value() == 6) {
           
          if (!q_flag->value()) {
            q_select_count->value() = q_select_count->value() + 1;
            ESP_LOGI("ui","Q select count = %d", q_select_count->value());
            if (q_select_count->value() >= 10) {
              q_flag->value() = true;
              q_select_count->value() = 0;
              ESP_LOGI("ui","Q enabled via 10 presses");
            }
          } else {
             
            q_flag->value() = false;
            q_select_count->value() = 0;
            ESP_LOGI("ui","Q disabled via single press");
          }
        } else {
          ui_mode->value() = 0;
        }
      } else if (ui_mode->value() == 2) {
         
        athan_file_index->value() = 1 + athan_index->value();
        dfp->stop();
        ui_mode->value() = 0;
        ESP_LOGI("ui","Athan %d selected", athan_file_index->value());
      } else if (ui_mode->value() == 3) {
         
        if (htick_index->value() == 0) htick_file_index->value() = 0; else htick_file_index->value() = 10 + htick_index->value();
        dfp->stop();
        ui_mode->value() = 0;
        ESP_LOGI("ui","Hourly Tick %d selected", htick_file_index->value());
      } else if (ui_mode->value() == 4) {
          if (location_index->value() != selected_location_index->value()) {
             
            change_location_handler->execute();
          } else {
            ui_mode->value() = 0;
          }
      } else if (ui_mode->value() == 5) {
         
        ESP_LOGI("ui", "Volume selected: %d%%", volume_level->value());
        ui_mode->value() = 0;
      }
      update_display->execute();
  });
  automation_id_4->add_actions({lambdaaction_id_8});
  ui_select->set_component_source(LOG_STR("gpio.binary_sensor"));
  App.register_component(ui_select);
  esphome_esp8266_esp8266gpiopin_id_4 = new esphome::esp8266::ESP8266GPIOPin();
  esphome_esp8266_esp8266gpiopin_id_4->set_pin(12);
  esphome_esp8266_esp8266gpiopin_id_4->set_inverted(true);
  esphome_esp8266_esp8266gpiopin_id_4->set_flags((gpio::Flags::FLAG_INPUT | gpio::Flags::FLAG_PULLUP));
  ui_select->set_pin(esphome_esp8266_esp8266gpiopin_id_4);
  ui_select->set_interrupt_type(gpio::INTERRUPT_ANY_EDGE);
  lambdaaction_id_11 = new StatelessLambdaAction<>([]() -> void {
      #line 375 "/config/athan.yaml"
      if (!athan_playing->value() && htick_file_index->value() > 0) {
          dfp->play_file(htick_file_index->value());
      }
  });
  automation_id_6->add_actions({script_scriptexecuteaction_id_4, lambdaaction_id_11});
  time_crontrigger_id_2 = new time::CronTrigger(sntp_time);
  time_crontrigger_id_2->add_seconds({0});
  time_crontrigger_id_2->add_minutes({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59});
  time_crontrigger_id_2->add_hours({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23});
  time_crontrigger_id_2->add_days_of_month({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31});
  time_crontrigger_id_2->add_months({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  time_crontrigger_id_2->add_days_of_week({1, 2, 3, 4, 5, 6, 7});
  time_crontrigger_id_2->set_component_source(LOG_STR("time"));
  App.register_component(time_crontrigger_id_2);
  automation_id_7 = new Automation<>(time_crontrigger_id_2);
  lambdaaction_id_12 = new StatelessLambdaAction<>([]() -> void {
      #line 381 "/config/athan.yaml"
      update_display->execute();
      if (!prayer_times_refreshed_at_least_once->value()){
        refresh_prayer_times_if_needed->execute();
      }
      return;
  });
  automation_id_7->add_actions({lambdaaction_id_12});
  time_synctrigger_id = new time::SyncTrigger(sntp_time);
  time_synctrigger_id->set_component_source(LOG_STR("time"));
  App.register_component(time_synctrigger_id);
  automation_id_5 = new Automation<>(time_synctrigger_id);
  lambdaaction_id_9 = new StatelessLambdaAction<>([]() -> void {
      #line 352 "/config/athan.yaml"
      if (!time_zone_changed_at_boot->value()) {
        ESP_LOGI("tz", "Applying persisted timezone after time sync: '%s'", selected_location_tz->value().c_str());
        sntp_time->set_timezone(selected_location_tz->value().c_str());
        sntp_time->update();
        time_zone_changed_at_boot->value() = true;
      }
  });
  script_scriptexecuteaction_id_3 = new script::ScriptExecuteAction<script::Script<>>(update_display);
  script_scriptexecuteaction_id_3->set_args();
  lambdacondition_id_2 = new StatelessLambdaCondition<>([]() -> bool {
      #line 362 "/config/athan.yaml"
      return sntp_time->now().is_valid();
  });
  waituntilaction_id_3 = new WaitUntilAction<>(lambdacondition_id_2);
  waituntilaction_id_3->set_timeout_value(8000);
  waituntilaction_id_3->set_component_source(LOG_STR("time"));
  App.register_component(waituntilaction_id_3);
  lambdaaction_id_10 = new StatelessLambdaAction<>([]() -> void {
      #line 364 "/config/athan.yaml"
      update_display->execute();
      if (!prayer_times_refreshed_at_least_once->value()) {
        compute_coming_prayer->execute();
      }
  });
  automation_id_5->add_actions({lambdaaction_id_9, script_scriptexecuteaction_id_3, waituntilaction_id_3, lambdaaction_id_10});
  // =========== AUTO GENERATED CODE END ============
  App.setup();
}

void loop() {
  App.loop();
}
