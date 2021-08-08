// #include <stdio.h>
// #include <stdlib.h>
// #include "../include/playlist.h"
#include "../include/lista_playlist.h"
#include "string.h"

#define TAM 200
#define VAZIO 0
#define NAOVAZIO 1

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
        destroiPlaylist(aux->playlist);
        free(aux);
    }
    free(songs);
}

void printListaPlaylist(Lista_playlist* songs, char* pasta){
    CelPlaylist* i = songs->first;
    FILE* f;
    strcat(pasta, "/");
    char* nomePlaylist;
    char aux[TAM];
    char aux2[TAM];
    strcpy(aux, pasta);
    while(i != NULL){
        nomePlaylist = get_nome_playlist(i->playlist);
        strcpy(aux2, nomePlaylist);
        strcat(aux2, ".txt");
        strcat(pasta, aux2);

        f = fopen(pasta, "w");
        if(f == NULL){
            printf("Erro na abertura do arquivo!\n");
            exit(1);
        }
        printPlaylist(i->playlist, f); //imprime no arquivo
        i = i->next;
        fclose(f);

        strcpy(pasta, aux); // resetando pasta
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

Playlist* buscaPlaylistNaLista(Lista_playlist* lista, char* nome){
    CelPlaylist* i;
    char* nomeAux;
    for(i = lista->first; i != NULL; i = i->next){
        nomeAux = get_nome_playlist(i->playlist);
        if(strcmp(nomeAux, nome) == 0){
            return i->playlist;
        }
    }
    return NULL;
}

CelPlaylist* getFirstCelListaPlaylist(Lista_playlist* listaPlaylist){
    return listaPlaylist->first;
}

CelPlaylist* getCelulaPlaylistNext(CelPlaylist* celPlaylist){
    return celPlaylist->next;
}

Playlist* getPlaylistDaCelula(CelPlaylist* celPlaylist){
    return celPlaylist->playlist;
}

int insereMusicasArtistaAPartirDeListaPlaylist(Playlist* playlistArtista, Lista_playlist* listaPlaylistGenero){
    CelPlaylist* i = listaPlaylistGenero->first;
    CelPlaylist* ant = NULL;
    CelPlaylist* aux;
    int ehVazia;
    while(i != NULL){
        ehVazia = insereMusicasArtistaEmSuaPlaylist(playlistArtista, i->playlist);
        
        if(ehVazia == VAZIO){ //se a playlist for vazia, precisamos retirar ela da lista
            //destroiPlaylist(i->playlist);
            if(listaPlaylistGenero->first == i && listaPlaylistGenero->last == i){ // removendo a unica playlist da lista
                listaPlaylistGenero->first = listaPlaylistGenero->last = NULL;
            
            } else if(listaPlaylistGenero->first == i){ //removendo a primeira playlist da lista
                listaPlaylistGenero->first = i->next;
            
            } else if(listaPlaylistGenero->last == i){ // removendo a ultima playlist da lista
                listaPlaylistGenero->last = ant;
                ant->next = NULL; //! pode dar seg fault, verificar aqui caso dê problema.
                
            } else{ // removendo uma playlist do meio
                ant->next = i->next;
            }
            // remove playlist da lista de playlists
            
            listaPlaylistGenero->tam--;
            aux = i;
            
            if(ant != NULL){
                
            } else{
                i = listaPlaylistGenero->first;
            }
            
            //if(listaPlaylistGenero->tam != 0){
            free(aux); //free na celula da playlist
            //}

            if(listaPlaylistGenero->tam == 0){
                //printf("CHEGOU AQUI\n");
                //destroiPlaylist(i->playlist);
                //destroiListaPlaylist(listaPlaylistGenero);
                return VAZIO;
            }
            continue;
        }
        ant = i;
        i = i->next;
    }
    return NAOVAZIO;
}

Lista_playlist* refatoraListaPlaylist(Lista_playlist* listaPlaylistGenero){
    //a primeira playlist refatora certo, mas da erro quando vai pras proximas
    CelPlaylist* i = listaPlaylistGenero->first;
    Lista_playlist* refatorada = criaListaPlaylist();;
    int ehVazio = 0 ;
    Playlist* playlistArtistaAux;
    CelMusica* aux;
    Musica* musicaAux;
    char* nomeArtista;

    while(i != NULL){
        i = listaPlaylistGenero->first; 
        //printf("endereco de i : [%p]\n", i);
        aux = getFirstCelPlaylist(i->playlist);
        musicaAux = getMusicaCelMusica(aux);
        nomeArtista = get_artista_musica(musicaAux);
        playlistArtistaAux = criaPlaylist(nomeArtista);
        ehVazio = insereMusicasArtistaAPartirDeListaPlaylist(playlistArtistaAux, listaPlaylistGenero);
        inserePlaylist(refatorada, playlistArtistaAux);

        if(ehVazio == VAZIO ){
            destroiListaPlaylist(listaPlaylistGenero);
            break;
        }
        // entrar na primeira playlist
        // ver a primeira musica para pegar o artista


        //i = listaPlaylistGenero->first; //COMENTEI AQUI
        
        //printf("endereco de i depois de 'incrementar': [%p]\n", i);
    }
    //printf("counter [%d]\n", counter);
    //destroiListaPlaylist(listaPlaylistGenero);
    return refatorada;
}

// get first musica de uma playlist
// get nome artista dessa musica


int getTamListaPlaylist(Lista_playlist* listaPlaylist){
    return listaPlaylist->tam;
}

void escreveListaPlaylistArquivo(Lista_playlist* listaPlaylist, FILE* f){
    CelPlaylist* celPlaylistAux = listaPlaylist->first;
    char* nomePlaylist;
    while(celPlaylistAux != NULL){
        nomePlaylist = get_nome_playlist(celPlaylistAux->playlist);
        fprintf(f, "%s", nomePlaylist);

        celPlaylistAux = celPlaylistAux->next;
        
        if(celPlaylistAux == NULL){
            break; //fprintf(f, "\n");
        } else{
            fprintf(f, ";");
        }
    }
}