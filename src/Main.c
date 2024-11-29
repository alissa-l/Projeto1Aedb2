#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Estrutura.h"

// Declara a raiz da árvore como variável global
No* raiz = NULL;

void exibirMenu() {
    printf("Seja bem-vindo(a) à biblioteca Gal Costa\n\n");
    printf("Opções:\n");
    printf("1 - Inserir novo livro\n");
    printf("2 - Buscar livro por código\n");
    printf("3 - Buscar livro por gênero\n");
    printf("4 - Carregar livros do arquivo CSV\n");
    printf("5 - Exibir todos os livros\n");
    printf("0 - Sair\n");
    printf("Insira o que você deseja fazer: ");
}

int main() 
{
    setlocale(LC_ALL, "Portuguese");
    int opcoes, codigo;
    char genero[50], nome_arquivo[256];

    do 
    {
        exibirMenu();
        scanf("%d", &opcoes);
        getchar(); // Limpar o buffer de entrada

        switch(opcoes) 
        {
            case 1:
                inicializarLivro(&raiz);
                break;
            case 2:
                printf("Insira o código do livro que deseja buscar: ");
                scanf("%d", &codigo);
                getchar();
                Livro* livroEncontrado = buscar(raiz, codigo);
                if (livroEncontrado != NULL) 
                {
                    printf("Livro encontrado: %s\n", livroEncontrado->titulo);
                } 
                else 
                {
                    printf("Livro não encontrado.\n");
                }
                break;
            case 3:
                printf("Insira o gênero do livro que deseja buscar: ");
                fgets(genero, sizeof(genero), stdin);
                genero[strcspn(genero, "\n")] = 0; // Remover o newline no final da string
                buscarPorGenero(raiz, genero);
                break;
            case 4:
                printf("Insira o nome do arquivo CSV: ");
                fgets(nome_arquivo, sizeof(nome_arquivo), stdin);
                nome_arquivo[strcspn(nome_arquivo, "\n")] = 0; // Remover o newline no final da string
                printf("Carregando livros do arquivo %s...\n", nome_arquivo);
                raiz = (No*) carregarLivros(nome_arquivo, raiz);
                break;
            case 5:
                printf("Livros em ordem:\n");
                exibirArvore(raiz);
                printf("\n");
                break;
            case 0:
                printf("Encerrar programa.\n");
                exit(0);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcoes != 0);
    return 0;

}