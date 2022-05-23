#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


void leitura(int *m, int linha, int coluna);
void imprime(int *m, int linha, int coluna);
int somaMaiorColuna(int *m,int linha, int coluna);
int somaMaiorColuna2(int *m,int linha, int coluna);//usando um vetor para guardar a soma das colunas
int maiorVetor(int *ponteiro, int ind);//usado na funcao anterior para achar a posicao do maior elemento do vetor
void aloca(int **p, int tam);

int main()
{
	int *m=NULL;
    
    aloca(&m,12);

	printf("Recebe valores de uma matriz bidimensional\n");
	leitura(m,3,4);
	system("cls");
	printf("Valores da matriz bidimensional\n\n");
	imprime(m,3,4);	
	//printf("\n\nteste %i end %i end %i",*(*matriz+(2*4+2) ),*matriz,(*matriz+(2*4+2) ));
	printf("\n\n1.A coluna com maior valor somado \x82 a coluna %i.",somaMaiorColuna(m,3,4)+1);
	printf("\n\n2.A coluna com maior valor somado \x82 a coluna %i.",somaMaiorColuna2(m,3,4));
	
	getch();
	return 0;
}

void aloca(int **p, int tam)
{
	if( (*p=(int *)realloc(*p,tam*sizeof(int)) )==NULL)
	{
		printf("Erro na alocação!");
		exit(1);
	}
	printf("Espaco alocado com sucesso! End= %u\n",*p);
}

void leitura(int *m, int linha, int coluna)
{
	int l, c;
	for(l=0;l<linha;l++)
	{
	    for(c=0;c<coluna;c++)
	    {
	     printf("matriz[%i][%i] = ", l, c);
	     scanf("%i", m+l*coluna+c);			// endereço de cada elemento
	    }
	}
}

void imprime(int *m, int linha, int coluna)
{
	int l, c;
	for(l=0;l<linha;l++)
	{
	   for(c=0;c<coluna;c++)
	   {
	        printf("%i \t", *(m+l*coluna+c));		// conteúdo de cada elemento
	   }
	   printf("\n");
	}
}

int somaMaiorColuna(int *m,int linha, int coluna)
{
	int l, c,soma=0,maior,cMaior;
	printf("\n");
	for (c=0;c<coluna;c++)
	{
		for (l=0;l<linha;l++)
		{
			soma+=*(m+l*coluna+c);			
		}
		printf("%i \t",soma);//conferencia
		if(soma>maior|| c==0)
		{
			maior=soma;
			cMaior=c;
		}
	    soma=0;   
	}
    return cMaior;
}

int somaMaiorColuna2(int *m,int linha, int coluna)
{
	int l, c,soma=0,maior;
	int vetor[4],*p;
	p=vetor;
	
	printf("\n");
	for (c=0;c<coluna;c++)
	{
		for (l=0;l<linha;l++)
		{
			soma+=*(m+l*coluna+c);			
		}
		*(vetor+c)=soma;
		soma=0;   
	}
	
	maior=maiorVetor(p,coluna);
    return maior;
}

int maiorVetor(int *ponteiro, int ind)
{
	int maior=0,c,cMaior;
	for (c=0;c<ind;c++)
	{		
		if(*(ponteiro+c)>maior|| c==0 )
		{
				maior=*(ponteiro+c);
				cMaior=c;
		}
	}
	return (cMaior+1);//passando a posicao e nao indice
}
