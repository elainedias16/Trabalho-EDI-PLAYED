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
};