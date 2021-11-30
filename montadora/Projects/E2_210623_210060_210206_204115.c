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

void alloc_store(loja **p1, int tam);//Line 382
int verify_store();//Line 392
void register_store(loja *p1, int tam);//Line 409
void save_store(loja *p1, char *str, int pos);//Line 461
void show_store(loja *p1, int qtt);//Line 479
void show_CNPJ(loja *p1, int tam, char aux[19]);//Line 521
int search_store(loja *p1, char reg[19], int qtt);//Line 562
void change_store(loja *p1, int qtt);//Line 586

void alloc_car(montadora **p2, int tam);//Line 372
int  verify_car();//Line 382
void register_car(montadora *p2, int tam);//Line 399
void save_car(montadora *p2, char *str, int pos);//Line 421
void show_car(montadora *p2, int qtt);//Line 435
void show_car_model(montadora *p2, int qtt);//Line 740
void show_car_status(montadora *p2, int qtt);//Line 801
int search_car(montadora *p2, int reg, int qtt);//Line 870
void change_car(montadora *p2, int qtt);//Line 894

void reserv(loja *p1, montadora *p2, int qtt_car, int qtt_str);//Line 947
void finish_reserv(loja *p1, montadora *p2, historicoVendas *p3, int qtt_car, int qtt_str, int qtt_hist, char *cnpj, int regcarro);//Line 1039

void alloc_history(historicoVendas **p3, int tam);//Line 1174
int verify_history();//Line 1184
void register_history(historicoVendas *p3, montadora *p2, loja *p1, int qtt_hist, int qtt_str, int qtt_car, char *cnpj, int regcarro, int bckp_regcar, char *bckp_model, char *bckp_color, float bckp_valor, int bckp_regstr, char *bckp_name, char *bckp_cnpj);//Line 1201
void save_history(historicoVendas *p3, char *str, int pos);//Line 1252
void show_history_CNPJ(historicoVendas *p3, int qtt);//Line 1270
void show_history_model(historicoVendas *p3, int qtt);//Line 1303

int main()
{
    loja *ps=NULL;
    montadora *pc=NULL;
    historicoVendas *ph=NULL;
    alloc_store(&ps, 1);
    alloc_car(&pc, 1);
    alloc_history(&ph, 1);
    char aux[19];
    int qtt=0, qtt1=0, qtt2=0, qtt3=0, menu_base, menu_store, menu_assembler, menu_check_store, menu_reserv, menu_check_car, menu_history, menu_change;
menu_base:
    printf("[1] - Store\n[2] - Car\n[3] - Manage Car Reservation\n[4] - History\n[5] - Change Registration\n[0] - Exit\n");
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
                qtt2 = verify_history();
                finish_reserv(ps, pc, ph, qtt, qtt1, qtt2, aux, qtt3);
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

        case 4:
        menu_history:
            system("cls");
            printf("[1] - search by CNPJ\n[2] - Search by model\n[0] - Back\n");
            scanf("%i", &menu_history);
            fflush(stdin);
            switch (menu_history)
            {
                case 1:
                    qtt2 = verify_history();
                    show_history_CNPJ(ph, qtt2);
                goto menu_history;

                case 2:
                    qtt2 = verify_history();
                    show_history_model(ph, qtt2);
                goto menu_history;

                case 0:
                system("cls");
            goto menu_base;

                default:
                    system("cls");
                    printf("Invalid Option");
                    system("pause");
                    system("cls");
                goto menu_history;
            }

        case 5:
        menu_change:
            system("cls");
            printf("[1] - Change Store Registration\n[2] - Change Car Registration\n[0] - Back\n");
            scanf("%i", &menu_change);
            fflush(stdin);
            switch (menu_change)
            {
                case 1:
                    system("cls");
                    qtt = verify_store();
                    change_store(ps, qtt);
                goto menu_change;

                case 2:
                    system ("cls");
                    qtt = verify_car();
                    change_car(pc, qtt);
                goto menu_change;

                case 0:
                    system("cls");
                goto menu_base;

            default:
                    system("cls");
                    printf("Invalid Option");
                    system("pause");
                    system("cls");
                goto menu_history;
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
}// main

void alloc_store(loja **p1, int tam)
{
    if((*p1=(loja*)realloc(*p1,tam*sizeof(loja)))==NULL)
    {
        printf("Not able to alloc");
        system("pause");
        exit(1);
    }
}//alloc_store

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
}//verify_store

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
    save_store(p1, "ab", 0);
}//register_store

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
}//save_store

void show_store(loja *p1, int qtt)
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
            printf("\nRegister: %i\nName: %s\nCNPJ: %s\nAdress: %s\nSold: %i\nReserved: %i", p1->regloja, p1->nome, p1->CNPJ, p1->end.logradouro, p1->sold, p1->reserved);
            for (size_t j = 0; j < 3; j++)
            {
                if (p1->tabela[j].reservado.sigla == 'L')
                {
                    printf("\nTable %i: %c", j, p1->tabela[j].reservado.sigla);
                }
                else
                {
                    printf("\nTable %i: %c %i", j, p1->tabela[j].reservado.sigla, p1->tabela[j].reservado.regcarro);
                }
            }
            printf("\n");
        }// Else - Data OK
    }
    fclose(fptr);
    printf("\n\n\n");
    system("pause");
    system("cls");
}//show_store

void show_CNPJ(loja *p1, int tam, char aux[19])//USAR A FUNCAO BUSCA
{
    int i_store;
    FILE *fptr=NULL;
    system("cls");
    if((fptr=fopen("concessionaria.bin", "rb"))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR
    
    
    printf("Write wanted CNPJ number: \n");
    fflush(stdin);
    gets(aux);
    fflush(stdin);
        
    
    i_store = search_store(p1, aux, tam);
    fseek(fptr, i_store*sizeof(loja), 0);
    fread(p1, sizeof(loja), 1,  fptr);
    if(strcmp(aux, p1->CNPJ)==0)
    {
        printf("Name: %s\tSold: %i\tReserved: %i", p1->nome, p1->sold, p1->reserved);
        for (size_t i = 0; i < 3; i++)
        {
            if (p1->tabela[i].reservado.sigla == 'R')
            {
                printf("\tTable %i: %c %i", i, p1->tabela[i].reservado.sigla, p1->tabela[i].reservado.regcarro);
            }    
        }
    }
    else
    {
        printf("No matching found");
    }// Else - No matching
    fclose(fptr);
    printf("\n\n\n");
    system("pause");
    system("cls");
}//show_CNPJ

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
}//search_store

void change_store(loja *p1, int qtt)
{
    int pos;
    char aux[19];
    FILE *fptr=NULL;
type_cnpj:
    printf("\nType store CNPJ: ");
    gets(aux);
    fflush(stdin);
    system("cls");
    if((fptr=fopen("concessionaria.bin", "rb"))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR
    pos=search_store(p1, aux, qtt);
    fseek(fptr, pos*sizeof(loja), 0);
    fread(p1, sizeof(loja), 1,  fptr);
    if(pos==-1)
        {
            system("cls");
            printf("type an existing CNPJ\n");
            system("pause");
            goto type_cnpj;
        }

        if(strcmp(aux, p1->CNPJ) == 0)
        {
            if(p1->reserved == 0)
            {  
                printf("\nRegister: %i\nName: %s\nAdress: %s\nSold: %i\nReserved: %i\nTable 0: %c\nTable 1: %c\nTable 2: %c\n", p1->regloja, p1->nome, p1->end.logradouro, p1->sold, p1->reserved, p1->tabela[0].sigla, p1->tabela[1].sigla, p1->tabela[2].sigla);
            }
            else if (p1->reserved == 1)
            {
                printf("\nRegister: %i\nName: %s\nAdress: %s\nSold: %i\nReserved: %i\nTable 0: %c %i\nTable 1: %c\nTable 2: %c\n", p1->regloja, p1->nome, p1->end.logradouro, p1->sold, p1->reserved, p1->tabela[0].reservado.sigla, p1->tabela[0].reservado.regcarro, p1->tabela[1].reservado.sigla, p1->tabela[2].reservado.sigla);
            }
            else if (p1->reserved == 2)
            {
                printf("\nRegister: %i\nName: %s\nAdress: %s\nSold: %i\nReserved: %i\nTable 0: %c %i\nTable 1: %c %i\nTable 2: %c\n", p1->regloja, p1->nome, p1->end.logradouro, p1->sold, p1->reserved, p1->tabela[0].reservado.sigla, p1->tabela[0].reservado.regcarro, p1->tabela[1].reservado.sigla, p1->tabela[1].reservado.regcarro, p1->tabela[2].reservado.sigla);
            }
            if (p1->reserved == 3)
            {
                printf("\nRegister: %i\nName: %s\nAdress: %s\nSold: %i\nReserved: %i\nTable 0: %c %i\nTable 1: %c %i\nTable 2: %c %i\n", p1->regloja, p1->nome, p1->end.logradouro, p1->sold, p1->reserved, p1->tabela[0].reservado.sigla, p1->tabela[0].reservado.regcarro, p1->tabela[1].reservado.sigla, p1->tabela[1].reservado.regcarro, p1->tabela[2].reservado.sigla, p1->tabela[2].reservado.regcarro);
            }
        }// If - aux = p1->CNPJ]
    printf("\n\n\n");
    system("pause");
    system("cls");
    printf("\nNew name: ");
    gets(p1->nome);
    fflush(stdin);
    printf("\nNew CNPJ: ");
    gets(p1->CNPJ);
    fflush(stdin);
    save_store(p1,"rb+",pos);
    printf("\nSuccess\n");
    system("pause");
    fclose(fptr);
}//change_store

void alloc_car(montadora **p2, int tam)
{
    if((*p2=(montadora*)realloc(*p2,tam*sizeof(montadora)))==NULL)
    {
        printf("Not able to alloc");
        system("pause");
        exit(1);
    }
}//alloc_car

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
}//verify_car

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
}//register_car

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
}//save_car

void show_car(montadora *p2, int qtt)
{
    int i=0;
    FILE *fptr=NULL;
    system("cls");
    if((fptr=fopen("carro.bin", "rb"))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR
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
}//show_car

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
            if(p2->status.sigla == 'L')
            {
                printf("\nRegister: %i\nModel: %s\nColor: %s\nPrice: %.2f\nStatus: %c\n", p2->regcarro, p2->modelo, p2->cor, p2->valor, p2->status.sigla);
                if (i != qtt)
                {
                    a = 1;
                    goto do_model;
                }
            }
            else if (p2->status.reserva.sigla == 'R')
            {
               printf("\nRegister: %i\nModel: %s\nColor: %s\nPrice: %.2f\nStatus: %c %s\n", p2->regcarro, p2->modelo, p2->cor, p2->valor, p2->status.reserva.sigla, p2->status.reserva.CNPJ);
               if (i != qtt)
                {
                    a = 1;
                    goto do_model;
                }
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
}//show_car_model

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
}//show_car

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
}//search_car

void change_car(montadora *p2, int qtt)
{
    int pos, aux;
    FILE *fptr=NULL;
type_regCar:
    printf("\nType Car Register: ");
    scanf("%i", &aux);
    fflush(stdin);
    system("cls");
    if((fptr=fopen("carro.bin", "rb"))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR
    pos=search_car(p2, aux, qtt);
    fseek(fptr, pos*sizeof(montadora), 0);
    fread(p2, sizeof(montadora), 1,  fptr);
    if(pos==-1)
        {
            system("cls");
            printf("type an existing Car register\n");
            system("pause");
            goto type_regCar;
        }

        if(aux == p2->regcarro)
        {
           if(p2->status.sigla == 'L')
           {
               printf("\nModel: %s\nColor: %s\nPrice: %.2f\nStatus: %c\n", p2->modelo, p2->cor, p2->valor, p2->status.sigla);
           }
           else if (p2->status.reserva.sigla == 'R')
           {
               printf("\nModel: %s\nColor: %s\nPrice: %.2f\nStatus: %c %s\n", p2->modelo, p2->cor, p2->valor, p2->status.reserva.sigla, p2->status.reserva.CNPJ);
           }
        }// If - aux = p1->CNPJ]
    printf("\n\n\n");
    system("pause");
    system("cls");
    printf("\nNew model: ");
    gets(p2->modelo);
    fflush(stdin);
    printf("\nNew color: ");
    gets(p2->cor);
    fflush(stdin);
    printf("\nNew price: ");
    scanf("%f", &(p2->valor));
    fflush(stdin);
    save_car(p2,"rb+",pos);
    printf("\nSuccess\n");
    system("pause");
    fclose(fptr);
}//change_store

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
            if(p2->status.sigla != 'R')
            {
                (p1->reserved)++;
                p2->status.reserva.sigla = 'R';
                strcpy(p2->status.reserva.CNPJ, p1->CNPJ);
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
}//reserv

void finish_reserv(loja *p1, montadora *p2, historicoVendas *p3, int qtt_car, int qtt_str, int qtt_hist, char *cnpj, int regcarro)
{
    int bckp_regcar, bckp_regstr, i_store = 0, i_table=0, i_car = 0, aux_reg, i=0;
    float bckp_valor;
    char bckp_model[20], bckp_color[10], bckp_name[30], bckp_cnpj[19], op;
    FILE *fptr1=NULL;
    FILE *fptr2=NULL;
    FILE *fptr3=NULL;
    system("cls");
    if((fptr1=fopen("concessionaria.bin","rb"))==NULL)
        printf("\nError\n");
    if((fptr2=fopen("carro.bin","rb"))==NULL)
        printf("\nError\n");
    if((fptr3=fopen("historico.bin","rb"))==NULL)
        printf("\nInexisting History\n");
    if(p1->reserved <= 2)
    {
    register_number1:
        printf("Number of register:\n");
        scanf("%i", &aux_reg);
        fflush(stdin);
        i_car = search_car(p2, aux_reg, qtt_car);
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

    system("cls");


    for ( i = 0; i < qtt_str; i++)
    {
        fseek(fptr1,i*sizeof(loja),0);
        fread(p1,sizeof(loja),1,fptr1);
        if(strcmp(p2->status.reserva.CNPJ, p1->CNPJ)==0)
        {
            i_store=i;
            break;
        }
    }
    fseek(fptr1,i_store*sizeof(loja),0);
	fread(p1,sizeof(loja),1,fptr1);
    if(p2->status.sigla=='R')
    {
        printf("Will the chosen car be [s]old or [r]eleased\n");
        fflush(stdin);
        scanf("%c", &op);
        fflush(stdin);
        switch (toupper(op))
        {
            case 'S':
            {
                for ( i = 0; i <= 2; i++)
                {
                    if(p1->tabela[i].reservado.regcarro == p2->regcarro)
                    {
                        i_table=i;
                        break;
                    }
                }
                strcpy(bckp_name, p1->nome);
                strcpy(bckp_model, p2->modelo);
                strcpy(bckp_cnpj, p1->CNPJ);
                strcpy(cnpj, p1->CNPJ);
                strcpy(bckp_color, p2->cor);
                bckp_regstr = p1->regloja;
                bckp_valor = p2->valor;
                bckp_regcar = p2->regcarro;
                regcarro = p2->regcarro;
                strcpy(p2->modelo, "vago");
                strcpy(p2->cor, "vago");
                p2->valor = 0;
                p2->status.reserva.sigla = 'L';
                p2->status.sigla = 'L';
                (p1->reserved)--;
                (p1->sold)++;
                for (size_t i = 0; i < 3; i++)
                {
                    if((p1->tabela+i_table)->reservado.sigla =='R')
                    {
                        (p1->tabela+i_table)->sigla ='L';
                        (p1->tabela+i_table)->reservado.regcarro = p2->regcarro;
                        i=3;
                    }
                }
                save_store(p1, "rb+", i_store);
                save_car(p2, "rb+", i_car);
                register_history(p3, p2, p1, qtt_hist, qtt_str, qtt_car, cnpj, regcarro, bckp_regcar, bckp_model, bckp_color, bckp_valor, bckp_regstr, bckp_name, bckp_cnpj);
            break;
            }
            
            case 'R':
            {
                for ( i = 0; i <= 2; i++)
                {
                    if(p1->tabela[i].reservado.regcarro == p2->regcarro)
                    {
                        i_table=i;
                        break;
                    }
                }
                p2->status.reserva.sigla = 'L';
                p2->status.sigla = 'L';
                (p1->reserved)--;
                for (size_t i = 0; i < 3; i++)
                {
                    if((p1->tabela+i_table)->reservado.sigla =='R')
                    {
                        (p1->tabela+i_table)->sigla ='L';
                        (p1->tabela+i_table)->reservado.regcarro = p2->regcarro;
                        i=3;
                    }
                }
                save_store(p1, "rb+", i_store);
                save_car(p2, "rb+", i_car);
            break;
            }
        }
    }
    else
    {
        printf("\n Selected car is free\n");
        system("pause");
    }
    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
}//finish_reserv

void alloc_history(historicoVendas **p3, int tam)
{
    if((*p3=(historicoVendas*)realloc(*p3,tam*sizeof(historicoVendas)))==NULL)
    {
        printf("Not able to alloc");
        system("pause");
        exit(1);
    }
}//function alloc_history

int verify_history()
{
    long int cont=0;
    FILE *fptr = NULL;
    if((fptr = fopen("historico.bin", "rb")) == NULL)
    {
        return cont;
    }// If - Case Data ERROR
    else
    {
        fseek(fptr,0,2);
  	    cont=ftell(fptr)/sizeof(historicoVendas);
  	    fclose(fptr);
  	    return cont;
    }// Else - Case Data OK
}//verify_history

void register_history(historicoVendas *p3, montadora *p2, loja *p1, int qtt_hist, int qtt_str, int qtt_car, char *cnpj, int regcarro, int bckp_regcar, char *bckp_model, char *bckp_color, float bckp_valor, int bckp_regstr, char *bckp_name, char *bckp_cnpj)
{
    int i1 = 0, i2 = 0, day, month, year;
    FILE *fptr1=NULL;
    FILE *fptr2=NULL;

    if((fptr1=fopen("concessionaria.bin", "rb"))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR

    if((fptr2=fopen("carro.bin", "rb"))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR

    i1 = search_store(p1, cnpj, qtt_str);
    i2 = search_car(p2, regcarro, qtt_car);

    fseek(fptr1, i1*sizeof(loja), 0);
  	fread(p1, sizeof(loja), 1, fptr1);
    fseek(fptr2, i2*sizeof(montadora), 0);
  	fread(p2, sizeof(montadora), 1, fptr2);

    p3->reghist=qtt_hist+1;
    p3->regcarro = bckp_regcar;
    strcpy(p3->modelo, bckp_model);
    strcpy(p3->cor, bckp_color);
    p3->valor = bckp_valor;
    p3->regloja = bckp_regstr;
    strcpy(p3->nome, bckp_name);
    printf("Type date of sell\n");
    strcpy(p3->cnpj, bckp_cnpj);
    printf("\nDay: ");
    scanf("%i", &day);
    fflush(stdin);
    printf("\nMonth: ");
    scanf("%i", &month);
    fflush(stdin);
    printf("\nYear: ");
    scanf("%i", &year);
    fflush(stdin);
    p3->dataVenda.dia = day;
    p3->dataVenda.mes = month;
    p3->dataVenda.ano = year;
    
    save_history(p3, "ab", 0);
    fclose(fptr1);
    fclose(fptr2);
}//register_history

void save_history(historicoVendas *p3, char *str, int pos)
{
    FILE *fptr=NULL;
    if((fptr=fopen("historico.bin", str))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR
    else
    {
        if(strcmp(str, "rb+")==0)
        {
            fseek(fptr, pos*sizeof(historicoVendas), 0);
        }
        fwrite(p3, sizeof(historicoVendas), 1, fptr);
    }// Else - Data OK
    fclose(fptr);
}//save_history

void show_history_CNPJ(historicoVendas *p3, int qtt)
{
    int i=0, a=0;
    char cnpj[19];
    FILE *fptr=NULL;
    system("cls");
    if((fptr=fopen("historico.bin", "rb"))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR
    printf("\nType CNPJ: \n");
    gets(cnpj);
    for(i=0; i<qtt; i++)
    {
        fseek(fptr, i*sizeof(historicoVendas), 0);
  	    fread(p3, sizeof(historicoVendas), 1, fptr);
  	    if(strcmp(p3->cnpj, cnpj) == 0)
  	    {
  	  	    printf("\nRegister History: %i\nRegister Car: %i\nModel: %s\nColor: %s\nPrice: %.2f\nregloja: %i\nName: %s\nCNPJ %s\nData: %i/%i/%i\n", p3->reghist, p3->regcarro, p3->modelo, p3->cor, p3->valor, p3->regloja, p3->nome, p3->cnpj, p3->dataVenda.dia, p3->dataVenda.mes, p3->dataVenda.ano);
            a=1;
	    }// If - Data OK and Status.Sigla == L
        
    }// For - Show Data
    if(a != 1)
    {
        printf("CNPJ can't be found");
    }
    fclose(fptr);
    printf("\n\n\n");
    system("pause");
    system("cls");
}//show_history_CNPJ

void show_history_model(historicoVendas *p3, int qtt)
{
    int i=0, a=0;
    char model[19];
    FILE *fptr=NULL;
    system("cls");
    if((fptr=fopen("historico.bin", "rb"))==NULL)
    {
        printf("\nError to open archive");
    }// If - Data ERROR
    printf("\nType car model: \n");
    gets(model);
    for(i=0; i<qtt; i++)
    {
        fseek(fptr, i*sizeof(historicoVendas), 0);
  	    fread(p3, sizeof(historicoVendas), 1, fptr);
  	    if(strcmp(p3->modelo, model) == 0)
  	    {
  	  	    printf("\nRegister History: %i\nRegister Car: %i\nModel: %s\nColor: %s\nPrice: %.2f\nregloja: %i\nName: %s\nCNPJ %s\nData: %i/%i/%i\n", p3->reghist, p3->regcarro, p3->modelo, p3->cor, p3->valor, p3->regloja, p3->nome, p3->cnpj, p3->dataVenda.dia, p3->dataVenda.mes, p3->dataVenda.ano);
            a=1;
	    }// If - Data OK and Status.Sigla == L
        
    }// For - Show Data
    if(a != 1)
        {
            printf("model can't be found");
        }
    fclose(fptr);
    printf("\n\n\n");
    system("pause");
    system("cls");
}//show_history_model