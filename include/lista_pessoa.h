#ifndef LISTA_PESSOA_H_
#define LISTA_PESSOA_H_

// #include <stdio.h>
// #include <stdlib.h>
// #include "../include/lista_pessoa.h"

typedef struct celPessoa CelPessoa;
typedef struct lista_pessoa Lista_pessoa;
#include "../include/pessoa.h"

/**
 * @brief Cria uma lista de pessoas.
 * @return Ponteiro para uma lista de pessoas vazia.
 **/
Lista_pessoa* criaListaPessoa();

/**
 * @brief Libera da memória uma lista de pessoas.
 * @param listaPessoa Lista de pessoas que será desalocada da memória.
 **/
void destroiListaPessoa(Lista_pessoa* listaPessoa);

/**
 * @brief Imprime uma lista de pessoas.
 * @param listaPessoa Lista de pessoas que será impressa.
 * @param f Ponteiro para arquivo cuja lista de pessoas será impressa. Casp seja necessário imprimir no terminal, considere f == STDOUT.
 **/
void printListaPessoa(Lista_pessoa* listaPessoa, FILE* f);

/**
 * @brief Insere uma pessoa numa lista de pessoas.
 * @param listaPessoa Lista de pessoas que receberá a inserção.
 * @param pessoa Pessoa que será adicionada na lista.
 **/
void inserePessoa(Lista_pessoa* listaPessoa, Pessoa* pessoa);

#endif /*LISTA_PESSOA_H*/
