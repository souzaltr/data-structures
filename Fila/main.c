#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void initializer_queue (Queue *q, int s){

       q->queueSize=s;
       q->date=(double*) malloc (q->queueSize * sizeof(double));
       q->first=0;
       q->last=-1;
       q->numberOfItens=0;
}

void enqueue (Queue *q, int value){

       q->last++; //incrementa indice ultimo
	q->date[q->last]=value; //nsere o valor na ultima posicao da fila
	q->numberOfItens++; //mais um item foi inserido

}

void dequeue(Queue *q) {

	q->first++;
	q->numberOfItens--;
}

void showQueue(Queue *q){

	int count, i;

	for (count=0, i=q->first; count < q->numberOfItens; count++){

		printf("%.2f\t",q->date[i++]);

		if (i == q->queueSize)
			i=0;

	}
	printf("\n\n");

}

int main() {
       int option, size;
       double value;
       Queue queue;

	// cria a fila
	printf("\nQual a capacidade da fila? ");
	scanf("%d",&size);
	initializer_queue(&queue, size);

	while( 1 ){

		printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Sair");
		scanf("%d", &option);

		switch(option){

			case 0: exit(0);

			case 1:
                                   printf("\nValor do elemento a ser inserido? ");
					scanf("%lf", &value);
					enqueue(&queue,value);
					break;

			case 2:
					dequeue(&queue);
					printf("\nRemovido com sucesso\n\n");
					break;

                     case 3:
                                   printf("\nConteudo da fila => ");
                                   showQueue(&queue);
                                   break;

				default:
					printf("\nOpcao Invalida\n\n");

		}
	}

    return 0;
}
