#include <stdlib.h>
#include <stdio.h>

No* raiz = NULL;

typedef struct no
{
    int valor;
    struct no *esq;
    struct no *dir;

} No;

No* inicializar_arvore(int** raiz)
{
    CriarNo(&raiz);

    return raiz;
}

No* criarNo(int *valor)
{
    No* novoNo = (No*) malloc(sizeof(No));

    novoNo -> valor = valor;
    novoNo -> esq = NULL;
    novoNo -> dir = NULL;

    return novoNo;
}

No* inserir(No* raiz, int valor) 
{
    if (raiz == NULL) 
    {
        return criarNo(valor);
    }

    if(buscar(raiz, valor))
    {
        printf("Código já existente.");
    }

    if (valor < raiz->valor) 
    {
        raiz -> esq = inserir(raiz->esq, valor);
    } 
    else if (valor > raiz->valor) 
    {
        raiz -> dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

No* buscar(No* raiz, int valor) 
{
    if (raiz == NULL || raiz->valor == valor) 
    {
        return raiz;
    }

    if (valor < raiz->valor) 
    {
        return buscar(raiz->esq, valor);
    } 
    else 
    {
        return buscar(raiz->dir, valor);
    }
}

No* encontrar_minimo(No* raiz) 
{
    while (raiz && raiz->esq != NULL) {
        raiz = raiz->esq;
    }
    return raiz;
}

void exibir_em_ordem(No* raiz) 
{
    if (raiz != NULL) 
    {
        exibir_em_ordem(raiz->esq);
        printf("%d ", raiz->valor);
        exibir_em_ordem(raiz->dir);
    }
}

