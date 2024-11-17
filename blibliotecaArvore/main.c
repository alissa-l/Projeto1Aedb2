#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "No.c"
#include "Livros.c"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int opcoes;    

    do
    {
        printf("Seja bem vindo(a) a biblioteca Gal Costa\n\n");
        printf("Opções: \n");
        printf("1 - Inserir novo livro\n");
        printf("2 - Buscar por gênero\n");

        switch(opcoes)
        {
            case 1: 
                informacoesLivro();

                break;
        }




    } while (opcoes != 0);
    



}