#ifndef ESTRUTURA_H
#define ESTRUTURA_H

typedef struct estruturaLivro {
    int codigo;
    char titulo[100];
    char autor[100];
    char genero[50];
    int ano;
    char editora[100];
    int nPaginas;
} Livro;

typedef struct estruturaNo {
    int valor;
    struct estruturaNo* esq;
    struct estruturaNo* dir;
    Livro* livro;
} No;

// Funções para manipular a árvore
No* criarNo(int valor, Livro* livro);
void inserirLivro(No** raiz, Livro* livro);
void buscarPorGenero(No* raiz, char genero[]);
void exibirArvore(No* raiz);
void liberarArvore(No* raiz);
Livro* buscar(No* raiz, int valor);

// Funções para manipular os livros
Livro criarLivro(int codigo, char* titulo, char* autor, char* genero, int ano, char* editora, int nPaginas);
void inicializarLivro(No** raiz);
No* carregarLivros(char* nome_arquivo, No* raiz);

#endif // ESTRUTURA_H
