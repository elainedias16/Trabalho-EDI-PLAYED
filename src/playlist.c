// #include <stdio.h>
// #include <stdlib.h>
// #include "../include/musica.h"
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

Playlist* criaPlaylist(){
    Playlist* playlist = (Playlist*) malloc(sizeof(Playlist));
    playlist->first = NULL;
    playlist->last = NULL;
    playlist->tam = 0;
    return playlist;
}

void insereMusica(Playlist* playlist, Musica* musica){
    CelMusica* nova = (CelMusica*)malloc(sizeof(CelMusica));
    nova->musica = musica;
    nova->next = NULL;
    if(playlist->tam != 0)
        playlist->last->next = nova; // Encadeando na lista.
    
    playlist->last = nova; // Atualizando sentinela last.

    if(playlist->tam == 0){ // Caso seja a primeira música, atualizar sentinela first.
        playlist->first = nova;
    }

    playlist->tam++;
}

void destroiPlaylist(Playlist* playlist){
    CelMusica* i = playlist->first;
    CelMusica* aux;
    while(i != NULL){
        aux = i;
        i = i->next;
        //! destroiMusica(aux->musica);
        free(aux);
    }
    free(playlist);
}

void printPlaylist(Playlist* playlist, FILE* f){
    CelMusica* i = playlist->first;
    while(i != NULL){
        printMusica(i->musica, f);
        i = i->next;
        printf("\n");
    }
}

Playlist* lePlaylist(char* fileName){
    FILE* f = fopen(fileName, "r");
    if(f == NULL){
        printf("Erro na abertura do arquvio!\n");
        exit(1);
    }
    Playlist* playlist = criaPlaylist();
    //while]
    //dentro do while chamar leMusica

    fclose(f);
    return playlist;
}

Musica* leMusica(char* fileName){
    // char nome[TAM];
    // char artista[TAM];
    // char genero[TAM];
    // // fscanf(f, );
    // Musica* musica = criaMusica();
}