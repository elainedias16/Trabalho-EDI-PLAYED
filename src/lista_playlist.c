#include "../include/lista_playlist.h"
#include "string.h"

#define TAM 200
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

void printListaPlaylist(Lista_playlist* songs, char* pasta){
    CelPlaylist* i = songs->first;
    FILE* f;
    strcat(pasta, "/");
    char* nomePlaylist;
    char aux[TAM];
    char aux2[TAM];
    strcpy(aux, pasta);
    while(i != NULL){
        nomePlaylist = get_nome_playlist(i->playlist);
        strcpy(aux2, nomePlaylist);
        strcat(aux2, ".txt");
        strcat(pasta, aux2);

        f = fopen(pasta, "w");
        if(f == NULL){
            printf("Erro na abertura do arquivo!\n");
            exit(1);
        }
        printPlaylist(i->playlist, f); //imprime no arquivo
        i = i->next;
        fclose(f);

        strcpy(pasta, aux); // resetando pasta
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

CelPlaylist* getFirstCelListaPlaylist(Lista_playlist* listaPlaylist){
    return listaPlaylist->first;
}

CelPlaylist* getCelulaPlaylistNext(CelPlaylist* celPlaylist){
    return celPlaylist->next;
}

Playlist* getPlaylistDaCelula(CelPlaylist* celPlaylist){
    return celPlaylist->playlist;
}

int insereMusicasArtistaAPartirDeListaPlaylist(Playlist* playlistArtista, Lista_playlist* listaPlaylistGenero){
    CelPlaylist* i = listaPlaylistGenero->first;
    CelPlaylist* ant = NULL;
    CelPlaylist* aux;
    int ehVazia;
    while(i != NULL){
        ehVazia = insereMusicasArtistaEmSuaPlaylist(playlistArtista, i->playlist);
        
        if(ehVazia == VAZIO){ //se a playlist for vazia, precisamos retirar ela da lista
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
            aux = i;
            
            if(ant != NULL){
                
            } else{
                i = listaPlaylistGenero->first;
            }
            
            
            free(aux); //free na celula da playlist
            

            if(listaPlaylistGenero->tam == 0){
                return VAZIO;
            }
            continue;
        }
        ant = i;
        i = i->next;
    }
    return NAOVAZIO;
}

Lista_playlist* refatoraListaPlaylist(Lista_playlist* listaPlaylistGenero){
    CelPlaylist* i = listaPlaylistGenero->first;
    Lista_playlist* refatorada = criaListaPlaylist();;
    int ehVazio = 0 ;
    Playlist* playlistArtistaAux;
    CelMusica* aux;
    Musica* musicaAux;
    char* nomeArtista;

    while(i != NULL){
        i = listaPlaylistGenero->first; 
        aux = getFirstCelPlaylist(i->playlist);
        musicaAux = getMusicaCelMusica(aux);
        nomeArtista = get_artista_musica(musicaAux);
        playlistArtistaAux = criaPlaylist(nomeArtista);
        ehVazio = insereMusicasArtistaAPartirDeListaPlaylist(playlistArtistaAux, listaPlaylistGenero);
        inserePlaylist(refatorada, playlistArtistaAux);

        if(ehVazio == VAZIO ){
            destroiListaPlaylist(listaPlaylistGenero);
            break;
        }
        
    }
   
    return refatorada;
}

int getTamListaPlaylist(Lista_playlist* listaPlaylist){
    return listaPlaylist->tam;
}

void escreveListaPlaylistArquivo(Lista_playlist* listaPlaylist, FILE* f){
    CelPlaylist* celPlaylistAux = listaPlaylist->first;
    char* nomePlaylist;
    char nomePlaylistAux[TAM];
    while(celPlaylistAux != NULL){
        nomePlaylist = get_nome_playlist(celPlaylistAux->playlist);
        strcpy(nomePlaylistAux, nomePlaylist);
        strcat(nomePlaylistAux, ".txt"); // Concatenando nome da playlist com .txt para imprimir no arquivo.

        fprintf(f, "%s", nomePlaylistAux);

        celPlaylistAux = celPlaylistAux->next;
        
        if(celPlaylistAux == NULL){
            break; 
        } else{
            fprintf(f, ";");
        }
    }
}

int similaridadeEntreListaPlaylist(Lista_playlist* listaP1, Lista_playlist* listaP2){
    int qtd = 0;
    CelPlaylist* i;
    CelPlaylist* j;
    char* nomeListaP1;
    char* nomeListaP2;

    for(i = listaP1->first ; i != NULL; i = i->next){
        for(j = listaP2->first; j != NULL; j = j->next){
            nomeListaP1 = get_nome_playlist(i->playlist);
            nomeListaP2 = get_nome_playlist(j->playlist);
            if(strcmp(nomeListaP1, nomeListaP2) == 0){
                qtd += similaridadeEntrePlaylists(i->playlist, j->playlist);
            }
        }
    }
    return qtd;
}
