#include <Arduino.h>
//#define RELEASE // Раскоментировать перед выпуском релиза. Это отключит вывод в серийный порт!
#define BUTTON 0 // Пин кнопки управления
#define LED 2    // Пин светодиода индикации

#include "html.h"

void setup() {
    framework();
}
void loop() {
    framework_handle();
}

