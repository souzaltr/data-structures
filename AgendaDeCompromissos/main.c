#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Códigos das cores padrão ANSI
#define RESETAR "\x1b[0m"
#define VERMELHO "\x1b[31m"
#define VERDE "\x1b[32m"
#define AMARELO "\x1b[33m"
#define AZUL "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CIANO "\x1b[36m"

//Define a estrutura Agenda
typedef struct Agenda {
    //Dados úteis de um compromisso (título, assunto, data) e o ponteiro próximo para criar uma lista encadeada
    char titulo [20];
    char assunto [35];
    char data [11];
    struct Agenda *proximo;

} Agenda;

//Função para criar um novo nó e inserir os dados de um compromisso
Agenda* inserirCompromisso (Agenda *agendaDeCompromissos){

    //Aloca dinamicamente um bloco de memória suficiente para armazenar uma estrutura da nossa Agenda
    Agenda *novo= (Agenda*) malloc(sizeof(Agenda));

    printf(AMARELO "\nTítulo do compromisso: " RESETAR);
    fgets(novo->titulo, 20, stdin);

    printf(AMARELO "Assunto do compromisso: " RESETAR);
    fgets(novo->assunto, 35, stdin);

    printf(AMARELO "Data do compromisso (dd/mm/aaaa): " RESETAR);
    fgets(novo->data, 11, stdin);

    novo->proximo= agendaDeCompromissos;
    printf(VERDE "\nO compromisso foi adicionado com sucesso!\n\n" RESETAR);

    return novo;
}

//Função para imprimir todos os compromissos adicionados à lista
void imprimirAgenda (Agenda *agendaDeCompromissos){

    if (agendaDeCompromissos==NULL) {
        printf(VERMELHO "\nNão há nenhum compromisso na agenda.\n" RESETAR);
        return;
    }

    printf(AZUL "\n--- Lista de Compromissos ---\n" RESETAR);
    while (agendaDeCompromissos!=NULL) {
        printf(CIANO "\nTítulo: %s" RESETAR, agendaDeCompromissos->titulo);
        printf(CIANO "Assunto: %s" RESETAR, agendaDeCompromissos->assunto);
        printf(CIANO "Data: %s" RESETAR, agendaDeCompromissos->data);
        agendaDeCompromissos= agendaDeCompromissos->proximo;
    }

    printf("\n");
}

//Função somente para exibir o menu para o usuário
void exibirMenu() {
    printf(MAGENTA "--- MENU ---\n\n" RESETAR);
    printf(VERDE "1. Adicionar compromisso\n" RESETAR);
    printf(AMARELO "2. Exibir os compromissos\n" RESETAR);
    printf(VERMELHO "3. Encerrar o programa\n\n" RESETAR);
    printf(MAGENTA "Escolha uma opção: " RESETAR);
}

int main() {

    setlocale(LC_ALL,"Portuguese");

    int opcao;
    Agenda *agendaDeCompromissos= NULL;

    //Laço de repetição para que as funcionalidades sejam executadas
    do {

        exibirMenu();
        scanf("%d", &opcao);
        getchar(); //Limpar buffer do teclado após caracter ENTER ser inserido

        switch (opcao) {
            case 1:
                agendaDeCompromissos= inserirCompromisso(agendaDeCompromissos);
                break;
            case 2:
                imprimirAgenda(agendaDeCompromissos);
                break;
            case 3:
                printf(VERDE "\nPrograma encerrado!\n" RESETAR);
                break;
            default:
                printf(VERMELHO "\nOpção inválida!\n" RESETAR);
                exit(0);
        }
    } while (opcao != 3);

    //Liberar memória
    Agenda *temp;
    while (agendaDeCompromissos != NULL) {
        temp = agendaDeCompromissos;
        agendaDeCompromissos= agendaDeCompromissos->proximo;
        free(temp);
    }

    return 0;
}
