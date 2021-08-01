#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct celMusica CelMusica;

typedef struct playlist Playlist;

/**
 * @brief Cria uma playlist vazia.
 * @return Ponteiro para a playlist criada.
 **/
Playlist* criaPlaylist();

/**
 * @brief Insere uma música no final de uma playlist.
 * @param musica Música que será inserida.
 * @param playlist Playlist que terá a música inserida.
 **/
void insereMusica(Musica* musica, Playlist* playlist);

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

#endif /*PLAYLIST*/
