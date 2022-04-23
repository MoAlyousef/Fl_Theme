#include <FL/Fl.H>

#include <FL/Enumerations.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Window.H>

#include "Fl_Theme/Fl_Theme.hpp"

int main() {
    WidgetTheme::apply(ThemeType::Metro);
    auto win = new Fl_Window(400, 300);
    {
        auto inp = new Fl_Input(100, 50, 200, 30, "Enter name");
        auto check = new Fl_Check_Button(80, 100, 60, 15, "Are you sure");
        auto round = new Fl_Round_Button(220, 95, 80, 30, "Check");
        auto choice = new Fl_Choice(160, 150, 80, 30, "Choices");
        choice->add("opt1|opt2|opt3");
        auto sep = new Fl_Box(10, 210, 380, 3);
        sep->box(FL_ENGRAVED_BOX);
        auto btn = new Fl_Button(160, 240, 80, 30, "Click");
        btn->box(METRO_BUTTON_BOX);
        btn->clear_visible_focus();
    }
    win->end();
    win->show();
    return Fl::run();
}
