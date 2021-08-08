// #include <stdio.h>
// #include <stdlib.h>
// #include "../include/musica.h"
#include "../include/playlist.h"

#define TAM 200
#define VAZIO 0
#define NAOVAZIO 1

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
    while(i != NULL){
        printMusica(i->musica, f);
        i = i->next;
        if(i != NULL){
            fprintf(f, "\n");
        }
    }
}

Playlist* lePlaylist(char* fileName){
    FILE* f = fopen(fileName, "r");
    if(f == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }
    Musica* aux;
    char nome[TAM];
    
    Playlist* playlist = criaPlaylist(fileName);    
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

Musica* getMusicaCelMusica(CelMusica* celMusica){
    return celMusica->musica;
}

CelMusica* getNextMusica(CelMusica* celMusica){
    return celMusica->next;
}

CelMusica* getFirstCelPlaylist(Playlist* playlist){
    return playlist->first;
}

int removeMusicasDeUmArtistaDaPlaylist(Playlist* playlist, char* artista){
   CelMusica* celMusAux = playlist->first;
   CelMusica* celMusAnt = NULL;
   CelMusica* celMusAux2;
   Musica* musicaAux;
   char* artistaAux;
 
    while(celMusAux != NULL){ //Fazendo a procura 
        musicaAux = celMusAux->musica;
        artistaAux = get_artista_musica(musicaAux);
        if(strcmp(artista, artistaAux) == 0){
            if(celMusAux != NULL){ //encontramos a celMusAux que tem o artista que buscamos
                if(celMusAux == playlist->first && celMusAux == playlist->last){ //só tem uma musica na lista
                    playlist->first = playlist->last = NULL;
                    //free(playlist);
                    //destroiPlaylist(playlist);
                    //return VAZIO;
                    //break;
                }
                else if(celMusAux == playlist->first){// a musica a ser retirada eh a primeira da playlist
                    playlist->first = celMusAux->next;
                }
                else if(celMusAux == playlist->last){ //a musica a ser retirada eh a ultima da playlist
                    playlist->last = celMusAnt;
                    celMusAnt->next = NULL;
                }
                else{// a musica a ser retirada nao eh nenhum caso acima
                    celMusAnt->next = celMusAux->next;
                }
                
                celMusAux2 = celMusAux;
                celMusAux = celMusAux->next;
                free(celMusAux2); //retirando a musica da lista
                playlist->tam--;
               
                
                if(playlist->tam == 0){
                    destroiPlaylist(playlist); 
                    return VAZIO;
                }

                continue;
            }
        }   
        celMusAnt = celMusAux;
        celMusAux = celMusAux->next;
    } 
    return NAOVAZIO;
}

int insereMusicasArtistaEmSuaPlaylist(Playlist* playlistArtista, Playlist* playlistGenero){
    CelMusica* i = playlistGenero->first;
    
    char* artistaAux;
    while(i != NULL){
        artistaAux = get_artista_musica(i->musica);
        if(strcmp(playlistArtista->nome, artistaAux) == 0){  
            insereMusica(playlistArtista, i->musica);
        }
        
        i = i->next;
      
    }
    return removeMusicasDeUmArtistaDaPlaylist(playlistGenero, playlistArtista->nome);
}
