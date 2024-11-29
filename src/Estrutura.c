#include "Estrutura.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Livro* criarLivro(int codigo, char* titulo, char* autor, char* genero, int ano,
                  char* editora, int nPaginas)
                {
    Livro* novoLivro = (Livro*)malloc(sizeof(Livro));
    if (novoLivro == NULL)
    {
        printf("Erro ao alocar memória para o livro.\n");
        exit(1);
    }
    novoLivro->codigo = codigo;
    strcpy(novoLivro->titulo, titulo);
    strcpy(novoLivro->autor, autor);
    strcpy(novoLivro->genero, genero);
    novoLivro->ano = ano;
    strcpy(novoLivro->editora, editora);
    novoLivro->nPaginas = nPaginas;
    return novoLivro;
}

void inserirLivro(No** raiz, Livro* livro)
{
    if (*raiz == NULL)
    {
        No* novoNo = (No*)malloc(sizeof(No));
        if (novoNo == NULL) {
            printf("Erro ao alocar memória para o nó.\n");
            exit(1);
        }
        novoNo->livro = livro;
        novoNo->esq = NULL;
        novoNo->dir = NULL;
        *raiz = novoNo;
    } else
    {
        if (livro->codigo < (*raiz)->livro->codigo)
        {
            inserirLivro(&((*raiz)->esq), livro);
        } else
        {
            inserirLivro(&((*raiz)->dir), livro);
        }
    }
}

Livro* buscar(No* raiz, int codigo)
{
    if (raiz == NULL)
    {
        return NULL;
    }
    if (raiz->livro->codigo == codigo)
    {
        return raiz->livro;
    }
    if (codigo < raiz->livro->codigo)
    {
        return buscar(raiz->esq, codigo);
    }
    return buscar(raiz->dir, codigo);
}

void buscarPorGenero(No* raiz, char genero[])
{
    if (raiz != NULL)
    {
        buscarPorGenero(raiz->esq, genero);
        if (strcmp(raiz->livro->genero, genero) == 0)
        {
            printf("Código: %d, Título: %s\n", raiz->livro->codigo,
                   raiz->livro->titulo);
        }
        buscarPorGenero(raiz->dir, genero);
    }
}


void exibirArvore(No* raiz)
{
    if (raiz != NULL && raiz->livro != NULL)
    {
        if (raiz->esq != NULL && raiz->esq->livro != NULL)
        {
            exibirArvore(raiz->esq);
        }
        printf("Código: %d, Título: %s\n", raiz->livro->codigo,
               raiz->livro->titulo);
        if (raiz->dir != NULL && raiz->dir->livro != NULL)
        {
            exibirArvore(raiz->dir);
        }
    }
}

void liberarArvore(No* raiz)
{
    if (raiz != NULL)
    {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz->livro);
        free(raiz);
    }
}

void inicializarLivro(No** raiz)
{
    int codigo, ano, nPaginas;
    char titulo[100], autor[100], genero[50], editora[100];

    printf(
        "Precisamos de algumas informações para cadastrar o livro. Seguem as "
        "informações necessárias:\n\n");
    printf("Insira o código do livro: ");
    scanf("%d", &codigo);
    getchar();  // Limpar buffer de entrada
    printf("Insira o Título do livro: ");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = 0;  // Remover o newline no final da string
    printf("Insira o autor do livro: ");
    fgets(autor, sizeof(autor), stdin);
    autor[strcspn(autor, "\n")] = 0;
    printf("Insira o gênero do livro: ");
    fgets(genero, sizeof(genero), stdin);
    genero[strcspn(genero, "\n")] = 0;
    printf("Insira o ano do livro: ");
    scanf("%d", &ano);
    getchar();  // Limpar buffer de entrada
    printf("Insira a editora do livro: ");
    fgets(editora, sizeof(editora), stdin);
    editora[strcspn(editora, "\n")] = 0;
    printf("Insira o número de páginas: ");
    scanf("%d", &nPaginas);

    Livro* novoLivro =
        criarLivro(codigo, titulo, autor, genero, ano, editora, nPaginas);
    inserirLivro(raiz,
                 novoLivro);  // Certifique-se de que a função inserirLivro está
                              // implementada corretamente
}

No* carregarLivros(char* nome_arquivo, No* raiz)
{
    FILE* file = fopen(nome_arquivo, "r");
    if (!file)
    {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return raiz;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), file))
    {
        Livro* livro = (Livro*)malloc(sizeof(Livro));
        sscanf(linha, "%d,%99[^,],%99[^,],%49[^,],%d,%99[^,],%d",
               &livro->codigo, livro->titulo, livro->autor, livro->genero,
               &livro->ano, livro->editora, &livro->nPaginas);
        inserirLivro(&raiz, livro);
    }
    fclose(file);
    return raiz;
}
