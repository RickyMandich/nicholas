#include <allegro5/allegro.h>
#include <iostream>
#include <algorithm>
using namespace std;

float verify_bounce_border(float position, float velocity, int dimension, int offset);
void verify_bounce_balls(
    float position1x,
    float position1y,
    float position2x,
    float position2y,
    float* velocity1x,
    float* velocity1y,
    float* velocity2x,
    float* velocity2y,
    int offset);

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
    timer = al_create_timer(1.0 / 60);
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
    float vel1_x = 1, vel1_y = 1, vel2_x = -1, vel2_y = -1;

    // Avvia timer e loop di gioco
    al_start_timer(timer);
    bool running = true;
    while (running) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        }else if (ev.type == ALLEGRO_EVENT_TIMER) {
            //Aggiorna posizione delle palline
            x1 += vel1_x;
            y1 += vel1_y;
            x2 += vel2_x;
            y2 += vel2_y;

            vel1_x = verify_bounce_border(x1, vel1_x, width, 62);
            vel1_y = verify_bounce_border(y1, vel1_y, height, 62);
            vel2_x = verify_bounce_border(x2, vel2_x, width, 62);
            vel2_y = verify_bounce_border(y2, vel2_y, height, 62);

            verify_bounce_balls(x1, y1, x2, y2, &vel1_x, &vel1_y, &vel2_x, &vel2_y, 62);

            //Disegna palline sulla finestra
            al_clear_to_color(al_map_rgb(0, 0, 0)); // sfondo nero
            al_draw_bitmap(ball1, x1, y1, 0);
            al_draw_bitmap(ball2, x2, y2, 0);
            al_flip_display();

            cout << "Ball1:\t" << x1 << ", " << y1 << "\t\t";
            cout << "Ball2:\t" << x2 << ", " << y2 << endl;
        }
    }
}

float verify_bounce_border(float position, float velocity, int dimension, int offset){
    // use <= / >= to avoid missing edge collisions
    if(position <= 0 || position >= dimension - offset){
        return -velocity;
    }
    return velocity;
}

void verify_bounce_balls(
    float position1x,
    float position1y,
    float position2x,
    float position2y,
    float *velocity1x,
    float *velocity1y,
    float *velocity2x,
    float *velocity2y,
    int offset){

    float size = static_cast<float>(offset);

    // Proper AABB overlap test (both axes must overlap)
    bool overlapX = position1x < position2x + size && position1x + size > position2x;
    bool overlapY = position1y < position2y + size && position1y + size > position2y;

    if (!overlapX || !overlapY) return; // no collision

    // relative velocities
    float relVx = (*velocity1x) - (*velocity2x);
    float relVy = (*velocity1y) - (*velocity2y);

    // penetration amounts on each axis
    float penX = min(position1x + size, position2x + size) - max(position1x, position2x);
    float penY = min(position1y + size, position2y + size) - max(position1y, position2y);

    // Choose axis of least penetration and invert velocities algebraically on that axis,
    // but only if objects are moving toward each other along that axis.
    if (penX < penY) {
        // collision primarily in X
        if ((position1x < position2x && relVx > 0) || (position1x > position2x && relVx < 0)) {
            *velocity1x = -(*velocity1x);
            *velocity2x = -(*velocity2x);
        }
    }
    else if (penY < penX) {
        // collision primarily in Y
        if ((position1y < position2y && relVy > 0) || (position1y > position2y && relVy < 0)) {
            *velocity1y = -(*velocity1y);
            *velocity2y = -(*velocity2y);
        }
    }
    else {
        // corner case: invert components independently if approaching on that axis
        if ((position1x < position2x && relVx > 0) || (position1x > position2x && relVx < 0)) {
            *velocity1x = -(*velocity1x);
            *velocity2x = -(*velocity2x);
        }
        if ((position1y < position2y && relVy > 0) || (position1y > position2y && relVy < 0)) {
            *velocity1y = -(*velocity1y);
            *velocity2y = -(*velocity2y);
        }
    }
}