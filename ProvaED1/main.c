#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// O(1) - Acesso Direto a um elemento num Array
void AcessoDireto() {
    //Typedef da biblioteca time.h do C que permite trabalharmos com o tempo.
    clock_t inicio = clock();  // Captura o tempo antes da execução

    //Declaração de um Array de inteiros.
    int valores[] = {5,15,25,35,45,78,97,12,74};

    //Printf mostrando o elemento acessado diretamente no índice 5, ou seja, o elemento 78.
    printf("O(1) -> Elemento acessado: %d\n", valores[5]);

    printf("Tempo de execucao O(1): %f segundos\n", (double)(clock() - inicio) / CLOCKS_PER_SEC);
}

//-----------------------------------------------------------------------------

// O(log n) - Busca Binária
void binarySearch(int arr[], int tamanho, int alvo) {
    //a função recebe um array ordenado onde será feita a pesquisa
    //o tamanho do array para sabermos os limites de busca
    //o alvo da busca

    //faz a captura do tempo inicial antes da execução do algoritmo
    clock_t inicio = clock();

    //define os limites da busca a ser feita: primeiro e último elemento respectivamente
    int inicioIntervalo = 0;
    int fimIntervalo = tamanho - 1;

    //variável para armazenar a posição do elemento encontrado
    int posicao = -1; //-1 serve como uma flag para indicar que o elemento não foi encontrado na busca

    //loop para percorrer o intervalo de pesquisa válido (início ainda não ultrapassou o fim)
    while (inicioIntervalo <= fimIntervalo) {
        //calcula o ponto médio do intervalo para dividir a busca pela metade
        int meio = (inicioIntervalo + fimIntervalo) / 2;

        //verifica se o elemento no meio é o que estamos buscando
        if (arr[meio] == alvo) {
            posicao = meio; //guarda a posição encontrada
            break; //sai do loop pois o elemento já foi encontrado
        }

        //ajusta os limites da busca com base no valor alvo comparado com o meio, eliminando o que estiver fora do limite em que o alvo pertence
        if (arr[meio] < alvo) {
            inicioIntervalo = meio + 1; //busca continua na metade direita, pois o elemento do meio é menor (está a esquerda do alvo)
        } else {
            fimIntervalo = meio - 1; //busca continua na metade esquerda, pois o elemento do meio é maior (está a direita do alvo)
        }
    }

    //calcula e exibe o tempo de execução
    printf("Tempo de execucao O(log n): %f segundos\n", (double)(clock() - inicio) / CLOCKS_PER_SEC);

    //exibe o resultado da busca
    if (posicao != -1) {
        printf("Elemento %d encontrado na posicao: %d\n\n", alvo, posicao);
    } else {
        printf("Elemento %d nao foi encontrado no array\n\n", alvo);
    }

}

//-----------------------------------------------------------------------------

// O(n) - Iterar sobre um Array
void percorrerArray(int array[], int tamanho) {
    //marcar o tempo
    clock_t inicio = clock();
    //loop que percorre os indices validos de um array e faz o print dos elementos
    //o tempo de execucao aumenta linearmente conforme o tamanho da entrada
    for (int i = 0; i < tamanho; i++) printf("%d ", array[i]);
    printf("\nTempo O(n): %f segundos\n", (double)(clock() - inicio) / CLOCKS_PER_SEC);
}

//-----------------------------------------------------------------------------

// O(n log n) - Merge Sort (Função principal e a merge desenvolvida)
    void merge(int arr[], int esq, int meio, int dir) {

    /*A função merge recebe o array, e os índices esq, meio e dir, que representam respectivamente,
     o início, o meio e o fim da parte do array que está será combinada*/

    //declaração de variáveis para os índices dos arrays temporários, k= inicio;
    int i = 0, j = 0, k = esq;

    //calcula e define o tamanho das duas metades do array
    int tamEsq = meio - esq + 1, tamDir = dir - meio;

    //arrays temporários para armazenar as metades do array original, L de left (esquerda) e R de right (direita)
    int L[tamEsq], R[tamDir];

    //pega os elementos da primeira metade e segunda metade do array e joga em L e R respectivamente
    for (i = 0; i < tamEsq; i++) L[i] = arr[esq + i];
    for (j = 0; j < tamDir; j++) R[j] = arr[meio + 1 + j];

    //resetamos os indices para nao gerar erro no loop 'while'
    i = j = 0;

    /*a primeira parte do loop tem um térnario que faz a comparação entre L[i] e R[j]
    e se L[i]<=R[j] for verdadeiro então coloca L[i] no array original na posicao correta da ordem
    senão, coloca R[j] no array original
    o loop continua enquanto houver elementos em L e R*/
    while (i < tamEsq && j < tamDir) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    //loops caso ainda houver elementos restantes em L e R, coloca-se eles no array original
    while (i < tamEsq) arr[k++] = L[i++];
    while (j < tamDir) arr[k++] = R[j++];
}

void mergeSort(int arr[], int esq, int dir) {
    //a funcao recebe o array a ser ordenado, esq se refere ao inicio (limite esquerdo) e dir ao fim

    //if para parar a recursao no caso base que é quando se divide até possuirmos arrays individuais onde esq==dir
    if (esq < dir) {
        //calculo do meio do array para que ele possa ser dividido
        int meio = esq + (dir - esq) / 2;

        //chamada recursiva para ordenar a primeira metade do array
       mergeSort(arr, esq, meio);
        //chamada recursiva para ordenar a segunda metade do array
        mergeSort(arr, meio + 1, dir);
        //chamada de merge para mesclar o array
        merge(arr, esq, meio, dir);
    }
}

//-----------------------------------------------------------------------------

// O(n²) - Selection Sort
void selectionSort(int arr[], int tamanho) {
    clock_t inicio = clock(); // captura o tempo inicial antes da excecução do algoritmo
    // variavel intermediaria para armazer os valores para a troca
    int troca;
    // looping para comparar todas as posições do array e econtrar o menor valor
    for (int i = 0; i < tamanho - 1; i++) {
        // considera que o menor ta na posicao i, que é 0 ou seja na primeira posição do array
        int menor = i;
         // procura o menor elemento em relação a i, ou seja, algum elemento menor que o nosso menor armazenado
       for (int j = i + 1; j < tamanho; j++) {
            // se encontrar algum menor atualiza nossa variavel menor
            if (arr[j] < arr[menor]) menor = j; // atualizando o valor do menor
        }
        //realizando a troca dos valores da posição atual com o novo menor encontrado
        troca = arr[i]; // variavel que recebe o valor da posicao atual
        arr[i] = arr[menor]; // posicao atual recebe o novo menor
        arr[menor] = troca; // posicao onde estava o novo menor recebe o valor que antes estava na posicao atual
    }
    //printando na tela o resultado do tempo
    printf("Tempo O(n^2): %f segundos\n", (double)(clock() - inicio) / CLOCKS_PER_SEC);
}

//-----------------------------------------------------------------------------

// O(2ⁿ) - Fibonacci Recursivo
int fibonacci(int n) {
    /*esse algoritmo vai retornar o numero da sequencia de Fibonacci na posição recebido como parametro 'n'
    o ternario verifica se a posicao pedida é um caso base da recursao que é 0 e 1 pois o Fibonacci desses numero
    sao 0 e 1 por definicao, caso nao seja o algoritmo inicia a recursividade com base na propria formula matematica de
    Fibonacci*/
    return (n <= 1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

//-----------------------------------------------------------------------------

// O(n!) - Permutações
void trocar(int *a, int *b) { int temp = *a; *a = *b; *b = temp; }
/*a funcao trocar como o proprio nome diz, faz a troca entre dois elementos,
  ela recebe ponteiros de inteiros que vao apontar o conteudo delas e usar uma
  variavel temporaria para realizar a troca*/

void permutacao(int arr[], int inicio, int tamanho) {
    //caso base que encerra a recursao
    if (inicio == tamanho) {
        //imprime a combinacao (permutacao feita)
        for (int i = 0; i < tamanho; i++) printf("%d ", arr[i]);
        printf("\n");
    } else {
        //loop para executar a recursao e gerar as combinacoes possiveis
        for (int i = inicio; i < tamanho; i++) {
            //troca o elemento do inicio com o elemento do indice i
            trocar(&arr[inicio], &arr[i]);

            /*chamada recursiva passando o proximo indice como inicio,
            esse chamada gera as permutações para o restante do array a partir do índice*/
            permutacao(arr, inicio + 1, tamanho);

            /*restaura a ordem anterior apos chamada recursiva para nao
            perdemos a refenrecia da permutacao e assim gerar todas as combinacoes possiveis*/
            trocar(&arr[inicio], &arr[i]);
        }
    }
}


int main() {
    int array[5] = {1, 2, 3, 4, 5};
    int array2[50000];
    int array3[125000];
    int array4[3000];
    int array5 [100000];
    int array6[1000];
    int array7[8] = {1,2,3,4,5,6,7,8};


    srand(time(NULL));
    for ( int i = 0; i < 100000; i++) array5[i] = rand(); //Preenche o array5 com 100K elementos aleatorios

    srand(time(NULL));
    for ( int i = 0; i < 1000; i++) array6[i] = rand(); //Preenche o array6 com 1K elementos aleatorios

    srand(time(NULL));
    for ( int i = 0; i < 3000; i++) array4[i] = rand(); //Preenche o array4 com 3K elementos aleatorios

    for (int i = 0; i < 50000; i++) array2[i] = i + 1; //Preenche o array2 com valores de 1 a 50000

    for (int i = 0; i < 125000; i++) array3[i] = i + 1; //Preenche o array3 com valores de 1 a 125000


    /*printf("\nExecutando O(1):\n\n");
    AcessoDireto();*/

//--------------------------------------------------------

   /*printf("\nExecutando O(Log n):\n\n");
    int n1 = 1000000, n2 = 10000000, n3 = 10000000000;
    //aloca memória dinamicamente para garantir seguranca da memoria ram e excucao
    int *arr1milhao = malloc(n1 * sizeof(int));
    int *arr10milhoes = malloc(n2 * sizeof(int));
    int *arr10bilhoes = malloc(n3 * sizeof(int));

    //array ordenado é obrigatório para busca binária
    for (int i=0; i<n1; i++) arr1milhao[i] = i+1;
    for (int i=0; i<n2; i++) arr10milhoes[i] = i+1;
    for (int i=0; i<n3; i++) arr10bilhoes[i] = i+1;

    binarySearch(arr10milhoes, n2, 4);

    binarySearch(arr1milhao, n1, 2);

    binarySearch(arr10bilhoes, n3, 7);

    //libera memória alocada
    free(arr1milhao);
    free(arr10milhoes);
    free(arr10bilhoes);*/

//--------------------------------------------------------

    /*printf("\nExecutando O(n):  \n\n");
    percorrerArray(array2,50000);
    percorrerArray(array3,125000);*/

//--------------------------------------------------------

    /*printf("\nExecutando: O(n log n): \n\n");

    clock_t inicioClock, fimClock;
    double tempoGasto;

    inicioClock = clock();  //Captura o tempo antes da execução

    mergeSort(array5,0,99999);

    fimClock = clock();  //Captura o tempo depois da execução

    printf("\n\n");
    printf("Array 5 Ordenado:  ");
    for( int i =0;i<100000;i++) printf("%d ",array5[i]);

    printf("\n\nTempo de execucao O(n Log n): %f segundos\n\n", double)(fimClock - inicioClock) / CLOCKS_PER_SEC);

    inicioClock = clock();

    mergeSort(array4,0,2999);

    fimClock = clock();

    printf("\n\n");
    printf("Array 4 Ordenado:  ");
    for( int i =0;i<3000;i++) printf("%d ",array4[i]);

    printf("\n\nTempo de execucao O(n Log n): %f segundos\n", (double)(fimClock - inicioClock) / CLOCKS_PER_SEC);*/

//------------------------------------------------------------------------------

    /*printf("\nExecutando O(n^2):\n");

    printf("Testanto com n=1000\n");
    selectionSort(array6, 1000);

    printf("Testanto com n=3000\n");
    selectionSort(array4, 3000);

    printf("Testanto com n=10000\n");
    int array8[10000];
    srand(time(NULL));
    for ( int i = 0; i < 10000; i++) array8[i] = rand();
    selectionSort(array8, 10000);*/


//----------------------------------------------------------------------------

    /*printf("\nExecutando O(2^n):\n\n");

    clock_t inicioClock, fimClock;
    double tempoGasto;

    inicioClock = clock();  //Captura o tempo antes da execução
    printf("Resultado: %d\n", fibonacci(30));

    fimClock = clock();  //Captura o tempo depois da execução
    printf("Tempo de execucao O(2^n): %f segundos\n", (double)(fimClock - inicioClock) / CLOCKS_PER_SEC);

    inicioClock = clock();
    printf("\nResultado: %d\n", fibonacci(40));

    fimClock = clock();  //Captura o tempo depois da execução
    printf("Tempo de execucao O(2^n): %f segundos\n", (double)(fimClock - inicioClock) / CLOCKS_PER_SEC);*/

//----------------------------------------------------------------------------

    /*printf("\nExecutando O(n!):\n");

    clock_t inicioClock, fimClock;
    double tempoGasto;

    inicioClock = clock();  //Captura o tempo antes da execução

    permutacao(array, 0, 5);

    fimClock = clock();  //Captura o tempo depois da execução
    printf("\nTempo de execucao O(n!): %f segundos\n", (double)(fimClock - inicioClock) / CLOCKS_PER_SEC);

    inicioClock = clock();  //Captura o tempo antes da execução

    permutacao(array7, 0, 8);

    fimClock = clock();  //Captura o tempo depois da execução
    printf("\nTempo de execucao O(n!): %f segundos\n", (double)(fimClock - inicioClock) / CLOCKS_PER_SEC);*/

    return 0;
}


