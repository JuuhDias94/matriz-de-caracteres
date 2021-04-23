#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <string.h> //para trabalhar com caracteres
#include <ctype.h> //para trabalhar com maiúsculo e minúsculo

#define maxLinha 10 //número máximo de linhas da matriz
#define maxColuna 10 //número máximo de colunas da matriz

int main()
{
	setlocale(LC_ALL, "Portuguese"); //para poder usar palavras com acentuação

	int L[1] = { 0 }, C[1] = { 0 }, c, a, b, tabASCII[255] = { 0 }, primeiroC; //variáveis do tipo inteiro
	char MATRIZ[maxLinha][maxColuna] = { 0 }, MatCaracRepete[maxLinha][maxColuna] = { ' ' }, caractereP; //variável do tipo caractere 

	//pede para o usuário digitar número de linhas:
	printf("Digite o número de LINHAS da sua matriz (mínimo 1 - máximo 10): ");
	scanf_s("%d", &L[0]);
	while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado

	//repete enquanto o usuário não digitar um número entre 1 e 10:
	while ((L[0] < 1) || (L[0] > 10))
	{
		printf("NÚMERO INVÁLIDO!\n");
		printf("Digite o número de LINHAS da sua matriz (mínimo 1 - máximo 10): ");
		scanf_s("%d", &L[0]);
		while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado
	}

	//pede para o usuário digitar número de colunas:
	printf("\nDigite o número de COLUNAS da sua matriz (mínimo 1 - máximo 10): ");
	scanf_s("%d", &C[0]);
	while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado

	//repete enquanto o usuário não digitar um número entre 1 e 10:
	while ((C[0] < 1) || (C[0] > 10))
	{
		printf("NÚMERO INVÁLIDO!\n");
		printf("Digite o número de COLUNAS da sua matriz (mínimo 1 - máximo 10): ");
		scanf_s("%d", &C[0]);
		while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado
	}

	//pede para o usuário digitar um caractere para cada índice:
	for (a = 0; a < L[0]; a++) //linhas
	{
		for (b = 0; b < C[0]; b++) //colunas
		{
			printf("\n\nDigite um caractere para o índice [%d][%d]: ", a, b);
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
		printf("\n"); //para os caracteres não ficarem todos na mesma linha
	}

	printf("__________________________________________");
	printf("\n\n");

	//caracteres digitados e o número de ocorrências:
	for (a = 0; a < 255; a++) 
	{
		tabASCII[a] = 0;
	}

	for (a = 0; a < L[0]; a++) 
	{
		for (b = 0; b < C[0]; b++) 
		{
			MatCaracRepete[a][b] = MATRIZ[a][b];
			tabASCII[MatCaracRepete[a][b]]++; //vetor recebe o resultado da comparação
		}
	}

	//impressão na tela dos caracteres digitados e o número de ocorrências:
	for (a = 0; a <= 255; a++) 
	{
		if (tabASCII[a] >= 1) 
		{
			printf("\nCaractere %c teve: %d ocorrência(s).\n", a, tabASCII[a]);
		}
	}

	printf("\n\n");

	caractereP = (MATRIZ[0][0]); //para definir o primeiro caractere

	//função que mostra se primeiro caractere é maiúsculo ou minúsculo:
	{
		primeiroC = caractereP; //caractere char convertido para int

		if (isupper(caractereP))
		{ //maiúsculo
			printf("O primeiro caractere é MAIÚSCULO %c, logo, dividido por 10: %d\n\n\n", caractereP, primeiroC / 10);
		}
		else
		{ //minúsculo
			printf("O primeiro caractere é MINÚSCULO %c, logo, multiplicado por 2: %d\n\n\n", caractereP, primeiroC * 2);
		}

	}

	system("pause");
	return 0;
}