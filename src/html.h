
void create_param(String name, String value);

void create_parameters()
{
    create_param(F("wifi_mode"), "1"); // wifi mode. 1 - AP, 2 - STA
    create_param(F("ssid"), F("Musa Pro"));
    create_param(F("pass"), F("Gigabyte2014"));
}
#include "sys/debug.h"
void make_page(int page)
{
    // Menu
    e_menu[0] = F("Settings");
    e_menu[1] = F("Wi-Fi");
    e_menu[2] = F("Info");

    switch (page)
    {
    case 0: // Settings Page

        button_save(F("Save"), 1);
        button_reboot(F("Reboot device"), 4);
        break;
    case 1: // Wi-Fi Page
    
        wifi_scan(); // Wi-Fi Scan table
        input_text(F("ssid"), F("ssid"), F("text"), "", F("SSID"));
        input_text("", F("pass"), F("password"), "", F("Password"));

        select_elements("1", F("AP"));
        select_elements("2", F("STA"));
        input_select("", F("wifi_mode"), false, F("Wi-Fi Mode"));

        button_save(F("Save"), 1);
        button_reboot(F("Reboot device"), 4);
        break;
    case 2: // Info page

        border(F("All Parameters"));
        param_table();
        border("");
        break;
    }

}