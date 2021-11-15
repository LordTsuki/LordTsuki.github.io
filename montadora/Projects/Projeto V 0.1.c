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

void aloc_store(loja **p1, int tam);
void register_store(loja *p1, int tam);
void save_store(loja *p1);
void show_store(loja *p1, int qtde);
int verify_store();

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
    int qtt, menu_base, menu_store, menu_assembler;
menu_base:
    printf("1 - store\n2 - Assembler\n0 - Exit\n");
    scanf("%i", &menu_base);
    fflush(stdin);
    switch (menu_base)
    {
        case 1:
            system("cls");
            printf("1 - Register\n2 - Check\n0 - Back\n");
            scanf("%i", &menu_store);
            fflush(stdin);
            switch (menu_store)
            {
                case 1:
                    system("cls");
                    aloc_store(&ps, 1);
                    qtt = verify_store();
                    if(qtt < 5)
                    {
                        register_store(ps, qtt+1);
                        qtt++;
                    }
                    else
                    {
                        printf("Maximum of five stores reached.");
                        goto menu_base;
                    }
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

                case 2://realizar consulta atraves do CPNJ
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

void aloc_store(loja **p1, int tam)
{
if((*p1=(loja*)realloc(*p1,tam*sizeof(loja)))==NULL)
  exit(1);
}//aloca

int verify_store()
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
  	    fclose(fptr);
  	    return cont;
    }//else
}//verify_store

void register_store(loja *p1, int tam)
{
    int i;
    p1->regloja=tam;
    system("cls");
    printf("\nRegistro: %i",p1->regloja);
    system("cls");
    printf("\nNome da concessionaria: \n");
    gets(p1->nome);
    fflush(stdin);
    system("cls");
    printf("CNPJ: \n");
    gets(p1->CNPJ);
    fflush(stdin);
    system("cls");
    printf("Logradouro:\n");
    gets(p1->end.logradouro);
    fflush(stdin);
    system("cls");
    printf("bairro:\n");
    gets(p1->end.bairro);
    fflush(stdin);
    system("cls");
    printf("CEP:\n");
    gets(p1->end.CEP);
    fflush(stdin);
    system("cls");
    printf("cidade:\n");
    gets(p1->end.cidade);
    fflush(stdin);
    system("cls");
    printf("estado:\n");
    gets(p1->end.estado);
    fflush(stdin);
    system("cls");
    printf("telefone:\n");
    gets(p1->end.fone);
    fflush(stdin);
    system("cls");
    printf("e-mail:\n");
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
}//register_store

void save_store(loja *p1)
{
    FILE *fptr=NULL;
    if((fptr=fopen("concessionaria.bin","ab"))==NULL)
    {
        printf("\nErro ao abrir o arquivo");
    }
    else
    {
        fwrite(p1,sizeof(loja),1,fptr);
    }
    fclose(fptr);
}//save_store

/*typedef struct loja
{ 
    int regloja;
    char nome[30];
    char CNPJ[19];
    endereco end;
    int sold;
    int reserved;
    dadoscarro tabela[3]; 
}loja;
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





















