#define CIMGGIP_MAIN
#include "CImgGIP08.h"

int main()
{
    // Für das "blaue Spielfeld" ...
    const int left_border = 100;
    const int right_border = 500;

    // Für Ausdehnung und Position des weißen Quadrats ...
    int x = 200, y = 300;
    const int rectangle_size = 50;
    int delta = 10;
    int dir = 1;
    gip_white_background();

    while (gip_window_not_closed())
    {
        // Blaues "Spielfeld" neu zeichnen
        // (übermalt dann auch das letzte weiße Quadrat) ...
        gip_draw_rectangle(left_border, 100, // linke obere Ecke
            right_border, 500, // rechte untere Ecke
            blue);

        // Weißes Quadrat neu zeichnen an der Position x,y ...
        gip_draw_rectangle(x, y,    // linke obere Ecke
            x + rectangle_size,  // rechte untere Ecke
            y + rectangle_size,
            white);

        x += dir*delta;
        if(x <= left_border || x+rectangle_size >= right_border){
            dir  *= -1;
        }


        // Nächste Position des weißen Quadrats berechnen.
        // Dabei berücksichtigen, dass das Quadrat von den Rändern des
        // blauen "Spielfelds" abprallen muss ...

		// TODO
        // Ihr Code zur Berechnung der neuen Werte von x und y hier ...


        gip_wait(50);
    }
    return 0;
}
