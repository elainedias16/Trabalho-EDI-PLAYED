#ifndef PESSOA_H_
#define PESSOA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/lista_playlist.h"
#include "../include/lista_pessoa.h"
//#include "../include/pessoa.h"

typedef struct pessoa Pessoa;

/**
 * @brief Captura o nome de uma pessoa.
 * @param pessoa Pessoa que terá o nome capturado.
 * @return Ponteiro que aponta para o início de uma string do nome da pessoa. 
**/
char* get_nome_pessoa(Pessoa* pessoa);

/**
 * @brief Cria uma pessoa
 * @param nome É o nome da pessoa.
 * @param songs Lista de playlist da pessoa.
 * @param amigos Lista de amigos da pessoa.
 * @return Pessoa criada.
**/
Pessoa* criaPessoa(char* nome, Lista_playlist* songs, Lista_pessoa* amigos);



#endif /*PESSOA_H*/
