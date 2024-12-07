#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct produto {
    int codigo;
    char descricao [50];
    int quantidade;
    float valor;
    struct produto *proximo
} Produto;

int main()
{
    setlocale(LC_ALL,"Portuguese");

    Produto *estoque;
    estoque= inicializar();

    int menu=20;

    system ("color fc");

    printf("Hello world!\n");
    return 0;
}
