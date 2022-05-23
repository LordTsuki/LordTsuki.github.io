/*
TRABALHO DE MMQ E TRAPEZIOS
NOME: CONRADO SETTI A M O RA: 210623
NOME: GABRIEL DE CARVALHO TORRES LUNA RA: 210060
NOME: MARCOS VINICIUS FOLENA RA: 204115
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void alloc_float(float **p, int tam);
void receive_values(float *x, float *y, int tam);
void save_values(float *x, float *u_0, float *u_1, float *u_2, int tam);
void print_gauss_elimination_line(float *x, float *y, float *u_0, float *u_1, int tam);

int main()
{
    char decision;
    float *x = NULL, *y = NULL, *u0 = NULL,*u1 = NULL, *u2 = NULL;
    int menu, npoints, equation;
    menu:
    printf("\n1 - MMQ\n2 - REGRA DOS TRAPEZIOS\n0 - Exit\n");
    scanf("%i", &menu);
    fflush(stdin);
    switch(menu)
    {
        case 1:
            printf("\nType the number of points from x and f(x) table: ");
            scanf("%i", &npoints);
            fflush(stdin);
            alloc_float(&x, npoints);
            alloc_float(&y, npoints);
            alloc_float(&u0, npoints);
            alloc_float(&u1, npoints);
            alloc_float(&u2, npoints);
            receive_values(x, y, npoints);
            save_values(x, u0, u1, u2, npoints);
            //printf("%f\t%f\t%f\n%f\t%f\t%f\n%f\t%f\t%f", *y, *u0, *u1, *(y+1), *(u0+1), *(u1+1), *(y+2), *(u0+2), *(u1+2));
            //printf("%f\t%f\t%f\n%f\t%f\t%f", *x, *(x+1), *(x+2), *y, *(y+1), *(y+2));
            equation:
            printf("\nChoose an option (1) Line Equation or (2) Parable Equation: ");
            scanf("%i", &equation);
            fflush(stdin);
            switch(equation)
            {
                case 1:
                    print_gauss_elimination_line(x, y, u0, u1, npoints);
                    printf("Do you wish to calculate the same p(x) again? (y/n)");
                    scanf("%c", &decision);
                    if(toupper(decision) == 'Y')
                    {
                        goto equation;
                    }
                break;
                
                case 2:

                break;
            }
            goto menu;
        break;

        case 2:

            goto menu;
        break;

        default:
            printf("\nCommand ERROR");
            goto menu;
        break;// Another Key
    }
}

void alloc_float(float **p, int tam)
{
	if( (*p=(float *)realloc(*p,(tam)*sizeof(float)) )==NULL)
	{
		printf("Error in the allocation!");
		exit(1);
	}
	//printf("Espaco alocado com sucesso! End= %u\n",*p);
}//alocaFloat

void receive_values(float *x, float *y, int tam)
{
    int i;

    printf("Enter the values of x:\n");

    for(i = 0; i < tam; i++)
    {
      printf("x[%d] = ", i);
      scanf("%f", x + i);
    }// For

    printf("Enter the values of y(x):\n");

    for(i = 0;i < tam; i++)
    {
      printf("y[%d] = ", i);
      scanf("%f", y + i);
    }// For
}//receive_values
//RECEBE OS AS COORDENADAS DE X E Y DOS PONTOS

void save_values(float *x, float *u_0, float *u_1, float *u_2, int tam)
{
    int i;
    for ( i = 0; i < tam; i++)
    {
        *(u_0+i)=pow(*(x+i), 0);
        *(u_1+i)=*(x+i);
        *(u_2+i)=pow(*(x+i), 2);
    }
    
}

void print_gauss_elimination_line(float *x, float *y, float *u_0, float *u_1, int tam)
{
    int i;
    float t1=0, t2=0, t3=0, t4=0, t5=0, t6=0, aux, a0, a1;
    for (i = 0; i < tam; i++)
    {
        t1= t1 + *(u_0+i)**(u_0+i);
        t2= t2 + *(u_0+i)**(u_1+i);
        t3= t3 + *(y+i)**(u_0+i);
        t4= t4 + *(u_1+i)**(u_0+i);
        t5= t5 + *(u_1+i)**(u_1+i);
        t6= t6 + *(y+i)**(u_1+i);
    }
    aux = t4/t1;
    //printf("%f", t1);
    //system("pause");
    
    printf("---------building p(x)---------\n\nVectors\n y\tu0\tu1\n");
    for ( i = 0; i < tam; i++)
    {
        printf("%.2f   %.2f   %.2f\n", *(y+i), *(u_0+i), *(u_1+i));
    }
    printf("--------Scalar System---------\n\nObtained system by scalar product\n");
    printf("%.2f   %.2f   %.2f\n%.2f   %.2f   %.2f", t1,t2, t3, t4, t5, t6);
    printf("\n\n---------Gauss Elimination----------\n\nEquivalent linear system\n");
    t4=t4-(t1*(aux));
    t5=t5-(t2*(aux));
    t6=t6-(t3*(aux));
    
    printf("%.2f   %.2f   %.2f\n%.2f   %.2f   %.2f\n", t1,t2, t3, t4, t5, t6);
    //system("pause");

    a1 = t6/t5;
    a0 = (t3-(t2*a1))/t1;

    printf("Answer:\na0=%.3f\na1=%.3f\n\n", a0, a1);
    printf("The line that best aproximates the function from the table is p(x)=%.3f+%.3fx\n", a0, a1);
}