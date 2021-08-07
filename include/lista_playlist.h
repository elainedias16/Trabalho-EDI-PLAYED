#ifndef LISTA_PLAYLIST_H_
#define LISTA_PLAYLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "../include/playlist.h"
//#include "../include/lista_pessoa.h"
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

/**
 * @brief Busca uma playlist numa lista de playlists.
 * @param lista Lista de playlists.
 * @param nome Chave de busca.
 * @return Ponteiro para playlist desejada. Caso a playlist não seja encontrada, retorna NULL. 
 **/
Playlist* buscaPlaylistNaLista(Lista_playlist* lista, char* nome);

/**
 * @brief 
 * @param lista 
 * @param nome 
 * @return  
 **/
//void refatoraPlaylistsDasPessoas(Lista_pessoa* listaPessoa);

/**
 * @brief Captura primeira célula de uma lista de playlits.
 * @param listaplaylist É a lista de playlists que terá sua primeira célula capturada. 
 * @return Retorna a primeira célula da lista. 
 **/
CelPlaylist* getFirstCelListaPlaylist(Lista_playlist* listaPlaylist);


/**
 * @brief Captura a próxima célula de playlist.
 * @param celPlaylist É a célula de playlist que terá o seu ponteiro next capturado.
 * @return Retorna a próxima célula de playlist.
 **/
CelPlaylist* getCelulaPlaylistNext(CelPlaylist* celPlaylist);

/**
 * @brief Captura uma playlist de uma célula.
 * @param celPlaylist É a célula de playlist que terá a sua playlist capturada.
 * @return Retorna a playlist da célula.
 **/
Playlist* getPlaylistDaCelula(CelPlaylist* celPlaylist);

void geraNovaListaPlaylist(char* artista, Playlist* novaPlaylist, Lista_playlist* percorrida, Lista_playlist* novaListaPlaylist);

int insereMusicasArtistaAPartirDeListaPlaylist(Playlist* playlistArtista, Lista_playlist* listaPlaylistGenero);


#endif /*LISTA_DE_PLAYLIST_*/