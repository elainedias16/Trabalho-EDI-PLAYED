#include "../include/musica.h"

#define TAM 200

struct musica{
    char* nome;
    char* artista;
};

char* get_nome_musica(Musica* musica){
    return musica->nome;
}

char* get_artista_musica(Musica* musica){
    return musica->artista;
}


Musica* criaMusica(char* nome, char* artista){
    Musica* musica = (Musica*) malloc(sizeof(Musica));
    musica->nome = strdup(nome);
    musica->artista = strdup(artista);
    return musica;
}

void destroiMusica(Musica* musica){
    free(musica->nome);
    free(musica->artista);
    free(musica);
}

void printMusica(Musica* musica, FILE* f){
    fprintf(f, "%s - %s" , musica->artista, musica->nome);

}

Musica* leMusica(FILE* f){
    char nome[TAM];
    char artista[TAM];
   
    fscanf(f, "%[^-]%*c%*c%[^\n]\n", artista , nome);
    artista[strlen(artista) - 1] = '\0'; // eliminar o espaço
   
    Musica* musica = criaMusica(nome, artista);
    return musica;
}
