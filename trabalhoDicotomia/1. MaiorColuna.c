#include <stdio.h>
#include <stdlib.h>

void leitura(int m[3][4]);
void imprime(int m[3][4]);
int somaMaiorColuna(int m[3][4],int *s);
int somaMaiorColuna2(int m[3][4],int *s);//usando um vetor para guardar a soma das colunas
int maiorVetor(int *ponteiro,int *s);//usado na funcao anterior para achar a posicao do maior elemento do vetor

int main()
{
	int matriz[3][4],soma;

	printf("Recebe valores de uma matriz bidimensional\n");
	leitura(matriz);
	system("cls");
	printf("Valores da matriz bidimensional\n\n");
	imprime(matriz);	
	printf("\n\n1.A coluna com maior valor somado \x82 a coluna %i, ",somaMaiorColuna(matriz,&soma)+1);
	printf("soma = %i.",soma);
	printf("\n\n2.A coluna com maior valor somado \x82 a coluna %i, soma = %i.",somaMaiorColuna2(matriz,&soma),soma);
	
	getch();
	return 0;
}

void leitura(int m[3][4])
{
	int linha, coluna;
	for(linha=0;linha<3;linha++)
	{
	    for(coluna=0;coluna<4;coluna++)
	    {
	     printf("matriz[%i][%i] = ", linha, coluna);
	     scanf("%i", *(m+linha)+coluna);			// endereço de cada elemento
	    }
	}
}
void imprime(int m[3][4])
{
	int linha, coluna;
	for(linha=0;linha<3;linha++)
	{
	   for(coluna=0;coluna<4;coluna++)
	   {
	        printf("%i \t", *(*(m+linha)+coluna));		// conteúdo de cada elemento m[linha][coluna]
	   }
	   printf("\n");
	}
}

int somaMaiorColuna(int m[3][4],int *s)
{
	int linha, coluna,soma=0,maior,c;
	printf("\n");
	for (coluna=0;coluna<4;coluna++)
	{
		for (linha=0;linha<3;linha++)
		{
			soma+=*(*(m+linha)+coluna);			
		}
		printf("%i \t",soma);//conferencia
		if(soma>maior||coluna==0)
		{
			maior=soma;
			c=coluna;			
		}
	    soma=0;   
	}
	*s=maior;
    return c;
}

int somaMaiorColuna2(int m[3][4],int *s)
{
	int linha, coluna,soma=0,maior;
	int vetor[4],*p;
	p=vetor;
	
	printf("\n");
	for (coluna=0;coluna<4;coluna++)
	{
		for (linha=0;linha<3;linha++)
		{
			soma+=*(*(m+linha)+coluna);			
		}
		*(p+coluna)=soma;
		//printf("%i \t",soma);//conferencia
	    soma=0;   
	}
	
	maior=maiorVetor(p,s);
    return maior;
}

int maiorVetor(int *ponteiro,int *s)
{
	//printf("\n%p",ponteiro);
	int maior=0,coluna,c;
	for (coluna=0;coluna<4;coluna++)
	{		
		if(*(ponteiro+coluna)>maior|| coluna==0 )
		{
				maior=*(ponteiro+coluna);
				c=coluna;
				*s=maior;
		}
	}
	//printf("\nMAIOR COLUNA %i",c+1);
	return (c+1);//passando a posicao e nao indice
}
