


#define DBG_OUTPUT_PORT Serial
#ifndef RELEASE
#define DEBUGLOG(...) DBG_OUTPUT_PORT.printf(__VA_ARGS__)
#else
#define DEBUGLOG(...)
#endif

#ifndef RELEASE
void ptintdeb(String s)
{
  Serial.println(s);
}
#define DEBG ptintdeb
#else
void ptintdeb(String s) {}
#define DEBG ptintdeb
#endif
bool ip_ok;
uint8_t wifiMode;
#ifdef ESP8266
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <FS.h>
#else
#include <WiFi.h>
#include <AsyncTCP.h>
#include "SPIFFS.h"
#endif

#include <ESPAsyncWebServer.h>
#include "AsyncJson.h"
#include "ArduinoJson.h"

String json_config;
String json_default_config;
bool first_start = true;
bool subscribe = false;
bool relay_trigger = false;

long restart_timer;
int restart_interval = 5000;

bool get_ip = false;
String ip_addres = "0.0.0.0";



void create_parameters(void);
void wifi_connect(void);
void gpio_handle(void);
void save_param(void);
String param(String name);
void wifi_scan(void);
void make_page(int page);
void page_update(void);
void title_update(void);
void menu_update(void);
void p_index_html(void);
void page_support(void);
void page_post(void);
void reboot_page(void);
void wifi_con(void);
void statrt_handle(void);
void write_param(String name, String value);
void getip(String devise_name, String email);

int var_num = 0;
bool save_flag = false;

#include "config.h"
#include "gpio.h"
#include "http/p_blankPage.h"
#include "http/p_bootstrap.min.css.h"
#include "http/p_bootstrap.min.js.h"
#include "http/p_jquery-3.2.1.min.js.h"
#include "http/p_bubbly_bg_js.h"
#include "http/p_logo.svg.h"
#include "http/p_favicon.h"
#include "html_elements.h"
#include "p_support.h"
#include "wi-fi.h"
#include "action.h"

void framework()
{
#ifndef RELEASE
  Serial.begin(115200);
#endif

  SPIFFS.begin();
  load_param(); // Загрузка конфигурации
  gpio_setup();
  wifi_connect();
  html_pages();
  server.begin();
}