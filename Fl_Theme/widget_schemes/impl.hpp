#pragma once

#include <stdlib.h>
#include <FL/Enumerations.H>
#include <FL/Fl_SVG_Image.H>

extern unsigned fl_cmap[256];

namespace detail {

struct Rgb {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

inline Rgb get_rgb(Fl_Color col) {
    unsigned char r = (col >> 24) & 0xFF;
    unsigned char g = (col >> 16) & 0xFF;
    unsigned char b = (col >> 8) & 0xFF;
    unsigned char i = col & 0xFF;
    if (i == 0) {
        return Rgb{r, g, b};
    } else {
        auto val = fl_cmap[i];
        unsigned char r1 = (val >> 24) & 0xFF;
        unsigned char g1 = (val >> 16) & 0xFF;
        unsigned char b1 = (val >> 8) & 0xFF;
        return Rgb{r1, g1, b1};
    }
}

template<typename ...Args>
char *gen_svg(const char *fmt, Args...args) {
    auto len = snprintf(NULL, 0, fmt, args...);
    auto buf = (char *)malloc(len + 1);
    snprintf(buf, len + 1, fmt, args...);
    return buf;
}

inline void draw_image(int x, int y, int w, int h, const char *str) {
    auto img = new Fl_SVG_Image(NULL, str);
    img->draw(x - 1, y - 1 , w + 2, h + 2);
    delete img;
}
} // namespace detail
