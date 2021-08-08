// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "../include/lista_pessoa.h"
// #include "../include/lista_playlist.h"
#include "../include/pessoa.h"

#define TAM 200

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
    destroiEncadeamentoListaPessoa(pessoa->amigos);
    //destroiListaPessoa(pessoa->amigos); //! SE DER, COLOCAR PARA DESTRUIR FORA
    //free(pessoa->amigos);
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
    fprintf(f , "Lista de playlists\n");
    printListaPlaylist(pessoa->songs, f);
    
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

void inserePlaylistsNasPessoas(Lista_pessoa* listaPessoa, char* fileNamePlaylists){
    FILE *f = fopen(fileNamePlaylists, "r");
    if(f == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    char nomePessoa[TAM];
    char nomePlaylist[TAM];
    char pasta[TAM];
    int qtd;
    Pessoa* pessoaAux;
    Playlist* playlistAux;
    
    while(!feof(f)){ //Lê até o final do arquivo.
        fscanf(f, "%[^;];%d;", nomePessoa, &qtd);
        pessoaAux = buscaPessoaNaLista(listaPessoa, nomePessoa); //chama funcao busca pessoa na lista de pessoa
        if(pessoaAux != NULL){
            for(int i = 0; i < qtd; i++){ // Lendo uma linha do arquivo.
                fscanf(f, "%[^;^\n]%*c", nomePlaylist);
                
                strcpy(pasta, "Entrada/"); // Resetando string pasta
                strcat(pasta, nomePlaylist); // Concatenando caminho do arquivo com nome do arquivo
                strcpy(nomePlaylist, pasta); // Passando o caminho para o nome da playlist

                playlistAux = lePlaylist(nomePlaylist);

                inserePlaylist(pessoaAux->songs, playlistAux);  
            } 
        } else{
            fscanf(f, "%*[^\n]\n"); // Caso dê pessoa NULL, ajustando fscanf pra próxima linha.
        }
    }

    fclose(f);
}

void refatoraListaPlaylistPessoa(Pessoa* pessoa){
    Lista_playlist* refatorada = refatoraListaPlaylist(pessoa->songs);
    pessoa->songs = refatorada;
}

void escreveListaPlaylistRefatoradaPessoaArquivo(Pessoa* pessoa, FILE* f){
    int tam = getTamListaPlaylist(pessoa->songs);
    fprintf(f, "%s;%d;", pessoa->nome, tam);

    
}
