
bool led_state = false;
unsigned long led_timer;
int led_mode = 2;

bool button_state;
bool old_button_state;

bool gpio_update = false;

void gpio_setup()
{
    pinMode(BUTTON, INPUT);
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
    gpio_update = false;
}

void led_handle()
{
    switch (led_mode)
    {
    case 0:
    {
        digitalWrite(LED, HIGH);
        break;
    }
    case 1:
    {

    digitalWrite(LED, LOW);
    break;
    }
    case 2:
    {
        if (led_timer + 500 > millis())
            return;
        led_timer = millis();
        led_state = !led_state;
        digitalWrite(LED, led_state);
        break;
    }
    case 3:
    {
        if (led_timer + 70 < millis() && led_timer + 140 > millis())
        {
#ifdef LED_INVERT
            digitalWrite(LED, HIGH);
#else
            digitalWrite(LED, LOW);
#endif
        }
        if (led_timer + 140 < millis() && led_timer + 210 > millis())
        {
#ifdef LED_INVERT
            digitalWrite(LED, LOW);
#else
            digitalWrite(LED, HIGH);
#endif
        }
        if (led_timer + 210 < millis() && led_timer + 280 > millis())
        {
#ifdef LED_INVERT
            digitalWrite(LED, HIGH);
#else
            digitalWrite(LED, LOW);
#endif
        }
        if (led_timer + 280 < millis() && led_timer + 350 > millis())
        {
#ifdef LED_INVERT
            digitalWrite(LED, LOW);
#else
            digitalWrite(LED, HIGH);
#endif
        }
        if (led_timer + 600 < millis())
        {
            led_timer = millis();
            Serial.print(".");
        }
        return;
    }
    default:
        return;
    }
}

void button_handle()
{
    button_state = false;
    if (digitalRead(BUTTON) == true)
        return;

    int wifi_mode = param(F("wifi_mode")).toInt();
    digitalWrite(LED, HIGH);
    long t = millis();
    while (digitalRead(BUTTON) == false)
    {
        delay(1);
        if (t + 5000 < millis()) // Нажатие 5 секунд
        {
            digitalWrite(LED, LOW);
            if (wifi_mode == 1)
                write_param(F("wifi_mode"), "2");
            if (wifi_mode == 2)
                write_param(F("wifi_mode"), "1");
        }
        if (t + 15000 < millis()) // Нажатие 10 секунд
        {
            digitalWrite(LED, HIGH);
            SPIFFS.remove(F("/config.json"));
            ESP.restart();
        }
    }
    if (wifi_mode != param(F("wifi_mode")).toInt())
    {
        save_flag = true;
        save_param();
        ESP.restart();
    }
}

void gpio_handle()
{
    led_handle();
    button_handle();
    if (gpio_update)
        gpio_setup();
}