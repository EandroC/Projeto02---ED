#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
#include <chrono>

#include "ordenacaoVetor.h"
#include "ordenacaoLista.h"

using namespace std;

int main()
{
    ordenacaoLista *ab = new ordenacaoLista;
    ordenacaoVetor a;
    // Os tamanhos dos vetores a serem testados estao
	// guardados neste vetor 'tam'
	const int tam[] = {500, 1000, 2000, 3000, 4000, 5000, 6000, 7000,
                       8000, 9000, 10000, 11000, 12000, 13000, 14000,
                       15000, 16000, 17000, 18000, 19000,20000};

	int TOTAL_N = sizeof(tam)/sizeof(tam[0]); // determina tamanho do vetor 'tam'


	// Os arquivos sao gerados e salvos na pasta dados
	a.gera_dados(TOTAL_N, tam);

    std::ofstream InsertSortVetor("Resultados/InsertionSortVetor.txt", std::ofstream::out ); // abre arquivo de resultados do InsertSortVetor

	for(int i = 0; i < TOTAL_N; i++) {

		long double duracao_media_insertSortVetor = 0.0;
		int tamanho_vetor = tam[i]; // pega o tamanho do vetor
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado

		//for semente
		for(int semente = 0; semente < 5; semente++)
		{
			string nome_arquivo = "Dados/Random"+std::to_string(i)+"_"+std::to_string(semente)+".dat";

			a.ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
            //exibi dados no vetor antes da ordenação
			/*for(int a=0;a<tamanho_vetor;a++){
                cout<<vetor[a]<<"\n";
			}*/

			// InsertSortVetor ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();

			a.insertionSort(vetor,tamanho_vetor); // ordena o vetor usando o InsertSortVetor

			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();

			// obtendo a duração total da ordenação
			auto duracao_insertSortVetor = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();

			duracao_media_insertSortVetor += duracao_insertSortVetor;

			//exibi dados no vetor depois da ordenação
			/*for(int a=0;a<tamanho_vetor;a++){
                cout<<vetor[a]<<"\n";
			}*/

		}

		duracao_media_insertSortVetor = duracao_media_insertSortVetor / 5.0;
		cout << "[InsertSortVetor] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_insertSortVetor << " microssegundos" << endl;
		InsertSortVetor << tamanho_vetor << " " << duracao_media_insertSortVetor << "\n"; // grava no arquivo de resultados do InsertSortVetor
	}

	InsertSortVetor.close(); // fecha arquivo de resultados do InsertSortVetor
	// ------------------------------------------------------------

	std::ofstream SelectionSortVetor("Resultados/SelectionSortVetor.txt", std::ofstream::out ); // abre arquivo de resultados do SelectionSortVetor

	for(int i = 0; i < TOTAL_N; i++) {

		long double duracao_media_selectSortVetor = 0.0;
		int tamanho_vetor = tam[i]; // pega o tamanho do vetor
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado

		//for semente
		for(int semente = 0; semente < 5; semente++)
		{
			string nome_arquivo = "Dados/Random"+std::to_string(i)+"_"+std::to_string(semente)+".dat";

			a.ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());

			//exibi dados no vetor antes da ordenação
			/*for(int a=0;a<tamanho_vetor;a++){
                cout<<vetor[a]<<"\n";
			}*/

			// SelectionSortVetor ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();

			a.selectionSort(vetor,tamanho_vetor); // ordena o vetor usando o SelectionSortVetor

			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();

			// obtendo a duração total da ordenação
			auto duracao_selectionSortVetor = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();

			duracao_media_selectSortVetor += duracao_selectionSortVetor;

			//exibi dados no vetor depois da ordenação
			/*for(int a=0;a<tamanho_vetor;a++){
                cout<<vetor[a]<<"\n";
			}*/

		}

		duracao_media_selectSortVetor = duracao_media_selectSortVetor / 5.0;
		cout << "[SelectionSortVetor] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_selectSortVetor << " microssegundos" << endl;
		SelectionSortVetor << tamanho_vetor << " " << duracao_media_selectSortVetor << "\n"; // grava no arquivo de resultados do SelectionSortVetor
	}

	SelectionSortVetor.close(); // fecha arquivo de resultados do SelectionSortVetor
	// ------------------------------------------------------------

    std::ofstream MergeSortVetor("Resultados/MergeSortVetor.txt", std::ofstream::out ); // abre arquivo de resultados do MergeSortVetor

	for(int i = 0; i < TOTAL_N; i++) {

		long double duracao_media_mergeSortVetor = 0.0;
		int tamanho_vetor = tam[i]; // pega o tamanho do vetor
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado

		//for semente
		for(int semente = 0; semente < 5; semente++)
		{
			string nome_arquivo = "Dados/Random"+std::to_string(i)+"_"+std::to_string(semente)+".dat";

			a.ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			//exibi dados no vetor antes da ordenação
			/*for(int a=0;a<tamanho_vetor;a++){
                cout<<vetor[a]<<"\n";
			}*/

			// MergeSortVetor ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();

			a.mergeSort(vetor,0,tamanho_vetor-1); // ordena o vetor usando o MergeSortVetor

			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();

			// obtendo a duração total da ordenação
			auto duracao_mergeSortVetor = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();

			duracao_media_mergeSortVetor += duracao_mergeSortVetor;
			//exibi dados no vetor depois da ordenação
			/*for(int a=0;a<tamanho_vetor;a++){
                cout<<vetor[a]<<"\n";
			}*/

		}

		duracao_media_mergeSortVetor = duracao_media_mergeSortVetor/ 5.0;
		cout << "[MergeSortVetor] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_mergeSortVetor << " microssegundos" << endl;
		MergeSortVetor << tamanho_vetor << " " << duracao_media_mergeSortVetor << "\n"; // grava no arquivo de resultados do MergeSortVetor
	}

	MergeSortVetor.close(); // fecha arquivo de resultados do MergeSortVetor
	// ------------------------------------------------------------
	std::ofstream QuickSortVetor("Resultados/QuickSortVetor.txt", std::ofstream::out ); // abre arquivo de resultados do QuickSortVetor

	for(int i = 0; i < TOTAL_N; i++) {

		long double duracao_media_quickSortVetor = 0.0;
		int tamanho_vetor = tam[i]; // pega o tamanho do vetor
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado

		//for semente
		for(int semente = 0; semente < 5; semente++)
		{
			string nome_arquivo = "Dados/Random"+std::to_string(i)+"_"+std::to_string(semente)+".dat";

			a.ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			//exibi dados no vetor antes da ordenação
			/*for(int a=0;a<tamanho_vetor;a++){
                cout<<vetor[a]<<"\n";
			}*/

			// QuickSortVetor ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();

			a.quickSort(vetor,0,tamanho_vetor-1); // ordena o vetor usando o QuickSortVetor

			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();

			// obtendo a duração total da ordenação
			auto duracao_quickSortVetor = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();

			duracao_media_quickSortVetor += duracao_quickSortVetor;
			//exibi dados no vetor depois da ordenação
			/*for(int a=0;a<tamanho_vetor;a++){
                cout<<vetor[a]<<"\n";
			}*/

		}

		duracao_media_quickSortVetor = duracao_media_quickSortVetor/ 5.0;
		cout << "[QuickSortVetor] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_quickSortVetor << " microssegundos" << endl;
		QuickSortVetor << tamanho_vetor << " " << duracao_media_quickSortVetor << "\n"; // grava no arquivo de resultados do QuickSortVetor
	}

	QuickSortVetor.close(); // fecha arquivo de resultados do QuickSortVetor
	// ------------------------------------------------------------

	std::ofstream ShellSortVetor("Resultados/ShellSortVetor.txt", std::ofstream::out ); // abre arquivo de resultados do ShellSortVetor

	for(int i = 0; i < TOTAL_N; i++) {

		long double duracao_media_shellSortVetor = 0.0;
		int tamanho_vetor = tam[i]; // pega o tamanho do vetor
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado

		//for semente
		for(int semente = 0; semente < 5; semente++)
		{
			string nome_arquivo = "Dados/Random"+std::to_string(i)+"_"+std::to_string(semente)+".dat";

			a.ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			//exibi dados no vetor antes da ordenação
			/*for(int a=0;a<tamanho_vetor;a++){
                cout<<vetor[a]<<"\n";
			}*/

			// ShellSortVetor ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();

			a.shellSort(vetor,tamanho_vetor); // ordena o vetor usando o ShellSortVetor

			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();

			// obtendo a duração total da ordenação
			auto duracao_shellSortVetor = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();

			duracao_media_shellSortVetor += duracao_shellSortVetor;

			//exibi dados no vetor depois da ordenação
			/*for(int a=0;a<tamanho_vetor;a++){
                cout<<vetor[a]<<"\n";
			}*/

		}

		duracao_media_shellSortVetor = duracao_media_shellSortVetor/ 5.0;
		cout << "[ShellSortVetor] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_shellSortVetor << " microssegundos" << endl;
		ShellSortVetor << tamanho_vetor << " " << duracao_media_shellSortVetor << "\n"; // grava no arquivo de resultados do ShellSortVetor
	}

	ShellSortVetor.close(); // fecha arquivo de resultados do ShellSortVetor
	// ------------------------------------------------------------

	std::ofstream InsertSortLista("Resultados/InsertionSortLista.txt", std::ofstream::out ); // abre arquivo de resultados do InsertSortLista

	for(int i = 0; i < TOTAL_N; i++) {

		long double duracao_media_insertionSortLista = 0.0;
		int tamanho_vetor = tam[i]; // pega o tamanho do vetor
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado

		//for semente
		for(int semente = 0; semente < 5; semente++)
		{
			string nome_arquivo = "Dados/Random"+std::to_string(i)+"_"+std::to_string(semente)+".dat";

			a.ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());

            for(int a=0;a<tamanho_vetor;a++){
                ab->push_back(vetor[a]);
			}
			//exibi dados no vetor antes da ordenação
			/*for(int a=0;a<tamanho_vetor;a++){
                cout<<vetor[a]<<"\n";
			}*/
			//Exibi a lista antes da ordenação
			//ab->print();

			// InsertSortLista ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();

			ab->insertionSort(); // ordena o vetor usando o InsertSortLista

			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();

			// obtendo a duração total da ordenação
			auto duracao_insertSortLista = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();

			duracao_media_insertionSortLista += duracao_insertSortLista;


			//Exibi a lista depois da ordenação
			//ab->print();

			ab->clear();

		}

		duracao_media_insertionSortLista = duracao_media_insertionSortLista/ 5.0;
		cout << "[InsertSortLista] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_insertionSortLista << " microssegundos" << endl;
		InsertSortLista << tamanho_vetor << " " << duracao_media_insertionSortLista << "\n"; // grava no arquivo de resultados do InsertSortLista
	}

	InsertSortLista.close(); // fecha arquivo de resultados do InsertionSortLista
	// ------------------------------------------------------------

	std::ofstream SelectionSortLista("Resultados/SelectionSortLista.txt", std::ofstream::out ); // abre arquivo de resultados do SelectionSortLista

	for(int i = 0; i < TOTAL_N; i++) {

		long double duracao_media_selectionSortLista = 0.0;
		int tamanho_vetor = tam[i]; // pega o tamanho do vetor
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado

		//for semente
		for(int semente = 0; semente < 5; semente++)
		{
			string nome_arquivo = "Dados/Random"+std::to_string(i)+"_"+std::to_string(semente)+".dat";

			a.ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());

            for(int a=0;a<tamanho_vetor;a++){
                ab->push_back(vetor[a]);
			}

			//exibi dados no vetor antes da ordenação
			/*for(int a=0;a<tamanho_vetor;a++){
                cout<<vetor[a]<<"\n";
			}*/
			//Exibi a lista antes da ordenação
			//ab->print();

			// SelectionSortLista ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();

			ab->selectionSort(); // ordena o vetor usando o SelectionSortLista

			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();

			// obtendo a duração total da ordenação
			auto duracao_selectionSortLista = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();

			duracao_media_selectionSortLista += duracao_selectionSortLista;

			//Exibi a lista depois da ordenação
			//ab->print();

			ab->clear();

		}

		duracao_media_selectionSortLista = duracao_media_selectionSortLista/ 5.0;
		cout << "[SelectionSortLista] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_selectionSortLista << " microssegundos" << endl;
		SelectionSortLista << tamanho_vetor << " " << duracao_media_selectionSortLista << "\n"; // grava no arquivo de resultados do SelectionSortLista
	}

	SelectionSortLista.close(); // fecha arquivo de resultados do SelectionSortLista
	// ------------------------------------------------------------

    std::ofstream MergeSortLista("Resultados/MergeSortLista.txt", std::ofstream::out ); // abre arquivo de resultados do MergeSortLista

	for(int i = 0; i < TOTAL_N; i++) {

		long double duracao_media_mergeSortLista = 0.0;
		int tamanho_vetor = tam[i]; // pega o tamanho do vetor
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado

		//for semente
		for(int semente = 0; semente < 5; semente++)
		{
			string nome_arquivo = "Dados/Random"+std::to_string(i)+"_"+std::to_string(semente)+".dat";

			a.ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());

            for(int a=0;a<tamanho_vetor;a++){
                ab->push_back(vetor[a]);
			}

			//exibi dados no vetor antes da ordenação
			/*for(int a=0;a<tamanho_vetor;a++){
                cout<<vetor[a]<<"\n";
			}*/
			//Exibi a lista antes da ordenação
			//ab->print();

			// MergeSortLista ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();

			ab->mergeSort(&ab->head); // ordena o vetor usando o MergeSortLista

			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();

			// obtendo a duração total da ordenação
			auto duracao_mergeSortLista = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();

			duracao_media_mergeSortLista+= duracao_mergeSortLista;

			//Exibi a lista depois da ordenação
			//ab->print();

			ab->clear();

		}

		duracao_media_mergeSortLista = duracao_media_mergeSortLista/ 5.0;
		cout << "[MergeSortLista] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_mergeSortLista << " microssegundos" << endl;
		MergeSortLista << tamanho_vetor << " " << duracao_media_mergeSortLista << "\n"; // grava no arquivo de resultados do MergeSortLista
	}

	MergeSortLista.close(); // fecha arquivo de resultados do MergeSortLista
	// ------------------------------------------------------------
	std::ofstream QuickSortLista("Resultados/QuickSortLista.txt", std::ofstream::out ); // abre arquivo de resultados do QuickSortLista

	for(int i = 0; i < TOTAL_N; i++) {

		long double duracao_media_quickSortLista = 0.0;
		int tamanho_vetor = tam[i]; // pega o tamanho do vetor
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado

		//for semente
		for(int semente = 0; semente < 5; semente++)
		{
			string nome_arquivo = "Dados/Random"+std::to_string(i)+"_"+std::to_string(semente)+".dat";

			a.ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());

            for(int a=0;a<tamanho_vetor;a++){
                ab->push_back(vetor[a]);
			}
			//exibi dados no vetor antes da ordenação
			/*for(int a=0;a<tamanho_vetor;a++){
                cout<<vetor[a]<<"\n";
			}*/
			//Exibi a lista antes da ordenação
			//ab->print();

			// QuickSortLista ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();

			ab->quickSort(ab->head); // ordena o vetor usando o QuickSortLista

			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();

			// obtendo a duração total da ordenação
			auto duracao_quickSortLista = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();

			duracao_media_quickSortLista+= duracao_quickSortLista;


			//Exibi a lista depois da ordenação
			//ab->print();

			ab->clear();

		}

		duracao_media_quickSortLista = duracao_media_quickSortLista/ 5.0;
		cout << "[QuickSortLista] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_quickSortLista << " microssegundos" << endl;
		QuickSortLista << tamanho_vetor << " " << duracao_media_quickSortLista<< "\n"; // grava no arquivo de resultados do QuickSortLista
	}

	QuickSortLista.close(); // fecha arquivo de resultados do QuickSortLista
	// ------------------------------------------------------------


	return 0;
}

//Eandro Cleiton -398487
