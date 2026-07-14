#include "owt_dialog.h"
#include "owt_draw.h"
#include "owt_theme.h"
#include "owt_button.h"
#include "owt_label.h"
#include "owt_window.h"

// Diálogo simples: desenha no centro da tela
void owt_dialog_message(const char *title, const char *message) {
    int dw = 350, dh = 150;
    int dx = (1024 - dw) / 2;
    int dy = (768 - dh) / 2;
    
    owt_theme_t *t = owt_theme_get();
    
    // Fundo escurecido (overlay)
    owt_draw_rect(0, 0, 1024, 768, 0x80000000);
    
    // Janela do diálogo
    owt_draw_rect(dx, dy, dw, dh, t->bg_primary);
    owt_draw_rect(dx, dy, dw, 1, t->border);
    owt_draw_rect(dx, dy, dw, 28, t->accent);
    owt_draw_text(dx + 10, dy + 6, title, t->text_primary);
    owt_draw_text(dx + 10, dy + 45, message, t->text_secondary);
    
    // Botão OK
    int bx = dx + dw/2 - 40;
    int by = dy + dh - 45;
    owt_draw_rect(bx, by, 80, 30, t->accent);
    owt_draw_text(bx + 25, by + 8, "OK", t->text_primary);
}

int owt_dialog_confirm(const char *title, const char *message) {
    int dw = 350, dh = 150;
    int dx = (1024 - dw) / 2;
    int dy = (768 - dh) / 2;
    
    owt_theme_t *t = owt_theme_get();
    
    owt_draw_rect(0, 0, 1024, 768, 0x80000000);
    owt_draw_rect(dx, dy, dw, dh, t->bg_primary);
    owt_draw_rect(dx, dy, dw, 28, t->accent);
    owt_draw_text(dx + 10, dy + 6, title, t->text_primary);
    owt_draw_text(dx + 10, dy + 45, message, t->text_secondary);
    
    // Botão Sim
    owt_draw_rect(dx + 50, dy + dh - 45, 80, 30, t->accent);
    owt_draw_text(dx + 70, dy + dh - 37, "Sim", t->text_primary);
    
    // Botão Não
    owt_draw_rect(dx + dw - 130, dy + dh - 45, 80, 30, t->bg_secondary);
    owt_draw_text(dx + dw - 105, dy + dh - 37, "Nao", t->text_primary);
    
    return 1; // Sempre retorna Sim por enquanto (sem input real)
}
