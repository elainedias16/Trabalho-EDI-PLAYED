#include <stdio.h>
#include <stdlib.h>
#include "../include/musica.h"

struct musica{
    char* nome;
    char* artista;
    char* genero;
};

char* get_nome_musica(Musica* musica){
    return musica->nome;
}

char* get_artista_musica(Musica* musica){
    return musica->artista;
}

char* get_genero_musica(Musica* musica){
    return musica->genero;
}