#ifndef LISTA_PLAYLIST_H_
#define LISTA_PLAYLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "../include/playlist.h"

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
 * @param pasta Pasta que será impressa a lista de playlists.
 **/
void printListaPlaylist(Lista_playlist* songs, char* pasta);

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

/**
 * @brief Percorre uma lista de playlists procurando por músicas de um determinado artista. Todas as músicas
 * desse artista são transferidas para a sua própria playlist. 
 * @param playlistArtista Playlist do artista.
 * @param listaPlaylistGenero Lista de playlists, que no contexto do trabalho está organizada por gêneros musicais.
 * @return 0, caso a lista de playlists fique vazia e 1, caso contrário.
 **/
int insereMusicasArtistaAPartirDeListaPlaylist(Playlist* playlistArtista, Lista_playlist* listaPlaylistGenero);

/**
 * @brief Dada uma lista de playlists, reorganiza ela com as músicas separadas por artistas.
 * @param listaPlaylistGenero Lista de playlists, que no contexto do trabalho está organizada por gêneros musicais.
 * @return Novo ponteiro para a nova lista de playlists. A playlist separada por gêneros musicais é liberada da memória.
 **/
Lista_playlist* refatoraListaPlaylist(Lista_playlist* listaPlaylistGenero);

/**
 * @brief Captura o tamanho de uma lista de playlists.
 * @param listaPlaylist É a célula de playlist que terá a sua playlist capturada.
 * @return Tamanho de uma lista de playlists1.
 **/
int getTamListaPlaylist(Lista_playlist* listaPlaylist);


/**
 * @brief Escreve uma lista de playlist refatorada no arquivo
 * @param listaPlaylist É a lista de playlist que será impressa.
 * @param f Ponteiro que aponta para o arquivo onde será impresso a lista.
 **/
void escreveListaPlaylistArquivo(Lista_playlist* listaPlaylist, FILE* f);

/**
 * @brief Calcula quantas músicas em comum possuem duas listas de playlists.
 * @param listaP1 Lista de playlists 1.
 * @param listaP2 Lista de playlists 2.
 * @return Quantidade de músicas iguais em duas playlists.
 **/
int similaridadeEntreListaPlaylist(Lista_playlist* listaP1, Lista_playlist* listaP2);

#endif /*LISTA_DE_PLAYLIST_*/
