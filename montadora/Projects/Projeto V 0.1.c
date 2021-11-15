#include <stdio.h>
#include <stdlib.h>

typedef struct endereco 
{
    char logradouro[80]; 
    char bairro[15]; 
    char CEP[10]; 
    char cidade[15]; 
    char estado[3]; 
    char fone[12]; 
    char email[40]; 
}endereco; 

typedef struct infocarro
{
    char sigla; 
    int regcarro; 
}infocarro; 
 
typedef union dadoscarro 
{
    char sigla; 
    infocarro reservado; 
}dadoscarro; 

typedef struct loja
{ 
    int regloja;
    char nome[30];
    char CNPJ[19];
    endereco end;
    int sold;
    int reserved;
    dadoscarro tabela[3]; 
}loja;

void aloc_shop(loja **p1, int tam);
void register_shop(loja **p1, int tam);
void save_shop(loja *p1);
void show_shop(loja *p1, int qtde);
int verify_shop();

//void aloc_assembler(assembler **p2, int tam);
//void register_assembler(assembler **p2, int tam);
//void save_assembler(assembler *p2);
//void show_assembler(assembler *p2, int qtde);
//int verify_assembler();

main()
{
    loja *ps=NULL;
    //assembler *pa=NULL;
    char op;
    int qtt, menu_base, menu_shop, menu_assembler;
menu_base:
    printf("1 - Shop\n2 - Assembler\n0 - Exit\n");
    scanf("%i", &menu_base);
    fflush(stdin);
    switch (menu_base)
    {
        case 1:
            system("cls");
            printf("1 - Register\n2 - Check\n0 - Back\n");
            scanf("%i", &menu_shop);
            fflush(stdin);
            switch (menu_shop)
            {
                case 1:
                    aloc_shop(&ps, 1);
                    qtt = verify_shop();

                    system("cls");

                break; 

                case 2:
                    system("cls");

                break;

                case 0:
                    system("cls");
                    //pastel
                goto menu_base;
            }
        case 2:
            system("cls");
            printf("1 - Register\n2 - Check\n0 - Back\n");
            scanf("%i", &menu_assembler);
            fflush(stdin);
            switch (menu_assembler)
            {
                case 1:
                    system("cls");

                break;

                case 2:
                    system("cls");

                break;

                case 0:
                    system("cls");
                goto menu_base;
            }
        case 0:
            exit(1);
    }
}

void aloc_shop(loja **p1, int tam)
{
if((*p1=(loja*)realloc(*p1,tam*sizeof(loja)))==NULL)
  exit(1);
}//aloca

int verify_shop()
{
    long int cont=0;
    FILE *fptr = NULL;
    if((fptr = fopen("conssecionaria.bin", "rb")) == NULL)
    {
        return cont;
    }
    else
    {
        fseek(fptr,0,2);  //posiciona o fptr no fim do arquivo
  	    cont=ftell(fptr)/sizeof(loja);
  	    fclose(fptr);   //dentro do else - por conta do rb
  	    return cont;
    }//else
}//verify_shop























