// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "../include/lista_pessoa.h"
// #include "../include/lista_playlist.h"
#include "../include/pessoa.h"

#define TAM 100

struct pessoa{
    char* nome;
    Lista_playlist* songs;
    Lista_pessoa* amigos;
};

char* get_nome_pessoa(Pessoa* pessoa){
    return pessoa->nome;
}

Lista_playlist* get_lista_playlist_pessoa(Pessoa* pessoa){
    return pessoa->songs;
}

Lista_pessoa* get_lista_amigos_pessoa(Pessoa* pessoa){
    return pessoa->amigos;
}

Pessoa* criaPessoa(char* nome){
    Pessoa* pessoa = (Pessoa*) malloc (sizeof (Pessoa));
    pessoa->nome = strdup(nome);
    pessoa->songs = criaListaPlaylist();
    pessoa->amigos = criaListaPessoa();
    return pessoa;
}

void destroiPessoa(Pessoa* pessoa){
    free(pessoa->nome);
    destroiListaPlaylist(pessoa->songs); //! PODE DAR PROBLEMA LA NA FRENTE
    destroiListaPessoa(pessoa->amigos); //! SE DER, COLOCAR PARA DESTRUIR FORA
    free(pessoa);
}

void printPessoa(Pessoa* pessoa, FILE* f){
    fprintf(f, "Nome: %s\n", pessoa->nome);
    CelPessoa* i = getFirstCelula(pessoa->amigos);
    Pessoa* aux;
    fprintf(f , "Lista de amigos\n");
    while(i != NULL){
        aux = getPessoaCelula(i);
        fprintf(f, "%s\n", aux->nome);
        i = getNextCelula(i);
    }
    
    fprintf(f, "---------------\n");
}

Pessoa* setSongs(Pessoa* pessoa, Lista_playlist* songs){
    pessoa->songs = songs;
    return pessoa;
}

Pessoa* setAmigos(Pessoa* pessoa, Lista_pessoa* amigos){
    pessoa-> amigos = amigos;
    return pessoa;
}

Lista_pessoa* leUsuarios(char* fileName){
    FILE* f = fopen(fileName, "r");
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
            inserePessoa(aux->amigos, aux2);
            inserePessoa(aux2->amigos, aux);
        }
        
        if(feof(f)){
            break;
        }  
    }

    fclose(f);
    return listaPessoa;
}
// Joao;Maria;Pedro;Alice
// Joao;Maria
// Joao;Pedro
// Pedro;Alice

