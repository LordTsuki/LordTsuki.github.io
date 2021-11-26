#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

//structs da proxima etapa a seguir
typedef struct data
{ 
int dia;  
int mes;  
int ano;  
}data;
 
typedef struct historicoVendas
{ 
int reghist; 
int regcarro; 
char modelo[20]; 
char cor[10]; 
float valor;  
int regloja; 
char nome[30]; 
char cnpj[19]; 
struct data dataVenda; 
}historicoVendas;

/*Ewis disse que que para a proxima etapa precisamos criar
mais 7 funções.
Uma nova alloc
Uma nova verify
Uma nova save
Uma nova register (?)
Uma nova show (?)
Uma nova search (?)
n sei mais kkkk
3 coisas novas pra fazer:
1.Historico de vendas(alterar a funcao terminaReserva para salvar
                        os dados no historico e salvar o dia da venda)
1.1Consulta do historico atraves do cnpj da concessionaria->mostra os carros
1.2Consulta do historico atraves do modelo do carro
                da conssecionaria->mostra as concessionarias
1.3Até pode fazer uma consulta que mostra td o historico
mas nao precisa
2.Alteracao de cadastro de concessionaria
3.Altercacao de cadastro dos carros
*/

void alloc_store(loja **p1, int tam);// Line 182
int verify_store();// Line 192
void register_store(loja *p1, int tam);// Line 209
void save_store(loja *p1, char *str, int pos);// Line 261
void show_store(loja *p1, int qtt);// Line 275
void show_CNPJ(loja *p1, int tam, char aux[19]);// Line 313

void alloc_car(montadora **p2, int tam);// Line 372
int  verify_car();// Line 382
void register_car(montadora *p2, int tam);// Line 399
void save_car(montadora *p2, char *str, int pos);// Line 421
void show_car(montadora *p2, int qtt);// Line 435


void show_car_model(montadora *p2, int qtt);
void show_car_status(montadora *p2, int qtt);

int search_store(loja *p1, char reg[19], int qtt);
int search_car(montadora *p2, int reg, int qtt);
void reserv(loja *p1, montadora *p2, int qtt_car, int qtt_str);
void finish_reserv(loja *p1, montadora *p2, int qtt_car, int qtt_str);
int main()
{
    loja *ps=NULL;
    montadora *pc=NULL;
    alloc_store(&ps, 1);
    alloc_car(&pc, 1);
    char aux[19];
    int qtt=0, qtt1=0, menu_base, menu_store, menu_assembler, menu_check_store, menu_reserv, menu_check_car;
menu_base:
    printf("[1] - Store\n[2] - Car\n[3] - Manage Car Reservation\n[0] - Exit\n");
    scanf("%i", &menu_base);
    fflush(stdin);
    switch (menu_base)
    {
        case 1:
            system("cls");
        menu_store:
            printf("[1] - Register Store\n[2] - Check\n[0] - Back\n");
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
                        goto menu_store;// Line 89
                    }// If Register is OK
                    else
                    {
                        printf("Maximum of five stores reached.");
                        system("pause");
                        goto menu_store;// Line 89
                    }// Else Register exceeded
                break;// Case 1 - Register

                case 2:
                    system("cls");
                menu_check_store:
                    printf("[1] - Check per CNPJ\n[2] - Check All\n[0] - Back\n");
                    scanf("%i", &menu_check_store);
                    switch (menu_check_store)
                    {
                    case 1:
                        qtt=verify_store();
                        system("cls");
                        show_CNPJ(ps, qtt, aux);    
                    goto menu_check_store;// Case 1 - Check per CNPJ - Line 114
                    
                    case 2:
                        qtt = verify_store();
                        system("cls");
                        show_store(ps, qtt);
                    goto menu_check_store;// Case 2 - Check All - Line 114
                    
                    case 0:
                        system("cls");
                    goto menu_store;// Line 89

                    default:
                        system("cls");
                        printf("Invalid Option");
                        system("pause");
                        system("cls");
                    goto menu_check_store;
                    }// Switch Menu Check
                break;// Case 2 - Check

                case 0:
                    system("cls");
                goto menu_base;// Case 0 - Return to Start Menu - Line 81

                default:
                    system("cls");
                    printf("Invalid Option");
                    system("pause");
                    system("cls");
                goto menu_store;
            }// Switch Menu Store
        case 2:
            system("cls");
        menu_assembler:
            printf("[1] - Register Car\n[2] - Check\n[0] - Back\n");
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
                        goto menu_assembler;// Line 143
                    }// If Register is OK
                    else
                    {
                        printf("Maximum of fifty cars reached.");
                        system("pause");
                        goto menu_assembler;// Line 143
                    }// Else Register exceeded
                break;// Case 1 - Register

                case 2:
                    system("cls");
                menu_check_car:
                    printf("[1] - Check Status\n[2] - Check Model\n[3] - Check All\n[0] - Back\n");
                    scanf("%i", &menu_check_car);
                    fflush(stdin);
                    switch (menu_check_car)
                    {
                    case 1:
                        system("cls");
                        qtt = verify_car();
                        show_car_status(pc, qtt);
                        printf("\n\n\n");
                        system("pause");
                        system("cls");
                    goto menu_check_car;

                    case 2:
                        system("cls");
                        qtt = verify_car();
                        show_car_model(pc, qtt);
                    goto menu_check_car;

                    case 3:
                        qtt = verify_car();
                        system("cls");
                        show_car(pc, qtt);
                    goto menu_check_car;

                    case 0:
                        system("cls");
                    goto menu_assembler;
                    
                    default:
                        system("cls");
                        printf("Invalid Option");
                        system("pause");
                        system("cls");
                    goto menu_check_car;
                    }
                goto menu_assembler;// Case 2 - Check - Line 143

                case 0:
                    system("cls");
                goto menu_base;// Case 0 - Return to Start Menu - Line 81

                default:
                    system("cls");
                    printf("Invalid Option");
                    system("pause");
                    system("cls");
                goto menu_assembler;
            }// Switch Menu Assembler

        case 3:
            system("cls");
        menu_reserv:
            printf("[1] - Add Reservation\n[2] - Finish Reservation\n[0] - Back\n");
            scanf("%i", &menu_reserv);
            fflush(stdin);
            switch (menu_reserv)
            {
                case 1:
                    qtt = verify_car();
                    qtt1 = verify_store();
                    reserv(ps, pc, qtt, qtt1);//AQUI
                    system("cls");
                goto menu_reserv;

                case 2:
                    qtt = verify_car();
                    qtt1 = verify_store();
                    finish_reserv(ps, pc, qtt, qtt1);
                    system("cls");
                goto menu_reserv;
            
                case 0:
                    system("cls");
                goto menu_base;

                default:
                    system("cls");
                    printf("Invalid Option");
                    system("pause");
                    system("cls");
                goto menu_reserv;
            }

        case 0:
            exit(1);// Case 0 - Exit Program

        default:
                system("cls");
                printf("Invalid Option\n");
                system("pause");
                system("cls");
                goto menu_base;
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
        //p1->tabela[i].reservado.sigla='R'
        //p1->tabela[i].reservado.regcarro = 'numero do registro do carro'
    }
    save_store(p1, "ab", 0);
}//Function register_store

void save_store(loja *p1, char *str, int pos)
{
    FILE *fptr=NULL;
    if((fptr=fopen("concessionaria.bin", str))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR
    else
    {
        if(strcmp(str, "rb+")==0)
        {
            fseek(fptr, pos*sizeof(loja), 0);
        }
        fwrite(p1, sizeof(loja), 1, fptr);
    }// Else - Data OK
    fclose(fptr);
}// Function save_store

void show_store(loja *p1, int qtt)//mudar a combinação dos ifs
{
    system("cls");
    int i=0;
    FILE *fptr=NULL;
    system("cls");
    if((fptr=fopen("concessionaria.bin", "rb"))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR
    for(i=0; i<qtt; i++)
    {
        fseek(fptr, i*sizeof(loja), 0);
        fread(p1, sizeof(loja), 1,  fptr);
  	    if(p1->reserved == 0)
  	    {
  	  	    printf("\nRegister: %i\nName: %s\nCNPJ: %s\nAdress: %s\nSold: %i\nReserved: %i\nTable 0: %c\nTable 1: %c\nTable 2: %c\n", p1->regloja, p1->nome, p1->CNPJ, p1->end.logradouro, p1->sold, p1->reserved, p1->tabela[0].sigla, p1->tabela[1].sigla, p1->tabela[2].sigla);
	    }// If - Data OK and Reserved == 0
    // For - Show Data
        else
        {
            if(p1->reserved == 1)
                printf("\nRegister: %i\nName: %s\nCNPJ: %s\nAdress: %s\nSold: %i\nReserved: %i\nTable 0: %c %i\nTable 1: %c\nTable 2: %c\n", p1->regloja, p1->nome, p1->CNPJ, p1->end.logradouro, p1->sold, p1->reserved, p1->tabela[0].reservado.sigla, p1->tabela[0].reservado.regcarro, p1->tabela[1].reservado.sigla, p1->tabela[2].reservado.sigla);
            if(p1->reserved == 2)
                printf("\nRegister: %i\nName: %s\nCNPJ: %s\nAdress: %s\nSold: %i\nReserved: %i\nTable 0: %c %i\nTable 1: %c %i\nTable 2: %c\n", p1->regloja, p1->nome, p1->CNPJ, p1->end.logradouro, p1->sold, p1->reserved, p1->tabela[0].reservado.sigla, p1->tabela[0].reservado.regcarro, p1->tabela[1].reservado.sigla, p1->tabela[1].reservado.regcarro, p1->tabela[2].reservado.sigla);
            if(p1->reserved == 3)
                printf("\nRegister: %i\nName: %s\nCNPJ: %s\nAdress: %s\nSold: %i\nReserved: %i\nTable 0: %c %i\nTable 1: %c %i\nTable 2: %c %i\n", p1->regloja, p1->nome, p1->CNPJ, p1->end.logradouro, p1->sold, p1->reserved, p1->tabela[0].reservado.sigla, p1->tabela[0].reservado.regcarro, p1->tabela[1].reservado.sigla, p1->tabela[1].reservado.regcarro, p1->tabela[2].reservado.sigla, p1->tabela[2].reservado.regcarro);
        }// Else - Data OK
    }
    fclose(fptr);
    printf("\n\n\n");
    system("pause");
    system("cls");
}// Function show_store

void show_CNPJ(loja *p1, int tam, char aux[19])//USAR A FUNCAO BUSCA
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
    printf("Write wanted CNPJ number: \n");
    fflush(stdin);
    gets(aux);
    fflush(stdin);
        
    do
    {
        if (i==tam)
        {
            break;
        }// If - Stop Loop
        fseek(fptr, i*sizeof(loja), 0);
        fread(p1, sizeof(loja), 1,  fptr);
        i++;
    }while(strcmp(aux, p1->CNPJ)!=0);

   
    if(strcmp(aux, p1->CNPJ)==0)
    {
        if(p1->reserved==0)
        {  
            printf("Name: %s\tSold: %i\tReserved: %i", p1->nome, p1->sold, p1->reserved);
        }
        else if (p1->reserved==1)
        {
            printf("Name: %s\tSold: %i\tReserved: %i\tTable 0: %c - %i", p1->nome, p1->sold, p1->reserved, p1->tabela[0].reservado.sigla, p1->tabela[0].reservado.regcarro);
        }
        else if (p1->reserved==2)
        {
            printf("Name: %s\tSold: %i\tReserved: %i\tTable 0: %c - %i\tTable 1: %c - %i", p1->nome, p1->sold, p1->reserved, p1->tabela[0].reservado.sigla, p1->tabela[0].reservado.regcarro, p1->tabela[1].reservado.sigla, p1->tabela[1].reservado.regcarro);
        }
        else
        {
            printf("Name: %s\tSold: %i\tReserved: %i\tTable 0: %c - %i\tTable 1: %c - %i\tTable 2: %c - %i", p1->nome, p1->sold, p1->reserved, p1->tabela[0].reservado.sigla, p1->tabela[0].reservado.regcarro, p1->tabela[1].reservado.sigla, p1->tabela[1].reservado.regcarro, p1->tabela[2].reservado.sigla, p1->tabela[2].reservado.regcarro);
        }
    }// If - aux = p1->CNPJ
    else
    {
        printf("No matching found");
    }// Else - No matching
    fclose(fptr);
    printf("\n\n\n");
    system("pause");
    system("cls");
}// Function show_CNPJ

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
    save_car(p2, "ab", 0);
}//Function register_car

void save_car(montadora *p2, char *str, int pos)
{
    FILE *fptr=NULL;
    if((fptr=fopen("carro.bin",str))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR
    else
    {
        if(strcmp(str, "rb+")==0)
        {
            fseek(fptr, pos*sizeof(montadora),0);
        }
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
    //fseek(fptr, i*sizeof(montadora), 0);
  	//fread(p2, sizeof(montadora), 1, fptr);
    for(i=0; i<qtt; i++)
    {
        fseek(fptr, i*sizeof(montadora), 0);
  	    fread(p2, sizeof(montadora), 1, fptr);
  	    if(p2->status.sigla == 'L')
  	    {
  	  	    printf("\nRegister: %i\nModel: %s\nColor: %s\nPrice: %.2f\nStatus: %c\n", p2->regcarro, p2->modelo, p2->cor, p2->valor, p2->status.sigla);
	    }// If - Data OK and Status.Sigla == L
        else
        {
            printf("\nRegister: %i\nModel: %s\nColor: %s\nPrice: %.2f\nStatus: %c %s\n", p2->regcarro, p2->modelo, p2->cor, p2->valor, p2->status.reserva.sigla, p2->status.reserva.CNPJ);
        }// Else - Data OK
    }// For - Show Data
    fclose(fptr);
    printf("\n\n\n");
    system("pause");
    system("cls");
}// Function show_car

void show_car_model(montadora *p2, int qtt)
{
    int i = 0, a = 0;
    char aux[21];
    FILE *fptr=NULL;
    system("cls");
    if((fptr=fopen("carro.bin", "rb"))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR
    fseek(fptr, i*sizeof(montadora), 0);
    fread(p2, sizeof(montadora), 1,  fptr);
    printf("Write wanted model name: \n");
    fflush(stdin);
    gets(aux);
    fflush(stdin);
do_model:
    do
    {
        if (i == qtt)
        {
            break;
        }// If - Stop Loop
        fseek(fptr, i*sizeof(montadora), 0);
        fread(p2, sizeof(montadora), 1,  fptr);
        i++;
    } 
    while (strcmp(aux, p2->modelo) != 0);
    {
    if (strcmp(aux, p2->modelo) == 0)
        {
            printf("\nRegister: %i\nModel: %s\nColor: %s\nPrice: %.2f\nStatus: %c\n", p2->regcarro, p2->modelo, p2->cor, p2->valor, p2->status.sigla);
            if (i != qtt)
            {
                a = 1;
                goto do_model;
            }
        }
    }
    
    if (strcmp(aux, p2->modelo) != 0 && a != 1)
    {
        printf("Can't found model\n");
    }
    fclose(fptr);
    system("pause");
    system("cls");
}

void show_car_status(montadora *p2, int qtt)
{
    int i=0;
    char aux;
    FILE *fptr=NULL;
    system("cls");
    if((fptr=fopen("carro.bin", "rb"))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR
    fseek(fptr, i*sizeof(montadora), 0);
  	fread(p2, sizeof(montadora), 1, fptr);
    do
    {
        printf("Write wanted car status [L][R]: \n");
        fflush(stdin);
        scanf("%c", &aux);
        fflush(stdin);
    }while(aux != 'L' && aux != 'R');
    if(aux=='L')
    {
        do_status:
            do
            {
                if (i == qtt)
                {
                    break;
                }// If - Stop Loop
                fseek(fptr, i*sizeof(montadora), 0);
                fread(p2, sizeof(montadora), 1,  fptr);
                i++;
        }
        while (p2->status.sigla != 'L');

            
            if(p2->status.sigla == 'L')
            {
                printf("\nRegister: %i\nModel: %s\nColor: %s\nPrice: %.2f\nStatus: %c\n", p2->regcarro, p2->modelo, p2->cor, p2->valor, p2->status.sigla);
                if (i != qtt)
                {
                    goto do_status;
                }
            }// If - Data OK and Status.Sigla == L
    }
    else if(aux=='R')
    {
        do_status1:
        do
        {
            if (i == qtt)
            {
                break;
            }// If - Stop Loop
            fseek(fptr, i*sizeof(montadora), 0);
            fread(p2, sizeof(montadora), 1,  fptr);
            i++;
        }while(p2->status.reserva.sigla != 'R');
            if(p2->status.reserva.sigla == 'R')
            {
                printf("\nRegister: %i\nModel: %s\nColor: %s\nPrice: %.2f\nStatus: %c %s\n", p2->regcarro, p2->modelo, p2->cor, p2->valor, p2->status.reserva.sigla, p2->status.reserva.CNPJ);
                if (i != qtt)
                {
                    goto do_status1;
                }
            }//if
    }
    fclose(fptr);
    
    
    
}// Function show_car

int search_store(loja *p1, char reg[19], int qtt)
{
FILE *fptr=NULL;
int achou=-1, i;
system("cls");
if((fptr=fopen("concessionaria.bin","rb"))==NULL)
  printf("\nErro");
else
  {
  	for(i=0;i<qtt;i++)
  	  {
  	  	fseek(fptr,i*sizeof(loja),0);
  	  	fread(p1,sizeof(loja),1,fptr);
  	  	if(strcmp(p1->CNPJ, reg) == 0)
  	  	  {
  	  	  	achou=i;
  	  	  	i=qtt;
		  }//if
	  }//for
  fclose(fptr);  
  }//else
return achou;
}//busca

int search_car(montadora *p2, int reg, int qtt)
{
FILE *fptr=NULL;
int achou=-1, i;
system("cls");
if((fptr=fopen("carro.bin","rb"))==NULL)
    printf("\nErro");
else
{
  	for(i=0;i<qtt;i++)
  	{
  	  	fseek(fptr,i*sizeof(montadora),0);
  	  	fread(p2,sizeof(montadora),1,fptr);
  	  	if(p2->regcarro == reg)
  	  	{
  	  	    achou=i;
  	  	  	i=qtt;
		}//if
	}//for
    fclose(fptr);  
}//else
return achou;
}//busca

void reserv(loja *p1, montadora *p2, int qtt_car, int qtt_str)
{
    int i_store = 0, i_car = 0, aux_reg;
    char CNPJ[19], op;
    FILE *fptr1=NULL;
    FILE *fptr2=NULL;
    system("cls");
inicial_switch:
    printf("Do you wish to see available cars?[s][n]\n");
    fflush(stdin);
    scanf("%c", &op);
    fflush(stdin);
    
    switch (toupper(op))
    {
        case 'S':
            show_car_status(p2, qtt_car);
            system("pause");
            system("cls");
            break;

        case 'N':
            break;
    default:
        printf("\nType a valid option [s][n]\n");
        system("pause");
        
        goto inicial_switch;
    }
if((fptr1=fopen("concessionaria.bin","rb"))==NULL)
    printf("\nErro");
register_CNPJ:
    printf("Type CNPJ: \n");
    gets(CNPJ);
    i_store = search_store(p1, CNPJ, qtt_str);

    if(i_store == -1)
    {
        printf("\nType an existing CNPJ\n");
        system("pause");
        system("cls");
        goto register_CNPJ;
    }
    if((fptr2=fopen("carro.bin","rb"))==NULL)
    printf("\nErro");
    if(p1->reserved <= 2)
    {
    register_number:
        printf("Number of register:\n");
        scanf("%i", &aux_reg);
        i_car = search_car(p2, aux_reg, qtt_car);
        printf("%i\n", i_car);
        system("pause");
        if(i_car == -1)
        {
            printf("\nType an existing register number");
            system("pause");
            system("cls");
            goto register_number;
        }
        fseek(fptr1,i_store*sizeof(loja),0);
	    fread(p1,sizeof(loja),1,fptr1);
        fseek(fptr2,i_car*sizeof(montadora),0);
	    fread(p2,sizeof(montadora),1,fptr2);
        if(p2->regcarro == aux_reg)
        {
            printf("teste1\n");
            if(p2->status.sigla != 'R')
            {
                printf("%c", p2->status.sigla);
                printf("teste2\n");
                system("pause");
                (p1->reserved)++;
                //strcpy(p2->status.sigla, 'R');
                //p2->status.sigla = 'R';
                p2->status.reserva.sigla = 'R';
                strcpy(p2->status.reserva.CNPJ, p1->CNPJ);
                //p2->status.reserva.CNPJ = p1->CNPJ;
                for (size_t i = 0; i < 3; i++)
                {
                    if(p1->tabela[i].reservado.sigla !='R')
                    {
                        p1->tabela[i].reservado.sigla ='R';
                        p1->tabela[i].reservado.regcarro = p2->regcarro;
                        save_store(p1, "rb+", i_store);
                        save_car(p2, "rb+", i_car);
                        i=3;
                    }
                }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
    }
    else
    {
        printf("Maximum number of cars reserved");
        system("pause");
    }
}
/*
FUNÇÃO COM ERRO. APÓS O TÉRMINO DA RESERVA,
FUNÇÃO ESTÁ DELETANDO UM DOS REGISTROS.
*/
void finish_reserv(loja *p1, montadora *p2, int qtt_car, int qtt_str)
{
    int i_store = 0, i_car = 0, aux_reg, cont, i=0;
    char op;
    FILE *fptr1=NULL;
    FILE *fptr2=NULL;
    system("cls");
    if((fptr2=fopen("carro.bin","rb"))==NULL)
    printf("\nErro");
    if((fptr1=fopen("concessionaria.bin","rb"))==NULL)
    printf("\nErro");
    if(p1->reserved <= 2)
    {
    register_number1:
        printf("Number of register:\n");
        scanf("%i", &aux_reg);
        i_car = search_car(p2, aux_reg, qtt_car);
        printf("%i\n", i_car);
        system("pause");
        if(i_car == -1)
        {
            printf("\nType an existing register number");
            system("pause");
            system("cls");
            goto register_number1;
        }
    }
    fseek(fptr2,i_car*sizeof(montadora),0);
	fread(p2,sizeof(montadora),1,fptr2);

    

    for ( i = 0; i < qtt_str; i++)
    {
        if(strcmp(p2->status.reserva.CNPJ, p1->CNPJ)==0)
        {
            i_store=i;
            break;
        }
    }
    fseek(fptr1,i_store*sizeof(loja),0);
	fread(p1,sizeof(loja),1,fptr1);
    //verify_reserved:
    if(p2->status.sigla=='R')
    {
        printf("Will the chosen car be [s]old or [r]eleased\n");
        fflush(stdin);
        scanf("%c", &op);
        fflush(stdin);
        switch (toupper(op))
        {
            case 'S':
                strcpy(p2->modelo, "vago");
                strcpy(p2->cor, "vago");
                p2->valor = 0;
                p2->status.sigla = 'L';
                (p1->reserved)--;
                (p1->sold)++;
                for (size_t i = 0; i < 3; i++)
                {
                    if((p1->tabela+i)->reservado.sigla =='R')
                    {
                        (p1->tabela+i)->sigla ='L';
                        (p1->tabela+i)->reservado.regcarro = p2->regcarro;
                        i=3;
                    }
                }
                break;
            case 'R':
                p2->status.sigla = 'L';
                p1->reserved--;
                for (size_t i = 0; i < 3; i++)
                {
                    if((p1->tabela+i)->reservado.sigla =='R')
                    {
                        (p1->tabela+i)->sigla ='L';
                        (p1->tabela+i)->reservado.regcarro = p2->regcarro;
                        i=3;
                    }
                }
                break;
        }
        save_store(p1, "rb+", i_store);
        save_car(p2, "rb+", i_car);
    }
    else
    {
        printf("\n Selected car is free\n");
        system("pause");
    }
    fclose(fptr1);
    fclose(fptr2);
}