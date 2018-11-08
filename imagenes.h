

#include "mapa.h"

bool salir;
Uint8 *teclas;

//declarar imagenes
SDL_Surface *fondo;
SDL_Surface *imagen;
SDL_Surface *choque;
//SDL_Surface *colicionador;

//definir origen de la imagen
SDL_Rect origen;
//SDL_Rect origen2;
//definir destino de la imagen
SDL_Rect destino;
SDL_Rect destino2;


int ax,ay,bx,by,ex,ey,animacion,direccion;






int desplazamiento_x_derecha = 4;
int desplazamiento_y_arriba = 4;
int desplazamiento_x_izquierda = 4;
int desplazamiento_y_abajo = 4;


void cargar_imagenes(){

    fondo = SDL_LoadBMP("casa.bmp");
    if(fondo == NULL){
        fprintf(stderr,"no se puede cargar el fondo imagen podria no tener el nombre correcto o no se detecta el archivo %s",SDL_GetError());
        exit(1);
    }

    choque = SDL_LoadBMP("casa-choque.bmp");
    //SDL_SetColorKey(colicionador, SDL_SRCCOLORKEY, SDL_MapRGB(colicionador->format, 255, 0, 0));
    /*SDL_SetColorKey(colicionador, SDL_SRCCOLORKEY, SDL_MapRGB(colicionador->format, 0, 0, 0));
    if(colicionador == NULL){
        fprintf(stderr,"no se puede cargar el fondo imagen podria no tener el nombre correcto o no se detecta el archivo %s",SDL_GetError());
        exit(1);
    }*/

    imagen = SDL_LoadBMP("personaje.bmp");
    //El protagonista debe tener contorno transparente
    SDL_SetColorKey(imagen, SDL_SRCCOLORKEY, SDL_MapRGB(imagen->format, 255, 0, 255));
    if(imagen == NULL){
        fprintf(stderr,"no se puede cargar la imagen podria no tener el nombre correcto o no se detecta el archivo %s",SDL_GetError());
        exit(1);
    }
}


void pintar_imagenes(){
    //con sdl filrect bmos el rastro de la imagen y siempre debe ponerse una linea antes de pintar la imagen
    SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));

    //dibujar_mapa();
    //SDL_FillRect(colicionador,NULL,SDL_MapRGB(colicionador->format,255,0,0));

    //imagen de fondo
    SDL_BlitSurface(fondo,NULL,screen,&destino2);

    //colicion de casa
    //SDL_BlitSurface(colicionador,NULL,screen,NULL);

    //con sdl blit surface pintamos la imagen del personaje
    SDL_BlitSurface(imagen,&origen,screen,&destino);
}

void animar(){

    //SDL_BlitSurface(fondo,NULL,screen,NULL);
    //x,y el lugar donde se lee la imagen y w,h el tamaño  de donde se lee del personaje
    origen.x=(animacion*32);
    origen.y=(direccion*32);
    origen.w=32;
    origen.h=32;
}

void posicion(){
    destino2.x = 150;
    destino2.y = 150;
    //x , y, el lugar donde se pinta la imagen y w,h el tamaño donde se pinta del personaje
    //destino.x = 0;
    //destino.y = 50;
    //destino.w=32;
    //destino.h=32;


    destino.x = destino2.x;
    destino.y = destino2.y;

    destino.x += ex;
    destino.y += ey;





}

void limites_colisiones(){
    int cx,cy,dx,dy;
    cx = 0;
    cy = 50;
    dx = 450;
    dy = 290;


    if(ex < cx){desplazamiento_x_izquierda=0;}else{desplazamiento_x_izquierda=4;}
    if(ey < cy){desplazamiento_y_arriba=0;}else{desplazamiento_y_arriba=4;}
    if(ex > dx){desplazamiento_x_derecha=0;}else{desplazamiento_x_derecha=4;}
    if(ey > dy){desplazamiento_y_abajo=0;}else{desplazamiento_y_abajo=4;}






    //prueva colisiones con bloques
    //if(ay == 'X'){desplazamiento_y -= 2; desplazamiento_x = 4;}
    //if(ax == 'o'){desplazamiento_x -= 0; desplazamiento_y = 4;}
    //if(ax > 'X' && ay > 'o'){desplazamiento_x = 4; desplazamiento_y = 4;}


}


void teclado_y_salida(){
    //evento para poder usar teclas
    SDL_Event event;
    SDL_PollEvent(&event);
    teclas = SDL_GetKeyState(NULL);



    //teclas movimiento del personaje
    if(teclas[SDLK_UP]){
        ey -= desplazamiento_y_arriba;
        direccion=3;
        animacion++;
    }
    if(teclas[SDLK_DOWN]){
        ey+=desplazamiento_y_abajo;
        direccion=0;
        animacion++;
    }
    if(teclas[SDLK_LEFT]){
        ex-=desplazamiento_x_izquierda;
        direccion=1;
        animacion++;
    }
    if(teclas[SDLK_RIGHT]){
        ex+=desplazamiento_x_derecha;
        direccion=2;
        animacion++;
    }
    //animacion
    if(animacion > 2){
        animacion = 0;
    }

    //tecla para salir de la ventana
    if(teclas[SDLK_ESCAPE]) salir = true;
}

