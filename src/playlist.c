#include <stdio.h>
#include <stdlib.h>
#include "../include/musica.h"
#include "../include/playlist.h"

struct celMusica{
    Musica* musica;
    CelMusica* next;
};

struct playlist{
    CelMusica* first;
    CelMusica* last;
    int tam;
};
