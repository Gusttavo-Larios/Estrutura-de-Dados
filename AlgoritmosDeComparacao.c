#include <stdio.h>
#include <stdlib.h>;
#include <time.h>;

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
void gerarColecaoDeInterios(int* collection, int length, int* SEED, int LOW, int HIGH) {

	for (int i = 0; i < length; i++)
	{
		collection[i] = inteiros_unif(&SEED, LOW, HIGH);
	}
}

// Helpers

double get_used_time(int start, int end) {
	return (end - start) * 1000 / CLOCKS_PER_SEC;
}

void escreverColecao(int* collection, int length) {
	for (int i = 0; i < length; i++)
	{
		printf("%d\n", collection[i]);
	}
}


// Algoritmos de ordenação

//Selecion Sort
void selectionSortCrescente(int* V, int tamanho) {
	int i, j, ref, aux;

	clock_t start, end;
	unsigned long int time;
	int amount_tests = 0;
	start = clock();

	int contadorDeTrocas = 0;

	for (i = 0; i < tamanho - 1; i++)
	{
		ref = i;
		for (j = i + 1; j < tamanho; j++)
		{
				if (V[j] < V[ref])
				{
					ref = j;
				}
			
		}

		if (i != ref)
		{
			contadorDeTrocas += 1;
			aux = V[i];
			V[i] = V[ref];
			V[ref] = aux;
		}
	}

	end = clock();
	time = get_used_time(start, end);

	printf("\nSelection Sort - Ordem Crescente - Quantidade de Comparacoes %d - Quantidade de Trocas: %d - Tempo de Execucao: %lu milissegundos\n", contadorDeTrocas, contadorDeTrocas, time);
}

void selectionSortDecrescente(int* V, int tamanho, int ordem) {
	int i, j, ref, aux;

	clock_t start, end;
	unsigned long int time;
	int amount_tests = 0;
	start = clock();

	int contadorDeTrocas = 0;

	for (i = 0; i < tamanho - 1; i++)
	{
		ref = i;
		for (j = i + 1; j < tamanho; j++)
		{
				if (V[j] > V[ref])
				{
					ref = j;
				}
		}

		if (i != ref)
		{
			contadorDeTrocas += 1;
			aux = V[i];
			V[i] = V[ref];
			V[ref] = aux;
		}
	}

	end = clock();
	time = get_used_time(start, end);

	printf("\nSelection Sort - Ordem Decrescente - Quantidade de Comparacoes %d - Quantidade de Trocas: %d - Tempo de Execucao: %lu milissegundos\n", contadorDeTrocas, contadorDeTrocas, time);
}

//Shell Sort
void shellSortCrescente(int* V, int tamanho) {
	int i, j, value;

	clock_t start, end;
	unsigned long int time;
	int contadorDeTrocas = 0;
	int contadorDeComparcoes = 0;
	start = clock();

	int h = 1;

	while (h < tamanho) {
		h = 3 * h + 1;
	}
	 
	while (h > 0) {
		for (i = h; i < tamanho; i++)
		{
			value = V[i];

			j = i;

			contadorDeComparcoes += 1;
			while (j > h - 1 && value <= V[j - h]) {
				V[j] = V[j - h];
				j = j - h;
			}
			contadorDeTrocas += 1;
			V[j] = value;
		}
		h = h / 3;
	}

	end = clock();
	time = get_used_time(start, end);

	printf("\nShell Sort - Ordem Crescente - Quantidade de Comparacoes %d - Quantidade de Trocas: %d - Tempo de Execucao: %lu milissegundos\n", contadorDeComparcoes, contadorDeTrocas, time);
}

void shellSortDecrescente(int* V, int tamanho) {
	int i, j, value;

	clock_t start, end;
	unsigned long int time;
	int contadorDeTrocas = 0;
	int contadorDeComparcoes = 0;
	start = clock();

	int h = 1;

	while (h < tamanho) {
		h = 3 * h + 1;
	}

	while (h > 0) {
		for (i = h; i < tamanho; i++)
		{
			value = V[i];

			j = i;

			contadorDeComparcoes += 1;
			while (j > h - 1 && value <= V[j - h]) {
				V[j] = V[j - h];
				j = j -  h;
			}
			contadorDeTrocas += 1;
			V[j] = value;
		}
		h = h / 3;
	}

	end = clock();
	time = get_used_time(start, end);

	printf("\nShell Sort - Ordem Decrescente - Quantidade de Comparacoes %d - Quantidade de Trocas: %d - Tempo de Execucao: %lu milissegundos\n", contadorDeComparcoes, contadorDeTrocas, time);
}

int main() {
	/*
	Parâmetros
	*/
	int SEED = 1234554321;
	int LOW = 0;
	int MAX_INSTANCIA = 1000;

	/*
	Instância 1 -> LOW = 1, HIGH = 1000
	*/

	int V[1000];

	// Gerando coleções
	gerarColecaoDeInterios(V, MAX_INSTANCIA, &SEED, LOW, 1000);

	//escreverColecao(colecaoInstanciaUm, 100);
	shellSortCrescente(V, MAX_INSTANCIA, 0);
	//printf("\n =============================== \n");
	escreverColecao(V, 1000);

	printf("rr");
	return 0;
}