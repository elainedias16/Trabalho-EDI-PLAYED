#ifndef MUSICA_H
#define MUSICA_H

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
char* get_genero_musica(Musica* musica);

#endif /*MUSICA_H*/
