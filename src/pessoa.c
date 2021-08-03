// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "../include/lista_pessoa.h"
// #include "../include/lista_playlist.h"
#include "../include/pessoa.h"

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

Pessoa* criaPessoa(char* nome, Lista_playlist* songs, Lista_pessoa* amigos){
    Pessoa* pessoa = (Pessoa*) malloc (sizeof (Pessoa));
    pessoa->nome = strdup(nome);
    pessoa->songs = songs;
    pessoa->amigos = amigos;
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
}

Pessoa* setSongs(Pessoa* pessoa, Lista_playlist* songs){
    pessoa->songs = songs;
    return pessoa;
}

Pessoa* setAmigos(Pessoa* pessoa, Lista_pessoa* amigos){
    pessoa-> amigos = amigos;
    return pessoa;
}