
void create_param(String name, String value);

void create_parameters()
{
    create_param(F("wifi_mode"), "1"); // режим wifi. 1 - точка доступа, 2 - клиент
    create_param(F("ssid"), F("Musa Pro"));
    create_param(F("pass"), F("Gigabyte2014"));
}
#include "sys/debug.h"
void make_page(int page)
{
    // Названия пунктов меню по номеру страницы
    e_menu[0] = F("Параметры устройства");
    e_menu[1] = F("Настройки Wi-Fi");
    e_menu[2] = F("Информация");

    switch (page)
    {
    case 0: // Главная страница
        button_save(F("Сохранить"), 1);
        button_reboot(F("Перезагрузить устройство"), 4);
        break;
    case 1: // Страница настройки сети
    
        wifi_scan(); // Таблица сканирования сетей
        input_text(F("ssid"), F("ssid"), F("text"), "", F("Имя сети"));
        input_text("", F("pass"), F("password"), "", F("Пароль сети"));
        select_elements("1", F("Точка доступа"));
        select_elements("2", F("Клиент"));
        input_select("", F("wifi_mode"), false, F("Режим Wi-Fi")); // Тест. Создали элемент SELECT (со значениями, что выше)

        button_save(F("Сохранить"), 1);
        button_reboot(F("Перезагрузить устройство"), 4);
        break;
    case 2: // Страница Информации

    
        border(F("Все параметры устройства"));
        param_table();
        border("");
        break;
    }
}