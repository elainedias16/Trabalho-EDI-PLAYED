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

Lista_pessoa* inicializaUsuarios(char* fileNameAmizades, char* fileNamePlaylists){
    FILE* f = fopen(fileNameAmizades, "r");
    if(f == NULL){
        printf("Erro na abertura do arquivoAAAA.\n");
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
    } // Fim da leitura do arquivo amizades.txt

    // Leitura do arquivo playlists.txt e inicializar as playlists dos usuários.
    inserePlaylistsNasPessoas(listaPessoa, fileNamePlaylists);

    fclose(f);
    return listaPessoa;
}

// Joao;Maria;Pedro;Alice
// Joao;Maria
// Joao;Pedro
// Pedro;Alice    PESSOA

// Joao;3;acoustic-hits.txt;nacional.txt;heavymetal.txt
// Maria;2;sertanejo.txt;metal.txt
// Pedro;1;eletronica.txt
// Alice;2;sert.txt;eletrica.txt

// void inserePlaylistsNasPessoas(Lista_pessoa* listaPessoa, char* fileNamePlaylists, Lista_playlist* listaPlaylist){
//     FILE *f = fopen(fileNamePlaylists, "r");
//     if(f == NULL){
//         printf("Erro na abertura do arquivo.\n");
//         exit(1);
//     }
    
//     char nomePessoa[TAM];
//     char nomePlaylist[TAM];
//     int qtd;
//     Pessoa* pessoaAux;
//     Playlist* playlistAux;
//     while(!feof(f)){
//         fscanf(f, "%[^;];%d;", nomePessoa, &qtd);
//         pessoaAux = buscaPessoaNaLista(listaPessoa, nomePessoa); //chama funcao busca pessoa na lista de pessoa
//         if(pessoaAux != NULL){
//             for(int i=0; i < qtd; i++){
//                 fscanf(f, "%[^;^\n]%*c", nomePlaylist);
//                 playlistAux = buscaPlaylistNaLista(listaPlaylist, nomePlaylist); //chama busca playlist na lista de playlists
//                 //printf("[%p]\n", playlistAux);
                
//                 inserePlaylist(pessoaAux->songs, playlistAux); 
//             } 
//         } else{
//             fscanf(f, "%*[^\n]\n"); // Caso dê pessoa NULL, ajustando fscanf pra próxima linha.
//         }
//     }
    
//     fclose(f);
// }

//funcao que le tudo 
//for ate tam chamando a lePlaylist
//abre o arquivo de musica e chama insere musica

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
