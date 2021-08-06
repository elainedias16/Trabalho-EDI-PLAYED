// #include <stdio.h>
// #include <stdlib.h>
#include "../include/lista_pessoa.h"
// #include "../include/pessoa.h"

#define TAM 50

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
        destroiPessoa(aux->pessoa); 
        free(aux);
    }
    free(listaPessoa);
}

void destroiEncadeamentoListaPessoa(Lista_pessoa* listaPessoa){
    CelPessoa* i = listaPessoa->first;
    CelPessoa* aux;
    while(i != NULL){
        aux = i;
        i = i->next;
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

Lista_pessoa* inicializaUsuarios(char* fileNameAmizades, char* fileNamePlaylists){
    FILE* f = fopen(fileNameAmizades, "r");
    if(f == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    Pessoa* aux;
    Pessoa* aux2;
    Lista_pessoa* listaPessoa = criaListaPessoa();

    char nome[TAM];
    char nome2[TAM];
    char sep = ' ';
    
    // Lendo primeira linha e inicializando pessoas somente com o campo nome preenchido.
    while(sep != '\n'){
        fscanf(f, "%[^;^\n]%c", nome, &sep);
        aux = criaPessoa(nome);
        inserePessoa(listaPessoa, aux);
    }
    
    while(!feof(f)){
        fscanf(f, "%[^;]%*c%[^\n]%*c", nome, nome2);
        aux = buscaPessoaNaLista(listaPessoa, nome);
        aux2 = buscaPessoaNaLista(listaPessoa, nome2);
        
        if(aux != NULL && aux2 != NULL){
            Lista_pessoa* listaAmigosAux = get_lista_amigos_pessoa(aux);
            Lista_pessoa* listaAmigosAux2 = get_lista_amigos_pessoa(aux2);
            inserePessoa(listaAmigosAux, aux2);
            inserePessoa(listaAmigosAux2 , aux);
        }
        
        if(feof(f)){
            break;
        }  
    } // Fim da leitura do arquivo amizades.txt

    // Leitura do arquivo playlists.txt e inicializar as playlists dos usuários.
    inserePlaylistsNasPessoas(listaPessoa, fileNamePlaylists);

    fclose(f);
    return listaPessoa;
}

CelPessoa* getCelulaPessoaNext(CelPessoa* celPessoa){
    return celPessoa->next;
}