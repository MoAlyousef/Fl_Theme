#pragma once

#include "color_themes/all.hpp"
#include "widget_schemes/all.hpp"
#include <FL/Enumerations.H>
#include <FL/Fl.H>
#include <stddef.h>

struct ColorTheme {
    template <size_t N>
    static void apply(const unsigned char (&color_map)[N][4]) {
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
        case SchemeType::Flat:
            init_flat_theme();
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
            Fl::foreground(255, 255, 255);
            Fl::set_color(FL_SELECTION_COLOR, 48, 79, 120);
            break;
        }
        }
    }
};
