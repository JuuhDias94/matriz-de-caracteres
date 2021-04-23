#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <string.h> //para trabalhar com caracteres
#include <ctype.h> //para trabalhar com mai�sculo e min�sculo

#define maxLinha 10 //n�mero m�ximo de linhas da matriz
#define maxColuna 10 //n�mero m�ximo de colunas da matriz

int main()
{
	setlocale(LC_ALL, "Portuguese"); //para poder usar palavras com acentua��o

	int L[1] = { 0 }, C[1] = { 0 }, c, a, b, tabASCII[255] = { 0 }, primeiroC; //vari�veis do tipo inteiro
	char MATRIZ[maxLinha][maxColuna] = { 0 }, MatCaracRepete[maxLinha][maxColuna] = { ' ' }, caractereP; //vari�vel do tipo caractere 

	//pede para o usu�rio digitar n�mero de linhas:
	printf("Digite o n�mero de LINHAS da sua matriz (m�nimo 1 - m�ximo 10): ");
	scanf_s("%d", &L[0]);
	while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado

	//repete enquanto o usu�rio n�o digitar um n�mero entre 1 e 10:
	while ((L[0] < 1) || (L[0] > 10))
	{
		printf("N�MERO INV�LIDO!\n");
		printf("Digite o n�mero de LINHAS da sua matriz (m�nimo 1 - m�ximo 10): ");
		scanf_s("%d", &L[0]);
		while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado
	}

	//pede para o usu�rio digitar n�mero de colunas:
	printf("\nDigite o n�mero de COLUNAS da sua matriz (m�nimo 1 - m�ximo 10): ");
	scanf_s("%d", &C[0]);
	while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado

	//repete enquanto o usu�rio n�o digitar um n�mero entre 1 e 10:
	while ((C[0] < 1) || (C[0] > 10))
	{
		printf("N�MERO INV�LIDO!\n");
		printf("Digite o n�mero de COLUNAS da sua matriz (m�nimo 1 - m�ximo 10): ");
		scanf_s("%d", &C[0]);
		while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado
	}

	//pede para o usu�rio digitar um caractere para cada �ndice:
	for (a = 0; a < L[0]; a++) //linhas
	{
		for (b = 0; b < C[0]; b++) //colunas
		{
			printf("\n\nDigite um caractere para o �ndice [%d][%d]: ", a, b);
			scanf_s("%c", &MATRIZ[a][b]);
			while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado
		}
	}

	printf("\n__________________________________________\n\n");
	printf("MATRIZ %dx%d DIGITADA:\n\n", L[0], C[0]); //matriz digitada

	//imprime a matriz de caracteres digitada:
	for (a = 0; a < L[0]; a++) //linhas
	{
		for (b = 0; b < C[0]; b++) //colunas
		{
			printf("%c  ", MATRIZ[a][b]);
		}
		printf("\n"); //para os caracteres n�o ficarem todos na mesma linha
	}

	printf("__________________________________________");
	printf("\n\n");

	//caracteres digitados e o n�mero de ocorr�ncias:
	for (a = 0; a < 255; a++) 
	{
		tabASCII[a] = 0;
	}

	for (a = 0; a < L[0]; a++) 
	{
		for (b = 0; b < C[0]; b++) 
		{
			MatCaracRepete[a][b] = MATRIZ[a][b];
			tabASCII[MatCaracRepete[a][b]]++; //vetor recebe o resultado da compara��o
		}
	}

	//impress�o na tela dos caracteres digitados e o n�mero de ocorr�ncias:
	for (a = 0; a <= 255; a++) 
	{
		if (tabASCII[a] >= 1) 
		{
			printf("\nCaractere %c teve: %d ocorr�ncia(s).\n", a, tabASCII[a]);
		}
	}

	printf("\n\n");

	caractereP = (MATRIZ[0][0]); //para definir o primeiro caractere

	//fun��o que mostra se primeiro caractere � mai�sculo ou min�sculo:
	{
		primeiroC = caractereP; //caractere char convertido para int

		if (isupper(caractereP))
		{ //mai�sculo
			printf("O primeiro caractere � MAI�SCULO %c, logo, dividido por 10: %d\n\n\n", caractereP, primeiroC / 10);
		}
		else
		{ //min�sculo
			printf("O primeiro caractere � MIN�SCULO %c, logo, multiplicado por 2: %d\n\n\n", caractereP, primeiroC * 2);
		}

	}

	system("pause");
	return 0;
}