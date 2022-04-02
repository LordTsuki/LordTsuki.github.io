#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main ()
{
    printf("\t\tCaculo de Raizes de uma Funcao pelo metodo da bisseccao\n\n");
    double a,b,x1,Fa,Fb,Fx1,erro,absFx1;
    //erro=0.00001;
    printf("\nDigite o valor de a:\n");
    scanf("%lf",&a);
    printf("\nDigite o valor de b:\n");
    scanf("%lf",&b);
    printf("\nDigite o erro:\n");
    scanf("%lf",&erro);
    Fa= log(a)-sin(a)-3;
    Fb= log(b)-sin(b)-3;

    if(Fa*Fb>0)
    {
         while(Fa*Fb>0)
        {
            printf("\nNeste intervalo nao ha raiz.\nDigite um novo intervalo:\n");
            printf("\nDigite o valor de a:\n");
            scanf("%lf",&a);
            printf("\nDigite o valor de b:\n");
            scanf("%lf",&b);
            printf("\nDigite o erro:\n");
            scanf("%lf",&erro);
            Fa= log(a)-sin(a)-3;
            Fb= log(b)-sin(b)-3;
        }

    }
    if(Fa*Fb<0)
    {
        x1=(a+b)/2;
        Fx1=log(x1)-sin(x1)-3;
        if(Fx1<0)
        {
            absFx1=-Fx1;
        }
        else
        {
            absFx1=Fx1;
        }
        while(absFx1>erro)
        {
            printf("F(%lf) e %lf\n",x1,Fx1);
            if(Fx1*Fa<0)
            {
                b=x1;
            }
            else
            {
                a=x1;
            }
            x1=(a+b)/2;
            Fx1=log(x1)-sin(x1)-3;
            if(Fx1<0)
            {
                absFx1=-Fx1;
            }
            else
            {
                absFx1=Fx1;
            }
        }
        printf ("\nF(%lf)=%lf\n",x1, Fx1);
        printf("\n%lf e raiz aproximada da funcao F(x)= X^2-4\n",x1);

    }
    if(Fa*Fb==0)
    {
        if(Fa==0)
        {
            printf("A raiz de F(x)= X^2-4 e %lf\n",a);
        }
        else
        if(Fb==0)
        {
            printf("A raiz de F(x)= X^2-4 e %lf\n",b);
        }
    }


}


