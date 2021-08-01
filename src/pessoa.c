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

// Joao;3;acoustic-hits.txt;nacional.txt;heavymetal.txt
// Maria;2;sertanejo.txt;metal.txt
// Pedro;1;eletronica.txt
// Alice;2;sert.txt;eletrica.txt