#include <iostream>

using namespace std;

// implementacao de heapsort usando a estrutura HEAP

//funcao heapify que organiza o vetor de forma padronizada
//transformando em uma arvore balanceada de um heap de maximo
//i e o indice de elementos, e tamanho e a quantidade total do vetor
//funcao heapify recursiva para balancear as subarvores
void heapify(int elementos[], int i, int tamanho){
    int esq = 2 * i + 1; //indice de no filho da esquerda
    int dir = 2 * i + 2; //indice de no filho da direita
    int maior = i; //indice de no raiz

    //verifica se filho da esquerda e o menor
    if (esq < tamanho && elementos[esq] > elementos[maior]){
        maior = esq;
    }
    
    //verifica se filho da direita e o menor
    if (dir < tamanho && elementos[dir] > elementos[maior]){
        maior = dir;
    }
    
    //caso maior nao seja mais a raiz, faz a recursao da subarvore
    if (maior != i){
        swap(elementos[maior], elementos[i]);

        heapify(elementos, maior, tamanho);
    }
}

//funcao que faz a ordenacao usando o heap
void heapsort(int elementos[], int tamanho){

    //organiza o vetor no formato de heap
    // dividimos o indice por dois pois o resto sao folhas
    for (int i = tamanho / 2 - 1; i >= 0; i--){
        heapify(elementos, i, tamanho);
    } 

    //faz a ordernacao de cada elemento, jogando o menor para a raiz
    for (int i = tamanho - 1; i > 0; i--){
        swap(elementos[0], elementos[i]);

        heapify(elementos, 0, i);
    }

}

int main(){
    //teste com um vetor de 6 elementos
    int elementos[] = {2,4,1,8,6,9};
    int tamanho = 6; //tamanho do vetor elementos

    //ordena vetor
    heapsort(elementos, tamanho);

    //imprime vetor organizado
    for(int i = 0; i < tamanho; i++){
        cout << elementos[i];
        cout << " ";
    }
    cout << endl;

    return 0;
}