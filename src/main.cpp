#include <Arduino.h>
//#define RELEASE // Раскоментировать перед выпуском релиза. Это отключит вывод в серийный порт!
#define BUTTON 0 // Пин кнопки управления
#define LED 2    // Пин светодиода индикации

#include "html.h"

void blink();

void setup() {
    framework();
}

void loop() {
    framework_handle();
    blink();
}

void blink(){
    static long blink_timer;
    static int blink_interval; // 50 - 5000 ms
    static bool blink_state;

    if (blink_interval + blink_timer < millis()){
        blink_state = !blink_state;
        Serial.println("blink: " + String(blink_state));
        blink_interval = param("blink_interval").toInt();
        blink_timer = millis();
    }
}