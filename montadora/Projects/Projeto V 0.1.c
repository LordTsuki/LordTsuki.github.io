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

typedef struct infoloja
{ 
    char sigla; 
    char CNPJ[19];
}infoloja; 
 
typedef union dadosloja
{ 
    char sigla;
    infoloja reserva;
}dadosloja; 
 
typedef struct montadora
{ 
    int regcarro;
    char modelo[20]; 
    char cor[10]; 
    float valor; 
    dadosloja status;
}montadora;

void alloc_store(loja **p1, int tam);
int verify_store();
void register_store(loja *p1, int tam);
void save_store(loja *p1);
void show_store(loja *p1, int qtt);

void alloc_car(montadora **p2, int tam);
int verify_car();
void register_car(montadora *p2, int tam);
void save_car(montadora *p2);
void show_car(montadora *p2, int qtde);

main()
{
    loja *ps=NULL;
    montadora *pc=NULL;
    char op;
    int qtt, menu_base, menu_store, menu_assembler, menu_check;
menu_base:
    printf("1 - Store\n2 - Car\n0 - Exit\n");
    scanf("%i", &menu_base);
    fflush(stdin);
    switch (menu_base)
    {
        case 1:
            system("cls");
        menu_store:
            printf("1 - Register Store\n2 - Check\n0 - Back\n");
            scanf("%i", &menu_store);
            fflush(stdin);
            switch (menu_store)
            {
                case 1:
                    system("cls");
                    alloc_store(&ps, 1);
                    qtt = verify_store();
                    if(qtt < 5)
                    {
                        register_store(ps, qtt+1);
                        qtt++;
                        printf("Wish to continue? Y or N\n");
                        gets(op);
                        fflush(stdin);
                        if (op == 'N' || 'n')
                        {
                            goto menu_store;
                        }
                    }// If Register is OK
                    else
                    {
                        printf("Maximum of five stores reached.");
                        goto menu_store;
                    }// Else Register exceeded
                break;// Case 1 - Register

                case 2:
                    system("cls");
                    alloc_store(&ps, 1);
                menu_check:
                    printf("1 - Check per CNPJ\n 2 - Check All\n0 - Back");
                    scanf("%i", &menu_check);
                    switch (menu_check)
                    {
                    case 1:
                        printf("Out of Order");
                        goto menu_check;
                    break;// Case 1 - Check per CNPJ
                    
                    case 2:
                        show_store(ps, qtt);
                    break;// Case 2 - Ckeck All
                    
                    case 0:
                        system("cls");
                    goto menu_store;
                    }// Switch Menu Check
                break;// Case 2 - Check

                case 0:
                    system("cls");
                goto menu_base;// Case 0 - Return to Start Menu
            }// Switch Menu Store
        case 2:
            system("cls");
        menu_assembler:
            printf("1 - Register Car\n2 - Check\n0 - Back\n");
            scanf("%i", &menu_assembler);
            fflush(stdin);
            switch (menu_assembler)
            {
                case 1:
                    system("cls");
                    system("pause");
                    alloc_car(&pc, 1);
                    system("pause");
                    qtt = verify_car();
                    if(qtt < 50)
                    {
                        system("pause");
                        register_car(ps, qtt+1);
                        qtt++;
                        printf("Wish to continue? Y or N\n");
                        gets(op);
                        fflush(stdin);
                        if (op == 'N' || 'n')
                        {
                            goto menu_assembler;
                        }
                    }// If Register is OK
                    else
                    {
                        printf("Maximum of fifty cars reached.");
                        goto menu_assembler;
                    }// Else Register exceeded
                break;// Case 1 - Register

                case 2:
                    system("cls");
                    alloc_car(&pc, 1);
                    show_car(pc, qtt);
                break;// Case 2 - Check

                case 0:
                    system("cls");
                goto menu_base;// Case 0 - Return to Start Menu
            }// Switch Menu Assembler
        case 0:
            exit(1);// Case 0 - Exit Program
    }// Switch Start Menu
}// Main

void alloc_store(loja **p1, int tam)
{
if((*p1=(loja*)realloc(*p1,tam*sizeof(loja)))==NULL)
  exit(1);
}// Function alloc_store

int verify_store()
{
    long int cont=0;
    FILE *fptr = NULL;
    if((fptr = fopen("conssecionaria.bin", "rb")) == NULL)
    {
        return cont;
    }// If - Case Data ERROR
    else
    {
        fseek(fptr,0,2);
  	    cont=ftell(fptr)/sizeof(loja);
  	    fclose(fptr);
  	    return cont;
    }// Else - Case Data OK
}// Function Verify_store

void register_store(loja *p1, int qtt)
{
    int i;
    p1->regloja=qtt;
    printf("\nRegister: %i",p1->regloja);
    system("pause");
    system("cls");
    printf("\nCar Store: \n");
    gets(p1->nome);
    fflush(stdin);
    system("cls");
    printf("CNPJ: \n");
    gets(p1->CNPJ);
    fflush(stdin);
    system("cls");
    printf("Street:\n");
    gets(p1->end.logradouro);
    fflush(stdin);
    system("cls");
    printf("district:\n");
    gets(p1->end.bairro);
    fflush(stdin);
    system("cls");
    printf("ZIP Code:\n");
    gets(p1->end.CEP);
    fflush(stdin);
    system("cls");
    printf("City:\n");
    gets(p1->end.cidade);
    fflush(stdin);
    system("cls");
    printf("State:\n");
    gets(p1->end.estado);
    fflush(stdin);
    system("cls");
    printf("Cell Phone:\n");
    gets(p1->end.fone);
    fflush(stdin);
    system("cls");
    printf("E-mail:\n");
    gets(p1->end.email);
    fflush(stdin);
    system("cls");
    for ( i = 0; i < 3; i++)
    {
        p1->tabela[i].sigla = 'L';
    }
    p1->sold=0;
    p1->reserved=0;
    save_store(p1);
}//Function register_store

void save_store(loja *p1)
{
    FILE *fptr=NULL;
    if((fptr=fopen("concessionaria.bin","ab"))==NULL)
    {
        printf("\nErro ao abrir o arquivo");
    }// If - Data ERROR
    else
    {
        fwrite(p1,sizeof(loja), 1, fptr);
    }// Else - Data OK
    fclose(fptr);
}// Function save_store

void show_store(loja *p1, int qtt)
{
    int i;
    FILE *fptr=NULL;
    system("cls");
    if((fptr=fopen("concessionaria.bin", "rb"))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR
    else
    {
  	    for(i=0; i<qtt; i++)
  	    {
  	  	    fseek(fptr, i*sizeof(loja), 0);
  	  	    fread(p1, sizeof(loja), 1, fptr);
  	  	    printf("\nRegister: %i\nName: %c\nCNPJ: %c\nAdress: %.c\nSold: %i\nReserved: %i\nTable 0: %c\nTable 1: %c\nTable 2: %c\n", p1->regloja, p1->nome, p1->CNPJ, p1->end.logradouro, p1->sold, p1->reserved, p1->tabela[0], p1->tabela[1], p1->tabela[2]);
	    }// For - Show Data
	    fclose(fptr);
    }// Else - Data OK
    printf("\n\n\n");
    system("pause");
}// Function show_store

void alloc_car(montadora **p2, int tam)
{
if((*p2=(montadora*)realloc(*p2,tam*sizeof(montadora)))==NULL)
  exit(1);
}// Function alloc_car

int verify_car()
{
    long int cont=0;
    FILE *fptr = NULL;
    if((fptr = fopen("carro.bin", "rb")) == NULL)
    {
        return cont;
    }// If - Case Data ERROR
    else
    {
        fseek(fptr,0,2);
  	    cont=ftell(fptr)/sizeof(montadora);
  	    fclose(fptr);
  	    return cont;
    }// Else - Case Data OK
}// Function verify_car

void register_car(montadora *p2, int qtt)
{
    int i;
    p2->regcarro=qtt;
    printf("\nRegister: %i",p2->regcarro);
    system("pause");
    system("cls");
    printf("\nModel: \n");
    gets(p2->modelo);
    fflush(stdin);
    system("cls");
    printf("Color: \n");
    gets(p2->cor);
    fflush(stdin);
    system("cls");
    printf("Price:\nR$:");
    scanf("%f", &(p2->valor));
    fflush(stdin);
    system("cls");
    printf("Sigla:\n");
    p2->status.sigla = 'L';
    save_car(p2);
}//Function register_car

void save_car(montadora *p2)
{
    FILE *fptr=NULL;
    if((fptr=fopen("carro.bin","ab"))==NULL)
    {
        printf("\nErro ao abrir o arquivo");
    }// If - Data ERROR
    else
    {
        fwrite(p2, sizeof(montadora), 1, fptr);
    }// Else - Data OK
    fclose(fptr);
}// Function save_car

void show_car(montadora *p2, int qtt)
{
    int i;
    FILE *fptr=NULL;
    system("cls");
    if((fptr=fopen("carro.bin", "rb"))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR
    else
    {
  	    for(i=0; i<qtt; i++)
  	    {
  	  	    fseek(fptr, i*sizeof(loja), 0);
  	  	    fread(p2, sizeof(loja), 1, fptr);
  	  	    printf("\nRegister: %i\nModel: %c\nColor: %c\nPrice: %.c\nStatus: %i\n", p2->regcarro, p2->modelo, p2->cor, p2->valor, p2->status.sigla);
	    }// For - Show Data
	    fclose(fptr);
    }// Else - Data OK
    printf("\n\n\n");
    system("pause");
}// Function show_car