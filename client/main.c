#include <stdio.h>
#include <stdlib.h>
#include "../include/musica.h"
#include "../include/playlist.h"
#include "../include/lista_playlist.h"
#include "../include/pessoa.h"
#include "../include/lista_pessoa.h"

int main(){
    Musica* musica1 = criaMusica("um dia frio", "djavan", "mpb");
    Musica* musica2 = criaMusica("this is me", "demi lovato", "pop");
    Musica* musica3 = criaMusica("kaKakakaka", "b", "kpop");
    Musica* musica4 = criaMusica("guitarra", "anastasia", "rock");
    Musica* musica5 = criaMusica("teclado", "bethoven", "classico");
    Musica* musica6 = criaMusica("Experience", "Ludocco", "classico");
    
    Playlist* p = criaPlaylist();
    Playlist* q = criaPlaylist();
    Playlist* r = criaPlaylist();

    Lista_playlist* lista = criaListaPlaylist();

    insereMusica(p, musica1);
    insereMusica(p, musica2);
    insereMusica(q, musica3);
    insereMusica(q, musica4);
    insereMusica(r, musica5);
    insereMusica(r, musica5);

    inserePlaylist(lista, p);
    inserePlaylist(lista, q);
    inserePlaylist(lista, r);

    // printPlaylist(p, stdout);
    //printListaPlaylist(lista, stdout);


    Pessoa* a = criaPessoa("Elaine", lista, NULL);
    Pessoa* b = criaPessoa("Filipe", lista, NULL);
    Pessoa* c = criaPessoa("senhor", lista, NULL);

    Lista_pessoa* listaPessoa = criaListaPessoa();
    inserePessoa(listaPessoa, a);
    inserePessoa(listaPessoa, b);
    inserePessoa(listaPessoa, c);

    printListaPessoa(listaPessoa, stdout);
    // printListaPessoa(listaPessoa, stdout);
    // destroiListaPessoa(listaPessoa);
    // CelP
    // CelPess
    // typedef struct CelP
    destroiPessoa(a);
    destroiListaPlaylist(lista);
    destroiPlaylist(p);
    destroiPlaylist(q);
    destroiPlaylist(r);
    destroiMusica(musica1);
    destroiMusica(musica2);
    destroiMusica(musica3);
    destroiMusica(musica4);
    destroiMusica(musica5);
    destroiMusica(musica6);
    return 0;
}


//TAD usuarios (lista de pessoas)
// TAD pessoa
//TAD playlist (lista de musicas)
//TAD musica

/*pessoa
 -lista de pessoas 

lista_de_pessoas  amigos
*/