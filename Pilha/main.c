#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha {
    int numero;
    char descricao [50];
    struct pilha *proximo;
} Processo;

Processo *push (Processo *processos){

    getchar();

    Processo *novo = (Processo*) malloc(sizeof(Processo));

    printf("\n------------------------------------------------------\n");
    printf("\t\t--Empilhar Processos--\n");
    printf("------------------------------------------------------\n");

    printf("Digite o numero do processo:");
    scanf("%d", &novo->numero);
    getchar();
    printf("Digite a descricao do processo:");
    gets(novo->descricao);
    printf("\n\n");

    novo->proximo = processos;

    return novo;
}

Processo *pop (Processo *processos){

    getchar();

    printf("\n------------------------------------------------------\n");
    printf("\t\t--Desempilhar Processos--\n");
    printf("------------------------------------------------------\n");
    //system("pause");
    getchar();

    printf("\n------------------------------------------------------\n");
    printf("\t\t--Processos--\n");
    printf("------------------------------------------------------\n");

    printf("Numero do processo: %d", processos->numero);
    printf("\nDescricao do processo: %s\n", processos->descricao);

    printf("Processo desempilhado!");

    processos=processos->proximo;

    return processos;
}

void consultarProcessos (Processo *processos){

    getchar();

    Processo *aux;
    int num;

    printf("\n------------------------------------------------------\n");
    printf("\t\t--Consultar Processos--\n");
    printf("------------------------------------------------------\n");

    printf("Digite o numero do processo:");
    scanf("%d", &num);
    getchar();

    for (aux=processos;aux!=NULL;aux=aux->proximo){
        if (aux->numero==num){
            relatorio(aux,1);

            return;
        }
    }

    printf("\nProcesso desempilhado!");
}

void relatorio (Processo *processos, int x){

    getchar();

    Processo *aux;
    int i;

    printf("\n------------------------------------------------------\n");
    printf("\t\t--Relatorio de Processos--\n");
    printf("------------------------------------------------------\n");

    for (aux=processos, i=0; aux!=NULL;aux=aux->proximo, i++){
        printf("\n------------------------------------------------------\n");
        printf("\t\t--Processos [%d]--\n",i+1);
        printf("------------------------------------------------------\n");

        printf("Numero do processo: %d", aux->numero);
        printf("\nDescricao do processo: %s\n", aux->descricao);

        if(x==1) break;
    }
}


int main()
{
    int menu=-1;
    Processo *processos=NULL;


    // menu
for (; menu != 0;) {

    // exibição e leitura de menu
    printf("\n------------------------------------------------------\n");
    printf("\t\t--Controle de Processos--\n");
    printf("------------------------------------------------------\n");

    printf("1- Empilhar Processos\n");
    printf("2- Consultar Processos\n");
    printf("3- Relatório de Processos\n");
    printf("4- Desempilhar Processos\n");
    printf("0- Sair\n");

    printf("\n------------------------------------------------------\n");
    printf("Digite a opção desejada:");
    scanf("%d", &menu);
    getchar();

    // controle de menu
    switch (menu) {
        case 1: processos = push(processos); break;
        case 2: consultarProcessos(processos); break;
        case 3: relatorio(processos, 2); break;
        case 4: processos = pop(processos); break; // desafio
        case 0: return 0; break;

        default: printf("\nOpção inválida!\n\n");
    }

    //system("pause");
    getchar();
    system("clear");
}

    return 0;
}
