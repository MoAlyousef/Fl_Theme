# Fl_Theme
Themer for FLTK

## Usage
Fl_Theme is a header only C++17 lib, targetting FLTK 1.4 (due to SVG support), it can be added directly to your project:

```c++
#include <FL/Fl.H>

#include <FL/Enumerations.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Window.H>

#include "Fl_Theme/Fl_Theme.hpp"
#include "Fl_Theme/colors/html.hpp"
#include "Fl_Theme/widgets/toggle.hpp"

extern int FLAT_BORDER_RADIUS; // for if we need to change the radius

Fl_Menu_Bar *create_menubar(int w) {
    auto menu = new Fl_Menu_Bar(0, 0, w, 40);
    menu->add("File/New\t");
    menu->add("File/Open\t");
    return menu;
}

int main() {
    FLAT_BORDER_RADIUS = 5; // This is the default
    WidgetTheme::apply(ThemeType::Dark);
    auto win = new Fl_Window(400, 300);
    {
        create_menubar(400);
        auto inp = new Fl_Input(100, 50, 200, 30, "Enter name");
        auto toggle = new Toggle(120, 100, 60, 15, "Are you sure");
        auto check = new Fl_Round_Button(220, 95, 80, 30, "Check");
        auto choice = new Fl_Choice(160, 150, 80, 30, "Choices");
        choice->add("opt1|opt2|opt3");
        auto sep = new Fl_Box(10, 210, 380, 3);
        sep->box(FL_ENGRAVED_BOX);
        auto btn = new Fl_Button(160, 240, 80, 30, "Click");
        btn->color(DarkRed);
        btn->selection_color(DarkRed);
        btn->clear_visible_focus();
    }
    win->end();
    win->show();
    return Fl::run();
}
```
![image](https://user-images.githubusercontent.com/37966791/164238382-871c14e2-9c4d-4b75-93f6-7cc3faf91083.png)
