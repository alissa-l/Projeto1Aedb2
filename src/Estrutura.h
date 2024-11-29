#ifndef ESTRUTURA_H
#define ESTRUTURA_H

typedef struct estruturaLivro
{
    int codigo;
    char titulo[100];
    char autor[100];
    char genero[50];
    int ano;
    char editora[100];
    int nPaginas;
} Livro;

typedef struct no
{
    Livro* livro;
    struct no* esq;
    struct no* dir;
} No;

Livro* criarLivro(int codigo, char* titulo, char* autor, char* genero, int ano, char* editora, int nPaginas);
void inicializarLivro(No** raiz);
void inserirLivro(No** raiz, Livro* livro);
void buscarPorGenero(No* raiz, char genero[]);
void exibirArvore(No* raiz);
void liberarArvore(No* raiz);
No* carregarLivros(char* nome_arquivo, No* raiz);
Livro* buscar(No* raiz, int codigo);

#endif // ESTRUTURA_H