#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/musica.h"
#include "../include/playlist.h"
#include "../include/lista_playlist.h"
#include "../include/pessoa.h"
#include "../include/lista_pessoa.h"

#define TAM 50

int main(int argc, char** argv){
    char fileNameAcoustic[TAM];
    char fileNameEletrica[TAM];
    char fileNameEletronica[TAM];
    char fileNameHeavyMetal[TAM];
    char fileNameMetal[TAM];
    char fileNameNacional[TAM];
    char fileNameSertanejo[TAM];
    char fileNameSert[TAM];
    char fileNamePlaylist[TAM];
    char fileNameAmizades[TAM];
    
    strcpy(fileNameAcoustic,   argv[2]);
    strcpy(fileNameEletrica,   argv[3]);
    strcpy(fileNameEletronica, argv[4]);
    strcpy(fileNameHeavyMetal, argv[5]);
    strcpy(fileNameMetal,      argv[6]);
    strcpy(fileNameNacional,   argv[7]);
    strcpy(fileNameSertanejo,  argv[8]);
    strcpy(fileNameSert,       argv[9]);
    strcpy(fileNamePlaylist,   argv[10]);
    strcpy(fileNameAmizades,   argv[11]);
    
    printf("%s\n", fileNameAcoustic);
    printf("%s\n", fileNameEletrica);
    printf("%s\n", fileNameEletronica);
    printf("%s\n", fileNameHeavyMetal);
    printf("%s\n", fileNameMetal);
    printf("%s\n", fileNameNacional);
    printf("%s\n", fileNameSertanejo);
    printf("%s\n", fileNameSert);
    printf("%s\n", fileNamePlaylist);
    printf("%s\n", fileNameAmizades);

    // ./tp1 10 z-inputs/Entrada/acoustic-hits.txt z-inputs/Entrada/eletrica.txt z-inputs/Entrada/eletronica.txt z-inputs/Entrada/heavymetal.txt z-inputs/Entrada/metal.txt z-inputs/Entrada/nacional.txt z-inputs/Entrada/sert.txt z-inputs/Entrada/sertanejo.txt z-inputs/Entrada/playlists.txt z-inputs/Entrada/amizade.txt

    // Musica* musica1 = criaMusica("um dia frio", "djavan", "mpb");
    // Musica* musica2 = criaMusica("this is me", "demi lovato", "pop");
    // Musica* musica3 = criaMusica("kaKakakaka", "b", "kpop");
    // Musica* musica4 = criaMusica("guitarra", "anastasia", "rock");
    // Musica* musica5 = criaMusica("teclado", "bethoven", "classico");
    // Musica* musica6 = criaMusica("Experience", "Ludocco", "classico");
    
    // Playlist* p = criaPlaylist();
    // Playlist* q = criaPlaylist();
    // Playlist* r = criaPlaylist();

    // Lista_playlist* lista = criaListaPlaylist();

    // insereMusica(p, musica1);
    // insereMusica(p, musica2);
    // insereMusica(q, musica3);
    // insereMusica(q, musica4);
    // insereMusica(r, musica5);
    // insereMusica(r, musica5);

    // inserePlaylist(lista, p);
    // inserePlaylist(lista, q);
    // inserePlaylist(lista, r);

    // // printPlaylist(p, stdout);
    // //printListaPlaylist(lista, stdout);


    // Pessoa* a = criaPessoa("Elaine", lista, NULL);
    // Pessoa* b = criaPessoa("Filipe", lista, NULL);
    // Pessoa* c = criaPessoa("senhor", lista, NULL);

    // Lista_pessoa* listaPessoa = criaListaPessoa();
    // inserePessoa(listaPessoa, a);
    // inserePessoa(listaPessoa, b);
    // inserePessoa(listaPessoa, c);

    // printListaPessoa(listaPessoa, stdout);
    // // printListaPessoa(listaPessoa, stdout);
    // // destroiListaPessoa(listaPessoa);
    // // CelP
    // // CelPess
    // // typedef struct CelP
    // destroiPessoa(a);
    // destroiListaPlaylist(lista);
    // destroiPlaylist(p);
    // destroiPlaylist(q);
    // destroiPlaylist(r);
    // destroiMusica(musica1);
    // destroiMusica(musica2);
    // destroiMusica(musica3);
    // destroiMusica(musica4);
    // destroiMusica(musica5);
    // destroiMusica(musica6);
    return 0;
}
