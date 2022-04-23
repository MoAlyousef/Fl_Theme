#include "impl.hpp"
#include <FL/Enumerations.H>

inline void metro_upbox(int x, int y, int w, int h, Fl_Color col) {
    auto svg =
        detail::gen_svg("<svg width='%d' height='%d'>"
        "<rect x='2' y='2' width='%d' height='%d' rx='0' stroke-width='1' stroke='rgb(0,0,0)' />"
        "<rect x='2' y='2' width='%d' height='%d' rx='0' fill='rgb(245,245,245)' />"
        "<rect x='2' y='%d' width='%d' height='%d' rx='0' fill='rgb(230,230,230)' />"
        "</svg>", w, h, w - 6, h -4, w - 6, (h - 4)/2, (h - 4)/2, w -6 , h / 2);
    detail::draw_image(x, y, w, h, svg);
    free(svg);
}

inline void metro_downbox(int x, int y, int w, int h, Fl_Color col) {
    auto svg =
        detail::gen_svg("<svg width='%d' height='%d'>"
        "<rect x='2' y='2' width='%d' height='%d' rx='0' stroke-width='1' stroke='rgb(0,0,0)' />"
        "<rect x='2' y='2' width='%d' height='%d' rx='0' fill='rgb(230,230,230)' />"
        "<rect x='2' y='%d' width='%d' height='%d' rx='0' fill='rgb(245,245,245)' />"
        "</svg>", w, h, w - 6, h -4, w - 6, (h - 4)/2, (h - 4)/2, w -6 , h / 2);
    detail::draw_image(x, y, w, h, svg);
    free(svg);
}


inline void metro_active_upbox(int x, int y, int w, int h, Fl_Color col) {
    auto svg =
        detail::gen_svg("<svg width='%d' height='%d'>"
        "<rect x='2' y='2' width='%d' height='%d' rx='0' stroke-width='2' stroke='rgb(69, 179, 234)' />"
        "<rect x='2' y='2' width='%d' height='%d' rx='0' fill='rgb(245,245,245)' />"
        "<rect x='2' y='%d' width='%d' height='%d' rx='0' fill='rgb(230,230,230)' />"
        "</svg>", w, h, w - 6, h - 4, w - 6, (h - 4)/2, (h - 4)/2, w - 6 , h / 2);
    detail::draw_image(x, y, w, h, svg);
    free(svg);
}

inline void metro_active_downbox(int x, int y, int w, int h, Fl_Color col) {
    auto svg =
        detail::gen_svg("<svg width='%d' height='%d'>"
        "<rect x='2' y='2' width='%d' height='%d' rx='0' stroke-width='2' stroke='rgb(69, 179, 234)' />"
        "<rect x='2' y='2' width='%d' height='%d' rx='0' fill='rgb(230,230,230)' />"
        "<rect x='2' y='%d' width='%d' height='%d' rx='0' fill='rgb(245,245,245)' />"
        "</svg>", w, h, w - 6, h - 4, w - 6, (h - 4)/2, (h - 4)/2, w - 6 , h / 2);
    detail::draw_image(x, y, w, h, svg);
    free(svg);
}

inline void init_metro_theme() {
    Fl::scheme("gtk+");
    Fl::set_boxtype(FL_UP_BOX, metro_upbox, 2, 2, 4, 4);
    Fl::set_boxtype(FL_DOWN_BOX, metro_downbox, 2, 2, 4, 4);
    Fl::set_boxtype(FL_DOWN_BOX, metro_downbox, 2, 2, 4, 4);
    Fl::set_boxtype(FL_DIAMOND_UP_BOX, metro_active_upbox, 2, 2, 4, 4);
    Fl::set_boxtype(FL_DIAMOND_DOWN_BOX, metro_active_downbox, 2, 2, 4, 4);
}

#define METRO_BUTTON_BOX FL_DIAMOND_UP_BOX