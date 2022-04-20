#include "Fl_Theme/Fl_Theme.hpp"
#include "Fl_Theme/colors/html.hpp"

extern int FLAT_BORDER_RADIUS; // for if we need to change the radius

#include <FL/Fl.H>
#include <FL/Enumerations.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Window.H>

int main() {
    WidgetTheme::apply(ThemeType::Dark);
    auto win = new Fl_Window(400, 300);
    auto menu = new Fl_Menu_Bar(0, 0, 400, 30);
    menu->add("File/New\t");
    menu->add("File/Open\t");
    auto inp = new Fl_Input(100, 100, 200, 30, "");
    auto box = new Fl_Button(160, 200, 80, 30, "Box");
    box->labelcolor(White);
    box->color(DarkRed);
    box->selection_color(DarkRed);
    box->callback([](Fl_Widget* w) { w->parent()->redraw(); });
    box->clear_visible_focus();
    win->end();
    win->show();
    return Fl::run();
}