#include <stdio.h>;
#include <stdlib.h>;
//#include <time.h>;

void quickSort(int *V, int indicieInicial, int indicieFinal) {
	int pivo;
	if (indicieFinal > indicieInicial) {
		pivo = particiona(V, indicieInicial, indicieFinal);
		quickSort(V, indicieInicial, pivo - 1);
		pivo = particiona(V, pivo + 1, indicieFinal);
	}
}

int particiona(int* V, int indicieInicial, int indicieFinal) {
	int indicieParteEsquerda, indicieParteDireita, pivo, auxiliar;

	indicieParteEsquerda = indicieInicial;
	indicieParteDireita = indicieFinal;
	pivo = V[indicieInicial];

	while (indicieParteEsquerda < indicieParteDireita) {

		// Avança posição da esquerda
		while (indicieParteEsquerda <= indicieFinal && V[indicieParteEsquerda] <= pivo)
			indicieParteEsquerda++;

		// Recua a posição da direita
		while (indicieParteDireita >= 0 && V[indicieParteDireita] > pivo)
			indicieParteDireita++;

		// Troca valor entre a parte esquerda e direita
		if (indicieParteEsquerda < indicieParteDireita) {
			auxiliar = V[indicieParteEsquerda];
			V[indicieParteEsquerda] = V[indicieParteDireita];
			V[indicieParteDireita] = auxiliar;
		}
	}

	V[indicieInicial] = V[indicieParteDireita];
	V[indicieParteDireita] = pivo;

	return indicieParteDireita;
}

int main()
{
	//int vetor[7] = { 10,9,20,5,8,4,32 };

	//quickSort(vetor, 0, 6);

	/*for (int i = 0; i < 7; i++)
	{
		printf("%d \n", vetor[i]);
	}*/
	return 0;
}