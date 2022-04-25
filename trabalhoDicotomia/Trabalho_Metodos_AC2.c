#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void make_lag();

int main()
{
    int i = 0, menu;
    
menu:
    printf("\n1 - Dicchotomy\n2 - Lagrange\n0 - Exit\n");
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

void make_lag()
{
    float x[50], y[50], pl, yp=0, p;
    int i, j, point;

    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n+++++++++++++++++Numerical methods: Lagrange+++++++++++++++++\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("Enter the number of points from the table x and f(x):\n");
    scanf("%i", &point);

    if (point == 0 || point > 5)
    {
        printf("Enter a value between 1 and 5\n");
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

    printf("Enter the value to be interpolated:\n");
    scanf("%f", &pl);

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
    
    printf("The point %.3f of f(x) is %.3f", pl, yp);
}// make_lag