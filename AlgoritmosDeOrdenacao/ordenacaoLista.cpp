#include <iostream>
#include <climits>


#include "ordenacaoLista.h"

//Node
struct node{
    int valor;
    node* proximo;
    node* anterior;
};

ordenacaoLista::ordenacaoLista(){
    //inicializa o head e faz ele apontar para ele mesmo
    head = new node;
    head->proximo=nullptr;
    head->anterior=nullptr;
}

ordenacaoLista::~ordenacaoLista(){
    //verifica se a lista esta vazia
    if(!this->empty()){

        node* aux = head->proximo;
        node* t = aux->anterior;

        //deleta node por node
        while(aux!=nullptr){
            delete aux;
            aux = t;
            t = aux->anterior;
        }
    }

    //após o processo apaga o head
    delete head;

    std::cout<<"Lista deletada\n";
}

//Verifica se lista possui elementos
bool ordenacaoLista::empty(){
    //retorna true se o proximo elemento for o head, caso contrario o retorno é false
    return head->proximo==nullptr;
}

//limpa toda a lista
void ordenacaoLista::clear(){
    node *aux = head, *temp;

    while(aux != nullptr){
        temp = aux; //guarda o nó atual
        aux = aux->proximo; //passa para o proximo nó

        if(temp->anterior){
            temp->anterior = nullptr;
        }
        if(temp->proximo){
            temp->proximo = nullptr;
        }
    }
}

//PushBack: adiciona valores
void ordenacaoLista::push_back(int key){
    node *aux = new node;
    aux->proximo = nullptr;
    aux->anterior = nullptr;
    aux->valor = key;

    if (head == nullptr) {
        head = aux;
    }
    else{
        node *last = head;
        while (last->proximo != nullptr){
            last = last->proximo;
        }
        last->proximo = aux;
        aux->anterior = last;
    }

}

//Print: exibi os valores
void ordenacaoLista::print(){

    std::cout<<"[";
    //se estiver vazia vai print somente:[]
    if(!empty()){
        //node que irá percorrer
        node* aux= head->proximo;
        while(aux != nullptr){
            //exibe o valor e vai para o proximo valor
            std::cout<<aux->valor;
            aux= aux->proximo;
            //condição para o aparecimento da virgula
            if(aux!=nullptr){
                std::cout<<",";
            }
        }
    }
    std::cout<<"]\n";
}

//InsertionSortLista
void ordenacaoLista::insertionSort(){
    //nodes que seram movimentados durante a execução
    node *i = nullptr, *j= nullptr;
    //variavel que irá armazenar temporariamente um valor
    int temp;
    //laço externo
    for(i = head; i->proximo != nullptr; i = i->proximo) {
        //laço interno
        for(j = i->proximo; j!= nullptr; j= j->proximo) {
            //if que possibilitará a troca dos valor de i e j
            if(i->valor > j->valor) {
                temp = i->valor;
                i->valor = j->valor;
                j->valor = temp;

            }
        }
    }
}

//SelectSortLista
void ordenacaoLista::selectionSort(){

    node* i = head;

    // laço externo
    while(i){
        node* min = i;
        node* j = i->proximo;

        // laço interno
        while(j){
            if(min->valor > j->valor){
                min = j;
            }
            j = j->proximo;
        }

        // Swap
        int x = i->valor;
        i->valor = min->valor;
        min->valor = x;
        i = i->proximo;
    }
}

//MergeSortLista
//recebe os dois nodes criado, os ordena e concatena
node *mergeSortedLists(node *i, node *j){
    //retorna a lista j se i estiver vazia
   if (i == nullptr) {
      return j;
   }
    //retorna a lista i se j estiver vazia
   if (j == nullptr) {
      return i;
   }
   //movimenta os nodes
   if (i->valor < j->valor) {
      i->proximo = mergeSortedLists(i->proximo, j);
      i->proximo->anterior = i;
      i->anterior = nullptr;
      return i;
   } else {
      j->proximo = mergeSortedLists(i, j->proximo);
      j->proximo->anterior = j;
      j->anterior = nullptr;
      return j;
   }
}

// Dividi os nós da lista em dois nodes usando a estratégia de ponteiro rapido/lento
void dividirLista(node *aux, node **i, node **j){
   node* rapido;
   node* lento;
   lento = aux;
   rapido = aux->proximo;
   //liga os nodes
   while (rapido != nullptr) {
      rapido = rapido->proximo;
      if (rapido != nullptr) {
         lento = lento->proximo;
         rapido = rapido->proximo;
      }
   }
   *i = aux;
   *j = lento->proximo;
   lento->proximo = nullptr;
}

void ordenacaoLista::mergeSort(node **head){
   node* aux = *head;
   //duas lista que serão criadas dividindo aux
   node* i = nullptr;
   node* j = nullptr;
    //se a lista estiver vazia ou possuir penas um elemento será interrompida
   if (aux == nullptr || aux->proximo == nullptr) {
      return;
   }
    //chama a função responsavel por dividir a lista em duas novas listas
   dividirLista(aux, &i, &j);
   //recursividade
   mergeSort(&i);
   mergeSort(&j);
   //função que irá juntar as duas lista depois de ordenar
   *head = mergeSortedLists(i, j);
 }

//QuickSortLista
//troca dois valores inteiros
void swap( int* i, int* j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

// função que irá busca o ultimo node da lista
node *ultimoNode(node *head){
    while (head && head->proximo){
        head = head->proximo;
    }

    return head;
}

//Organiza os elementos da lista pelo elemento
node* organiza(node *i, node *j){
    // j é definido com pivô
    int temp = j->valor;
    node *aux = i->anterior;

  //laço para percorrer
    for (node *r = i; r != j; r = r->proximo){
        if (r->valor <= temp){
            // funciona como um incremento
            aux = (aux == nullptr)? i : aux->proximo;
            swap(&(aux->valor), &(r->valor));
        }
    }
    //funciona como um imcremento
    aux = (aux == nullptr)? i : aux->proximo;
    swap(&(aux->valor), &(j->valor));

    return aux;
}

void _quickSort(node* head, node *aux){

    if (aux != nullptr && head != aux && head != aux->proximo){
        // função que organiza os elementos
        node *p = organiza(head, aux);
        //recursividade
        _quickSort(head, p->anterior);
        _quickSort(p->proximo, aux);
    }

}

void ordenacaoLista::quickSort(node *head){
   // pega o ultimo node
    node *aux = ultimoNode(head);
    //recusividade do algoritmo
    _quickSort(head, aux);
}

//Eandro Cleiton -398487
