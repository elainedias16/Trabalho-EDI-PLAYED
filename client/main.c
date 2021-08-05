#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/musica.h"
#include "../include/playlist.h"
#include "../include/lista_playlist.h"
#include "../include/pessoa.h"
#include "../include/lista_pessoa.h"

int main(int argc, char** argv){
    char* fileNameAmizades = "Entrada/amizade.txt";
    char* fileNamePlaylists = "Entrada/playlists.txt";
    
    Lista_pessoa* listaPessoa =  inicializaUsuarios(fileNameAmizades, fileNamePlaylists); 
    printListaPessoa(listaPessoa, stdout);
    
    destroiListaPessoa(listaPessoa);
        
    return 0;
}
