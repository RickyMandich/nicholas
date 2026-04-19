#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
using namespace std;

int main()
{
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;
    ALLEGRO_TIMER* timer = NULL;
    ALLEGRO_COLOR default_color = al_map_rgb(255, 0, 0);
    const int display_width = 800, display_height = 600;
	// ball properties
    float ball_x = 400;
	float ball_y = 300;
    float ball_radius = 30;
	float ball_speed_x = 1;
	float ball_speed_y = 1;
	// paddle properties
	const int paddle_width = ball_radius;
	const int paddle_height = 100;
	float paddle_x = 0;
	float paddle_y = display_height/2 - paddle_height/2;
    // punteggio
	int score = 0;

    // Inizializza Allegro 5
    if (!al_init()) {
        return -1;
    } else {
        al_install_keyboard();
        if (!al_init_primitives_addon()) {
            return -1; // primitives addon failed to initialize
        }
    }

    // Crea finestra di visualizzazione
    display = al_create_display(display_width, display_height);
    if (!display) {
        return -1;
    }

    // Crea coda degli eventi e timer
    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 / 60);
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    // Avvia timer e loop di gioco
    al_start_timer(timer);
    bool running = true;
    while (running) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        } else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (ev.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE:
                    running = false;
                    break;
                case ALLEGRO_KEY_W:
				case ALLEGRO_KEY_UP:
					paddle_y -= 1;
                    break;
                case ALLEGRO_KEY_S:
				case ALLEGRO_KEY_DOWN:
                    paddle_y += 1;
                    break;
			}
		}
        else if (ev.type == ALLEGRO_EVENT_TIMER) {
			ball_x += ball_speed_x;
			ball_y += ball_speed_y;

            // rimbalzo orizzontale (muro laterale destro e paddle)
            if (
                (ball_x - ball_radius <= paddle_width)
                &&
                (paddle_y <= ball_y && ball_y <= paddle_y + paddle_height)
                ||
                (ball_x + ball_radius >= display_width)
                ) {
				ball_speed_x = -ball_speed_x;
            }

			// rimbalzo verticale (muri superiore e inferiore)
            if (
                (ball_y - ball_radius <= 0)
                ||
                (ball_y + ball_radius >= display_height)
                ) {
				ball_speed_y = -ball_speed_y;
            }

            // controllo se tocca il paddle per aggiungere 1 punto
            if (
                (ball_x - ball_radius <= paddle_width)
                &&
                (paddle_y <= ball_y && ball_y <= paddle_y + paddle_height)
                ) {
                score++;
				cout << "Punto! (" << score << ")" << endl;
            }

			// disegna tutto
            al_clear_to_color(al_map_rgb(
                255 - default_color.r,
                255 - default_color.g,
                255 - default_color.b
            ));
            al_draw_filled_circle(ball_x, ball_y, ball_radius, default_color);
			al_draw_filled_rectangle(paddle_x, paddle_y, paddle_x + paddle_width, paddle_y + paddle_height, default_color);
            al_flip_display();
        }
    }
}