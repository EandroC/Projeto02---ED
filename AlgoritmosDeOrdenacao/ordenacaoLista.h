#ifndef ORDENACAOLISTA_H_INCLUDED
#define ORDENACAOLISTA_H_INCLUDED

struct node;

class ordenacaoLista{

public:
    //funções
    ordenacaoLista();

    ~ordenacaoLista();

    bool empty();

    void clear();

    void push_back(int key);

    void print();

    void insertionSort();

    void selectionSort();

    void mergeSort(node **head);

    void quickSort(node *head);


    //variaveis
    node* head;
    int tamanho;
};

#endif // ORDENACAOLISTA_H_INCLUDED

//Eandro Cleiton -398487
