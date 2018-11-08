


SDL_Surface *screen;

Uint32 referencia;
Uint32 actual;

const int PANTALLA_ANCHO = 800;
const int PANTALLA_ALTO = 600;



void ventana(){
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        fprintf(stderr,"ERROR NO SE PUEDE INICIAR EL SUBSISTEMA VIDEO %s",SDL_GetError());
        exit(1);
    }

    screen = SDL_SetVideoMode(800,600,32,SDL_RESIZABLE | SDL_SWSURFACE);
    if(screen == NULL){
        fprintf(stderr,"no se puede crear la pantalla %s",SDL_GetError());
        exit(1);
    }
    //nombre de la ventana
    SDL_WM_SetCaption("juego de neto", NULL);
}



void My_Delay(Uint32 milisegundos){
    referencia = SDL_GetTicks();
    do{
        actual = SDL_GetTicks();
    }while(milisegundos > (actual - referencia));
}

//volatile unsigned int contador_tiempo_juego = 0;

//const int FRAME_RATE = 30;

/*void inc_contador_tiempo_juego(){
    contador_tiempo_juego++;
}*/


