// #include <stdio.h>
// #include <stdlib.h>
#include "../include/lista_pessoa.h"
// #include "../include/pessoa.h"

struct celPessoa{
    Pessoa* pessoa;
    CelPessoa* next;
};

struct lista_pessoa{
    CelPessoa* first;
    CelPessoa* last;
    int tam;
};

Lista_pessoa* criaListaPessoa(){
    Lista_pessoa* lista = (Lista_pessoa*)malloc(sizeof(Lista_pessoa));
    lista->first = NULL;
    lista->last = NULL;
    lista->tam = 0;
    return lista;
}

CelPessoa* getFirstCelula(Lista_pessoa* listaPessoa){
    return listaPessoa->first;
}

CelPessoa* getNextCelula(CelPessoa* celula){
    return celula->next;
}

Pessoa* getPessoaCelula(CelPessoa* celula){
    return celula->pessoa;
}

void destroiListaPessoa(Lista_pessoa* listaPessoa){
    CelPessoa* i = listaPessoa->first;
    CelPessoa* aux;
    while(i != NULL){
        aux = i;
        i = i->next;
        //!destroiPessoa(aux->pessoa);
        free(aux);
    }
    free(listaPessoa);
}

void printListaPessoa(Lista_pessoa* listaPessoa, FILE *f){
    CelPessoa* i = listaPessoa->first;

    while(i != NULL){
        printPessoa(i->pessoa, f);
        i = i->next;
    }
}

void inserePessoa(Lista_pessoa* listaPessoa, Pessoa* pessoa){
    CelPessoa* nova = (CelPessoa*)malloc(sizeof(CelPessoa));
    nova->pessoa = pessoa;
    nova->next = NULL;
    
    if(listaPessoa->tam != 0){
        listaPessoa->last->next = nova;
    }
    listaPessoa->last = nova;

    if(listaPessoa->tam == 0){
        listaPessoa->first = nova;
    }
    listaPessoa->tam++;
}

Pessoa* buscaPessoaNaLista(Lista_pessoa* lista, char* nome){
    CelPessoa* i;
    char* nomeAux;
    for(i= lista->first; i != NULL; i= i->next){
        nomeAux = get_nome_pessoa(i->pessoa);
        if(strcmp(nomeAux, nome)== 0){
            return i->pessoa;
        }
    }
    return NULL;
}