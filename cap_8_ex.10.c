/* Livro KOCHAN - Programming in C (3rd ed) 
Cap. 8

Ex.10
Write a function prime that returns 1 if its argument is a prime number and
returns 0 otherwise.  */

#include <stdio.h>
#include <stdbool.h>

/* Para números 'grandes' (1000x menor que 2147483647) está causando falha
 de segmentação */
int prime (int num)
{
	int p, i, primeIndex = 2;
	unsigned long long int primes[20000];
	bool isPrime;

	primes[0] = 2;
	primes[1] = 3;

	/* Popula a lista de números primos */
	for ( p = 5; p <= num; p = p+2 )
		{
		isPrime = true;
		
		for ( i = 1; isPrime && p / primes[i] >= primes[i]; i++)	
			if (p % primes[i] == 0)
				isPrime = false;
			
		if (isPrime == true)
			{
			primes[primeIndex] = p;
			primeIndex++;
			}	
		}

		/* Testa para ver se número fornecido é primo
		Estou sendo um pouco redundante aqui */
		for (i = 0; i < primeIndex; i++)
		{
			if (num == primes[i])
				return 1;
		}
		return 0;
}


int main(void)
{
	int num;

	printf("Forneça um número e direi se ele é primo:  \n");
	scanf("%i", &num);

	printf("%i \n\n", prime(num));
	
	return 0;
}

