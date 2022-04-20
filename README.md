# Fl_Theme
Themer for FLTK

## Usage
Fl_Theme is a header only lib, it can be added directly to your project:

```c++
#include <FL/Fl.H>
#include <FL/Enumerations.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Window.H>

#include "Fl_Theme/Fl_Theme.hpp"
#include "Fl_Theme/colors/html.hpp"

extern int FLAT_BORDER_RADIUS; // for if we need to change the radius

int main() {
    WidgetTheme::apply(ThemeType::Dark);
    auto win = new Fl_Window(400, 300);
    auto menu = new Fl_Menu_Bar(0, 0, 400, 30);
    menu->add("File/New\t");
    menu->add("File/Open\t");
    auto inp = new Fl_Input(100, 100, 200, 30, "");
    auto btn = new Fl_Button(160, 200, 80, 30, "Click");
    btn->labelcolor(White);
    btn->color(DarkRed);
    btn->selection_color(DarkRed);
    btn->clear_visible_focus();
    win->end();
    win->show();
    return Fl::run();
}
```
![image](https://user-images.githubusercontent.com/37966791/164227801-5ffe594e-5cc5-479c-83c9-65f9f1fd91a0.png)
