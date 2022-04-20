#include "impl.hpp"
#include <FL/Enumerations.H>

static int FLAT_BORDER_RADIUS = 5;

static const char *FL_FLAT_RECT_UP =
    "<svg width='%d' height='%d'>"
    "<defs>"
    "<linearGradient id='grad1' x1='0%%' y1='0%%' x2='0%%' y2='100%%'>"
    "<stop offset='0%%' style='stop-color:rgb(%d,%d,%d);stop-opacity:1' />"
    "<stop offset='100%%' style='stop-color:rgb(%d,%d,%d);stop-opacity:1' />"
    "</linearGradient>"
    "</defs>"
    "<rect width='%d' height='%d' rx='%d' fill='url(#grad1)' />"
    "</svg>";

static const char *FL_FLAT_RECT_DOWN =
    "<svg width='%d' height='%d'>"
    "<defs>"
    "<linearGradient id='grad1' x1='0%%' y1='0%%' x2='0%%' y2='100%%'>"
    "<stop offset='100%%' style='stop-color:rgb(%d,%d,%d);stop-opacity:1' />"
    "<stop offset='0%%' style='stop-color:rgb(%d,%d,%d);stop-opacity:1' />"
    "</linearGradient>"
    "</defs>"
    "<rect width='%d' height='%d' rx='%d' fill='url(#grad1)' />"
    "</svg>";

static const char *FL_FLAT_RECT_FRAME = "<svg width='%d' height='%d'>"
                                        "<rect x='1' y='1' width='%d' height='%d' rx='%d' "
                                        "fill='none' stroke-width='2' stroke='rgb(%d,%d,%d)'/>"
                                        "</svg>";


inline void flat_box(int x, int y, int w, int h, Fl_Color col) {
    auto rgb = detail::get_rgb(fl_color_average(FL_WHITE, col, 0.2));
    auto [r, g, b] = rgb;
    auto darker = fl_darker(col);
    auto [r1, g1, b1] = detail::get_rgb(darker);
    auto svg = detail::gen_svg(FL_FLAT_RECT_UP, w, h, r, g, b, r1, g1, b1, w, h, 0);
    detail::draw_image(x, y, w, h, svg);
    free(svg);
}

inline void upbox(int x, int y, int w, int h, Fl_Color col) {
    auto rgb = detail::get_rgb(fl_color_average(FL_WHITE, col, 0.2));
    auto [r, g, b] = rgb;
    auto darker = fl_darker(col);
    auto [r1, g1, b1] = detail::get_rgb(darker);
    auto svg =
        detail::gen_svg(FL_FLAT_RECT_UP, w, h, r, g, b, r1, g1, b1, w, h, FLAT_BORDER_RADIUS);
    detail::draw_image(x, y, w, h, svg);
    free(svg);
}

inline void downbox(int x, int y, int w, int h, Fl_Color col) {
    auto rgb = detail::get_rgb(fl_color_average(FL_WHITE, col, 0.2));
    auto [r, g, b] = rgb;
    auto darker = fl_darker(col);
    auto [r1, g1, b1] = detail::get_rgb(darker);
    auto svg =
        detail::gen_svg(FL_FLAT_RECT_DOWN, w, h, r, g, b, r1, g1, b1, w, h, FLAT_BORDER_RADIUS);
    detail::draw_image(x, y, w, h, svg);
    free(svg);
}

inline void roundedframe(int x, int y, int w, int h, Fl_Color col) {
    auto rgb = detail::get_rgb(fl_color_average(FL_WHITE, col, 0.2));
    auto [r, g, b] = rgb;
    auto svg = detail::gen_svg(FL_FLAT_RECT_FRAME, w, h, w - 2, h - 2, FLAT_BORDER_RADIUS, r, g, b);
    detail::draw_image(x, y, w, h, svg);
    free(svg);
}

inline void init_flat_theme() {
    Fl::reload_scheme();
    Fl::set_boxtype(FL_FLAT_BOX, flat_box, 2, 2, 4, 4);
    Fl::set_boxtype(FL_RFLAT_BOX, upbox, 2, 2, 4, 4);
    Fl::set_boxtype(FL_UP_BOX, upbox, 2, 2, 4, 4);
    Fl::set_boxtype(FL_DOWN_BOX, downbox, 2, 2, 4, 4);
    Fl::set_boxtype(FL_ROUND_UP_BOX, upbox, 2, 2, 4, 4);
    Fl::set_boxtype(FL_ROUND_DOWN_BOX, downbox, 2, 2, 4, 4);
    Fl::set_boxtype(FL_THIN_UP_BOX, upbox, 2, 2, 4, 4);
    Fl::set_boxtype(FL_THIN_DOWN_BOX, downbox, 2, 2, 4, 4);
    Fl::set_boxtype(FL_ROUNDED_FRAME, roundedframe, 2, 2, 4, 4);
    Fl::set_boxtype(FL_UP_FRAME, roundedframe, 2, 2, 4, 4);
    Fl::set_boxtype(FL_DOWN_FRAME, roundedframe, 2, 2, 4, 4);
    Fl::set_boxtype(FL_BORDER_FRAME, roundedframe, 2, 2, 4, 4);
    Fl::set_boxtype(FL_BORDER_BOX, upbox, 2, 2, 4, 4);
}