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
void show_CNPJ(loja *p1, int tam, char aux[19]);

void alloc_car(montadora **p2, int tam);
int verify_car();
void register_car(montadora *p2, int tam);
void save_car(montadora *p2);
void show_car(montadora *p2, int qtt);

int main()
{
    loja *ps=NULL;
    montadora *pc=NULL;
    alloc_store(&ps, 1);
    alloc_car(&pc, 1);
    char aux[19];
    int qtt=0, menu_base, menu_store, menu_assembler, menu_check;
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
                    qtt = verify_store();
                    if(qtt < 5)
                    {
                        register_store(ps, qtt+1);
                        qtt++;
                        goto menu_store;
                    }// If Register is OK
                    else
                    {
                        printf("Maximum of five stores reached.");
                        goto menu_store;
                    }// Else Register exceeded
                break;// Case 1 - Register

                case 2:
                    system("cls");
                menu_check:
                    printf("1 - Check per CNPJ\n2 - Check All\n0 - Back\n");
                    scanf("%i", &menu_check);
                    switch (menu_check)
                    {
                    case 1:
                        qtt=verify_store();//AQUII AQUII AQUIII
                        system("cls");
                        printf("Write wanted CNPJ number: \n");
                        gets(aux);
                        show_CNPJ(ps, qtt, aux);    
                    goto menu_check;// Case 1 - Check per CNPJ
                    
                    case 2:
                        qtt = verify_store();
                        system("cls");
                        show_store(ps, qtt);
                    goto menu_store;// Case 2 - Ckeck All
                    
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
                    qtt = verify_car();
                    if(qtt < 50)
                    {
                        register_car(pc, qtt+1);
                        qtt++;
                        goto menu_assembler;
                    }// If Register is OK
                    else
                    {
                        printf("Maximum of fifty cars reached.");
                        goto menu_assembler;
                    }// Else Register exceeded
                break;// Case 1 - Register

                case 2:
                    qtt = verify_car();
                    system("cls");
                    show_car(pc, qtt);
                goto menu_assembler;// Case 2 - Check

                case 0:
                    system("cls");
                goto menu_base;// Case 0 - Return to Start Menu
            }// Switch Menu Assembler
        case 0:
            exit(1);// Case 0 - Exit Program
    }// Switch Start Menu
    return 0;
}// Main

void alloc_store(loja **p1, int tam)
{
if((*p1=(loja*)realloc(*p1,tam*sizeof(loja)))==NULL)
{
    printf("Not able to alloc");
    system("pause");
    exit(1);
}
}// Function alloc_store

int verify_store()
{
    long int cont=0;
    FILE *fptr = NULL;
    if((fptr = fopen("concessionaria.bin", "rb")) == NULL)
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
    printf("\nRegister: %i\n",p1->regloja);
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
    p1->sold=0;
    p1->reserved=0;
    for ( i = 0; i < 3; i++)
    {
        p1->tabela[i].sigla = 'L';
    }
    save_store(p1);
}//Function register_store

void save_store(loja *p1)
{
    FILE *fptr=NULL;
    if((fptr=fopen("concessionaria.bin", "ab"))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR
    else
    {
        fwrite(p1, sizeof(loja), 1, fptr);
    }// Else - Data OK
    fclose(fptr);
}// Function save_store

void show_store(loja *p1, int qtt)
{
    int i=0;
    FILE *fptr=NULL;
    system("cls");
    if((fptr=fopen("concessionaria.bin", "rb"))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR
    fseek(fptr, i*sizeof(loja), 0);
    fread(p1, sizeof(loja), 1,  fptr);
    if(p1->reserved == 0)
    {
  	    for(i=0; i<qtt; i++)
  	    {
            fseek(fptr, i*sizeof(loja), 0);
            fread(p1, sizeof(loja), 1,  fptr);
  	  	    printf("\nRegister: %i\nName: %s\nCNPJ: %s\nAdress: %s\nSold: %i\nReserved: %i\nTable 0: %c\nTable 1: %c\nTable 2: %c\n", p1->regloja, p1->nome, p1->CNPJ, p1->end.logradouro, p1->sold, p1->reserved, p1->tabela[0].sigla, p1->tabela[1].sigla, p1->tabela[2].sigla);
	    }// For - Show Data
	    fclose(fptr);
    }// If - Data OK and Reserved == 0
    else
    {
  	    for(i=0; i<qtt; i++)
  	    {
            fseek(fptr, i*sizeof(loja), 0);
            fread(p1, sizeof(loja), 1,  fptr);
  	  	    printf("\nRegister: %i\nName: %s\nCNPJ: %s\nAdress: %s\nSold: %i\nReserved: %i\nTable 0: %c %i\nTable 1: %c %i\nTable 2: %c %i\n", p1->regloja, p1->nome, p1->CNPJ, p1->end.logradouro, p1->sold, p1->reserved, p1->tabela[0].reservado.sigla, p1->tabela[0].reservado.regcarro, p1->tabela[1].reservado.sigla, p1->tabela[1].reservado.regcarro, p1->tabela[2].reservado.sigla, p1->tabela[2].reservado.regcarro);
	    }// For - Show Data
	    fclose(fptr);
    }// Else - Data OK
    printf("\n\n\n");
    system("pause");
    system("cls");
}// Function show_store

void alloc_car(montadora **p2, int tam)
{
if((*p2=(montadora*)realloc(*p2,tam*sizeof(montadora)))==NULL)
{
    printf("Not able to alloc");
    system("pause");
    exit(1);
}
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
    p2->regcarro=qtt;
    printf("\nRegister: %i\n",p2->regcarro);
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
    p2->status.sigla = 'L';
    save_car(p2);
}//Function register_car

void save_car(montadora *p2)
{
    FILE *fptr=NULL;
    if((fptr=fopen("carro.bin","ab"))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR
    else
    {
        fwrite(p2, sizeof(montadora), 1, fptr);
    }// Else - Data OK
    fclose(fptr);
}// Function save_car

void show_car(montadora *p2, int qtt)
{
    int i=0;
    FILE *fptr=NULL;
    system("cls");
    if((fptr=fopen("carro.bin", "rb"))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR
    fseek(fptr, i*sizeof(montadora), 0);
  	fread(p2, sizeof(montadora), 1, fptr);
    if(p2->status.sigla == 'L')
    {
  	    for(i=0; i<qtt; i++)
  	    {
        fseek(fptr, i*sizeof(montadora), 0);
  	    fread(p2, sizeof(montadora), 1, fptr);
  	  	    printf("\nRegister: %i\nModel: %s\nColor: %s\nPrice: %.2f\nStatus: %c\n", p2->regcarro, p2->modelo, p2->cor, p2->valor, p2->status.sigla);
	    }// For - Show Data
	    fclose(fptr);
    }// If - Data OK and Status.Sigla == L
    else
    {
  	    for(i=0; i<qtt; i++)
  	    {
        fseek(fptr, i*sizeof(montadora), 0);
  	    fread(p2, sizeof(montadora), 1, fptr);
  	  	    printf("\nRegister: %i\nModel: %s\nColor: %s\nPrice: %.2f\nStatus: %c %s\n", p2->regcarro, p2->modelo, p2->cor, p2->valor, p2->status.reserva.sigla, p2->status.reserva.CNPJ);
	    }// For - Show Data
	    fclose(fptr);
    }// Else - Data OK
    printf("\n\n\n");
    system("pause");
    system("cls");
}// Function show_car

void show_CNPJ(loja *p1, int tam, char aux[19])
{
    int i=0;
    FILE *fptr=NULL;
    system("cls");
    if((fptr=fopen("concessionaria.bin", "rb"))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR
    fflush(stdin);
    system("cls");
    for (i = 0; i < tam; i++)
    {
        fseek(fptr, i*sizeof(loja), 0);
        fread(p1, sizeof(loja), 1,  fptr);
        if (aux==p1->CNPJ)
        {
            if (p1->reserved==0)
            {
                printf("Name: %s\tSold: %i\tReserved: %i", p1->nome, p1->sold, p1->reserved);
            }
            if (p1->reserved==1)
            {
                printf("Name: %s\tSold: %i\tReserved: %i\tTable 0: %c - %i", p1->nome, p1->sold, p1->reserved, p1->tabela[0].reservado.sigla, p1->tabela[0].reservado.regcarro);
            }
            if (p1->reserved==2)
            {
                printf("Name: %s\tSold: %i\tReserved: %i\tTable 0: %c - %i\tTable 1: %c - %i", p1->nome, p1->sold, p1->reserved, p1->tabela[0].reservado.sigla, p1->tabela[0].reservado.regcarro, p1->tabela[1].reservado.sigla, p1->tabela[1].reservado.regcarro);
            }
            if (p1->reserved==3)
            {
                printf("Name: %s\tSold: %i\tReserved: %i\tTable 0: %c - %i\tTable 1: %c - %i\tTable 2: %c - %i", p1->nome, p1->sold, p1->reserved, p1->tabela[0].reservado.sigla, p1->tabela[0].reservado.regcarro, p1->tabela[1].reservado.sigla, p1->tabela[1].reservado.regcarro, p1->tabela[2].reservado.sigla, p1->tabela[2].reservado.regcarro);
            }
            fclose(fptr);
        }
        else
        {
            printf("No matching found");
            fclose(fptr);
        }
    }
    printf("\n\n\n");
    system("pause");
    system("cls");
}