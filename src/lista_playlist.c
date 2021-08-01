#include <stdio.h>
#include <stdlib.h>
#include "../include/playlist.h"
#include "../include/lista_playlist.h"

struct celPlaylist{
    Playlist* playlist;
    CelPlaylist* next;
};

struct lista_playlist{
    Playlist* first;
    Playlist* last;
    int qtdPlaylist;
};