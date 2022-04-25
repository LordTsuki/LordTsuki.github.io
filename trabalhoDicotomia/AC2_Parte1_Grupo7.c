#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void alloc_lag(float **p2, int tam);
void make_lag();
//void receive_values(float *p)

int main()
{
    int i = 0, menu;
    
menu:
    printf("\n1 - Dichotomy\n2 - Lagrange\n0 - Exit\n");
    scanf("%i", &menu);
    fflush(stdin);
    switch (menu)
    {
    case 1: // Dichotomy
        /* Dichotomy */
        break;
    
    case 2: // Lagrange
        make_lag();
        goto menu;
        break;
    
    case 0:
        exit(1);

    default:
        printf("Command ERROR");
        goto menu;
        break;
    }// Switch Menu

}// Main

/*void receive_values(float *p)
{
    float x[50], y[50], pl, yp=0, p;
    int i, j, point;

    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n+++++++++++++++++Numerical methods: Lagrange+++++++++++++++++\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("Enter the number of points from the table x and f(x):\n");
    scanf("%i", &point);

    if (point < 1 || point > 5)
    {
        printf("Enter a integer value between 1 and 5\n");
        scanf("%i", &point);
    }// If

    printf("Enter the values of x:\n");

    for(i = 0; i < point; i++)
    {
      printf("x[%d] = ", i);
      scanf("%f", &x[i]);
    }// For

    printf("Enter the values of f(x):\n");

    for(i = 0;i < point; i++)
    {
      printf("f[x%d] = ", i);
      scanf("%f", &y[i]);
    }// For

    printf("Enter the value of x to be interpolated:\n");
    scanf("%f", &pl);
}*/

void alloc_lag(float **p2, int tam)
{
    if((*p2=(float*)realloc(*p2,tam*sizeof(float)))==NULL)
    {
        printf("Not able to alloc");
        system("pause");
        exit(1);
    }
}//alloc_lag

void make_lag()
{
    float x[50], y[50], pl, yp=0, p;
    int i, j, point, prov;
    char resp;

    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n+++++++++++++++++Numerical methods: Lagrange+++++++++++++++++\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("Enter the number of points from the table x and f(x):\n");
    scanf("%i", &point);

    while(point < 1 || point > 5)
    {
        printf("Enter a integer value between 1 and 5\n");
        scanf("%i", &point);
    }//while

    printf("Enter the values of x:\n");

    for(i = 0; i < point; i++)
    {
      printf("x[%d] = ", i);
      scanf("%f", &x[i]);
    }// For
    i--;
    prov = i;

    printf("Enter the values of f(x):\n");

    for(i = 0;i < point; i++)
    {
      printf("f[x%d] = ", i);
      scanf("%f", &y[i]);
    }// For
a:
    yp=0;
    printf("Enter the value of x to be interpolated:\n");
    scanf("%f", &pl);

    while(pl<x[0] || pl>x[prov])
    {
        printf("Please type values of x between the ones assigned previously (DO NOT EXTRAPOLATE): ");
        scanf("%f", &pl);
    }

    printf("+++++++++++++++++++++++++++++++++++++++++++++++\n+++++++++++++++++Interpolation+++++++++++++++++\n+++++++++++++++++++++++++++++++++++++++++++++++\n");

    for(i = 0; i < point;i++)
    {
        p = 1;
        for(j = 0; j < point; j++)
            {

            if(i != j)
                {
                    p = p * (pl - x[j])/(x[i] - x[j]);
                }
            }
        printf("L[%d] = %.3f\n", i, p);
        yp = yp + p * y[i];
    }// For
    
    printf("The point %.3f of f(x) is %.3f\n", pl, yp);
    system("pause");
    system("cls");
    printf("Do you want to interpolate another point?: [y/n]\n");
    fflush(stdin);
    scanf("%c", &resp);
    fflush(stdin);
    if (resp == 'y' || resp == 'Y')
    {
        goto a;
    }
}// make_lag