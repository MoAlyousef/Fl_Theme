#pragma once

#include <FL/Enumerations.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/fl_draw.H>

class Toggle : public Fl_Toggle_Button {
    const char *label_ = NULL;

  protected:
    virtual void draw() override {
        if (label_) {
            fl_color(0xffffff00);
            fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
            fl_draw(label_, x() - 100, y(), 80, h(), FL_ALIGN_CENTER);
        }
        Fl_Toggle_Button::draw();
    }
    virtual int handle(int e) override {
        auto ret = 0;
        switch (e) {
        case FL_PUSH: {
            if (value()) {
                align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
                labelcolor(FL_RED);
            } else {
                align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);
                labelcolor(FL_GREEN);
            }
            parent()->redraw();
            ret = 1;
        }
        }
        return Fl_Toggle_Button::handle(e) | ret;
    }

  public:
    Toggle(int x, int y, int w, int h, const char *label = NULL)
        : Fl_Toggle_Button(x, y, w, h, "@+6square"), label_(label) {
        align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        labelcolor(FL_RED);
        color(0xffffff00);
        selection_color(0xffffff00);
        box(FL_FLAT_BOX);
        down_box(FL_FLAT_BOX);
        clear_visible_focus();
    }
};