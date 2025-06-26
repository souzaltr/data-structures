#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct {
    char nome[50];
    char email[50];
    int telefone;
    struct lista *proximo;
} listaTelefonica;

listaTelefonica* inicializar();
listaTelefonica* inserir(listaTelefonica*);
void imprimir(listaTelefonica*);

int main(){
    setlocale(LC_ALL,"Portuguese");

    listaTelefonica *lista1;
    lista1= inicializar();
    lista1= inserir(lista1);
    imprimir(lista1);

    return 0;
}

listaTelefonica* inicializar(){
    return NULL;
}

listaTelefonica* inserir(listaTelefonica* destino){
    listaTelefonica* novo= (listaTelefonica*) malloc(sizeof(listaTelefonica));

    printf("\nDigite o nome a ser inserido:");
    gets(novo->nome);
    printf("\nDigite o email a ser inserido:");
    scanf("%s",&novo->email);
    fflush(stdin);
    printf("\nDigite o telefone a ser inserido:");
    scanf("%d",&novo->telefone);
    fflush(stdin);

    novo->proximo=destino;

    return novo;
}

void imprimir(listaTelefonica* lista){
    listaTelefonica* aux;

    for(aux=lista; aux!=NULL; aux=aux->proximo){
        printf("\nNome: %s", aux->nome);
        printf("\nE-mail: %s", aux->email);
        printf("\nTelefone: %d", aux->telefone);
    }
}
