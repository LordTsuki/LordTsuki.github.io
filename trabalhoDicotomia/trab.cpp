#include<stdio.h> //teste
#include<stdlib.h> 
#include<math.h>

void alocaFloat(float **p,int tam);
void valores_d(float *p, int tam);
void print_d();
//aaaaaa
int main ()
{
    int menu, numTermos, funcao;
    float *termo = NULL;
    printf(" 1 - Dicotomia \n 2 - Lagrange \n 0 - Exit");
    switch (menu)
    {
        case 1:
            printf("\nDigite o grau da equacao: ");// [MO FOME]
            scanf("%i", &numTermos);
            alocaFloat(&termo, numTermos);
            system("pause");
           // valores_d();
        break;
        
        case 2:

        break;

        case 0:
            exit(0);
        break;

        default:
            printf("Digita certo, burro");
        break;
    }
    return 0;
}

void alocaFloat(float **p, int tam)
{
	if( (*p=(float *)realloc(*p,tam*sizeof(float)) )==NULL)
	{
		printf("Erro na alocação!");
		exit(1);
	}
	//printf("Espaco alocado com sucesso! End= %u\n",*p);
}

void valores_d(float *p, int tam)
{
   /* printf("\t\tCalculo de Raizes de uma Funcao pelo metodo da bisseccao\n\n");
    double a,b,x1,Fa,Fb,Fx1,erro,absFx1;
    //erro=0.00001;
    printf("\nDigite o valor de a:\n");
    scanf("%lf",&a);
    printf("\nDigite o valor de b:\n");
    scanf("%lf",&b);
    printf("\nDigite o erro:\n");
    scanf("%lf",&erro);
    Fa= pow(a,fa)+a-4;
    Fb= pow(b,fb)+b-4;*/
}
/*
void print_d()
{
    int qtd_termo()
    printf("Iterações | A | M | B | F(a) | F(m) | f(b) |\n")
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < qtd_termo; j++)
        {
            printf("%i          %i  %i  %i   %i     %i     %i" j, a, m, b, f_a, f_m, f_b);
        }
    }
    printf("A raiz da função é: %i com erro de %i(< %i)"m, f_m, e);
}*/
