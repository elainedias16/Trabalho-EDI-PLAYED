#ifndef MUSICA_H
#define MUSICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "../include/musica.h"

typedef struct musica Musica;

/**
 * @brief Captura o ponteiro para o início da string que representa o nome de uma música.
 * @param musica Música que terá seu nome capturado.
 * @return Ponteiro para nome de uma música.
 **/
char* get_nome_musica(Musica* musica);

/**
 * @brief Captura o ponteiro para o início da string que representa o artista ou a banda de uma música.
 * @param musica Música que terá seu artista capturado.
 * @return Ponteiro para o artista de uma música.
 **/
char* get_artista_musica(Musica* musica);

/**
 * @brief Captura o ponteiro para o início da string que representa o gênero de uma música.
 * @param musica Música que terá seu nome pego.
 * @return Ponteiro para nome de um gênero de uma música.
 **/
//!char* get_genero_musica(Musica* musica);

/** 
 * @brief Cria uma musica
 * @param nome É o nome da musica.
 * @param artista É o artista da musica.
 * @return Retorna a musica criada.
 **/
Musica* criaMusica(char* nome, char* artista);

/**
 * @brief Libera uma música da memória.
 * @param musica Música que será liberada.
 **/
void destroiMusica(Musica* musica);

/**
 * @brief Imprime os dados de uma música.
 * @param musica Música que será impressa.
 * @param f Ponteiro para o arquivo cuja música será impresso. Para imprimir no terminal, considere f == STDOUT.
 **/
void printMusica(Musica* musica, FILE* f);

/**
 * @brief Faz a leitura das informações de uma música em um .txt e a inicializa.
 * @param f Ponteiro do arquivo cujos dados serão pegos.
 * @return Música inicializada.
 **/
Musica* leMusica(FILE* f);

#endif /*MUSICA_H*/
