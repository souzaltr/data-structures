#include <stdlib.h>
#include  <stdio.h>

// Estrutura dos nós que vão compor a árvore de busca
typedef struct arvore {
    int chave;
    struct arvore *esq, *dir;
} Arvore;

// Estrutura para ser a cabeça da árvore
typedef struct {
    Arvore *raiz;
} Cabeca;

// Função que insere um novo nó na arvore de busca
Arvore* insere (Arvore *no, int valor){
    // Caso a referencia seja nula devemos de fato criar o novo nó que será inserido
    if (no == NULL) {
        Arvore *novoNo = (Arvore*) malloc(sizeof(Arvore));
        novoNo->chave = valor;
        novoNo->esq = novoNo->dir = NULL;
        return novoNo;
    }

    // Caso o valor a ser inserido seja menor do que o valor de seu pai, devemos inseri-lo à esquerda
    if (valor < no->chave) 
    {
        no->esq = insere (no->esq, valor); // Recursão para inserir, passando como referencia agora a subarvore esquerda
    } 
    
    // Mesma lógica do if anterior porém considerando que agora o valor é maior, logo inserção à direita
    else if (valor > no->chave) 
    {
        no->dir = insere (no->dir, valor);
    }
    
    return no; // Retornamos a referencia atualizada
}

// Calcula a altura de uma subárvore
int altura (Arvore* raiz){
    if (raiz == NULL) return -1; // Se a referencia é nula sua altura é -1

    // Recursão para termos as alturas da subarvore à esquerda e direita
    int alturaEsq = altura(raiz->esq); 
    int alturaDir = altura(raiz->dir);

    /* Se a altura da subarvore a esquerda for maior retornamos esse valor 
    acrescido de 1 para corrigir o decremento do caso base, caso contrário reotrnamos o outro lado que é maior.*/
    return (alturaEsq > alturaDir ? alturaEsq : alturaDir) +1;
}

// Encontra/busca o nó que contem o valor desejado (usada para uma busca, nesse exercicio é usado para processarmos subarvores na função altura)
Arvore* encontrar(Arvore *arvore, int valor) {
    if (arvore == NULL || arvore->chave == valor) // Se a refencia é nula não há esse valor, se a referencia tem nosso valor a retornamos entao
        return arvore;
    if (valor < arvore->chave) // Se valor for menor devemos procurar apenas na subarvres à esquerda, se não na direita
        return encontrar(arvore->esq, valor);
    else
        return encontrar(arvore->dir, valor);
}

// Impressões em pré-ordem, em ordem e pós ordem 
void preOrdem(Arvore* arvore){
    if (arvore != NULL){
        printf ("%d ", arvore->chave);
        preOrdem(arvore->esq);
        preOrdem(arvore->dir);
    }
}

void emOrdem(Arvore* arvore){
    if (arvore != NULL){
        emOrdem(arvore->esq);
        printf ("%d ", arvore->chave);
        emOrdem(arvore->dir);
    }
}

void posOrdem(Arvore* arvore){
    if (arvore != NULL){
        posOrdem(arvore->esq);
        posOrdem(arvore->dir);
        printf ("%d ", arvore->chave);
    }
}

// Função
Arvore* menorFilho(Arvore* arvore){
    while (arvore->esq != NULL){
        arvore= arvore->esq;
    }

    return arvore;
}

Arvore* remover (Arvore* arvore, int valor){
    if(arvore == NULL) return arvore;

    if (valor < arvore->chave){
        arvore->esq = remover(arvore->esq, valor);
    }

    else if (valor > arvore->chave){
        arvore->dir = remover(arvore->dir, valor);
    }

    else {
        // Caso de remoção de um nó folha 
        if (arvore->esq == NULL && arvore->dir == NULL){
            free(arvore);
            return NULL;
        }

        // Caso em que há dois filhos, então subtituimos pelo menor valor da subarvore à direita
        else if(arvore->esq != NULL && arvore->dir != NULL){
            Arvore* menorDir = menorFilho(arvore->dir);
            arvore->chave = menorDir->chave;
            arvore->dir = remover(arvore->dir, menorDir->chave);
        }

        // Caso de possuir apenas um filho
        else {
            Arvore* aux = arvore->esq ? arvore->esq : arvore->dir;
            free(arvore);
            return aux;
        }
    }

    return arvore;
}

int main (){
    Cabeca cabeca;
    cabeca.raiz = NULL;

    int escolha, valor;

    do {
        printf("\nEscolha uma opcao \n\n");
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Altura da subarvore\n");
        printf("4. Imprimir em pre-ordem\n");
        printf("5. Imprimir em ordem\n");
        printf("6. Imprimir em pos-ordem\n");
        printf("0. Encerrar\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
                printf("Insira um valor a inserir: ");
                scanf("%d", &valor);
                cabeca.raiz = insere(cabeca.raiz, valor);
                break;
            case 2:
                printf("Insira o valor a ser removido: ");
                scanf("%d", &valor);
                cabeca.raiz = remover(cabeca.raiz, valor);
                break;
            case 3:
                printf("Digite o valor da raiz da subarvore: ");
                scanf("%d", &valor);
                Arvore *subArvore = encontrar(cabeca.raiz, valor);
                if (subArvore)
                    printf("Altura da subarvore com raiz %d: %d\n", valor, altura(subArvore));
                else
                    printf("Valor nao esta na arvore.\n");
                break;
            case 4:
                printf("Pre-ordem: ");
                preOrdem(cabeca.raiz);
                printf("\n");
                break;
            case 5:
                printf("Em ordem: ");
                emOrdem(cabeca.raiz);
                printf("\n");
                break;
            case 6:
                printf("Pos-ordem: ");
                posOrdem(cabeca.raiz);
                printf("\n");
                break;
            case 0:
                printf("Finalizado.\n");
                break;
            default:
                printf("Opcao foi invalida!\n");
        }
    } while (escolha != 0);

    return 0;
}