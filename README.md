# 🎨 OWT - Ovsb.OS Widget Toolkit

Biblioteca gráfica nativa do **Ovsb.OS** para criação de interfaces com widgets prontos.

[![Widgets](https://img.shields.io/badge/widgets-11-blue)](#)
[![Temas](https://img.shields.io/badge/temas-2-purple)](#)
[![Status](https://img.shields.io/badge/status-completo-green)](#)

---

## ✅ Widgets Implementados

| Widget | Arquivo | Descrição |
|--------|---------|-----------|
| 🪟 Window | `owt_window` | Janela com barra de título |
| 📝 Label | `owt_label` | Texto simples |
| 🔘 Button | `owt_button` | Botão clicável com hover |
| 📥 TextBox | `owt_textbox` | Input de 1 linha com cursor |
| 📄 TextArea | `owt_textarea` | Editor multilinhas |
| 📋 ListView | `owt_listview` | Lista selecionável |
| 🔽 ComboBox | `owt_combobox` | Dropdown de opções |
| 📊 Menu | `owt_menu` | Barra de menu |
| 💬 Dialog | `owt_dialog` | Diálogos modais |
| 📌 StatusBar | `owt_statusbar` | Barra de status |
| 🎨 Theme | `owt_theme` | Temas escuro/claro |

---

## 🚀 Exemplo Rápido

```c
#include <owt.h>

void meu_app(void) {
    owt_window_t *win = owt_window_create("Meu App", 100, 100, 400, 300);
    owt_label_t *lbl = owt_label_create("Bem-vindo ao OWT!", 80, 40);
    owt_button_t *btn = owt_button_create("Clique Aqui", 120, 100, 150, 35);
    owt_textbox_t *input = owt_textbox_create(50, 160, 300);
    owt_statusbar_t *sb = owt_statusbar_create(0, 280, 400);
    
    owt_window_set_content(win, (owt_widget_t *)lbl);
    owt_widget_add_child((owt_widget_t *)win, (owt_widget_t *)btn);
    owt_widget_draw((owt_widget_t *)win);
}

📦 Estrutura
text

src/owt/
├── owt.h              # Header principal
├── owt_base.h/c       # Widget base
├── owt_draw.h/c       # Primitivas de desenho
├── owt_theme.h/c      # Temas (escuro/claro)
├── owt_window.h/c     # Janelas
├── owt_label.h/c      # Labels
├── owt_button.h/c     # Botões
├── owt_textbox.h/c    # Input de texto
├── owt_statusbar.h/c  # Barra de status
├── owt_listview.h/c   # Listas
├── owt_combobox.h/c   # Dropdowns
├── owt_menu.h/c       # Menus
└── owt_dialog.h/c     # Diálogos

🎨 Temas
c

owt_theme_set(&THEME_DARK);   // Tema escuro (padrão)
owt_theme_set(&THEME_LIGHT);  // Tema claro

Cores: THEME_BG, THEME_TEXT, THEME_ACCENT, THEME_BORDER, THEME_TEXT2
📐 Desenho Livre
c

owt_draw_rect(10, 10, 100, 50, THEME_ACCENT);
owt_draw_text(20, 20, "Texto", THEME_TEXT);
owt_draw_pixel(50, 50, 0xFFFF0000);

🏗️ Build
bash

git clone https://github.com/Gabicnt/Owt-Ovsb-Widget-Toolkit-
cd Owt-Ovsb-Widget-Toolkit-
# Adicione os .c e .h ao seu projeto
# Inclua o diretório src/owt no -I do GCC

📝 Licença: MIT
🔗 Ovsb.OS: github.com/Gabicnt/Ovsb.OS
