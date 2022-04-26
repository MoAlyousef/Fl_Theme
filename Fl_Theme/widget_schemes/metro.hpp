#include "impl.hpp"
#include <FL/Enumerations.H>

inline void metro_upbox(int x, int y, int w, int h, Fl_Color col) {
    auto svg =
        detail::gen_svg("<svg width='%d' height='%d' viewBox='0 0 100 100'>"
        "<rect x='1' y='1' width='99' height='99' rx='0' stroke-width='1' stroke='rgb(0,0,0)' />"
        "<rect x='1' y='1' width='97.5' height='48' rx='0' fill='rgb(245,245,245)' />"
        "<rect x='1' y='48' width='97.5' height='48' rx='0' fill='rgb(230,230,230)' />"
        "</svg>", w, h);
    detail::draw_image(x, y, w, h, svg);
    free(svg);
}

inline void metro_downbox(int x, int y, int w, int h, Fl_Color col) {
    auto svg =
        detail::gen_svg("<svg width='%d' height='%d' viewBox='0 0 100 100'>"
        "<rect x='1' y='1' width='99' height='99' rx='0' stroke-width='1' stroke='rgb(0,0,0)' />"
        "<rect x='1' y='1' width='97.5' height='48' rx='0' fill='rgb(230,230,230)' />"
        "<rect x='1' y='48' width='97.5' height='48' rx='0' fill='rgb(245,245,245)' />"
        "</svg>", w, h);
    detail::draw_image(x, y, w, h, svg);
    free(svg);
}

inline void metro_active_upbox(int x, int y, int w, int h, Fl_Color col) {
    auto svg =
        detail::gen_svg("<svg width='%d' height='%d' viewBox='0 0 100 100'>"
        "<rect x='2' y='2' width='96' height='96' rx='0' stroke-width='2' stroke='rgb(69,179,234)' />"
        "<rect x='3' y='4' width='94' height='46' rx='0' fill='rgb(245,245,245)' />"
        "<rect x='3' y='48' width='94' height='46' rx='0' fill='rgb(230,230,230)' />"
        "</svg>", w, h);
    detail::draw_image(x, y, w, h, svg);
    free(svg);
}

inline void metro_active_downbox(int x, int y, int w, int h, Fl_Color col) {
    auto svg =
        detail::gen_svg("<svg width='%d' height='%d' viewBox='0 0 100 100'>"
        "<rect x='2' y='2' width='96' height='96' rx='0' stroke-width='2' stroke='rgb(69,179,234)' />"
        "<rect x='3' y='4' width='94' height='46' rx='0' fill='rgb(230,230,230)' />"
        "<rect x='3' y='48' width='94' height='46' rx='0' fill='rgb(245,245,245)' />"
        "</svg>", w, h);
    detail::draw_image(x, y, w, h, svg);
    free(svg);
}

inline void init_metro_theme() {
    Fl::scheme("gtk+");
    Fl::set_boxtype(FL_UP_BOX, metro_upbox, 2, 2, 4, 4);
    Fl::set_boxtype(FL_DOWN_BOX, metro_downbox, 2, 2, 4, 4);
    Fl::set_boxtype(FL_DIAMOND_UP_BOX, metro_active_upbox, 2, 2, 4, 4);
    Fl::set_boxtype(FL_DIAMOND_DOWN_BOX, metro_active_downbox, 2, 2, 4, 4);
}

#define METRO_BUTTON_BOX FL_DIAMOND_UP_BOX