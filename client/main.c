#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/musica.h"
#include "../include/playlist.h"
#include "../include/lista_playlist.h"
#include "../include/pessoa.h"
#include "../include/lista_pessoa.h"

int main(){
    char* fileNameAmizades = "data/Entrada/amizade.txt";
    char* fileNamePlaylists = "data/Entrada/playlists.txt";
    Lista_pessoa* listaPessoa =  inicializaUsuarios(fileNameAmizades, fileNamePlaylists); 
    refatoraListaPlaylistDaListaPessoa(listaPessoa);
    geraArquivosSaida(listaPessoa);
    destroiListaPessoa(listaPessoa);
    return 0;
}

//readme.
//makefile.
// fazer diff depois.
// desafio.
