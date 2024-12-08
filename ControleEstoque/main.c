#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct produto {

    int codigo;
    char descricao [50];
    int quantidade;
    float valor;
    struct produto *proximo;

} Produto;

Produto* inserir(Produto* destino){

    Produto* novo= (Produto*) malloc(sizeof(Produto));

    printf("\nDigite o código do produto: ");
    scanf("%d",&novo->codigo);
    printf("\nDigite uma descrição para o produto: ");
    scanf("%s",&novo->descricao);
    fflush(stdin);
    printf("\nDigite a quantidade do produto: ");
    scanf("%d",&novo->quantidade);
    fflush(stdin);
    printf("\nDigite o valor do produto: ");
    scanf("%f",&novo->valor);
    fflush(stdin);

    novo->proximo=destino;

    return novo;
}

void consultarProduto(Produto* estoque){

    Produto *auxiliar;
    int codigo;

    printf("\n--------------------------------------------------------");
    printf("\n------------------Consulta de produtos------------------");
    printf("\n--------------------------------------------------------\n");
    printf("Digite o código do produto: ");
    scanf("%d",&codigo);

    for(auxiliar=estoque;auxiliar!=NULL;auxiliar=auxiliar->proximo){

        if(auxiliar->codigo==codigo){
            relatorio(auxiliar,1);
            return;
        }
    }

    printf("\nProduto não cadastrado!\n\n");
}

void relatorio(Produto *estoque, int x){

    Produto *auxiliar;
    int i;
    printf("\n---------------------------------------------------------");
    printf("\n------------------Relatório de produtos------------------");
    printf("\n---------------------------------------------------------\n");

    for(auxiliar=estoque,i=0;auxiliar!=NULL;auxiliar=auxiliar->proximo,i++){
        printf("\n---------------------------------------------------------");
        printf("\n------------------Produto[%d]------------------",i+1);
        printf("\n---------------------------------------------------------\n");

        printf("\nCódigo do produto: %d",auxiliar->codigo);
        printf("\nDescrição do produto: %s",auxiliar->descricao);
        printf("\nQuantidade do produto: %d",auxiliar->quantidade);
        printf("\nCódigo do produto: %d",auxiliar->codigo);
        printf("\nValor do produto: R$ %.2f\n\n",auxiliar->valor);

        if(x==1) break;
    }

}

Produto *removerProduto(Produto *estoque) {

    Produto *anterior;
    Produto *auxiliar;
    int codigo;

    printf("\n---------------------------------------------------------");
    printf("\n------------------Remoção de produtos------------------");
    printf("\n---------------------------------------------------------\n");
    printf("Digite o código do produto: ");
    scanf("%d",&codigo);

    for (anterior=NULL, auxiliar=estoque; auxiliar!=NULL && auxiliar->codigo!=codigo; anterior=auxiliar, auxiliar=auxiliar->proximo) {}

    if (auxiliar==NULL) {
        printf("\nProduto não cadastrado!");
        return estoque;
    }

    if (anterior==NULL) {
        estoque=auxiliar->proximo;
    }

    else {
        anterior->proximo=auxiliar->proximo;
    }

    printf("\nProduto removido!\n");
    return estoque;
}

int main(){

    setlocale(LC_ALL,"Portuguese");

    Produto *estoque = NULL;

    int menu=20;

    system ("color fc"); //estilização do programa (windows)

    for (;menu!=0;){
        printf("-------------------------------------------------------");
        printf("\n------------------Controle de Estoque------------------");
        printf("\n-------------------------------------------------------\n");

        printf("1- Cadastrar produtos\n");
        printf("2- Consultar produtos\n");
        printf("3- Relatório de produtos\n");
        printf("4- Consultar volume em estoque\n");
        printf("5- Remover produtos\n");
        printf("0- Sair\n");

        printf("\n-------------------------------------------------------\n");
        printf("Digite a opção desejada: ");
        scanf("%d",&menu);

        switch (menu){

            case 1: estoque=inserir(estoque); break;
            case 2: consultarProduto(estoque); break;
            case 3: relatorio(estoque,0); break;
            case 4: break;
            case 5: removerProduto(estoque); break;
            case 0: return 0; break;
            default: printf ("\nOpção inválida!");
        }

        system("pause");
        system("cls");

        /*
        As duas linhas abaixo substituem as linhas 151 e 152 respectivamente caso seu SO seja linux

        getchar();
        system("clear"); */

    }

    return 0;
}
