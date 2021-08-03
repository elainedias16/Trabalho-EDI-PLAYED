// #include <stdio.h>
// #include <stdlib.h>
// #include "../include/playlist.h"
#include "../include/lista_playlist.h"

struct celPlaylist{
    Playlist* playlist;
    CelPlaylist* next;
};

struct lista_playlist{
    CelPlaylist* first;
    CelPlaylist* last;
    int tam;
};

Lista_playlist* criaListaPlaylist(){
    Lista_playlist* lista = (Lista_playlist*) malloc (sizeof (Lista_playlist));
    lista->first =NULL;
    lista->last = NULL;
    lista->tam = 0;
    return lista;
}

void destroiListaPlaylist(Lista_playlist* songs){
    CelPlaylist* i = songs->first;
    CelPlaylist* aux;
    while(i != NULL){
        aux = i;
        i = i->next;
        //!destroiPlaylist(i->playlist);
        free(aux);
    }
    free(songs);
}

void printListaPlaylist(Lista_playlist* songs, FILE* f){
    CelPlaylist* i = songs->first;
    while(i != NULL){
        fprintf(f, "\n-----\n");
        printPlaylist(i->playlist, f);
        i = i->next;
        fprintf(f, "\n-----\n");
    }
}

void inserePlaylist(Lista_playlist* songs, Playlist* playlist){
    CelPlaylist* nova = (CelPlaylist*)malloc(sizeof(CelPlaylist));
    nova->playlist = playlist;
    nova->next = NULL;

    if(songs->tam != 0)
        songs->last->next = nova;
    
    songs->last = nova;

    if(songs->tam == 0){
        songs->first = nova;
    }
    songs->tam++;
}
