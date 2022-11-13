#include <stdio.h>;
#include <stdlib.h>;
#include <time.h>;

int SEED = 1234554321;
int LOW = 0;
int HIGH = 100000;

double unif(long int* seed, double low, double high) {
	double unif_ret;
	long int m, a, b, c, k;
	double value_0_1;
	m = 2147483647;
	a = 16807;
	b = 127773;
	c = 2836;
	k = *seed / b;
	*seed = a * (*seed % b) - k * c;
	if (*seed < 0)
		*seed = *seed + m;
	value_0_1 = (double)*seed / m;
	unif_ret = low + value_0_1 * (high - low);
	return (unif_ret);
}

int inteiros_unif(long int* seed, int low, int high) {
	int unif_ret;
	long int m, a, b, c, k;
	double value_0_1;
	m = 2147483647;
	a = 16807;
	b = 127773;
	c = 2836;
	k = *seed / b;
	*seed = a * (*seed % b) - k * c;
	if (*seed < 0)
		*seed = *seed + m;
	value_0_1 = (double)*seed / m;
	unif_ret = low + value_0_1 * (high - low + 1);
	return (unif_ret);
}

//Gerar coleção
void generate_integer_collection(int* collection, int length) {

	for (int i = 0; i < length; i++)
	{
		collection[i] = inteiros_unif(&SEED, LOW, HIGH);
	}
}

void generate_double_collection(double* collection, int length) {

	for (int i = 0; i < length; i++)
	{
		collection[i] = unif(&SEED, LOW, HIGH);
	}
}

// Obter tempo utilizado
double get_used_time(int start, int end) {
	return (end - start) * 1000 / CLOCKS_PER_SEC;
}

// Busca sequencial
int integer_sequential_search(int* collection, int reference, int length) {
	int counter = 0;
	for (int i = 0; i < length; i++)
	{
		counter++;;
		if (collection[i] == reference)
		{
			return counter;
		}
	}

	return counter;
}

int double_sequential_search(double* collection, double reference, int length) {
	int counter = 0;
	for (int i = 0; i < length; i++)
	{
		counter++;;
		if (collection[i] == reference)
		{
			return counter;
		}
	}

	return counter;
}

//Busca sequencial com sentinela
int sequential_integer_search_with_sentinel(int* collection, int reference, int length) {
	int i = 0;

	collection[length + 1] = reference;

	while (collection[i] != reference) {
		i++;
	}
	return i;
}

int sequential_double_search_with_sentinel(double* collection, double reference, int length) {
	int i = 0;

	collection[length + 1] = reference;

	while (collection[i] != reference) {
		i++;
	}

	return i;
}

//Busca binária
int search_integer_binary(int* collection, int reference, int length) {
	int bottom = 0 /*limite inferior*/, higher = length - 1 /*limite superior*/, middle, counter = 0;

	while (bottom <= higher) {
		middle = (bottom + higher) / 2;
		counter++;
		if (reference == collection[middle])
			//return middle; //posicao do número buscado
			return counter;
		if (higher < collection[middle])
			higher = middle - 1;
		else
			bottom = middle + 1;
	}
	return counter;
}

int search_double_binary(double* collection, double reference, int length) {
	int bottom = 0 /*limite inferior*/, higher = length - 1 /*limite superior*/, middle, counter = 0;

	while (bottom <= higher) {
		middle = (bottom + higher) / 2;
		counter++;
		if (reference == collection[middle])
			//return middle; //posicao do número buscado
			return counter;
		if (higher < collection[middle])
			higher = middle - 1;
		else
			bottom = middle + 1;
	}
	return counter;
}

//Ordenação com BubleSort
int integerBubleSort(int* collection, int length) {
	int cont = 0, aux, end = length;

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			cont++;
			if (collection[j] > collection[j + 1]) {
				aux = collection[j];
				collection[j] = collection[j + 1];
				collection[j + 1] = aux;
			}
		}
	}

	return cont;
}

int doubleBubleSort(double* collection, int length) {
	int cont = 0, end = length;
	double aux;

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			cont++;
			if (collection[j] > collection[j + 1]) {
				aux = collection[j];
				collection[j] = collection[j + 1];
				collection[j + 1] = aux;
			}
		}
	}

	return cont;
}

//Ordenação com SelectionSort
int integerSelectioSort(int* collection, int length) {
	int i, j, smaller, swap, counter = 0;

	for (i = 0; i < length - 1; i++)
	{
		smaller = i;
		for (j = i + 1; j < length; j++)
		{
			counter++;
			if (collection[j] < collection[smaller])
				smaller = j;
		}
		if (i != smaller)
		{
			swap = collection[i];
			collection[i] = collection[smaller];
			collection[smaller] = swap;
		}
	}

	return counter;
}

int doubleSelectioSort(double* collection, int length) {
	int i, j, smaller, counter = 0;
	double swap;

	for (i = 0; i < length - 1; i++)
	{
		smaller = i;
		for (j = i + 1; j < length; j++)
		{
			counter++;
			if (collection[j] < collection[smaller])
				smaller = j;
		}
		if (i != smaller)
		{
			swap = collection[i];
			collection[i] = collection[smaller];
			collection[smaller] = swap;
		}
	}

	return counter;
}

//Escrever coleção
void write_collection(int* collection, int lentgh) {
	for (int i = 0; i < lentgh; i++)
	{
		printf("%d\n", collection[i]);
	}
}

void write_double_collection(double* collection, int lentgh) {
	for (int i = 0; i < lentgh; i++)
	{
		printf("%lf\n", collection[i]);
	}
}

//Busca binária com BubbleSort
void integer_binarySearch_whith_bubbleSort(int* collection, int length, int reference) {
	clock_t start, end;
	unsigned long int time;
	int amount_tests = 0;
	start = clock();

	amount_tests = integerBubleSort(collection, length);
	amount_tests += search_integer_binary(collection, reference, length);
	end = clock();
	time = get_used_time(start, end);
	printf("\nTamanho do Vetor: %d - Numero Buscado: %d - Quantidade de Testes: %d - Tempo de Execucao: %lu milissegundos\n", length, reference, amount_tests, time);
}

void double_binarySearch_whith_bubbleSort(int* collection, int length, int reference) {
	clock_t start, end;
	unsigned long int time;
	int amount_tests = 0;
	start = clock();

	amount_tests = doubleBubleSort(collection, length);
	amount_tests += search_double_binary(collection, reference, length);
	end = clock();
	time = get_used_time(start, end);
	printf("\nTamanho do Vetor: %d - Numero Buscado: %d - Quantidade de Testes: %d - Tempo de Execucao: %lu milissegundos\n", length, reference, amount_tests, time);
}

//Busca binária com SelectionSort
void integer_binarySearch_whith_selectioSort(int* collection, int length, int reference) {
	clock_t start, end;
	unsigned long int time;

	int amount_tests = 0;
	start = clock();

	amount_tests = integerSelectioSort(collection, length);
	amount_tests += search_integer_binary(collection, reference, length);
	end = clock();
	time = get_used_time(start, end);
	printf("\nTamanho do Vetor: %d - Numero Buscado: %d - Quantidade de Testes: %d - Tempo de Execucao: %lu milissegundos\n", length, reference, amount_tests, time);
}

void double_binarySearch_whith_selectioSort(int* collection, int length, int reference) {
	clock_t start, end;
	unsigned long int time;

	int amount_tests = 0;
	start = clock();

	amount_tests = doubleSelectioSort(collection, length);
	amount_tests += search_double_binary(collection, reference, length);
	end = clock();
	time = get_used_time(start, end);
	printf("\nTamanho do Vetor: %d - Numero Buscado: %d - Quantidade de Testes: %d - Tempo de Execucao: %lu milissegundos\n", length, reference, amount_tests, time);
}

//Exibir performace da busca linear
void show_performace_double_sequential_search(double* collection, int length, double reference) {
	clock_t start, end;
	unsigned long int time;

	int amount_tests = 0;

	start = clock();
	amount_tests = double_sequential_search(collection, reference, length);
	end = clock();

	time = get_used_time(start, end);

	printf("\nTamanho do Vetor: %d - Numero Buscado: %lf - Quantidade de Testes: %d - Tempo de Execucao: %lu milissegundos\n", length, reference, amount_tests, time);
}

void show_performace_integer_sequential_search(int* collection, int length, int reference) {
	clock_t start, end;
	unsigned long int time;

	int amount_tests = 0;

	start = clock();
	amount_tests = integer_sequential_search(collection, reference, length);
	end = clock();

	time = get_used_time(start, end);

	printf("\nTamanho do Vetor: %d - Numero Buscado: %d - Quantidade de Testes: %d - Tempo de Execucao: %lu milissegundos\n", length, reference, amount_tests, time);
}

//Exibir performace da busca linear com sentinela
void show_performace_double_sequential_search_whit_sentinel(double* collection, int length, double reference) {
	clock_t start, end;
	unsigned long int time;

	int amount_tests = 0;

	start = clock();
	amount_tests = sequential_double_search_with_sentinel(collection, reference, length);
	end = clock();

	time = get_used_time(start, end);

	printf("\nTamanho do Vetor: %d - Numero Buscado: %lf - Quantidade de Testes: %d - Tempo de Execucao: %lu milissegundos\n", length, reference, amount_tests, time);
}

void show_performace_integer_sequential_search_whit_sentinel(int* collection, int length, int reference) {
	clock_t start, end;
	unsigned long int time;

	int amount_tests = 0;

	start = clock();
	amount_tests = sequential_integer_search_with_sentinel(collection, reference, length);
	end = clock();

	time = get_used_time(start, end);

	printf("\nTamanho do Vetor: %d - Numero Buscado: %d - Quantidade de Testes: %d - Tempo de Execucao: %lu milissegundos\n", length, reference, amount_tests, time);
}

//Exibir performace do BubbleSort
void show_performace_double_bubbleSort(double* collection, int length) {
	clock_t start, end;
	unsigned long int time;

	int amount_tests = 0;

	start = clock();
	amount_tests = doubleBubleSort(collection, length);
	end = clock();

	time = get_used_time(start, end);

	printf("\nTamanho do Vetor: %d - Quantidade de Testes: %d - Tempo de Execucao: %lu milissegundos\n", length, amount_tests, time);
}

//Exbir performace do SelectioSort
void show_performace_double_selectionSort(double* collection, int length) {
	clock_t start, end;
	unsigned long int time;

	int amount_tests = 0;

	start = clock();
	amount_tests = doubleSelectioSort(collection, length);
	end = clock();

	time = get_used_time(start, end);

	printf("\nTamanho do Vetor: %d - Quantidade de Testes: %d - Tempo de Execucao: %lu milissegundos\n", length, amount_tests, time);
}

//Método Principal
int main() {
	int SMALL = 100;
	int MEDIUM = 1000;
	int LARGE = 10000;
	int EXTRA_LARGE = 100000;

	int REFERENCE = 87;
	int NON_EXISTING_REFERENCE = 100001;

	clock_t start, end;
	unsigned long int time;
	
	
	int amount_tests = 0;

	int integersCollection1[100];
	int integersCollection2[1000];
	int integersCollection3[10000];
	int integersCollection4[100000];

	generate_integer_collection(&integersCollection1, SMALL);
	generate_integer_collection(&integersCollection2, MEDIUM);
	generate_integer_collection(&integersCollection3, LARGE);
	generate_integer_collection(&integersCollection4, EXTRA_LARGE);


	/*double doublesCollection1[100];
	double doublesCollection2[1000];
	double doublesCollection3[10000];
	double doublesCollection4[100000];
	generate_double_collection(doublesCollection1, SMALL);
	generate_double_collection(doublesCollection2, MEDIUM);
	generate_double_collection(doublesCollection3, LARGE);
	generate_double_collection(doublesCollection4, EXTRA_LARGE);
	*/

	//PASSO 1 - REAIS
	//BUSCA LIENAR
	//BUSCANDO O NÚMERO 87
	/*show_performace_double_sequential_search(doublesCollection1, SMALL, 87);//100
	show_performace_double_sequential_search(doublesCollection2, MEDIUM, 87);//1000
	show_performace_double_sequential_search(doublesCollection3, LARGE, 87);//10000
	show_performace_double_sequential_search(doublesCollection4, EXTRA_LARGE, 87);//100000
	*/

	//BUSCANDO O NÚMERO 100001
	/*show_performace_double_sequential_search(doublesCollection1, SMALL, 100001);//100
	show_performace_double_sequential_search(doublesCollection2, MEDIUM, 100001);//1000
	show_performace_double_sequential_search(doublesCollection3, LARGE, 100001);//10000
	show_performace_double_sequential_search(doublesCollection4, EXTRA_LARGE, 100001);//100000
	*/

	//BUSCA COM SENTINELA
	//BUSCANDO O NÚMERO 100001
	//show_performace_double_sequential_search_whit_sentinel(doublesCollection1, SMALL, 87);
	//show_performace_double_sequential_search_whit_sentinel(doublesCollection2, MEDIUM, 87);
	//show_performace_double_sequential_search_whit_sentinel(doublesCollection3, LARGE, 87);
	//show_performace_double_sequential_search_whit_sentinel(doublesCollection4, EXTRA_LARGE, 87);

	//BUSCANDO O NÚMERO 100001
	//show_performace_double_sequential_search_whit_sentinel(doublesCollection1, SMALL, 100001);
	//show_performace_double_sequential_search_whit_sentinel(doublesCollection2, MEDIUM, 100001);
	//show_performace_double_sequential_search_whit_sentinel(doublesCollection3, LARGE, 100001);
	//show_performace_double_sequential_search_whit_sentinel(doublesCollection4, EXTRA_LARGE, 100001);

	//PASSO 2 - REAIS
	//ORDENAÇÃO
	//ORDENANDO COM BUBBLESORT
	//show_performace_double_bubbleSort(doublesCollection1, SMALL);//100
	//show_performace_double_bubbleSort(doublesCollection2, MEDIUM);//1000
	//show_performace_double_bubbleSort(doublesCollection3, LARGE);//10000
	//show_performace_double_bubbleSort(doublesCollection4, EXTRA_LARGE);//100000

	//ORDENAÇÃO
	//ORDENANDO COM SELECTIONSORT
	//show_performace_double_selectionSort(doublesCollection1, SMALL);//100
	//show_performace_double_selectionSort(doublesCollection2, MEDIUM);//1000
	//show_performace_double_selectionSort(doublesCollection3, LARGE);//10000
	//show_performace_double_selectionSort(doublesCollection4, EXTRA_LARGE);//100000

	//PASSO 3 - REAIS
	//BUSCA BINARIA
	//BUSCA BINARIA DO NUMRO 87 COM BUBBLESORT
	//double_binarySearch_whith_bubbleSort(doublesCollection1, SMALL, 87);
	//double_binarySearch_whith_bubbleSort(doublesCollection2, MEDIUM, 87);
	//double_binarySearch_whith_bubbleSort(doublesCollection3, LARGE, 87);
	//double_binarySearch_whith_bubbleSort(doublesCollection4, EXTRA_LARGE, 87);

	//BUSCA BINARIA DO NUMRO 100001 COM BUBBLESORT
	//double_binarySearch_whith_bubbleSort(doublesCollection1, SMALL, 100001);
	//double_binarySearch_whith_bubbleSort(doublesCollection2, MEDIUM, 100001);
	//double_binarySearch_whith_bubbleSort(doublesCollection3, LARGE, 100001);
	//double_binarySearch_whith_bubbleSort(doublesCollection4, EXTRA_LARGE, 100001);

	//BUSCA BINARIA DO NUMRO 87 COM SELECTIONSORT
	//double_binarySearch_whith_selectioSort(doublesCollection1, SMALL, 87);
	//double_binarySearch_whith_selectioSort(doublesCollection2, MEDIUM, 87);
	//double_binarySearch_whith_selectioSort(doublesCollection3, LARGE, 87);
	//double_binarySearch_whith_selectioSort(doublesCollection4, EXTRA_LARGE, 87);

	//BUSCA BINARIA DO NUMRO 100001 COM SELECTIONSORT
	//double_binarySearch_whith_selectioSort(doublesCollection1, SMALL, 100001);
	//double_binarySearch_whith_selectioSort(doublesCollection2, MEDIUM, 100001);
	//double_binarySearch_whith_selectioSort(doublesCollection3, LARGE, 100001);
	//double_binarySearch_whith_selectioSort(doublesCollection4, EXTRA_LARGE, 100001);


	//PASSO 1 - INTEIROS

	//BUSCA LIENAR
	//BUSCANDO O NÚMERO 87
	//show_performace_integer_sequential_search(integersCollection1, SMALL, 87);
	//show_performace_integer_sequential_search(integersCollection2, MEDIUM, 87);
	//show_performace_integer_sequential_search(integersCollection3, LARGE, 87);
	//show_performace_integer_sequential_search(integersCollection4, EXTRA_LARGE, 87);

	//BUSCANDO O NÚMERO 100001
	//show_performace_integer_sequential_search(integersCollection1, SMALL, 100001);
	//show_performace_integer_sequential_search(integersCollection2, MEDIUM, 100001);
	//show_performace_integer_sequential_search(integersCollection3, LARGE, 100001);
	//show_performace_integer_sequential_search(integersCollection4, EXTRA_LARGE, 100001);

	//BUSCA COM SENTINELA
	//BUSCANDO O NÚMERO 100001
	//show_performace_integer_sequential_search_whit_sentinel(integersCollection1, SMALL, 87);
	//show_performace_integer_sequential_search_whit_sentinel(integersCollection2, MEDIUM, 87);
	//show_performace_integer_sequential_search_whit_sentinel(integersCollection3, LARGE, 87);
	//show_performace_integer_sequential_search_whit_sentinel(integersCollection4, EXTRA_LARGE, 87);

	//BUSCANDO O NÚMERO 100001
	//show_performace_integer_sequential_search_whit_sentinel(integersCollection1, SMALL, 100001);
	//show_performace_integer_sequential_search_whit_sentinel(integersCollection2, MEDIUM, 100001);
	//show_performace_integer_sequential_search_whit_sentinel(integersCollection3, LARGE, 100001);
	//show_performace_integer_sequential_search_whit_sentinel(integersCollection4, EXTRA_LARGE, 100001);

	//write_collection(integersCollection1, SMALL);
	//write_double_collection(doublesCollection1, SMALL);


	//ORDENACAO DE INTEIROS COM BUBBLESORT
	/*start = clock();
	amount_tests = integerBubleSort(&integersCollection1, SMALL);//100
	end = clock();

	time = get_used_time(start, end);

	printf("\nTamanho do Vetor: %d - Quantidade de Testes: %d - Tempo de Execucao: %lu milissegundos\n", SMALL, amount_tests, time);
	*/

	/*start = clock();
	amount_tests = integerBubleSort(&integersCollection2, MEDIUM);//1000
	end = clock();

	time = get_used_time(start, end);

	printf("\nTamanho do Vetor: %d - Quantidade de Testes: %d - Tempo de Execucao: %lu milissegundos\n", MEDIUM, amount_tests, time);
	*/

	/*start = clock();
	amount_tests = integerBubleSort(&integersCollection3, LARGE);//10000
	end = clock();

	time = get_used_time(start, end);

	printf("\nTamanho do Vetor: %d - Quantidade de Testes: %d - Tempo de Execucao: %lu milissegundos\n", LARGE, amount_tests, time);
	*/

	/*start = clock();
	amount_tests = integerBubleSort(&integersCollection4, EXTRA_LARGE);//100000
	end = clock();

	time = get_used_time(start, end);

	printf("\nTamanho do Vetor: %d - Quantidade de Testes: %d - Tempo de Execucao: %lu milissegundos\n", EXTRA_LARGE, amount_tests, time);
	*/


	//ORDENACAO DE INTEIROS COM SELECTIONSORT
	/*start = clock();
	amount_tests = integerSelectioSort(&integersCollection1, SMALL);//100
	end = clock();

	time = get_used_time(start, end);

	printf("\nTamanho do Vetor: %d - Quantidade de Testes: %d - Tempo de Execucao: %lu milissegundos\n", SMALL, amount_tests, time);
	*/

	/*start = clock();
	amount_tests = integerSelectioSort(&integersCollection2, MEDIUM);//1000
	end = clock();

	time = get_used_time(start, end);

	printf("\nTamanho do Vetor: %d - Quantidade de Testes: %d - Tempo de Execucao: %lu milissegundos\n", MEDIUM, amount_tests, time);
	*/

	/*start = clock();
	amount_tests = integerSelectioSort(&integersCollection3, LARGE);//10000
	end = clock();

	time = get_used_time(start, end);

	printf("\nTamanho do Vetor: %d - Quantidade de Testes: %d - Tempo de Execucao: %lu milissegundos\n", LARGE, amount_tests, time);
	*/

	/*start = clock();
	amount_tests = integerSelectioSort(&integersCollection4, EXTRA_LARGE);//100000
	end = clock();

	time = get_used_time(start, end);

	printf("\nTamanho do Vetor: %d - Quantidade de Testes: %d - Tempo de Execucao: %lu milissegundos\n", EXTRA_LARGE, amount_tests, time);
	*/


	//BUSCA BINARIA DO NUMERO 87 COM ORDENACAO POR BUBBLESORT

	//integer_binarySearch_whith_bubbleSort(integersCollection1, SMALL, 87);//100
	//integer_binarySearch_whith_bubbleSort(integersCollection2, MEDIUM, 87);//1000
	//integer_binarySearch_whith_bubbleSort(integersCollection3, LARGE, 87);//10000
	//integer_binarySearch_whith_bubbleSort(integersCollection4, EXTRA_LARGE, 87);//100000

	//BUSCA BINARIA DO NUMERO 100001 COM ORDENACAO POR BUBBLESORT
	//integer_binarySearch_whith_bubbleSort(integersCollection1, SMALL, 100001);//100
	//integer_binarySearch_whith_bubbleSort(integersCollection2, MEDIUM, 100001);//1000
	//integer_binarySearch_whith_bubbleSort(integersCollection3, LARGE, 100001);//10000
	//integer_binarySearch_whith_bubbleSort(integersCollection4, EXTRA_LARGE, 100001);//100000

	//BUSCA BINARIA DO NUMERO 87 COM ORDENACAO POR SELECTIONSORT
	//integer_binarySearch_whith_selectioSort(integersCollection1, SMALL, 87);//100
	//integer_binarySearch_whith_selectioSort(integersCollection2, MEDIUM, 87);//1000
	//integer_binarySearch_whith_selectioSort(integersCollection3, LARGE, 87);//10000
	//integer_binarySearch_whith_selectioSort(integersCollection4, EXTRA_LARGE, 87);//100000 704.982.721

	//Elemento na posicao 103 Ú 87Elemento na posicao 104 e 87
	
	
	//BUSCA BINARIA DO NUMERO 100001 COM ORDENACAO POR SELECTIONSORT
	//integer_binarySearch_whith_selectioSort(integersCollection1, SMALL, 100001);//100
	//integer_binarySearch_whith_selectioSort(integersCollection2, MEDIUM, 100001);//1000
	//integer_binarySearch_whith_selectioSort(integersCollection3, LARGE, 100001);//10000
	integer_binarySearch_whith_selectioSort(integersCollection4, EXTRA_LARGE, 100001);//100000

	return 0;
}