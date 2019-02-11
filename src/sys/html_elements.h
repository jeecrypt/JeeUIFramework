
String e_select[50][2]; // Массив (двумерный) значений селекта (value, text) предел - 20 значений
String e_menu[20]; // Массив названий пунктов меню
String menu_content;
String page_content;
int select_num = 0;
int current_page = 0; // Номер текущей страницы

void make_menu(int page){
    int i = 0;
    menu_content = F("<div class=\"collapse navbar-collapse\" id=\"navbarSupportedContent\"><ul class=\"navbar-nav mr-auto\">");
    while (e_menu[i] != "")
    {
        menu_content += F("<li class=\"nav-item");
        if (i == page)
            menu_content += F(" active");
        menu_content += F("\" onclick=\"update(");
        menu_content += String(i);
        menu_content += F(");\"><a class=\"nav-link\" href=\"#\">");
        menu_content += e_menu[i];
        menu_content += F("</a></li>");
        i++;
  }
  menu_content += F("</ul></div>");
}

void button_save(String title, int color){
    page_content += F("<div id=\"messegeResult\"></div><input id=\"button\" type=\"button\" class=\"btn btn-");
    switch (color){
        case 1: page_content += F("primary"); break;
        case 2: page_content += F("secondary"); break;
        case 3: page_content += F("success"); break;
        case 4: page_content += F("danger"); break;
        case 5: page_content += F("warning"); break;
        case 6: page_content += F("info"); break;
        case 7: page_content += F("light"); break;
        case 8: page_content += F("dark"); break;
    }
    page_content += F(" btn-block\" onclick=\"sendForm('formMain', '/post');\" value=\"");
    page_content += title;
    page_content += F("\"><br>");
}

void button_connect(String title, int color){
    page_content += F("<div id=\"messegeResult\"></div><input id=\"button\" type=\"button\" class=\"btn btn-");
    switch (color){
        case 1: page_content += F("primary"); break;
        case 2: page_content += F("secondary"); break;
        case 3: page_content += F("success"); break;
        case 4: page_content += F("danger"); break;
        case 5: page_content += F("warning"); break;
        case 6: page_content += F("info"); break;
        case 7: page_content += F("light"); break;
        case 8: page_content += F("dark"); break;
    }
    page_content += F(" btn-block\" onclick=\"connect(");
    page_content += current_page;
    page_content += F(");\" value=\"");
    page_content += title;
    page_content += F("\"><br>");
}

void button_reboot(String title, int color){
    page_content += F("<div id=\"messegeResult\"></div><input id=\"button\" type=\"button\" class=\"btn btn-");
    switch (color){
        case 1: page_content += F("primary"); break;
        case 2: page_content += F("secondary"); break;
        case 3: page_content += F("success"); break;
        case 4: page_content += F("danger"); break;
        case 5: page_content += F("warning"); break;
        case 6: page_content += F("info"); break;
        case 7: page_content += F("light"); break;
        case 8: page_content += F("dark"); break;
    }
    page_content += F(" btn-block\" onclick=\"reboot();\" value=\"");
    page_content += title;
    page_content += F("\"><br>");
}

void input_text(String id, String name, String type, String placeholder, String title) {
    page_content += F("<div class=\"input-group mb-3\"><div class=\"input-group-prepend\"><span class=\"input-group-text\">");
    page_content += title;
    page_content += F("</span></div><input type=\"");
    page_content += type;
    page_content += F("\" id=\"");
    page_content += id;
    page_content += F("\" name=\"");
    page_content += name;
    page_content += F("\" value=\"");
    page_content += param(name);
    page_content += F("\" class=\"form-control\" placeholder=\"");
    page_content += placeholder;
    page_content += F("\"></div>");
}

void border(String title)
{
    if (title != "")
    {
        page_content += F("<fieldset class=\"border p-2\"><legend class=\"w-auto\" style=\"font-size: 1em\">");
        page_content += title;
        page_content += F("</legend>");
        
    }
    else page_content += F("</fieldset><br>");
}

void mes(String title, String text, int fontsize, int align)
{
        page_content += F("<fieldset class=\"border p-2\"><legend class=\"w-auto\" style=\"font-size: 1em\">");
        page_content += title;
        page_content += F("</legend><p align=\"");
        if(align == 1) page_content += F("right");
        if(align == 0) page_content += F("center");
        if(align == 2) page_content += F("left");
        if(align == 3) page_content += F("justify");
        page_content += F("\" style=\"font-size: ");
        page_content += fontsize;
        page_content += F("em\">");
        page_content += text;
        page_content += F("</p></fieldset><br>");
}

void alert(int color, String strong, String text, bool close) {
    page_content += F("<div class=\"alert alert-");
    switch (color){
        case 1: page_content += F("primary"); break;
        case 2: page_content += F("secondary"); break;
        case 3: page_content += F("success"); break;
        case 4: page_content += F("danger"); break;
        case 5: page_content += F("warning"); break;
        case 6: page_content += F("info"); break;
        case 7: page_content += F("light"); break;
        case 8: page_content += F("dark"); break;
    }
    page_content += F("\" role=\" alert\">");
    if (close) page_content += F("<a href=\"#\" class=\"close\" data-dismiss=\"alert\" aria-label=\"close\">&times;</a>");
    page_content += F("<strong>");
    page_content += strong;
    page_content += F("</strong>");
    page_content += text;
    page_content += F("</div>");
}

void param_table()
{
    DynamicJsonBuffer jsonBuffer;
    JsonObject &root = jsonBuffer.parseObject(json_config);
    page_content += F("<table class=\"table text-justify\" style=\"font-size: 14px; word-break: break-all\"><thead><tr><th>Parameter</th><th>Value</th></tr></thead><tbody>");
    int num = 1;
    for (auto kv : root)
    {
        page_content += F("<tr><td>");
        page_content += String(kv.key);
        page_content += F("</td><td>");
        page_content += kv.value.as<String>();
        page_content += F("</td></tr>");
        num++;
    }
    page_content += F("</tbody></table>");
}

void input_textarea(String id, String name, int rows, String title){
    page_content += F("<div class=\"form-group\"><label>");
    page_content += title;
    page_content += F(":&nbsp</label><label id=\"");
    page_content += name;
    page_content += F("\"></label><textarea class=\"form-control\" maxlength=\"175\" type=\"text\" id=\"");
    page_content += id;
    page_content += F("\" name=\"");
    page_content += name;
    page_content += F("\" rows=\"");
    page_content += String(rows);
    page_content += F("\"oninput=\"updateTextInput('");
    page_content += name;
    page_content += F("',this.value.length);");
    page_content += F("\">");
    page_content += param(name);
    page_content += F("</textarea></div>");
}

void select_elements(String value, String title){
        e_select[select_num][0] = value;
        e_select[select_num][1] = title;
        e_select[select_num + 1][0] = "";
        select_num++;
}

void input_select(String id, String name, bool refresh, String title) {
    int i = 0;
    page_content += F("<div class=\"input-group mb-3\"><div class=\"input-group-prepend\"><label class=\"input-group-text\">");
    page_content += title;
    page_content += F("</label></div><select class=\"custom-select\" id=\"");
    page_content += id;
    if(refresh)
    {
        page_content += F("\"oninput=\"AjaxFormRequest('formMain', '/post'); page_update('");
        page_content += current_page;
        page_content += F("', this.value);");
    }
    page_content += F("\" name=\"");
    page_content += name;
    page_content += F("\">");
    while(e_select[i][0] != ""){
        page_content += F("<option value=\"");
        page_content += e_select[i][0];
        page_content += F("\"");
        if (e_select[i][0] == param(name)) page_content += F(" selected");
        page_content += F(">");
        page_content += e_select[i][1];
        page_content += F("</option>");
        i++;
    }
    page_content += F("</select></div>");
    select_num = 0;
    for(int i = 0; i <= 20; i++)
    {
        e_select[select_num][0] = "";
        e_select[select_num][1] = "";
    }
}

void input_range(String id, String name, int min, int max, String title)
{
    page_content += F("<div class=\"input-group mb-3\"><label>");
    page_content += title;
    page_content += F(":&nbsp</label><label id=\"");
    page_content += id;
    page_content += F("\">");
    page_content += param(name);
    page_content += F("</label><input type=\"range\"class=\"custom-range\" min=\"");
    page_content += String(min);
    page_content += F("\" max=\"");
    page_content += String(max);
    page_content += F("\" name=\"");
    page_content += name;
    page_content += F("\" value=\"");
    page_content += param(name);
    page_content += F("\"oninput=\"updateTextInput('");
    page_content += id;
    page_content += F("', this.value);\"></div>");
}
