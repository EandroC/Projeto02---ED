#ifndef ORDENACAOVETOR_H_INCLUDED
#define ORDENACAOVETOR_H_INCLUDED

class ordenacaoVetor {
public:
    void gera_dados(int num_iteracoes, const int vetor_tam[]);

    void ler_dados(int n, int A[], const char *nomeArquivo);

    void insertionSort(int vetor[], int tamanho);

    void selectionSort(int vetor[], int tamanho);

    void mergeSort(int vetor[],int p,int r);

    void quickSort(int vetor[], int low, int high);

    void shellSort(int vetor[], int tamanho);

};
#endif // ORDENACAOVETOR_H_INCLUDED

//Eandro Cleiton -398487
