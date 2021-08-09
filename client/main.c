#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/musica.h"
#include "../include/playlist.h"
#include "../include/lista_playlist.h"
#include "../include/pessoa.h"
#include "../include/lista_pessoa.h"

int main(){

    char* fileNameAmizades = "Entrada/amizade.txt";
    char* fileNamePlaylists = "Entrada/playlists.txt";
    
    Lista_pessoa* listaPessoa =  inicializaUsuarios(fileNameAmizades, fileNamePlaylists); 
    //printListaPessoa(listaPessoa, stdout);
    
    refatoraListaPlaylistDaListaPessoa(listaPessoa);
    escrevePlaylistsRefatoradasArquivo(listaPessoa);
    imprimeListaPlaylistDaListaPessoaNoArquivo(listaPessoa);
    similaridade(listaPessoa);

    destroiListaPessoa(listaPessoa);
    return 0;
}

//TODO SIMILARIDADES

//TODO IDEIA: PERCORRER O ARQUIVO AMIZADES.TXT E PEGAR OS PARES DE AMIGOS. 
//TODO PEGO OS PARES, FAZER SIMILARIDADE ENTRE AMBOS.

//funcoes:
// - similaridade VERIFICA SIMILARIDADE ENTRE DUAS PESSOAS
//le o arquivo , pega (busca) as duas pessoas na lista de pessoas que encontramos no arquivo e calculada 
//a similaridade.   funcao grandona: similaridade . Funcao pequeninnha: calcula similaridade
//
