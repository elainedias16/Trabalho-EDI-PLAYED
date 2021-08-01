#include <stdio.h>
#include <stdlib.h>
#include "../include/pessoa.h"
#include "../include/lista_pessoa.h"
#include "../include/lista_playlist.h"

struct pessoa{
    char* nome;
    Lista_playlist* songs;
    Lista_pessoa* amigos;
};

char* get_nome_pessoa(Pessoa* pessoa){
    return pessoa->nome;
}

char* criaPessoa(char* nome, Lista_playlist* songs, Lista_pessoa* amigos){
    Pessoa* pessoa = (Pessoa*) malloc (sizeof (Pessoa));
    pessoa->nome = strdup(nome);
    pessoa->songs = songs;
    pessoa->amigos = amigos;
    return pessoa;
}

// void destroiPessoa(Pessoa* pessoa){
//     free(pessoa->nome);
    
// }

// char* nome;
//     Lista_playlist* songs;
//     Lista_pessoa* amigos;
// Joao;3;acoustic-hits.txt;nacional.txt;heavymetal.txt
// Maria;2;sertanejo.txt;metal.txt
// Pedro;1;eletronica.txt
// Alice;2;sert.txt;eletrica.txt