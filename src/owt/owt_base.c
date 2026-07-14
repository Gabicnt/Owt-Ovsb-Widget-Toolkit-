#include "owt_base.h"

owt_widget_t *owt_widget_create(int x, int y, int w, int h) {
    owt_widget_t *widget = (owt_widget_t *)kmalloc(sizeof(owt_widget_t));
    if (!widget) return 0;
    widget->x = x; widget->y = y; widget->w = w; widget->h = h;
    widget->visible = 1;
    widget->enabled = 1;
    widget->child_count = 0;
    widget->child_capacity = 4;
    widget->children = (owt_widget_t **)kmalloc(sizeof(owt_widget_t *) * 4);
    return widget;
}

void owt_widget_add_child(owt_widget_t *parent, owt_widget_t *child) {
    if (parent->child_count >= parent->child_capacity) {
        parent->child_capacity *= 2;
        // realloc simplificado
    }
    parent->children[parent->child_count++] = child;
    child->parent = parent;
}

void owt_widget_draw(owt_widget_t *w) {
    if (!w || !w->visible) return;
    if (w->draw) w->draw(w);
    for (int i = 0; i < w->child_count; i++) {
        owt_widget_draw(w->children[i]);
    }
}
