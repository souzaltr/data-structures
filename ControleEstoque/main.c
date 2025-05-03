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
    getchar();
    printf("\nDigite uma descrição para o produto: ");
    fgets(&novo->descricao,50,stdin);
    printf("\nDigite a quantidade do produto: ");
    scanf("%d",&novo->quantidade);
    printf("\nDigite o valor do produto: ");
    scanf("%f",&novo->valor);

    novo->proximo=destino;

    return novo;
}

void consultarProduto(Produto* estoque){

    int codigo;

    printf("\n--------------------------------------------------------");
    printf("\n------------------Consulta de produtos------------------");
    printf("\n--------------------------------------------------------\n");
    printf("Digite o código do produto: ");
    scanf("%d",&codigo);

    while (estoque != NULL){
        if (estoque->codigo==codigo){
            relatorio(estoque,1);
            return;
        }
        estoque=estoque->proximo;
    }

    printf("\nProduto não cadastrado!\n\n");
}

void relatorio(Produto *estoque, int x){

    Produto *auxiliar;
    int i;

    if (estoque==NULL) {
            printf("Lista vazia!\n");
            return;
    }

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

    Produto *anterior=NULL;
    Produto *aux=estoque;
    int codigo;

    printf("\n---------------------------------------------------------");
    printf("\n------------------Remoção de produtos------------------");
    printf("\n---------------------------------------------------------\n");
    printf("Digite o código do produto: ");
    scanf("%d",&codigo);

    while (aux!=NULL && aux->codigo != codigo){
        anterior=aux;
        aux=aux->proximo;
    }

    if (aux==NULL) {
        printf("\nProduto não cadastrado!");
        return estoque;
    }

    if (anterior==NULL) {
        estoque=estoque->proximo;
    }

    else {
        anterior->proximo=aux->proximo;
    }

    printf("\nProduto removido!\n");
    return estoque;
}

//Função desafio
void consultarVolumeEmEstoque(Produto *estoque){

    Produto *auxiliar;
    Produto *listaVolumeBaixo=NULL;
    int volume;

    printf("\n--------------------------------------------------------");
    printf("\n---------Consulta do volume em estoque------");
    printf("\n--------------------------------------------------------\n");
    printf("Digite o volume mínimo em estoque para filtrar os produtos: ");
    scanf("%d", &volume);

    for(auxiliar=estoque;auxiliar!=NULL;auxiliar=auxiliar->proximo){

        if(auxiliar->quantidade < volume){

            Produto *novo= (Produto*) malloc(sizeof(Produto));
            novo=auxiliar;
            novo->proximo=listaVolumeBaixo;

            listaVolumeBaixo=novo;

        }
    }

        if (listaVolumeBaixo!=NULL) {

        relatorio(listaVolumeBaixo,0);

    } else {

        printf("\nNenhum produto com volume abaixo foi encontrado!\n");

    }
}

int main(){

    setlocale(LC_ALL,"Portuguese");

    Produto *estoque=NULL;

    int menu= 20;

    system ("color fc"); //Estilização do programa (windows)

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
            case 4: consultarVolumeEmEstoque(estoque); break;
            case 5: estoque=removerProduto(estoque); break;
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
