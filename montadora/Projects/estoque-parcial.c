#include <stdio.h>
#include <stdlib.h>

typedef struct dados
{
    int    reg;
    char   produto[20];
    int    qtde;
    float  preco;
} dados;

typedef struct dados2
{
	int reg;
	char produto[20];
	int qtde;
	float preco;	
} dados2;

void aloca2(dados2 **p2, int tam);
void cadastro2(dados2 *p2, int tam);
void grava2(dados2 *p2);
void mostra2(dados2 *p2, int qtde);
int verifica2();

void aloca(dados **p,int tam);
int verifica();
void cadastro(dados *p,int qtde);
void grava(dados *p);
void mostra(dados *p,int qtde);

main()
{
dados *pd=NULL;
dados2 *pd2=NULL;
char op;
int qtde, menu;
printf("1 - Dados 1\n");
printf("2 - Dados 2\n");
printf("0 - Sair\n");
scanf("%i", &menu);
fflush(stdin);
switch (menu)
{
case 1:
		aloca(&pd,1);
		qtde=verifica();
	do
	{
		cadastro(pd, qtde+1);
		qtde++;
		printf("\nDeseja continuar <S/N>: ");
		scanf("%c", &op);
		fflush(stdin);
  	}
	while(op!='n' && op!='N');
		mostra(pd, qtde);
	break;

case 2:
		aloca2(&pd2,1);
	qtde=verifica2();
	do
	{
		cadastro2(pd2, qtde+1);
		qtde++;
		printf("\nDeseja continuar <S/N>: ");
		scanf("%c", &op);
		fflush(stdin);
  	}
	while(op!='n' && op!='N');
		mostra2(pd2, qtde);
	break;

case 0:
	exit(1);
	break;

default:
	break;
}

}//main

void aloca2(dados2 **p2,int tam)
{
if((*p2=(dados2*)realloc(*p2,tam*sizeof(dados2)))==NULL)
  exit(1);
}//aloca

void aloca(dados **p,int tam)
{
if((*p=(dados*)realloc(*p,tam*sizeof(dados)))==NULL)
  exit(1);
}//aloca

int verifica2()
{
long int cont=0;
FILE *fptr=NULL;
if((fptr=fopen("estoque2.bin","rb"))==NULL)
  return cont;
else
  {
  	fseek(fptr,0,2);  //posiciona o fptr no fim do arquivo
  	cont=ftell(fptr)/sizeof(dados);
  	fclose(fptr);   //dentro do else - por conta do rb
  	return cont;
  }//else
}// Verifica

int verifica()
{
long int cont=0;
FILE *fptr=NULL;
if((fptr=fopen("estoque.bin","rb"))==NULL)
  return cont;
else
  {
  	fseek(fptr,0,2);  //posiciona o fptr no fim do arquivo
  	cont=ftell(fptr)/sizeof(dados);
  	fclose(fptr);   //dentro do else - por conta do rb
  	return cont;
  }//else
}//verifica

void cadastro2(dados2 *p2,int qtde)
{
p2->reg=qtde;
printf("\nRegistro: %i",p2->reg);
printf("\nProduto: ");
gets(p2->produto);
fflush(stdin);
printf("Qtde: ");
scanf("%i",&(p2->qtde));
fflush(stdin);
printf("Preco: ");
scanf("%f",&(p2->preco));
fflush(stdin);
grava(p2);
}//cadastro
/*typedef struct dados
{
    int    reg;
    char   produto[20];
    int    qtde;
    float  preco;
} dados;
*/
void cadastro(dados *p,int qtde)
{
p->reg=qtde;
printf("\nRegistro: %i",p->reg);
printf("\nProduto: ");
gets(p->produto);
fflush(stdin);
printf("Qtde: ");
scanf("%i",&(p->qtde));
fflush(stdin);
printf("Preco: ");
scanf("%f",&(p->preco));
fflush(stdin);
grava(p);
}//cadastro

void grava2(dados2 *p2)
{
FILE *fptr=NULL;
if((fptr=fopen("estoque2.bin","ab"))==NULL)
  printf("\nErro ao abrir o arquivo");
else
  fwrite(p2,sizeof(dados2),1,fptr);
fclose(fptr);   //fora do else - por conta do ab
}//grava

void grava(dados *p)
{
FILE *fptr=NULL;
if((fptr=fopen("estoque.bin","ab"))==NULL)
  printf("\nErro ao abrir o arquivo");
else
  fwrite(p,sizeof(dados),1,fptr);
fclose(fptr);   //fora do else - por conta do ab
}//grava

void mostra2(dados2 *p2,int qtde)
{
int i;
FILE *fptr=NULL;
system("cls");
if((fptr=fopen("estoque2.bin","rb"))==NULL)
  printf("\nErro ao abrir o arquivo");
else
  {
  	for(i=0;i<qtde;i++)
  	  {
  	  	fseek(fptr,i*sizeof(dados2),0);
  	  	fread(p2,sizeof(dados2),1,fptr);
  	  	printf("\nRegistro: %i\nProduto: %s\nQtde: %i\nPreco: %.2f\n",p2->reg,p2->produto,p2->qtde,p2->preco);
	  }//for
	fclose(fptr);   //dentro do else - por conta do rb  
  }//else
printf("\n\n");
system("pause");
}//mostra

void mostra(dados *p,int qtde)
{
int i;
FILE *fptr=NULL;
system("cls");
if((fptr=fopen("estoque.bin","rb"))==NULL)
  printf("\nErro ao abrir o arquivo");
else
  {
  	for(i=0;i<qtde;i++)
  	  {
  	  	fseek(fptr,i*sizeof(dados),0);
  	  	fread(p,sizeof(dados),1,fptr);
  	  	printf("\nRegistro: %i\nProduto: %s\nQtde: %i\nPreco: %.2f\n",p->reg,p->produto,p->qtde,p->preco);
	  }//for
	fclose(fptr);   //dentro do else - por conta do rb  
  }//else
printf("\n\n");
system("pause");
}//mostra
