#include <stdio.h>
#include <stdlib.h>
#include "../include/playlist.h"
#include "../include/lista_playlist.h"

struct celPlaylist{
    Playlist* playlist;
    CelPlaylist* next;
};

struct lista_playlist{
    Playlist* first;
    Playlist* last;
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