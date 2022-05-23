/*
TRABALHO DE DICOTOMIA E LAGRANGE
NOME: CONRADO SETTI A M O RA: 210623
NOME: GABRIEL DE CARVALHO TORRES LUNA RA: 210060
NOME: MARCOS VINICIUS FOLENA RA: 204115
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void alocaFloat(float **p, int tam);
void valores_d(float *p, int tam, float *inicial, float *final, float *medio, float *prec);
float calculaF(float *p, int tam, float *x);
void print_d(float *p, int tam, float *inicial, float *final, float *medio, float *prec);

void alloc_lag(float **p2, int tam);
void receive_values(float *x, float *y, int point);
void make_lag(float pl, float yp, float p, float *x, float *y, int tam);

int main()
{
    float *termo = NULL, *a = NULL, *b = NULL, *c = NULL, *precisao = NULL, pl_l, yp_l, p_l, *x_l = NULL, *y_l = NULL;
    int menu, point, numTermos;

menu:
    printf("\n1 - Dichotomy\n2 - Lagrange\n0 - Exit\n");
    scanf("%i", &menu);
    fflush(stdin);
    switch(menu)
    {
        case 1:
            printf("\nType the degree of the equation: ");//RECEBE O MAIOR GRAU DA EQUAÇÃO
            scanf("%i", &numTermos);
            alocaFloat(&termo, numTermos+1);
            alocaFloat(&a, 1);
            alocaFloat(&b, 1);
            alocaFloat(&c, 1);
            alocaFloat(&precisao, 1);
            valores_d(termo, numTermos, a, b, c, precisao);
            print_d(termo, numTermos, a, b, c, precisao);
            goto menu;
        break;// Dichotomy
        
        case 2: // Lagrange
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n+++++++++++++++++Numerical methods: Lagrange+++++++++++++++++\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("Enter the number of points from the table x and f(x):\n");//RECEBE VALORES DE X E Y DOS PONTOS
            scanf("%i", &point);
            while(point < 1 || point > 5)
            {
                printf("Enter a integer value between 1 and 5\n");
                scanf("%i", &point);
            }//while
            alloc_lag(&x_l, point);
            alloc_lag(&y_l, point);
            receive_values(x_l, y_l, point);
            make_lag(pl_l, yp_l, p_l, x_l, y_l, point);
            goto menu;
        break;// Lagrange
        
        case 0:
            exit(1);
        break;// Exit

        default:
            printf("Command ERROR");
            goto menu;
        break;// Another Key
    }// Switch Menu

}// Main


void alocaFloat(float **p, int tam)
{
	if( (*p=(float *)realloc(*p,(tam)*sizeof(float)) )==NULL)
	{
		printf("Error in the allocation!");
		exit(1);
	}
	//printf("Espaco alocado com sucesso! End= %u\n",*p);
}//alocaFloat

void valores_d(float *p, int tam, float *inicial, float *final, float *medio, float *prec)
{
    int i;
    float f1, f2;
    for(i=0; i < tam+1; i++)
        {
            printf("Type the coefficient of x^%i: ", i);
            scanf("%f", p+i);
            fflush(stdin);
        }
    printf("\nType the value of the precision: ");
    scanf("%f", prec);
    fflush(stdin);
    printf("\nType the value of a: ");
    scanf("%f", inicial);
    fflush(stdin);
    printf("\nType the value of b: ");
    scanf("%f", final);
    fflush(stdin);
    f1 = calculaF(p, tam, inicial);
    f2 = calculaF(p, tam, final);
    while (f1*f2>0)
    {
        printf("\nThe product of the images of these two points is positive, type a new range: ");
        printf("\na: ");
        scanf("%f", inicial);
        fflush(stdin);
        printf("\nb: ");
        scanf("%f", final);
        fflush(stdin);
        f1 = calculaF(p, tam, inicial);
        f2 = calculaF(p, tam, final);
    }
    *medio= *(inicial)/2 + *(final)/2;
}//valores_d
//RECEBE OS COEFICIENTES, A PRECISAO, E OS VALORES INICIAL E FINAL DO INTERVALO

float calculaF(float *p, int tam, float *x)
{
    float valfunc = 0;
    int i;
    for(i=0; i<tam+1; i++)
    {
        valfunc = valfunc + (pow((*x), i))*(*(p+i));
    }
    return valfunc;
}//calculaF
//CALCULA O VALOR DA FUNCAO

void print_d(float *p, int tam, float *inicial, float *final, float *medio, float *prec)
{
    float fa = 0, fb = 0, fm = 0, absfm;
    int j;
    fa = calculaF(p, tam, inicial);
    fb = calculaF(p, tam, final);
    fm = calculaF(p, tam, medio);
    absfm = *prec + 1;
    system("cls");
    printf("----------Iterations of the Dichotomy Method----------\ni\ta\tm\tb\tf(a)\tf(m)\tf(b)");
        for (j = 0; absfm > *prec; j++)
        {
            printf("\n%i     %.3f   %.3f   %.3f   %.3f   %.3f   %.3f", j, *inicial, *medio, *final, fa, fm, fb);
            if (fa * fm < 0)
            {
                fb = fm;
                *final = *medio;
                *medio = (*(inicial) + *(medio))/2;
                fm = calculaF(p, tam, medio);
                if(fm<0)
                {
                    absfm = -fm;
                }
                else
                    absfm = fm;
            }
            else if (fb * fm <0)
            {
                *inicial = *medio;
                fa = fm;
                *medio = (*(final) + *(medio))/2;
                fm = calculaF(p, tam, medio);
                if(fm<0)
                {
                    absfm = -fm;
                }
                else
                    absfm = fm;
            }
        }
        printf("\n%i     %.3f   %.3f   %.3f   %.3f   %.3f   %.3f", j, *inicial, *medio, *final, fa, fm, fb);
    printf("\n\nThe root of the function is about: %.3f with error of %.3f, less than the initial error %.3f, with %i iterations", *medio, absfm, *prec, j);
}//print_d
//PRINTA NA TELA AS ITERAÇÕES DO MÉTODO DA DICOTOMIA

void alloc_lag(float **p2, int tam)
{
    if((*p2=(float*)realloc(*p2,tam*sizeof(float)))==NULL)
    {
        printf("Not able to alloc");
        system("pause");
        exit(1);
    }// If
}//alloc_lag

void receive_values(float *x, float *y, int point)
{
    int i;

    printf("Enter the values of x:\n");

    for(i = 0; i < point; i++)
    {
      printf("x[%d] = ", i);
      scanf("%f", x + i);
    }// For

    printf("Enter the values of y:\n");

    for(i = 0;i < point; i++)
    {
      printf("y[%d] = ", i);
      scanf("%f", y + i);
    }// For

}//receive_values
//RECEBE OS AS COORDENADAS DE X E Y DOS PONTOS

void make_lag(float pl, float yp, float p, float *x, float*y, int tam)
{
    int i, j;
    char resp;

new_point:

    yp=0;
    printf("Enter the value of x to be interpolated:\n");
    scanf("%f", &pl);

    while(pl<*x || pl>*(x + tam - 1))
    {
        printf("\nPlease type values of x between the ones assigned previously (DO NOT EXTRAPOLATE):\n");
        scanf("%f", &pl);
    }// While

    printf("\n+++++++++++++++++++++++++++++++++++++++++++++++\n+++++++++++++++++Interpolation+++++++++++++++++\n+++++++++++++++++++++++++++++++++++++++++++++++\n");

    for(i = 0; i < tam; i++)
    {
        p = 1;
        for(j = 0; j < tam; j++)
            {
            if(i != j)
                {
                    p = p * (pl - *(x + j))/(*(x + i) - *(x + j));
                }
            }
        printf("L[%i] = %.3f\n", i, p);
        yp = yp + p * (*(y + i));
    }// For
    
    printf("The point %.3f of f(x) is %.5f\n", pl, yp);
    system("pause");
    system("cls");
    printf("Do you want to interpolate another point?: [y/n]\n");
    fflush(stdin);
    scanf("%c", &resp);
    fflush(stdin);
    if (resp == 'y' || resp == 'Y')
    {
        goto new_point;
    }// If
}// make_lag
//RECEBE O VALOR DE X A SER INTERPOLADO E ENCONTRA O VALOR RESPECTIVO EM Y