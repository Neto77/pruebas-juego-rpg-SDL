#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "iniciar_ventana.h"
#include "imagenes.h"
//#include "mapa.h"
//#include "player.h"
//#include "mijuego.h"



int main(int argc, char * args[])
{

    ventana();

    cargar_imagenes();
    cargar_mapa();




    salir = false;
    while(!salir){


        pintar_imagenes();
        //dibujar_mapa();
        animar();
        posicion();
        limites_colisiones();
        SDL_Flip(screen);
        My_Delay(20);
        teclado_y_salida();

    }


    SDL_FreeSurface(fondo);
    SDL_FreeSurface(imagen);
    SDL_FreeSurface(screen);
    SDL_Quit();
    return 0;
}
