


//EN LA MATRIS TIENE UNA CASILLA LIBRE AUNQUE DIGA MAX FILAS 60 EN REALIDAD SON 59 Y AUNQUE DIGA MAXCOL 81 ENREALIDAD SON 80
#define MAXFILA 60
#define MAXCOL 81

char mapa_aux[MAXFILA][MAXCOL]={
  "oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
  "o                                                                              o",
  "o                                                                              o",
  "oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                   oooooooooooo",
  "oXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXoooooooooooo",
  "o                                                                   oooooooooooo",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "oooooXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXo",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "oXXXXXXXXXXXXooooooXXXXXoooooXXXXXoooooXXXXXoooooXXXXXoooooXXXXXoooooXXXXXoooooo",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "ooooooXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXoooooXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXo",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "oXXXXXXXXoooooXXXXXXXXXXXXXXXXXXXXXXXXXoooooXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXoooooo",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "ooooo                                                                          o",
  "o     XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXo",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                         oooooo",
  "oXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXoooooo",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "o                                                                              o",
  "oXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXo",
};

SDL_Surface *bloque;
SDL_Surface *bloque2;
int fil_m = 0, col_m = 0;
SDL_Rect destino_bloque;

void cargar_mapa(){
    bloque = SDL_LoadBMP("bloque1.bmp");
    if(bloque == NULL){
    fprintf(stderr,"Error no se puede cargar el archivo bloque1 %s",SDL_GetError());
    exit(1);
    }
    bloque2 = SDL_LoadBMP("bloque2.bmp");
    if(bloque2 == NULL){
    fprintf(stderr,"Error no se puede cargar el archivo bloque2.bmp %s",SDL_GetError());
    exit(1);
    }
}

void dibujar_mapa(){
    for(fil_m=0; fil_m<MAXFILA ; fil_m++){
        for(col_m=0; col_m<MAXCOL; col_m++){

        destino_bloque.x=col_m*10;
        destino_bloque.y=fil_m*10;
        destino_bloque.w=10;
        destino_bloque.h=10;

            if(mapa_aux[fil_m][col_m] == 'X'){
                    SDL_BlitSurface(bloque,NULL,screen,&destino_bloque);}

            if(mapa_aux[fil_m][col_m] == 'o'){
                    SDL_BlitSurface(bloque2,NULL,screen,&destino_bloque);}



        }


    }
}
