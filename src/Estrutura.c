#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estrutura.h"

No* criarNo(int valor, Livro* livro) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->livro = livro;
    return novoNo;
}

void inserirLivro(No** raiz, Livro* livro) {
    if (*raiz == NULL) {
        *raiz = criarNo(livro->codigo, livro);
        return;
    }

    if (buscar(*raiz, livro->codigo)) {
        printf("Código já existente.\n");
        return;
    }

    if (livro->codigo < (*raiz)->valor) {
        inserirLivro(&(*raiz)->esq, livro);
    } else if (livro->codigo > (*raiz)->valor) {
        inserirLivro(&(*raiz)->dir, livro);
    }
}

Livro* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz ? raiz->livro : NULL;
    }

    if (valor < raiz->valor) {
        return buscar(raiz->esq, valor);
    } else {
        return buscar(raiz->dir, valor);
    }
}

void buscarPorGenero(No* raiz, char genero[]) {
    if (raiz != NULL) {
        buscarPorGenero(raiz->esq, genero);
        if (strcmp(raiz->livro->genero, genero) == 0) {
            printf("Código: %d, Título: %s\n", raiz->livro->codigo, raiz->livro->titulo);
        }
        buscarPorGenero(raiz->dir, genero);
    }
}

void exibirArvore(No* raiz) {
    if (raiz != NULL) {
        exibirArvore(raiz->esq);
        printf("Código: %d, Título: %s\n", raiz->livro->codigo, raiz->livro->titulo);
        exibirArvore(raiz->dir);
    }
}

void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz->livro);
        free(raiz);
    }
}

Livro criarLivro(int codigo, char* titulo, char* autor, char* genero, int ano, char* editora, int nPaginas) {
    Livro* novoLivro = (Livro*)malloc(sizeof(Livro));
    novoLivro->codigo = codigo;
    strcpy(novoLivro->titulo, titulo);
    strcpy(novoLivro->autor, autor);
    strcpy(novoLivro->genero, genero);
    novoLivro->ano = ano;
    strcpy(novoLivro->editora, editora);
    novoLivro->nPaginas = nPaginas;

    return *novoLivro;
}

void inicializarLivro(No** raiz) {
    Livro livro;
    printf("Precisamos de algumas informações para cadastrar o livro. Seguem as informações necessárias:\n\n");

    printf("Insira o código do livro: ");
    scanf("%d", &livro.codigo);
    getchar(); // Limpar buffer de entrada

    printf("Insira o Título do livro: ");
    fgets(livro.titulo, sizeof(livro.titulo), stdin);
    livro.titulo[strcspn(livro.titulo, "\n")] = 0; // Remover o newline no final da string

    printf("Insira o autor do livro: ");
    fgets(livro.autor, sizeof(livro.autor), stdin);
    livro.autor[strcspn(livro.autor, "\n")] = 0;

    printf("Insira o gênero do livro: ");
    fgets(livro.genero, sizeof(livro.genero), stdin);
    livro.genero[strcspn(livro.genero, "\n")] = 0;

    printf("Insira o ano do livro: ");
    scanf("%d", &livro.ano);
    getchar(); // Limpar buffer de entrada

    printf("Insira a editora do livro: ");
    fgets(livro.editora, sizeof(livro.editora), stdin);
    livro.editora[strcspn(livro.editora, "\n")] = 0;

    printf("Insira o número de páginas: ");
    scanf("%d", &livro.nPaginas);

    // Chama a função para inserir o livro na árvore
    inserirLivro(raiz, &livro);
}

No* carregarLivros(char* nome_arquivo, No* raiz) {
    FILE* file = fopen(nome_arquivo, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return raiz;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), file)) {
        Livro livro;
        sscanf(linha, "%d,%99[^,],%99[^,],%49[^,],%d,%99[^,],%d",
               &livro.codigo, livro.titulo, livro.autor, livro.genero, &livro.ano, livro.editora, &livro.nPaginas);
        inserirLivro(&raiz, &livro);
    }
    fclose(file);
    return raiz;
}
