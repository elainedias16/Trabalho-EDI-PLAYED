// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
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

Musica* criaMusica(char* nome, char* artista, char* genero){
    Musica* musica = (Musica*) malloc(sizeof(Musica));
    musica->nome = strdup(nome);
    musica->artista = strdup(artista);
    musica->genero = strdup(genero);
    return musica;
}

void destroiMusica(Musica* musica){
    free(musica->nome);
    free(musica->artista);
    free(musica->genero);
    free(musica);
}

void printMusica(Musica* musica, FILE* f){
    fprintf(f, "Nome: %s\n" , musica->nome);
    fprintf(f, "Artista: %s\n", musica->artista);
    fprintf(f, "Genero: %s\n", musica->genero);
}

