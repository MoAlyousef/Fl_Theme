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
    Metro,
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
    Metro,
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
        case ThemeType::Metro: {
            init_metro_theme();
            Fl::background(0xF0, 0xF0, 0xF0);
            Fl::background2(0xFF, 0xFF, 0xFF);
            Fl::foreground(0x00, 0x00, 0x00);
            Fl::set_color(FL_INACTIVE_COLOR, 0x6F, 0x6F, 0x6F);
            Fl::set_color(FL_SELECTION_COLOR, 0x33, 0x99, 0xFF);
            Fl::set_color(FL_FREE_COLOR, 0xFF, 0xFF, 0xFF);
            break;
        }
        }
    }
};
