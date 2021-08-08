// #include <stdio.h>
// #include <stdlib.h>
// #include "../include/playlist.h"
#include "../include/lista_playlist.h"

#define TAM 100
#define VAZIO 0
#define NAOVAZIO 1

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

// void refatoraPlaylistsDasPessoas(Lista_pessoa* listaPessoa){
//     Lista_playlist* listaPlaylistAux;
//     CelPessoa* i = getFirstCelula(listaPessoa);
//     CelPlaylist* j;
//     CelMusica* k;
//     Playlist* playlistNova;
//     Playlist* playlistAux;
//     Pessoa* pessoaAux;
//     Lista_playlist* novaListaPlaylists;
//     char* artistaAux;
//     Musica* musicaAux;
//     ////varrear a lista de pessoa
//     ////na pessoa, ver quantas playlists tem e 
//     //na playlist , ver o nome da banda/cantor , criar uma playlist com esse nome e
//     //inserir aquela musica e retirar da playlist master
//     //chegar ate o fim do arquivo e ver se tem esse cantor/banda de novo 
//     //se tiver, inserir aquela musica e retirar da playlist master
//     //se n, passar para proxima linha e criar outra plaliyst
    
//     while(i != NULL){ // Percorrendo lista de pessoas.
//         pessoaAux = getPessoaCelula(i);
//         listaPlaylistAux = get_lista_playlist_pessoa(pessoaAux);
//         j = getFirstCelListaPlaylist(listaPlaylistAux);
        
//         novaListaPlaylists = criaListaPlaylist();
//         while(j != NULL){ // Percorrendo lista de playlists de uma pessoa.
//             playlistAux = getPlaylistDaCelula(j);
//             k = getFirstCelPlaylist(playlistAux);
            
//             while(k != NULL){ // Percorrendo as musicas de uma playlist.
//                 musicaAux = getMusicaCelMusica(k);
//                 artistaAux = get_artista_musica(musicaAux);
//                 playlistNova = criaPlaylist(artistaAux);
//                 //! função que percorre todas as playlists de uma pessoa procurando o mesmo artista
//                 geraNovaListaPlaylist(artistaAux, playlistNova, listaPlaylistAux, novaListaPlaylists);
//                 k = getNextMusica(k); // Incrementando k.
//             }

//             j = getCelulaPlaylistNext(j); // Incrementando j, ou seja indo para a próxima playlist da listaPlaylistAux.
           
//         }
        
//         i = getNextCelula(i); // Incrementando i, ou seja, indo para a próxima pessoa da listaPessoa.
//     }
        
//     //! LIBERAR A LISTA DEPLAYLIST ANTIGA
//     //! SETAR A NOVA LISTA DE PLAYLIST NA PESSOA
// }


CelPlaylist* getFirstCelListaPlaylist(Lista_playlist* listaPlaylist){
    return listaPlaylist->first;
}


CelPlaylist* getCelulaPlaylistNext(CelPlaylist* celPlaylist){
    return celPlaylist->next;
}

Playlist* getPlaylistDaCelula(CelPlaylist* celPlaylist){
    return celPlaylist->playlist;
}

/**
 * modularizar:
 * 0- função de remoção da música de uma playlist com chave sendo o artista. playlist.c
 * 1- função que pega uma lista de playlists qualquer e a refatora. listaplaylist.c
 * 2- função que pega uma pessoa e refatora sua lista de playlists (usando 1 como auxiliar). pessoa.c
 * 3- função que pega uma lista de pessoas e refatora a playlist de todos (usando 2 como auxiliar). listapessoa.c
 **/

int insereMusicasArtistaAPartirDeListaPlaylist(Playlist* playlistArtista, Lista_playlist* listaPlaylistGenero){
    CelPlaylist* i = listaPlaylistGenero->first;
    CelPlaylist* ant = NULL;
    CelPlaylist* aux;
    int ehVazia;
    while(i != NULL){
        ehVazia = insereMusicasArtistaEmSuaPlaylist(playlistArtista, i->playlist);
        
        if(ehVazia == VAZIO){ //se a playlist for vazia, precisamos retirar ela da lista
            //destroiPlaylist(i->playlist);
            if(listaPlaylistGenero->first == i && listaPlaylistGenero->last == i){ // removendo a unica playlist da lista
                listaPlaylistGenero->first = listaPlaylistGenero->last = NULL;
            
            } else if(listaPlaylistGenero->first == i){ //removendo a primeira playlist da lista
                listaPlaylistGenero->first = i->next;
            
            } else if(listaPlaylistGenero->last == i){ // removendo a ultima playlist da lista
                listaPlaylistGenero->last = ant;
                ant->next = NULL; //! pode dar seg fault, verificar aqui caso dê problema.
                
            } else{ // removendo uma playlist do meio
                ant->next = i->next;
            }
            // remove playlist da lista de playlists
            
            listaPlaylistGenero->tam--;
            printf("tam [%d]\n", listaPlaylistGenero->tam);
            aux = i;
            
            if(ant != NULL){
                
            } else{
                i = listaPlaylistGenero->first;
            }
            
            //if(listaPlaylistGenero->tam != 0){
            free(aux); //free na celula da playlist
            //}

            if(listaPlaylistGenero->tam == 0){
                //printf("CHEGOU AQUI\n");
                //destroiPlaylist(i->playlist);
                //destroiListaPlaylist(listaPlaylistGenero);
                return VAZIO;
            }
            continue;
        }
        ant = i;
        i = i->next;
    }
    return NAOVAZIO;
}

//void insereMusicasArtistas
//Playlist* playlistArtista, Playlist* playlistGenero

// void refatoraListaPlaylistPessoa(Pessoa* pessoa){

// }

// void refatoraListaPlaylistListaPessoa(Pessoa* pessoa, Lista_playlist* listaplaylistGenero){  

// }

Lista_playlist* refatoraListaPlaylist(Lista_playlist* listaPlaylistGenero){
    //a primeira playlist refatora certo, mas da erro quando vai pras proximas
    CelPlaylist* i = listaPlaylistGenero->first;
    Lista_playlist* refatorada = criaListaPlaylist();;
    int ehVazio = 0 ;
    Playlist* playlistArtistaAux;
    CelMusica* aux;
    Musica* musicaAux;
    char* nomeArtista;
    int counter = 0;
    while(i != NULL){
        counter++;
        i = listaPlaylistGenero->first; 
        //printf("endereco de i : [%p]\n", i);
        aux = getFirstCelPlaylist(i->playlist);
        musicaAux = getMusicaCelMusica(aux);
        nomeArtista = get_artista_musica(musicaAux);
        playlistArtistaAux = criaPlaylist(nomeArtista);
        ehVazio = insereMusicasArtistaAPartirDeListaPlaylist(playlistArtistaAux, listaPlaylistGenero);
        printf("ehVazio: %d\n", ehVazio);
        inserePlaylist(refatorada, playlistArtistaAux);

        if(ehVazio == VAZIO ){
            destroiListaPlaylist(listaPlaylistGenero);
            break;
        }
        // entrar na primeira playlist
        // ver a primeira musica para pegar o artista


        //i = listaPlaylistGenero->first; //COMENTEI AQUI
        
        //printf("endereco de i depois de 'incrementar': [%p]\n", i);
    }
    //printf("counter [%d]\n", counter);
    //destroiListaPlaylist(listaPlaylistGenero);
    return refatorada;
}

// get first musica de uma playlist
// get nome artista dessa musica


int getTamListaPlaylist(Lista_playlist* listaPlaylist){
    return listaPlaylist->tam;
}

void escreveListaPlaylistArquivo(Lista_playlist* listaPlaylist, FILE* f){
    CelPlaylist* celPlaylistAux = listaPlaylist->first;
    char* nomePlaylist;
    while(celPlaylistAux != NULL){
        nomePlaylist = get_nome_playlist(celPlaylistAux->playlist);
        fprintf(f, "%s", nomePlaylist);

        celPlaylistAux = celPlaylistAux->next;
        
        if(celPlaylistAux == NULL){
            fprintf(f, "\n");
        }else{
            fprintf(f, ";");
        }
    }
}