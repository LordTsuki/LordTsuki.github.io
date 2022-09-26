#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct time
{
    float altura;
    float idade;
}time;

void alloc(time **p, int tam);
void register_jogador(time *p, int tam);
int verify_time();
void save(time *p, char *str, int pos);
void show(time *p, int qtt);

int main()
{
    time *pj=NULL;
    alloc(&pj, 1);
    int qtt=0;
    qtt=verify_time();
    register_jogador(pj, qtt+1);
    qtt++;
    qtt=verify_time();
    show(pj, qtt);
}

void register_jogador(time *p, int qtt)
{
    int i = 0;
    for (i = 0; i <= 10; i++)
    {
        printf("Digite a altura do jogador\n>>");
        scanf("%f", &(p->altura));
        fflush(stdin);
        system("cls");
        printf("Digite a idade do jogador\n>>");
        scanf("%f", &(p->idade));
        fflush(stdin);
        system("cls");
    }
    save(p, "ab", 0);
}

int verify_time()
{
    long int cont=0;
    FILE *fptr = NULL;
    if((fptr = fopen("time.bin", "rb")) == NULL)
    {
        return cont;
    }
    else
    {
        fseek(fptr,0,2);
  	    cont=ftell(fptr)/sizeof(time);
  	    fclose(fptr);
  	    return cont;
    }
}

void save(time *p, char *str, int pos)
{
    FILE *fptr=NULL;
    if((fptr=fopen("time.bin",str))==NULL)
    {
        printf("\nError to open archive");
    }
    else
    {
        if(strcmp(str, "rb+")==0)
        {
            fseek(fptr, pos*sizeof(time),0);
        }
        fwrite(p, sizeof(time), 1, fptr);
    }
    fclose(fptr);
}

void show(time *p, int qtt)
{
    int i=0;
    FILE *fptr=NULL;
    system("cls");
    if((fptr=fopen("time.bin", "rb"))==NULL)
    {
        printf("\nError to open archive");
    }
    for(i=0; i<qtt; i++)
    {
        fseek(fptr, i*sizeof(time), 0);
  	    fread(p, sizeof(time), 1, fptr);
  	    if(p->altura >= 1.90)
  	    {
  	  	    printf("\nAltura: %f\nIdade: %f", p->altura, p->idade);
	    }
        if(p->altura < 1.90)
        {
            printf("Jogador não irá participar do campeonato");
        }
    }
    fclose(fptr);
    printf("\n\n\n");
    system("pause");
    system("cls");
}

void alloc(time **p, int tam)
{
    if((*p=(time*)realloc(*p,tam*sizeof(time)))==NULL)
    {
        printf("Not able to alloc");
        system("pause");
        exit(1);
    }
}