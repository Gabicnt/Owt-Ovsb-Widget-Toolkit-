# Guia Rápido do OWT - Criando Apps no Ovsb.OS

## 1. Incluir a biblioteca
```c
#include <owt.h>
```

## 2. Criar uma janela
```c
owt_window_t *janela = owt_window_create("Meu App", 100, 100, 400, 300);
```

## 3. Adicionar um texto (label)
```c
owt_label_t *texto = owt_label_create("Olá Mundo!", 10, 20);
```

## 4. Adicionar um botão
```c
owt_button_t *botao = owt_button_create("Clique Aqui", 10, 60, 120, 30);
```

## 5. Colocar widgets na janela
```c
owt_window_set_content(janela, (owt_widget_t *)texto);
owt_widget_add_child((owt_widget_t *)janela, (owt_widget_t *)botao);
```

## 6. Mudar o tema
```c
owt_theme_set(&THEME_LIGHT);  // Tema claro
owt_theme_set(&THEME_DARK);   // Tema escuro (padrão)
```

## 7. Cores do tema atual
```c
THEME_BG        // Fundo principal
THEME_TEXT      // Texto principal
THEME_ACCENT    // Cor de destaque
THEME_BORDER    // Cor da borda
```

## 8. Desenhar livremente
```c
owt_draw_rect(10, 10, 100, 50, THEME_ACCENT);     // Retângulo
owt_draw_text(20, 20, "Texto", THEME_TEXT);         // Texto
owt_draw_pixel(50, 50, 0xFFFF0000);                 // Pixel vermelho
```

---

## EXEMPLO COMPLETO: App "Olá Mundo"
```c
#include <owt.h>

void meu_app(void) {
    owt_window_t *win = owt_window_create("Olá Mundo", 200, 100, 300, 200);
    owt_label_t *lbl = owt_label_create("Bem-vindo ao Ovsb.OS!", 50, 30);
    owt_button_t *btn = owt_button_create("Fechar", 90, 80, 100, 30);
    
    owt_widget_add_child((owt_widget_t *)win, (owt_widget_t *)lbl);
    owt_widget_add_child((owt_widget_t *)win, (owt_widget_t *)btn);
    owt_widget_draw((owt_widget_t *)win);
}
```

---

## EXEMPLO: App Calculadora (esqueleto)
```c
#include <owt.h>

owt_label_t *display;

void botao_clicado(owt_button_t *btn) {
    // Adiciona o número no display
}

void calculadora(void) {
    owt_window_t *win = owt_window_create("Calculadora", 100, 100, 200, 280);
    display = owt_label_create("0", 10, 10);
    
    const char *nums[] = {"7","8","9","4","5","6","1","2","3","0"};
    for (int i = 0; i < 10; i++) {
        int col = i % 3, row = i / 3;
        owt_button_t *b = owt_button_create(nums[i], 
            10 + col * 60, 50 + row * 55, 55, 50);
        b->on_click = botao_clicado;
        owt_widget_add_child((owt_widget_t *)win, (owt_widget_t *)b);
    }
    
    owt_widget_add_child((owt_widget_t *)win, (owt_widget_t *)display);
    owt_widget_draw((owt_widget_t *)win);
}
```

---

## RESUMO DAS FUNÇÕES

| Função | O que faz |
|--------|-----------|
| `owt_window_create(titulo, x, y, w, h)` | Cria janela |
| `owt_label_create(texto, x, y)` | Cria texto |
| `owt_button_create(texto, x, y, w, h)` | Cria botão |
| `owt_window_set_content(win, widget)` | Define conteúdo |
| `owt_widget_add_child(pai, filho)` | Adiciona widget |
| `owt_widget_draw(widget)` | Desenha na tela |
| `owt_theme_set(&THEME_DARK)` | Muda tema |
| `owt_draw_rect(x, y, w, h, cor)` | Desenha retângulo |
| `owt_draw_text(x, y, texto, cor)` | Desenha texto |
| `owt_draw_pixel(x, y, cor)` | Desenha pixel |
