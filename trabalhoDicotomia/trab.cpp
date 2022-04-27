#include<stdio.h>
#include<stdlib.h> 
#include<math.h>

void alocaFloat(float **p, int tam);
void valores_d(float *p, int tam, float *inicial, float *final, float *medio, float *prec);
float calculaF(float *p, int tam, float *x);
void print_d(float *p, int tam, float *inicial, float *final, float *medio, float *prec);

int main ()
{
    int menu, numTermos;
    float *termo = NULL, *a = NULL, *b = NULL, *c = NULL, *precisao = NULL;
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
            valores_d(termo, numTermos, a, b, c, precisao);
            print_d(termo, numTermos, a, b, c, precisao);

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

void valores_d(float *p, int tam, float *inicial, float *final, float *medio, float *prec)
{
    int i;
    float f1, f2;
    for(i=0; i < tam+1; i++)
        {
            printf("Digite o coeficiente de x^%i: ", i);
            scanf("%f", p+i);
            fflush(stdin);
        }
    printf("\nDigite o valor da precisao: ");
    scanf("%f", prec);
    fflush(stdin);
    printf("\nDigite o valor de a: ");
    scanf("%f", inicial);
    fflush(stdin);
    printf("\nDigite o valor de b: ");
    scanf("%f", final);
    fflush(stdin);
    f1 = calculaF(p, tam, inicial);
    f2 = calculaF(p, tam, final);
    while (f1*f2>0)
    {
        printf("\nO produto das imagens desses dois pontos é positivo, digite um novo intervalo: ");
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
}

float calculaF(float *p, int tam, float *x)
{
    float valfunc = 0;
    int i;
    for(i=0; i<tam+1; i++)
    {
        valfunc = valfunc + (pow((*x), i))*(*(p+i));
    }
    return valfunc;
}

void print_d(float *p, int tam, float *inicial, float *final, float *medio, float *prec)
{
    float fa = 0, fb = 0, fm = 0, absfm;
    int j;
    fa = calculaF(p, tam, inicial);
    fb = calculaF(p, tam, final);
    fm = calculaF(p, tam, medio);
    absfm = *prec + 1;
    printf("----------Iteracoes do Metodo da Dicotomia----------\ni\ta\tm\tb\tf(a)\tf(m)\tf(b)");
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
    printf("\n\nA raiz da funcao eh aproximadamente: %.3f com erro de %.3f menor que o erro inicial %.3f, com %i iteracoes", *medio, absfm, *prec, j);
}
