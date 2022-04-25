#include<stdio.h> //teste a
#include<stdlib.h> 
#include<math.h>

void alocaFloat(float **p,int tam);
void valores_d(float *p, int tam, float *inicial, float *final, float *prec);
float calculaF(float *p, int tam, float *x, float valfunc);
void print_d(float *a, float *b, float *c, float fa, float fm, float fb, float *erro);
//aaaaaa
int main ()
{
    int menu, numTermos, funcao, i;
    float *termo = NULL, *a =NULL, *b=NULL, *c=NULL,  *precisao=NULL, valorFuncao = 0, teste, f_a, f_m, f_b;
    printf(" 1 - Dicotomia \n 2 - Lagrange \n 0 - Exit\n");
    scanf("%i", &menu);
    fflush(stdin);
    switch (menu)
    {
        case 1:
            printf("\nDigite o grau da equacao: ");
            scanf("%i", &numTermos);
            alocaFloat(&termo, numTermos+1);
            alocaFloat(&a, 1);
            alocaFloat(&b, 1);
            alocaFloat(&c, 1);
            alocaFloat(&precisao, 1);
            //alocaFloat(&valorFuncao, 1)
            system("pause");
            valores_d(termo, numTermos, a, b, precisao);
            //printf("%f  %f  %f  %f   %f  %f",*termo , *(termo+1), *(termo+2), *a, *b, *precisao);
            f_a = calculaF(termo, numTermos, a, valorFuncao);
            f_b = calculaF(termo, numTermos, b, valorFuncao);
            *c= (*a)/2 + (*b)/2;
            f_m = calculaF(termo, numTermos, c, valorFuncao);
            print_d(a, b, c, f_a, f_m, f_b, precisao);
            //teste = calculaF(termo, numTermos, 2, valorFuncao);
            //system("cls");
            //printf("\n Valor: %f", teste);

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
	if( (*p=(float *)realloc(*p,(tam)*sizeof(float)) )==NULL)
	{
		printf("Erro na alocação!");
		exit(1);
	}
	//printf("Espaco alocado com sucesso! End= %u\n",*p);
}

void valores_d(float *p, int tam, float *inicial, float *final, float *prec)
{
    int i;
    for(i=0; i < tam+1; i++)
        {
            printf("Digite o coeficiente de x^%i: ", i);
            scanf("%f", p+i);
            fflush(stdin);
        }
        printf("\nDigite o valor de a: ");
        scanf("%f", inicial);
        fflush(stdin);
        printf("\nDigite o valor de b: ");
        scanf("%f", final);
        fflush(stdin);
        printf("\nDigite o valor da precisao: ");
        scanf("%f", prec);
        fflush(stdin);
        //printf("%f  %f  %f  %f   %f  %f", *p , *(p+1), *(p+2), *inicial, *final, *prec);
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

float calculaF(float *p, int tam, float x, float valfunc)
{
    int i;
    for(i=0; i<tam+1; i++)
    {
        valfunc = valfunc + (pow(x, i))*(*(p+i));
    }
    return valfunc;
    /*supondo que tam eh 2
    (pow(x, 0))*(*p) + (pow(x, 1))*(*p+1) + (pow(x, 2))*(*p+2)
    */
}

void print_d(float *a, float *b, float *c, float fa, float fm, float fb, float erro)
{
    int qtd_termo();
    printf("----------Iteracoes do Metodo da Dicotomia----------\ni\ta\tm\tb\tf(a)\tf(m)\tf(b)");
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < erro; j++)
        {
            printf("%i          %i  %i  %i   %i     %i     %i", j, a, c, b, fa, fm, fb);
            //fm = 
        }
    }
    //printf("A raiz da função é: %i com erro de %i(< %i)"m, f_m, e);
}
