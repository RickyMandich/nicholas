#include <allegro5/allegro.h>

int main() {
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;
    ALLEGRO_TIMER* timer = NULL;
    ALLEGRO_BITMAP* ball1 = NULL;
    ALLEGRO_BITMAP* ball2 = NULL;

    // Inizializza Allegro 5
    if (!al_init()) {
        return -1;
    }

    // Crea finestra di visualizzazione
    int width = 800, height = 600;
    display = al_create_display(width, height);
    if (!display) {
        return -1;
    }

    // Crea coda degli eventi e timer
    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 / 60); // 30 FPS
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    // Crea bitmap delle palline
    ball1 = al_create_bitmap(62, 62);
    ball2 = al_create_bitmap(62, 62);
    al_set_target_bitmap(ball1);
    al_clear_to_color(al_map_rgb(255, 0, 0)); // pallina rossa
    al_set_target_bitmap(ball2);
    al_clear_to_color(al_map_rgb(0, 0, 255)); // pallina blu
    al_set_target_bitmap(al_get_backbuffer(display));

    // Posizione iniziale delle palline
    float x1 = 100, y1 = 100, x2 = 200, y2 = 200;
    float vel1_x = 1, vel1_y = 1, vel2_x = 1, vel2_y = 1;

    // Avvia timer e loop di gioco
    al_start_timer(timer);
    bool running = true;
    while (running) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        }else if (ev.type == ALLEGRO_EVENT_TIMER) {
            // Aggiorna posizione delle palline
            x1 += vel1_x;
            y1 += vel1_y;
            x2 += vel2_x;
            y2 += vel2_y;



            // Disegna palline sulla finestra
            al_clear_to_color(al_map_rgb(0, 0, 0)); // sfondo nero
            al_draw_bitmap(ball1, x1, y1, 0);
            al_draw_bitmap(ball2, x2, y2, 0);
            al_flip_display();
        }
    }
}
