// Upar para github
// 
// Theorem 2.1 (Pythagorean Triples Theorem).
// 
// 
// We will get every primitive Pytha­gorean triple (a, b, c) with a odd and
// b even by using the formulas ...
// 
// Silverman, 26_PDF, 17_livro


# include <stdio.h>

int gcd (int u, int v)
{
	int temp;

	while ( v != 0 )
	{
		temp = u % v;
		u = v;
		v = temp;
	}

	return u;
}

int main (void)

{

	int a, b, c;
	int s,t;

	printf("\n\nGeradora de triplos pitagóricos primitivos\n");
	printf("==========================================\n\n");
	printf("Forneça 2 números inteiros ímpares sem fatores comuns:\n");
	scanf("%i %i", &s, &t);

	// s e t  precisam ser inteiros ímpares
	if (s % 2 == 0 || t % 2 == 0)
		printf("Escolha inválida: forneça 2 números ímpares inteiros sem fatores comuns.\n");

	// Testar fatores comuns 
	else if (gcd (s,t) != 1)
		printf("Escolha inválida: os números possuem fatores em comum.\n");
	
	// s > t >= 1
	else if (s < 1 || t < 1)
		printf("Escolha inválida: forneça pelo menos um número ímpar inteiro maior que 1.\n");

	else
		{
		a = s*t;

		// s precisa ser maior que t
		b = (s < t) ? (t*t - s*s)/2 : (s*s - t*t)/2;

		c = (s*s + t*t)/2;

		printf("O triângulo reto gerado tem lados: \n");
		printf("Catetos: a = %i e b = %i  Hipotenusa: c = %i\n\n", a,b,c);

		// Mera verificação		
		printf("%i + %i = %i  ==>  ", a*a, b*b, c*c);
		
		if ( a*a + b*b == c*c )
			printf("OK!!\n\n");
		else
			printf("Deu algo errado!\n");
		}

	return 0;

}