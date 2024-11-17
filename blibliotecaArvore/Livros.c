#include <stdio.h>
#include <string.h>
#include "No.c"

Livro livro;

typedef struct estruturaLivro
{//esse estruturalivro é o nome da estrutura
    int codigo;
    char titulo[100];
    char autor[100];
    char genero[50];
    int ano;
    char editora[100];
    int nPaginas;
} Livro;
//esse livro de baixo é para criarmos o novo livro

void informacoesLivro()
{
    printf("Precisamos de algumas informações pára cadastrarmos os livros. Seguem a seguir as informações necessárias: \n\n");
    printf("Insira o código do livro: ");
    scanf("%d", &livro.codigo);

    printf("\nInsira o nome do livro: ");
    scanf("%s", &livro.titulo);

    printf("\nInsira o autor do livro: ");
    scanf("%s", &livro.autor);

    printf("\nInsira o gênero do livro: ");
    printf("%s", &livro.genero); 

    printf("\nInsira o ano do livro: ");
    scanf("%d", &livro.ano);

    printf("\nInsira a editora do livro: ");
    scanf("%s", &livro.editora);

    printf("\nInsira o ano de lançamento: ");
    scanf("%d", &livro.nPaginas);

    criarLivro(livro.codigo, livro.titulo, livro.autor, livro.genero, livro.ano, livro.editora, livro.nPaginas);
}

Livro criarLivro(int codigo, char titulo[100], char autor[100], char genero[50], int ano, char editora[100], int nPaginas)
{

    Livro* novoLivro = (Livro*) malloc(sizeof(Livro));
    
    novoLivro -> codigo = codigo;
    novoLivro -> titulo[100] = titulo;
    novoLivro -> autor[100] = autor;
    novoLivro -> genero[50] = genero;
    novoLivro -> ano = ano;
    novoLivro -> editora[100] = editora;
    novoLivro -> nPaginas = nPaginas;

    inserir(&raiz, livro.codigo);
}

