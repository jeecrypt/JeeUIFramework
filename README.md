# JeeUIFramework
**The framework will allow you in a few minutes to create a web interface for your projects on ESP8266 and ESP32**

Use my code as a template for your **ESP8266** and **ESP32** projects.
The framework will help you use the configuration file and the web interface.
As a development environment, I highly recommend using [PlatformIO](https://platformio.org)!

To get started, you need to create parameters that will later be configured using the web interface. The parameter is actually a json object. The following manipulations are done in the file 'html.h'

Create a new parameter:
***`create_param (String Name, String Value)`***

The web interface is created using simple methods:

***`input_text (String id, String name, String type, String placeholder, String title)`***
'*id*', '*name*', '*type*', '*placeholder*', '*title*' are similar to what you would use in HTML
for example '*type*':
 - '*text*' - enter text
 - '*numbet*' - enter only digits
 - '*date*' - enter date
 - '*time*' - enter time
specify the parameter created earlier with create_param as '*id*'

***`input_range (String id, String name, int min, int max, String title)`***
'*min*' and '*max*' - the minimum and maximum values ​​of the slider
 - specify the parameter created earlier with create_param as '*id*'

***`select_elements (String value, String title)`***
creates a dropdown item.

***`input_select (String id, String name, bool refresh, String title)`***
'*refresh*' - if true, the page will be updated immediately after selecting the item
 - specify the parameter created earlier with create_param as '*id*'

***`button_save (String title, int color)`***
Creates a form submit button
'*color*' - color of the button, matches the colors of Bootstrap
 - 1 - "**primary**"
 - 2 - "**secondary**"
 - 3 - "**success**"
 - 4 - "**danger**"
 - 5 - "**warning**"
 - 6 - "**info**"
 - 7 - "**light**"
 - 8 - "**dark**"

***`button_reboot (String title, int color)`***
Creates a device reset button (sometimes it is necessary for the settings to take effect)

***`alert (int color, String strong, String text, bool close)`***
Creates an HTML alert element
 - '*strong*' - Text with selection
- '*text*' - text
- '*close*' - if true - the option to close the item

***`border (String title)`***
starts and ends border.
- To start the border the '*title*' must not be empty,
To finish the border the '*title*' must be = "".
