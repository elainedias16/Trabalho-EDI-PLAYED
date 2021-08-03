#ifndef LISTA_PLAYLIST_H_
#define LISTA_PLAYLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "../include/playlist.h"
//#include "../include/lista_playlist.h"

typedef struct celPlaylist CelPlaylist;
typedef struct lista_playlist Lista_playlist;

/**
 * @brief Cria uma lista de playlists vazia.
 * @return Ponteiro para a lista de playlists.
 **/
Lista_playlist* criaListaPlaylist();

/**
 * @brief Libera da memória uma lista de playlists.
 * @param songs Lista de playlists que será liberada.
 **/
void destroiListaPlaylist(Lista_playlist* songs);

/**
 * @brief Imprime uma lista de playlists.
 * @param songs Lista de playlists que será impressa.
 * @param f Ponteiro para arquivo cuja playlist será impressa. Caso necessário imprimir no terminal, considere f == STDOUT.
 **/
void printListaPlaylist(Lista_playlist* songs, FILE* f);

/**
 * @brief Insere uma playlist numa lista de playlists.
 * @param songs Lista de playlists que terá uma nova playlist adicionada.
 * @param playlist Playlist que será inserida.
 **/
void inserePlaylist(Lista_playlist* songs, Playlist* playlist);

#endif /*LISTA_DE_PLAYLIST_*/