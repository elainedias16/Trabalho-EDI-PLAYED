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

    destroiListaPessoa(listaPessoa);
    return 0;
    
}

//TODO FIZEMOS ATÉ O PONTO:
//TODO VARREMOS UMA LISTA DE PLAYLISTS PROCURANDO AS MUSICAS DE UM ARTISTA ESPECÍFICO E AS 
//TODO INSERIMOS NA PLAYLIST DESSE MESMO ARTISTA. [OK]

//TODO PROXIMO PASSO:
//TODO FAZER ISSO PARA TODOS OS ARTISTAS. [OK]

//TODO DEPOIS:
//TODO FAZER ISSO PARA UMA DETERMINADA PESSOA DO PLAYED. [OK]

//TODO DEPOIS DEPOIS:
//TODO FAZER ISSO PARA TODAS AS PESSOAS DO PLAYED. [OK]