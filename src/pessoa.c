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
    destroiListaPlaylist(pessoa->songs);
    destroiEncadeamentoListaPessoa(pessoa->amigos);
    //destroiListaPessoa(pessoa->amigos); 
    //free(pessoa->amigos);
    free(pessoa);
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

void imprimeListaPlaylistPessoaArquivo(Pessoa* pessoa){
    char pasta[TAM] = "Saida_testes/";
    strcat(pasta, pessoa->nome);
    mkdir(pasta, 0777);
    printListaPlaylist(pessoa->songs, pasta);
}

int similaridadeEntre2Amigos(Pessoa* pessoa1, Pessoa* pessoa2){
    int qtd = 0;
    qtd = similaridadeEntreListaPlaylist(pessoa1->songs, pessoa2->songs);
    return qtd;
}
