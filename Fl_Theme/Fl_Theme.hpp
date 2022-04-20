#pragma once

#include <stddef.h>
#include <FL/Fl.H>
#include "widget_schemes/all.hpp"
#include "color_themes/all.hpp"

struct ColorTheme {
    template<size_t N>
    static void apply(const unsigned char (&color_map)[N][4]) {
        unsigned char i = 0;
        for (size_t i = 0; i < N; i++) {
            auto val = color_map[i];
            Fl::set_color(val[0], val[1], val[2], val[3]);
        }
    }
};

enum class SchemeType {
    Flat,
};

struct WidgetScheme {
    static void apply(SchemeType typ) {
        switch (typ) {
            case SchemeType::Flat: init_flat_theme();
        }
    }
};

enum class ThemeType {
    Dark,
};

struct WidgetTheme {
    static void apply(ThemeType typ) {
        switch (typ) {
            case ThemeType::Dark: {
                init_flat_theme();
                ColorTheme::apply(BLACK_THEME); 
                Fl::background(70, 70, 70);
                break;
            }
        }
    }
};
