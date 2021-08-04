// #include <stdio.h>
// #include <stdlib.h>
// #include "../include/musica.h"
#include "../include/playlist.h"

#define TAM 50

struct celMusica{
    Musica* musica;
    CelMusica* next;
};

struct playlist{
    CelMusica* first;
    CelMusica* last;
    char* nome;
    int tam;
};

char* get_nome_playlist(Playlist* playlist){
    return playlist->nome;
}

Playlist* criaPlaylist(char* nome){
    Playlist* playlist = (Playlist*) malloc(sizeof(Playlist));
    playlist->first = NULL;
    playlist->last = NULL;
    playlist->nome = strdup(nome);
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
        destroiMusica(aux->musica); //! TALVEZ DE PROBLEMA
        free(aux);
    }
    free(playlist->nome);
    free(playlist);
}

void printPlaylist(Playlist* playlist, FILE* f){
    CelMusica* i = playlist->first;
    fprintf(f, "Nome playlist: %s\n", playlist->nome);
    while(i != NULL){
        //!printMusica(i->musica, f);
        i = i->next;
        //!printf("\n");
    }
}

Playlist* lePlaylist(char* fileName){
    FILE* f = fopen(fileName, "r");
    if(f == NULL){
        printf("Erro na abertura do arquvio!\n");
        exit(1);
    }
    Musica* aux;
    char nome[TAM];
    sscanf(fileName, "z-inputs/Entrada/%s", nome); //esta hardcodado, queremos melhorar isso, embora funcione
    //!sscanf(fileName, "%*s/%s", nome);
    
    Playlist* playlist = criaPlaylist(nome);    
    while(!feof(f)){
        aux = leMusica(f);
        insereMusica(playlist, aux);

        if(feof(f)){
            break;
        }
    }
    //z-input/entrada/acoustic.txt
    
    fclose(f);
    return playlist;
}

