/**
 * Estruturas de Dados I - Trabalho Prático I - PlayED
 * Professora: Patricia Dockhorn Costa
 * Dupla:
 * Elaine Dias Pires 2020101903
 * Filipe Gomes Arante de Souza 2020100625
 **/

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
