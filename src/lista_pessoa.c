#include <stdio.h>
#include <stdlib.h>
#include "../include/pessoa.h"
#include "../include/lista_pessoas.h"

struct celPessoa{
    Pessoa* pessoa;
    CelPessoa* next;
};

struct lista_pessoa{
    CelPessoa* first;
    CelPessoa* last;
};