#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "../include/musica.h"
//#include "../include/playlist.h"


typedef struct celMusica CelMusica;

typedef struct playlist Playlist;

/**
 * @brief Cria uma playlist vazia.
 * @return Ponteiro para a playlist criada.
 **/
Playlist* criaPlaylist();

/**
 * @brief Insere uma música no final de uma playlist.
 * @param playlist Playlist que terá a música inserida.
 * @param musica Música que será inserida.
 **/
void insereMusica(Playlist* playlist, Musica* musica);

/**
 * @brief Libera da memória uma lista de músicas. Essa função não libera o conteúdo das celulas.
 * É responsabilidade do programador liberar as músicas quando necessário.
 * @param playlist Playlist que será liberada.
 **/
void destroiPlaylist(Playlist* playlist);

/**
 * @brief Imprime todas as músicas de uma playlist.
 * @param playlist Playlist que será impressa.
 * @param f Ponteiro para arquivo cuja playlist será impressa. Para printar no terminal, considere f == STDOUT.
 **/
void printPlaylist(Playlist* playlist, FILE* f);

/**
 * @brief Lê os dados de todas as músicas de um .txt e cria uma playlist.
 * @param fileName É o caminho para o arquivo.
 * @return Ponteiro para uma lista de músicas.
 **/
Playlist* lePlaylist(char* fileName);

#endif /*PLAYLIST*/
