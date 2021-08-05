#ifndef PESSOA_H_
#define PESSOA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/lista_playlist.h"
//#include "../include/pessoa.h"

typedef struct pessoa Pessoa;
#include "../include/lista_pessoa.h"

/**
 * @brief Captura o nome de uma pessoa.
 * @param pessoa Pessoa que terá o nome capturado.
 * @return Ponteiro que aponta para o início de uma string do nome da pessoa. 
**/
char* get_nome_pessoa(Pessoa* pessoa);

/**
 * @brief Captura o ponteiro para a lista de playlists de uma pessoa.
 * @param pessoa Pessoa que terá sua lista de playlists capturada.
 * @return Ponteiro para lista de playlists da pessoa. 
**/
Lista_playlist* get_lista_playlist_pessoa(Pessoa* pessoa);

/**
 * @brief Captura o ponteiro para a lista de amigos de uma pessoa.
 * @param pessoa Pessoa que terá sua lista de amigos capturada.
 * @return Ponteiro para lista de amigos da pessoa. 
**/
Lista_pessoa* get_lista_amigos_pessoa(Pessoa* pessoa);

/**
 * @brief Cria uma pessoa.
 * @param nome É o nome da pessoa.
 * @return Pessoa criada.
**/
Pessoa* criaPessoa(char* nome);

/**
 * @brief Libera uma pessoa da memória.
 * @param pessoa Pessoa que será liberada.
 **/
void destroiPessoa(Pessoa* pessoa);

/**
 * @brief Imprime os dados de uma pessoa.
 * @param pessoa Pessoa que será impressa.
 * @param f Ponteiro para o arquivo cuja pessoa será impresso. Para imprimir no terminal, considere f == STDOUT.
 **/
void printPessoa(Pessoa* pessoa, FILE* f);

/**
 * @brief Atualiza o ponteiro para a lista de playlists do usuário.
 * @param pessoa Pessoa que terá o ponteiro songs atualizado.
 * @return Pessoa com o campo songs atualizado.
 **/
Pessoa* setSongs(Pessoa* pessoa, Lista_playlist* songs);

/**
 * @brief Atualiza o ponteiro para a lista de amigos do usuário.
 * @param pessoa Pessoa que terá o ponteiro amigos atualizado.
 * @return Pessoa com o campo amigos atualizado.
 **/
Pessoa* setAmigos(Pessoa* pessoa, Lista_pessoa* amigos);

/**
 * @brief Inicializa a lista de usuários do PLAYED com a leitura do arquivo amizades.txt e playlists.txt.
 * @param fileNameAmizades Caminho para o arquivo amizades.txt.
 * @param fileNamePlaylists Caminho para o arquivo playlists.txt.
 * @return Lista de pessoas com os campos 'nome', 'amigos' e 'songs', inicializados.
 **/
Lista_pessoa* inicializaUsuarios(char* fileNameAmizades, char* fileNamePlaylists);

/**
 * @brief Coloca as playlists da pessoa no campo songs (onde é armazenado a lista de de playlists da pessoa)
 * @param listaPessoa Lista de pessoas do PLAYED.
 * @param fileNamePlaylists Caminho para o arquivo playlists.txt.
 **/
void inserePlaylistsNasPessoas(Lista_pessoa* listaPessoa, char* fileNamePlaylists);

#endif /*PESSOA_H*/
