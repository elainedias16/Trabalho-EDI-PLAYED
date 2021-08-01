#ifndef PESSOA_H
#define PESSOA_H

typedef struct pessoa Pessoa;

/**
 * @brief Captura o nome de uma pessoa.
 * @param pessoa Pessoa que terá o nome capturado.
 * @return Ponteiro que aponta para o início de uma string do nome da pessoa. 
**/
char* get_nome_pessoa(Pessoa* pessoa);



#endif /*PESSOA_H*/
