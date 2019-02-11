
unsigned long time_action;      // таймер проверки событий
int interval_action = 1000;     // интервал опроса событий 1 секунда

void slow_handle()
{
    if (time_action + interval_action > millis())
        return;
    time_action = millis();

}

void framework_handle()
{
    gpio_handle();
    save_param();
    slow_handle();
}

