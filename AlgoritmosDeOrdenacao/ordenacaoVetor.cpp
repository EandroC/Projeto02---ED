#include <iostream>
#include <fstream>
#include "ordenacaoVetor.h"

using namespace std;
//Gera os dados nos arquivos que estão dentro da pasta Dados
void ordenacaoVetor::gera_dados(int num_iteracoes, const int vetor_tam[])
{
	for(int n = 0; n < num_iteracoes; n++) {
		// para cada tamanho n, sao gerados 5 vetores de tamanho n aleatorios
		for(int semente = 0; semente < 5; semente++) {
			std::string nome_arquivo = "Dados/Random"+std::to_string(n)+"_"+std::to_string(semente)+".dat";
			ofstream fout(nome_arquivo.c_str(), ios::binary);
			srand(time(NULL)); // gera semente
			int r;
			int tamanho_vetor = vetor_tam[n];
			for(int i = 0; i < tamanho_vetor; i++)
			{
				r = rand()%100+1; // gera numero aleatorio
				fout.write((char*)&r, sizeof(r));
			}
			fout.close();
		}
	}
}

//Ler os dados que foram gerados dentro de cada arquivo
void ordenacaoVetor::ler_dados(int n, int A[], const char *nomeArquivo) {
	ifstream fin(nomeArquivo, ios::binary); // abre arquivo para leitura
	for (int i = 0; i < n; i++)
	{
		fin.read((char*)&A[i], sizeof(int)); // ler os inteiros do arquivo e guarda no vetor A
	}
	fin.close(); // fecha o arquivo de leitura
}

//InsertionSortVetor
void ordenacaoVetor::insertionSort(int vetor[], int tamanho){
    //i e j serão usados nos laços | key guardará v[i] a cada interação
    int i, j, key;

    //laço externo
    for (j = 1; j < tamanho; j++) {
        //key recebe o segundo valor do vetor
        key = vetor[j];
        //laço interno
        for (i = j-1; i >= 0 && vetor[i] > key ; i--){
            vetor[i+1] = vetor[i];
        }
        //troca de valores
        vetor[i+1] = key ;
    }
}

//SelectionSortVetor
void ordenacaoVetor::selectionSort(int vetor[], int tamanho){
    //i será o laço externo e j o laço interno
    int i, j;
    //laço externo
    for (i = 0; i < tamanho-1; i ++) {
        int min = i ;
        //laço interno
        for (j = i+1; j < tamanho;j++){
            if(vetor[j] < vetor[min])
                min = j ;
        }
        //faz a troca dos dois valores inteiros(swap)
        int aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;
    }
}

//MergeSortVetor
void Intercala(int vetor[], int inicio, int meio, int fim) {
    int i, j, k ;
    int *aux = new int [fim-inicio+1]; // Vetor auxiliar
    i = inicio; j = meio +1; k = 0;

    // Intercala vetor[inicio..meio] e vetor[meio +1.. fim]
    while(i<=meio && j<=fim) {
        if (vetor[i]<=vetor[j]){
            aux[k++] = vetor[i++];
        }
        else{
            aux[k++] = vetor[j++];
        }
    }
    while(i<=meio){
        aux[k++] = vetor[i++];
    }
    while(j<=fim){
        aux[k++] = vetor[j++];
    }

    // Copia os elementos que foram ordenados para vetor[]
    for (i=inicio; i<=fim; i++){
        vetor[i] = aux[i-inicio];
    }

    delete [] aux;
}

void ordenacaoVetor::mergeSort( int vetor[], int p, int r) {
    if(p<r){
        //Dividir
        int q = (p+r)/2;
        // Conquistar
        mergeSort(vetor, p, q);
        mergeSort(vetor, q+1, r);
        // Combinar
        Intercala(vetor, p, q, r);
    }
}

//QuickSortVetor
//faz a troca de dois elementos inteiros
void swapQuickSort(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}
//faz a ordenação
int partition (int arr[], int low, int high){
    int pivo = arr[high]; // pivo
    int i = (low-1); // indica a posição correta do pivô

    for (int j=low; j<=high-1 ; j++){
        // Se o elemento atual for menor que o pivô
        if (arr[j]<pivo){
            i++; // índice de incremento do menor elemento
            swapQuickSort(&arr[i], &arr[j]);
        }
    }
    swapQuickSort(&arr[i+1], &arr[high]);
    return (i+1);
}

void ordenacaoVetor::quickSort(int vetor[], int low, int high){

    if (low<high){
        //índice de particionamento
        int pi = partition(vetor, low, high);

        //classica os elementos
        quickSort(vetor, low, pi - 1);
        quickSort(vetor, pi + 1, high);
    }
}

//ShellSortVetor
void ordenacaoVetor::shellSort(int vetor[], int tamanho) {
    int i , j , valor;
    int gap = 1;
    //calcula o valor inicial de gap
    while(gap < tamanho){
        gap = 3*gap+1;
    }
    while (gap > 1){
        gap /= 3; //atualiza o valor de gap
        for(i = gap; i < tamanho; i++){
            valor = vetor[i];
            j = i - gap;
            //faz as comparações
            while (j >= 0 && valor < vetor[j]) {
                vetor[j+gap] = vetor[j];
                j-= gap;
            }
            vetor[j+gap] = valor;
        }
    }
}

//Eandro Cleiton -398487
