#include <stdio.h>
#include <stdlib.h>
#include "../include/pessoa.h"
#include "../include/lista_pessoas.h"
#include "../include/playlist.h"

struct pessoa{
    char* nome;
    Playlist* playlist;
    Lista_pessoas* amigos;
};

char* get_nome_pessoa(Pessoa* pessoa){
    return pessoa->nome;
}
