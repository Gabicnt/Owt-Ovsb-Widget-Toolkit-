#ifndef OWT_BASE_H
#define OWT_BASE_H

#include <stdint.h>

typedef struct owt_widget {
    int x, y, w, h;
    int min_w, min_h;
    int max_w, max_h;
    int padding[4];
    int margin[4];
    uint32_t bg_color;
    uint32_t fg_color;
    uint32_t border_color;
    int border_width;
    int border_radius;
    int visible;
    int enabled;
    struct owt_widget *parent;
    struct owt_widget **children;
    int child_count;
    int child_capacity;
    int id;
    char name[32];
    void *user_data;
    void (*draw)(struct owt_widget *self);
    void (*on_click)(struct owt_widget *self, int x, int y);
    void (*on_key)(struct owt_widget *self, char key, int modifiers);
    void (*on_resize)(struct owt_widget *self);
    void (*on_focus)(struct owt_widget *self);
    void (*on_blur)(struct owt_widget *self);
    void (*destroy)(struct owt_widget *self);
} owt_widget_t;

owt_widget_t *owt_widget_create(int x, int y, int w, int h);
void owt_widget_destroy(owt_widget_t *w);
void owt_widget_add_child(owt_widget_t *parent, owt_widget_t *child);
void owt_widget_draw(owt_widget_t *w);
void owt_widget_set_position(owt_widget_t *w, int x, int y);
void owt_widget_set_size(owt_widget_t *w, int width, int height);

#endif
