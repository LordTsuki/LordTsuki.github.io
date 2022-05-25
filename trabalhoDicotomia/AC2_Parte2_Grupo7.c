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
#include <conio.h>
#include <ctype.h>

void alloc_float(float **p, int tam);
void alloc_int(int **p, int tam);
void receive_values(float *x, float *y, int tam);
void save_values(float *x, float *u_0, float *u_1, float *u_2, int tam);
void print_gauss_elimination_line(float *y, float *u_0, float *u_1, int tam);
void print_gauss_elimination_parable(float *y, float *u_0, float *u_1, float *u_2, int tam);
void receive_values_trapeze(float *p, int tam, float *inicial, float *final);
float calculateF(float *p, int tam, float x);
void print_trapezoidal_rule(float *p, float *fx, int tam, float *inicial, float *final, int *ndivisions);

int main()
{
    char decision;
    float *x = NULL, *y = NULL, *u0 = NULL,*u1 = NULL, *u2 = NULL, *coef = NULL, *a = NULL, *b = NULL, *f_x = NULL;
    int menu, npoints, equation, degree, *divisions = NULL;
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
            equation:
            printf("\nChoose an option (1) Line Equation or (2) Parable Equation: ");
            scanf("%i", &equation);
            fflush(stdin);
            switch(equation)
            {
                case 1:
                    print_gauss_elimination_line(y, u0, u1, npoints);
                    printf("Do you wish to calculate the same p(x) again? (y/n)");
                    scanf("%c", &decision);
                    if(toupper(decision) == 'Y')
                    {
                        goto equation;
                    }
                break;
                
                case 2:
                    print_gauss_elimination_parable(y, u0, u1, u2, npoints);
                    printf("\nDo you wish to calculate the same p(x) again (y/n)?: ");
                    scanf("%c", &decision);
                    if(toupper(decision) == 'Y')
                    {
                        goto equation;
                    }
                break;
            }
            goto menu;
        break;

        case 2:
            printf("\nType the degree of the polynomial[0-10]: ");
            scanf("%i", &degree);
            fflush(stdin);
            alloc_float(&coef, degree+1);
            alloc_float(&a, 1);
            alloc_float(&b, 1);
            alloc_int(&divisions, 1);
            alloc_float(&f_x, *divisions+1);
            receive_values_trapeze(coef, degree, a, b);
            divisions:
            print_trapezoidal_rule(coef, f_x, degree, a, b, divisions);
            printf("\nDo you wish to calculate with anoter number of trapezoidals (y/n)?: ");
            scanf("%c", &decision);
            if(toupper(decision) == 'Y')
            {
                goto divisions;
            }
            goto menu;
        break;

        default:
            printf("\nCommand ERROR");
            goto menu;
        break;// Another Key

        case 0:
            exit(1);
        break;
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

void alloc_int(int **p, int tam)
{
	if( (*p=(int *)realloc(*p,(tam)*sizeof(int)) )==NULL)
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
      printf("x[%i] = ", i);
      scanf("%f", x + i);
    }// For

    printf("Enter the values of y(x):\n");

    for(i = 0;i < tam; i++)
    {
      printf("y[%i] = ", i);
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

void print_gauss_elimination_line(float *y, float *u_0, float *u_1, int tam)
{
    int i;
    float t1=0, t2=0, t3=0, t4=0, t5=0, t6=0, aux, a0, a1;
    for (i = 0; i < tam; i++)
    {
        t1 = t1 + *(u_0+i)**(u_0+i);
        t2 = t2 + *(u_1+i)**(u_0+i);
        t3 = t3 + *(y+i)**(u_0+i);
        t4 = t4 + *(u_0+i)**(u_1+i);
        t5 = t5 + *(u_1+i)**(u_1+i);
        t6 = t6 + *(y+i)**(u_1+i);
    }
    aux = t4/t1;
    
    printf("---------building p(x)---------\n\nVectors\n y\tu0\tu1\n");
    for ( i = 0; i < tam; i++)
    {
        printf("%.2f   %.2f   %.2f\n", *(y+i), *(u_0+i), *(u_1+i));
    }
    getch();
    printf("--------Scalar System---------\n\nObtained system by scalar product\n");
    printf("%.2f   %.2f   %.2f\n%.2f   %.2f   %.2f", t1,t2, t3, t4, t5, t6);
    getch();
    printf("\n\n---------Gauss Elimination----------\n\nEquivalent linear system\n");
    t4=t4-(t1*(aux));
    t5=t5-(t2*(aux));
    t6=t6-(t3*(aux));
    
    printf("%.2f   %.2f   %.2f\n%.2f   %.2f   %.2f\n\n", t1,t2, t3, t4, t5, t6);

    a1 = t6/t5;
    a0 = (t3-(t2*a1))/t1;

    printf("Answer:\na0=%.3f\na1=%.3f\n\n", a0, a1);
    printf("The line that best aproximates the function from the table is p(x)=%.3f+%.3fx\n", a0, a1);
}

void print_gauss_elimination_parable(float *y, float *u_0, float *u_1, float *u_2, int tam)
{
    int i;
    float t1=0, t2=0, t3=0, t4=0, t5=0, t6=0,t7=0, t8=0, t9=0, t10=0, t11=0, t12=0, aux, aux1, aux2, a0, a1, a2;
    for (i = 0; i < tam; i++)
    {
        t1 = t1 + *(u_0+i)**(u_0+i);
        t2 = t2 + *(u_1+i)**(u_0+i);
        t3 = t3 + *(u_2+i)**(u_0+i);
        t4 = t4 + *(y+i)**(u_0+i);
        t5 = t5 + *(u_0+i)**(u_1+i);
        t6 = t6 + *(u_1+i)**(u_1+i);
        t7 = t7 + *(u_2+i)**(u_1+i);
        t8 = t8 + *(y+i)**(u_1+i);
        t9 = t9 + *(u_0+i)**(u_2+i);
        t10 = t10 + *(u_1+i)**(u_2+i);
        t11 = t11 + *(u_2+i)**(u_2+i);
        t12 = t12 + *(y+i)**(u_2+i);
    }
    aux = t5/t1;

    printf("---------building p(x)---------\n\nVectors\n y\tu0\tu1\tu2\n");
    for ( i = 0; i < tam; i++)
    {
        printf("%.2f   %.2f   %.2f   %.2f\n", *(y+i), *(u_0+i), *(u_1+i), *(u_2+i));
    }
    getch();
    printf("--------Scalar System---------\n\nObtained system by scalar product\n");
    printf("%.2f   %.2f   %.2f   %.2f\n%.2f   %.2f   %.2f   %.2f\n%.2f   %.2f   %.2f   %.2f", t1,t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12);
    getch();
    printf("\n\n---------Gauss Elimination----------\n\nEquivalent linear system\n");
    t5=t5-(t1*(aux));
    t6=t6-(t2*(aux));
    t7=t7-(t3*(aux));
    t8=t8-(t4*(aux));
    aux1= t9/t1;
    t9=t9-(t1*(aux1));
    t10=t10-(t2*(aux1));
    t11=t11-(t3*(aux1));
    t12=t12-(t4*(aux1));
    aux2= t10/t6;
    t10=t10-(t6*(aux2));
    t11=t11-(t7*(aux2));
    t12=t12-(t8*(aux2));
    printf("%.2f   %.2f   %.2f   %.2f\n%.2f   %.2f   %.2f   %.2f\n%.2f   %.2f   %.2f   %.2f\n\n", t1,t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12);
    
    a2= t12/t11;
    a1 = (t8-(t7*a2))/t6;
    a0 = (t4-((t2*a1)+(t3*a2)))/t1;

    printf("Answer:\na0=%.3f\na1=%.3f\na2=%.3f\n\n", a0, a1, a2);
    printf("The line that best aproximates the function from the table is p(x)=%.3f+%.3fx+%.3fx^2\n", a0, a1, a2);
}

void receive_values_trapeze(float *p, int tam, float *inicial, float *final)
{
    int i;
    float aux;
    for(i=0; i < tam+1; i++)
    {
        printf("Type the coefficient of x^%i: ", i);
        scanf("%f", p+i);
        fflush(stdin);
    }
    printf("\nType the value of a: ");
    scanf("%f", inicial);
    fflush(stdin);
    printf("\nType the value of b: ");
    scanf("%f", final);
    fflush(stdin);
    if(*inicial>*final)
    {
        aux = *inicial;
        *inicial = *final;
        *final = aux;
        printf("Warning - Altered Range\nCorrected Order: ");
        printf("[a]=%.2f and [b]=%.2f", *inicial, *final);
    }
}

float calculateF(float *p, int tam, float x)
{
    float valfunc = 0;
    int i;
    for(i=0; i<tam+1; i++)
    {
        valfunc = valfunc + (pow((x), i))*(*(p+i));
    }
    return valfunc;
}

void print_trapezoidal_rule(float *p, float *fx, int tam, float *inicial, float *final, int *ndivisions)
{
    int i;
    float h, itr = 0;
    printf("\nType the number of division from the interval: ");
    scanf("%i", ndivisions);
    fflush(stdin);
    h =((*final)-(*inicial))/(*ndivisions);
    for (i = 0; i < *ndivisions+1; i++)
    {
        *(fx+i) = calculateF(p, tam, h*i + *inicial);
    }
    printf("h = (%.4f - %.4f) / %i\n\n", *inicial, *final, *ndivisions);
    printf("h: %.4f\n\n", h);
    getch();
    printf("Values Table\n\n  x     f(x)\n");
    for ( i = 0; i < *ndivisions+1; i++)
    {
        printf("%.4f  %.4f\n", *(inicial) + h*i, *(fx+i));
    }
    getch();
    for (i = 1; i < *ndivisions; i++)
    {
        itr = itr + *(fx+i);
    }
    itr = (h/2)*(2*itr + *fx + *(fx+*ndivisions));
    printf("\nITR = %.4f", itr);
}