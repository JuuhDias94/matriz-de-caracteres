# Exercício 3 - Matriz de caracteres

Faça um algoritmo em linguagem C que receba como dado de entrada uma matriz de caracteres. Cada posição da matriz deve armazenar um caractere.

A dimensão da matriz deverá ser MxN, onde M e N são dados de entrada escolhidos pelo usuário. Declare a matriz como sendo de dimensão máxima 10x10, e valide os valores de M e N, que devem estar entre 1 e 10, incluindo 1 e 10. Para a validação, o usuário deve ficar preso no programa enquanto não digitar um número válido para M e para N.

Após escolhida a dimensão da matriz e povoado ela com caracteres. Faça:

* Conte o número de ocorrências de cada caractere que aparece na matriz. Após a contagem, liste cada caractere digitado e o número de ocorrências;
* Crie uma função que receba como parâmetro o primeiro caractere cadastrado na matriz. A função deve retornar um dado numérico. Se o caractere for maiúsculo, retorne na função o resultado deste caractere dividido por 10. Caso contrário, retorne o resultado do caractere multiplicado por 2.