#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct lista {
    char produto [20];
    int quantidade;
    struct lista* proximo;
} ListaCompras;

ListaCompras* inserirProdutos (ListaCompras* destino){

    getchar();

    ListaCompras* novo= (ListaCompras*) malloc(sizeof(ListaCompras));

    printf("\nQual produto você deseja adicionar à lista de compras? ");
    gets(novo->produto);
    printf("\nQual a quantidade? ");
    scanf("%d",&novo->quantidade);

    novo->proximo=destino;

    return novo;
}

void imprimirLista (ListaCompras* lista){

    getchar();

    ListaCompras* auxiliar;

    if (lista==NULL){
        printf("A lista de compras está vazia!");
        return;
    }

    printf("\t\t\t\t--- Lista de Compras ---\n\n");

    for(auxiliar=lista;auxiliar!=NULL;auxiliar=auxiliar->proximo){
        printf("Produto: %s",auxiliar->produto);
        printf("\t\t\tQuantidade: %d\n",auxiliar->quantidade);
    }

    printf("\nAperte ENTER para continuar.");
}

int main () {

    setlocale(LC_ALL,"Portuguese");

    int escolha;
    ListaCompras *lista1=NULL;

    do {
        system("clear"); //linux
        //system("cls") windows

        printf("\t\t\t\t--- Lista de Compras ---\n\n");
        printf("Escolha uma opção:\n\n");
        printf("1. Adicionar produto\n");
        printf("2. Imprimir a lista\n");
        printf("3. Sair\n\n");
        printf("Digite a opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                lista1 = inserirProdutos(lista1);
                break;
            case 2:
                imprimirLista(lista1);
                getchar();
                system("clear");
                break;
            case 3:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                exit(0);
                break;
        }

    } while (escolha != 3);

    return 0;
}
