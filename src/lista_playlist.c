// #include <stdio.h>
// #include <stdlib.h>
// #include "../include/playlist.h"
#include "../include/lista_playlist.h"

#define TAM 100

struct celPlaylist{
    Playlist* playlist;
    CelPlaylist* next;
};

struct lista_playlist{
    CelPlaylist* first;
    CelPlaylist* last;
    int tam;
};

Lista_playlist* criaListaPlaylist(){
    Lista_playlist* lista = (Lista_playlist*) malloc (sizeof (Lista_playlist));
    lista->first =NULL;
    lista->last = NULL;
    lista->tam = 0;
    return lista;
}

void destroiListaPlaylist(Lista_playlist* songs){
    CelPlaylist* i = songs->first;
    CelPlaylist* aux;
    while(i != NULL){
        aux = i;
        i = i->next;
        destroiPlaylist(aux->playlist);
        free(aux);
    }
    free(songs);
}

void printListaPlaylist(Lista_playlist* songs, FILE* f){
    CelPlaylist* i = songs->first;
    while(i != NULL){
        fprintf(f, "\n-----\n");
        printPlaylist(i->playlist, f);
        i = i->next;
        fprintf(f, "\n-----\n");
    }
}

void inserePlaylist(Lista_playlist* songs, Playlist* playlist){
    CelPlaylist* nova = (CelPlaylist*)malloc(sizeof(CelPlaylist));
    nova->playlist = playlist;
    nova->next = NULL;

    if(songs->tam != 0)
        songs->last->next = nova;
    
    songs->last = nova;

    if(songs->tam == 0){
        songs->first = nova;
    }
    songs->tam++;
}

Playlist* buscaPlaylistNaLista(Lista_playlist* lista, char* nome){
    CelPlaylist* i;
    char* nomeAux;
    for(i = lista->first; i != NULL; i = i->next){
        nomeAux = get_nome_playlist(i->playlist);
        if(strcmp(nomeAux, nome) == 0){
            return i->playlist;
        }
    }
    return NULL;
}

void refatoraPlaylistsDasPessoas(Lista_pessoa* listaPessoa){
    Lista_playlist* listaPlaylistAux;
    CelPessoa* i = getFirstCelula(listaPessoa);
    CelPlaylist* j;
    CelMusica* k;
    Playlist* playlistNova;
    Playlist* playlistAux;
    Pessoa* pessoaAux;
    Lista_playlist* novaListaPlaylists;
    char* artistaAux;
    Musica* musicaAux;
    ////varrear a lista de pessoa
    ////na pessoa, ver quantas playlists tem e 
    //na playlist , ver o nome da banda/cantor , criar uma playlist com esse nome e
    //inserir aquela musica e retirar da playlist master
    //chegar ate o fim do arquivo e ver se tem esse cantor/banda de novo 
    //se tiver, inserir aquela musica e retirar da playlist master
    //se n, passar para proxima linha e criar outra plaliyst
    
    while(i != NULL){ // Percorrendo lista de pessoas.
        pessoaAux = getPessoaCelula(i);
        listaPlaylistAux = get_lista_playlist_pessoa(pessoaAux);
        j = getFirstCelListaPlaylist(listaPlaylistAux);
        
        novaListaPlaylists = criaListaPlaylist();
        while(j != NULL){ // Percorrendo lista de playlists de uma pessoa.
            playlistAux = getPlaylistDaCelula(j);
            k = getFirstCelPlaylist(playlistAux);
            
            while(k != NULL){ // Percorrendo as musicas de uma playlist.
                musicaAux = getMusicaCelMusica(k);
                artistaAux = get_artista_musica(musicaAux);
                playlistNova = criaPlaylist(artistaAux);
                //! função que percorre todas as playlists de uma pessoa procurando o mesmo artista
                geraNovaListaPlaylist(artistaAux, playlistNova, listaPlaylistAux, novaListaPlaylists);
                k = getNextMusica(k); // Incrementando k.
            }

            j = getCelulaPlaylistNext(j); // Incrementando j, ou seja indo para a próxima playlist da listaPlaylistAux.
           
        }
        
        i = getNextCelula(i); // Incrementando i, ou seja, indo para a próxima pessoa da listaPessoa.
    }
        
    //! LIBERAR A LISTA DEPLAYLIST ANTIGA
    //! SETAR A NOVA LISTA DE PLAYLIST NA PESSOA
}


CelPlaylist* getFirstCelListaPlaylist(Lista_playlist* listaPlaylist){
    return listaPlaylist->first;
}


CelPlaylist* getCelulaPlaylistNext(CelPlaylist* celPlaylist){
    return celPlaylist->next;
}

Playlist* getPlaylistDaCelula(CelPlaylist* celPlaylist){
    return celPlaylist->playlist;
}

void geraNovaListaPlaylist(char* artista, Playlist* novaPlaylist, Lista_playlist* percorrida, Lista_playlist* novaListaPlaylist){
    CelPlaylist* i = getFirstCelListaPlaylist(percorrida);
    Playlist* j;
    CelMusica* k;
    Musica* musicaAux;
    char* nomeArtista;

    while(i != NULL){ //Percorrendo a lista de playlists (celulas de playlist).
       j = getPlaylistDaCelula(i);
       while(j != NULL){ // Percorrendo as musicas de uma playlist.
            musicaAux = getMusicaCelMusica(j);
            nomeArtista = get_artista_musica(musicaAux);
            if(strcmp(nomeArtista, artista) == 0){
                insereMusica(novaPlaylist, musicaAux);
                //! REMOVE A MÚSICA DA LISTA ANTIGA (SEM DAR FREE NA MUSICA)
            }

            j = getNextMusica(j);
        } 

        i = getCelulaPessoaNext(i); //i++
    }

    inserePlaylist(novaListaPlaylist, novaPlaylist);
}