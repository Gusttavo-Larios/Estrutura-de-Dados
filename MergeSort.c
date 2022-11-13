#include <stdio.h>;
#include <stdlib.h>;
#include <math.h>
#include <time.h>;


// Constantes globais
int SEED = 1234554321;
int LOW = 0;
int HIGH = 100000;

//Métodos

int obterTamanhoDoVetorDinamicamente(int tamanho) {
	return (int*)malloc(tamanho * sizeof(int));
}

double gerarNumeroInterio(long int* seed, double low, double high) {// gerarNumeroInterio -> gera 1 número inteiro randomicamente
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

void gerarVetorDeInteiros(int* vetor, int tamanho) {

	for (int i = 0; i < tamanho; i++)
	{
		vetor[i] = gerarNumeroInterio(&SEED, LOW, HIGH);
	}
}

int mergeSort(int* V, int inicio, int fim) {// mergeSort -> divide recursivamente os dados em coleções menores 
	int meio;
	if (inicio < fim) {
		meio = floor((inicio + fim) / 2);// floor -> obtém o piso da divisão

		mergeSort(V, inicio, meio);
		mergeSort(V, meio + 1, fim);

		merge(V, inicio, meio, fim);
	}
}


int merge(int* V, int inicio, int meio, int fim) {// merge -> intercala os dados de forma ordenada

	int* vetorTemporario, indicieInicialDaPrimeiraMetade, indicieInicialDaSegundaMetade, tamanho, i, j, k;

	int chegouAoFimDaPrimeiraMetade = 0, chegouAoFimDaSegundaMetade = 0;

	tamanho = fim - inicio + 1;

	indicieInicialDaPrimeiraMetade = inicio;
	indicieInicialDaSegundaMetade = meio + 1;

	vetorTemporario = (int*)malloc(tamanho * sizeof(int));

	if (vetorTemporario != NULL) {
		for (i = 0; i < tamanho; i++)
		{
			if (!chegouAoFimDaPrimeiraMetade && !chegouAoFimDaSegundaMetade) {

				if (V[indicieInicialDaPrimeiraMetade] < V[indicieInicialDaSegundaMetade])
					vetorTemporario[i] = V[indicieInicialDaPrimeiraMetade++];
				else
					vetorTemporario[i] = V[indicieInicialDaSegundaMetade++];

				if (indicieInicialDaPrimeiraMetade > meio) chegouAoFimDaPrimeiraMetade = 1;

				if (indicieInicialDaSegundaMetade > fim) chegouAoFimDaSegundaMetade = 1;
			}
			else {
				if (!chegouAoFimDaPrimeiraMetade) vetorTemporario[i] = V[indicieInicialDaPrimeiraMetade++];
				else vetorTemporario[i] = V[indicieInicialDaSegundaMetade++];
			}
		}

		for (j = 0, k = inicio; j < tamanho; j++, k++)
			V[k] = vetorTemporario[j];
	}
	free(vetorTemporario);// remove os dados alocados na memória
}

// Método principal

int main()
{
	int SMALL = 100;
	int MEDIUM = 1000;
	int LARGE = 10000;
	int EXTRA_LARGE = 100000;

	int REFERENCE = 87;
	//int NON_EXISTING_REFERENCE = 100001;

	clock_t start, end;
	unsigned long int time;


	int amount_tests = 0;

	int smallCollection[10];

	//int* smallCollection;
	//, * mediumCollection, * largeCollection, * extraLargeCollection;
	//smallCollection = obterTamanhoDoVetorDinamicamente(SMALL);
	/*int mediumCollection[1000];
	int largeCollection[10000];
	int extraLargeCollection[100000];
	*/

	gerarVetorDeInteiros(&smallCollection, 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%d \n", smallCollection[i]);
	}


	mergeSort(smallCollection, 0, 9);

	printf("\n============================\n");

	for (int i = 0; i < 10; i++)
	{
		printf("%d \n", smallCollection[i]);
	}
	/*gerarVetorDeInteiros(&mediumCollection, MEDIUM);
	gerarVetorDeInteiros(&largeCollection, LARGE);
	gerarVetorDeInteiros(&extraLargeCollection, EXTRA_LARGE);
	*/
	return 0;
}