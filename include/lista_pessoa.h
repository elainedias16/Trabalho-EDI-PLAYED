#ifndef LISTA_PESSOA_H_
#define LISTA_PESSOA_H_

typedef struct celPessoa CelPessoa;
typedef struct lista_pessoa Lista_pessoa;
#include "../include/pessoa.h"

/**
 * @brief Cria uma lista de pessoas.
 * @return Ponteiro para uma lista de pessoas vazia.
 **/
Lista_pessoa* criaListaPessoa();

/**
 * @brief Libera da memória uma lista de pessoas.
 * @param listaPessoa Lista de pessoas que será desalocada da memória.
 **/
void destroiListaPessoa(Lista_pessoa* listaPessoa);

/**
 * @brief Libera da memória somenta o encadeamento da lista. As pessoas dentro das células permanecem intactas.
 * @param listaPessoa Lista de pessoas que terá seus ponteiros para células liberados.
 **/
void destroiEncadeamentoListaPessoa(Lista_pessoa* listaPessoa);

/**
 * @brief Imprime uma lista de pessoas.
 * @param listaPessoa Lista de pessoas que será impressa.
 * @param f Ponteiro para arquivo cuja lista de pessoas será impressa. Casp seja necessário imprimir no terminal, considere f == STDOUT.
 **/
void printListaPessoa(Lista_pessoa* listaPessoa, FILE* f);

/**
 * @brief Insere uma pessoa numa lista de pessoas.
 * @param listaPessoa Lista de pessoas que receberá a inserção.
 * @param pessoa Pessoa que será adicionada na lista.
 **/
void inserePessoa(Lista_pessoa* listaPessoa, Pessoa* pessoa);

/**
 * @brief Busca uma pessoa em uma lista de pessoas.
 * @param lista Lista de pessoas na qual será feita a busca.
 * @param nome Nome da pessoa que estamos procurando.
 **/
Pessoa* buscaPessoaNaLista(Lista_pessoa* lista, char* nome);

/**
 * @brief Captura a sentinela referente à primeira célula de uma lista de pessoas.
 * @param listaPessoa Lista que terá sua sentinela first capturada.
 * @return Ponteiro para a primeira célula de uma lista de pessoas.
 **/
CelPessoa* getFirstCelula(Lista_pessoa* listaPessoa);

/**
 * @brief Captura o ponteiro a proxima celula contido na struct celula
 * @param celula É a célula que terá o ponteiro next capturado.
 * @return Retorna a próxima célula.
 **/
CelPessoa* getNextCelula(CelPessoa* celula);

/**
 * @brief Captura o ponteiro para um tipo pessoa de uma célula específica.
 * @param celula Célula que terá a pessoa capturada.
 * @return Ponteiro para pessoa.
 **/
Pessoa* getPessoaCelula(CelPessoa* celula);

/**
 * @brief Inicializa a lista de usuários do PLAYED com a leitura do arquivo amizades.txt e playlists.txt.
 * @param fileNameAmizades Caminho para o arquivo amizades.txt.
 * @param fileNamePlaylists Caminho para o arquivo playlists.txt.
 * @return Lista de pessoas com os campos 'nome', 'amigos' e 'songs', inicializados.
 **/
Lista_pessoa* inicializaUsuarios(char* fileNameAmizades, char* fileNamePlaylists);

/**
 * @brief Captura a próxima célula de pessoa.
 * @param celPessoa É a célula de pessoa que terá o seu ponteiro next capturado.
 * @return Retorna a próxima célula de pessoa.
 **/
CelPessoa* getCelulaPessoaNext(CelPessoa* celPessoa);

/**
 * @brief Refatora as listas de playlists de todas as pessoas cadastradas no PLAYED.
 * @param listaPessoa Lista de pessoas que será percorrida.
 **/
void refatoraListaPlaylistDaListaPessoa(Lista_pessoa* listaPessoa);

/**
 * @brief Escreve as listas de playlist refatoradas das pessoas no arquivo.
 * @param listaPessoa São as pessoas que tiveram suas listas de playlist refatoradas 
   e que agora serão impressas no arquivo.
 **/
void escrevePlaylistsRefatoradasArquivo(Lista_pessoa* listaPessoa);

/**
 * @brief Imprime a lista de playlist das lista de pessoas no arquivo.
 * @param listaPessoa Lista de pessoas do PLAYED.
 **/
void imprimeListaPlaylistDaListaPessoaNoArquivo(Lista_pessoa* listaPessoa);

/**
 * @brief Calcula as similaridades entre os amigos de uma lista de pessoas e as imprime num arquivo.
 * @param listaPessoa Lista de pessoas do PLAYED.
 **/
void similaridade(Lista_pessoa* listaPessoa);

/**
 * @brief Função que chama outras que geram os arquivos de saída, similaridade, played-refatorada e
 * as playlists refatoradas por pesssoa.
 * @param listaPessoa Lista de pessoas do PLAYED.
 **/
void geraArquivosSaida(Lista_pessoa* listaPessoa);

void setSimilaridade(CelPessoa* celPessoa, int similaridade);

int getSimilaridade(CelPessoa* celPessoa);

CelPessoa* buscaCelPessoa(Lista_pessoa* listaPessoa, char* nomePessoa);

//void similaridadePessoaComAmigos(Pessoa* pessoa, FILE* f, int aux);

#endif /*LISTA_PESSOA_H*/
