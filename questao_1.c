#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Arv23 Arv23;

struct Arv23{
    char cod[7];
    char tipo[30];
    char marca[30];
    int tamanho;
    int quantidade;
    float preco;
    int pos;

    char cod2[7];
    char tipo2[20];
    char marca2[20];
    int tamanho2;
    int quantidade2;
    float preco2;
    int pos2;

    int NInfos;
    Arv23 *esq, *cen, *dir;
};

int ehFolha(struct Arv23 *R)
{ 
    return (R->cen == NULL && R->esq == NULL && R->dir == NULL);
}

// void preencheArq(){
//     Arv23 * NO;
//     FILE *arq = fopen("bt.txt", "a");
//     printf("cod: ");
//     scanf("%s",NO->cod);

//     printf("tipo: ");
//     scanf("%s",NO->tipo);

//     printf("marca: ");
//     scanf("%s",NO->marca);

//     printf("tamanho: ");
//     scanf("%d",NO->tamanho);

//     printf("quantidade: ");
//     scanf("%d",NO->quantidade);

//     printf("preco: ");
//     scanf("%f",NO->preco);

//     fprintf(arq,"%s %s %s %d %d %f\n", NO->cod, NO->tipo, NO->marca, NO->tamanho, NO->quantidade, NO->preco);
// }
struct Arv23 *criaNo(char *cod, char *tipo,char *marca, int tamanho, int quantidade, float preco,int pos, struct Arv23 *FEsq,struct Arv23 *FCen,struct Arv23 *FDir)
{
	struct Arv23 *No;
	
	No = (struct Arv23 *) malloc(sizeof(struct Arv23));
	
	// (*No).Info1 = valor;
    strcpy((*No).cod, cod);
    strcpy((*No).tipo, tipo);
    strcpy((*No).marca, marca);
    (*No).quantidade = quantidade;
    (*No).tamanho = tamanho;
    (*No).preco = preco;
    (*No).pos = pos;

	// (*No).Info2 = 0;
    strcpy((*No).cod2, "000000");
	(*No).NInfos = 1;
	(*No).esq = FEsq;
	(*No).cen = FCen;
	(*No).dir = FDir;
	
    return No;	
}
void adiciona(struct Arv23 **Raiz, char *cod, char *tipo,char *marca, int tamanho, int quantidade, float preco,int pos, struct Arv23 *MaiorNo)
{
    if(strcmp(cod, (*Raiz)->cod) > 0)
	{ 
        // (*Raiz)->Info2 = Valor;
        strcpy((*Raiz)->cod2 ,cod);
        strcpy((*Raiz)->tipo2,tipo);
        strcpy((*Raiz)->marca2,marca);
        (*Raiz)->tamanho2 = tamanho;
        (*Raiz)->quantidade2 = quantidade;
        (*Raiz)->preco2 = preco;
        (*Raiz)->pos2 = pos;
        (*Raiz)->dir = MaiorNo;
	}	
	else {
		// (*Raiz)->Info2 = (*Raiz)->Info1;
        strcpy((*Raiz)->cod2 ,(*Raiz)->cod);
        strcpy((*Raiz)->tipo2,(*Raiz)->tipo);
        strcpy((*Raiz)->marca2,(*Raiz)->marca);
        (*Raiz)->tamanho2 = (*Raiz)->tamanho;
        (*Raiz)->quantidade2 = (*Raiz)->quantidade;
        (*Raiz)->preco2 = (*Raiz)->preco;
        (*Raiz)->pos2 = (*Raiz)->pos;

		// (*Raiz)->Info1 = Valor;
        strcpy((*Raiz)->cod ,cod);
        strcpy((*Raiz)->tipo,tipo);
        strcpy((*Raiz)->marca,marca);
        (*Raiz)->tamanho = tamanho;
        (*Raiz)->quantidade = quantidade;
        (*Raiz)->preco = preco;
        (*Raiz)->pos = pos;

		(*Raiz)->dir = (*Raiz)->cen;
		(*Raiz)->cen = MaiorNo;
	}
	
	(*Raiz)->NInfos = 2;
}
struct Arv23 *quebraNo(struct Arv23 **Raiz,char cod[], char tipo[], char marca[], int tamanho, int quantidade, float preco, int pos,char *sobecod, char *sobetipo, char *sobemarca, int *sobetamanho, int *sobequantidade, float *sobepreco, int *sobepos, struct Arv23 *MaiorNo)
{ 
    struct Arv23 *Novo;
    if(strcmp(cod, (*Raiz)->cod) < 0)
    {
        // *sobe = (*Raiz)->Info1;
        strcpy(sobecod, (*Raiz)->cod);
        strcpy(sobetipo, (*Raiz)->tipo);
        strcpy(sobemarca, (*Raiz)->marca);
        *sobetamanho = (*Raiz)->tamanho;
        *sobequantidade = (*Raiz)->quantidade;
        *sobepreco = (*Raiz)->preco;
        *sobepos = (*Raiz)->pos;

        Novo = criaNo((*Raiz)->cod2,(*Raiz)->tipo2,(*Raiz)->marca2, (*Raiz)->tamanho2, (*Raiz)->quantidade2,(*Raiz)->preco,(*Raiz)->pos,(*Raiz)->cen,(*Raiz)->dir,NULL);
        // (*Raiz)->Info1 = valor;
        strcpy((*Raiz)->cod, cod);
        strcpy((*Raiz)->tipo, tipo);
        strcpy((*Raiz)->marca, marca);
        (*Raiz)->tamanho = tamanho;
        (*Raiz)->quantidade = quantidade;
        (*Raiz)->preco = preco;
        (*Raiz)->pos = pos;
        (*Raiz)->cen = MaiorNo;
        
    }
    // else if (valor < (*Raiz)->Info2) 	
    else if(strcmp(cod, (*Raiz)->cod2) < 0)
    {
        // *sobe = valor;
        strcpy(sobecod, cod);
        strcpy(sobetipo, tipo);
        strcpy(sobemarca, marca);
        *sobetamanho = tamanho;
        *sobequantidade = quantidade;
        *sobepreco = preco;
        *sobepos = pos;
        Novo = criaNo((*Raiz)->cod2, (*Raiz)->tipo2, (*Raiz)->marca2, (*Raiz)->tamanho2, (*Raiz)->quantidade2, (*Raiz)->preco2,(*Raiz)->pos2,MaiorNo,(*Raiz)->dir,NULL);
    }
    else{
        // *sobe = (*Raiz)->Info2;
        strcpy(sobecod, (*Raiz)->cod2);
        strcpy(sobetipo, (*Raiz)->tipo2);
        strcpy(sobemarca, (*Raiz)->marca2);
        *sobetamanho = (*Raiz)->tamanho2;
        *sobequantidade = (*Raiz)->quantidade2;
        *sobepreco = (*Raiz)->preco2;
        *sobepos = (*Raiz)->pos2;
        Novo = criaNo(cod, tipo, marca, tamanho, quantidade, preco,pos,(*Raiz)->dir,MaiorNo,NULL);
    }
    strcpy((*Raiz)->cod2, "000000");
    (*Raiz)->NInfos = 1;
    (*Raiz)->dir = NULL;

    return(Novo);	
}
struct Arv23 *inserirArv23(struct Arv23 *Pai, struct Arv23 **Raiz, char *cod, char *tipo, char *marca, int tamanho, int quantidade, float preco,int pos, char *sobecod, char *sobetipo, char *sobemarca, int *sobetamanho, int *sobequantidade, float *sobepreco, int *sobepos)
{ struct Arv23 *maiorNo;
	maiorNo = NULL;
	if(*Raiz == NULL)
		*Raiz = criaNo(cod,tipo, marca, tamanho, quantidade, preco, pos,NULL,NULL,NULL);	
	else{ 
        if(ehFolha(*Raiz))
	    { 
            if((*Raiz)->NInfos == 1)
                adiciona(Raiz,cod, tipo, marca, tamanho, quantidade, preco,pos,maiorNo);
			else // quando não tem espaço
			{ 
                struct Arv23 *novo;	
                novo=quebraNo(Raiz,cod, tipo, marca, tamanho, quantidade, preco, pos,sobecod, sobetipo, sobemarca, sobetamanho, sobequantidade,sobepreco,sobepos, maiorNo);
                if(Pai == NULL)
                {	
                    struct Arv23 *no;
                    no = criaNo(sobecod, sobetipo, sobemarca, *sobetamanho, *sobequantidade, *sobepreco, *sobepos,*Raiz,novo,NULL);
                    *Raiz = no;
                }
                else maiorNo = novo;
					
			}
        }
        else
        {//quando não é folha
            if(strcmp(cod,(*Raiz)->cod) < 0)
                maiorNo = inserirArv23(*Raiz, &((*Raiz)->esq), cod, tipo, marca, tamanho, quantidade, preco,pos, sobecod, sobetipo, sobemarca, sobetamanho, sobequantidade, sobepreco,sobepos);
            else if((*Raiz)->NInfos == 1 || strcmp(cod,(*Raiz)->cod2)< 0)
                maiorNo = inserirArv23(*Raiz, &((*Raiz)->cen), cod, tipo, marca, tamanho, quantidade, preco,pos, sobecod, sobetipo, sobemarca, sobetamanho, sobequantidade, sobepreco, sobepos);
            else maiorNo = inserirArv23(*Raiz, &((*Raiz)->dir), cod, tipo, marca, tamanho, quantidade,preco,pos, sobecod, sobetipo, sobemarca, sobetamanho, sobequantidade, sobepreco, sobepos);	
            
            if(maiorNo != NULL)
            {
                if((*Raiz)->NInfos == 1)
                {
                    adiciona(Raiz,sobecod, sobetipo, sobemarca, *sobetamanho, *sobequantidade, *sobepreco,*sobepos, maiorNo);
                    maiorNo = NULL;
                }
                else // quando não tem espaço
                {  
                    char *sobecod1 = (char *) malloc(sizeof(char) * 6), sobetipo1[20], sobemarca1[20];
                    int sobequantidade1, sobetamanho1, sobepos1;
                    float sobepreco1;
                    struct Arv23 *novo;	
                    novo=quebraNo(Raiz, sobecod, sobetipo, sobemarca, *sobetamanho, *sobequantidade, *sobepreco,*sobepos, sobecod1, sobetipo1, sobemarca1, &sobetamanho1, &sobequantidade1, &sobepreco1,&sobepos1,maiorNo);
                    if(Pai == NULL)
                    {	
                        struct Arv23 *no;
                        no = criaNo(sobecod1, sobetipo1, sobemarca1, sobetamanho1, sobequantidade1, sobepreco1,sobepos1, *Raiz,novo,NULL);
                        *Raiz = no;
                        maiorNo = NULL;
                    }
                    else {
                        maiorNo = novo;
                        strcpy(sobecod, sobecod1);
                        strcpy(sobetipo, sobetipo1);
                        strcpy(sobemarca, sobemarca1);
                        *sobetamanho = sobetamanho1;
                        *sobequantidade = sobequantidade1;
                        *sobepreco = sobepreco1;
                        *sobepos = sobepos1;
                    }
                }
            }     
	    }	
	}
    return maiorNo;	
}

Arv23 * criaArv23(){
    FILE *arq = fopen("bd.txt", "r");

    Arv23 *tree = NULL, *pai = NULL;
    if(arq == NULL)
        printf("nao abriu\n");
    //     preencheArq();
    int tamanho, quantidade;
    float preco;
    char cod[7], tipo[20],marca[20];

    int sobetamanho, sobequantidade;
    float sobepreco;
    char sobecod[7],sobetipo[20],sobemarca[20];

    int pos = 1, sobepos = 1;
    while(fscanf(arq, " %s %s %s %d %d %f", cod, tipo, marca, &tamanho, &quantidade, &preco)!= EOF){
        inserirArv23(pai,&tree, cod, tipo, marca, tamanho, quantidade, preco, pos, sobecod, sobetipo, sobemarca, &sobetamanho, &sobequantidade, &sobepreco, &pos);
        pos ++;
    }
    return tree;
}

Arv23 **buscaCalcado(Arv23 *tree, char *codigo){
    Arv23 **NO = NULL;
    if(tree != NULL){
        if(strcmp(codigo, tree->cod) == 0){
            NO = &tree;
        }
        else{ 
            if( strcmp(codigo, tree->cod) < 0)
                NO = buscaCalcado(tree->esq, codigo);
            else if(strcmp(codigo, tree->cod) > 0 && tree->NInfos == 1)
                NO = buscaCalcado(tree->cen, codigo);
            else if(tree->NInfos == 2 && strcmp(tree->cod2, codigo) < 0)
                NO = buscaCalcado(tree->dir, codigo);
            else if(tree->NInfos == 2 && (strcmp(tree->cod, codigo) < 0 && strcmp(tree->cod2, codigo) > 0))
                NO = buscaCalcado(tree->cen, codigo);
        }
    }
    return NO;
}

void insereCalcado(Arv23 *tree, char *codigo, int quantidade){
    Arv23 **aux;
    aux = buscaCalcado(tree, codigo);
    if(aux != NULL){
        if(strcmp((*aux)->cod, codigo) == 0){
            (*aux)->quantidade += quantidade;
            printf("Nova quantidade: %d\n", (*aux)->quantidade);
        }
        else{
            (*aux)->quantidade2 += quantidade;
            printf("Nova quantidade: %d\n", (*aux)->quantidade2);
        }
    }
    else
        printf("Produto não registrado!\n");
}
void vendeCalcado(Arv23 *tree, char *codigo, int quantidade){
    Arv23 **aux;
    aux = buscaCalcado(tree, codigo);
    if(aux != NULL){
        if(strcmp((*aux)->cod, codigo) == 0){
            (*aux)->quantidade -= quantidade;
            printf("Nova quantidade: %d\n", (*aux)->quantidade);
        }
        else{
            (*aux)->quantidade2 -= quantidade;
            printf("Nova quantidade: %d\n", (*aux)->quantidade2);
        }
    }
    else
        printf("Produto não registrado!\n");
}
void mostra(Arv23 *tree){
    if(tree != NULL){
        mostra(tree->esq);
        printf("%10s | %10s | %10s | %10d | %10d | R$%5.2f\n",tree->cod, tree->tipo, tree->marca, tree->tamanho, tree->quantidade, tree->preco);
        printf("-----------------------------------------------------------------------------------\n");
        mostra(tree->cen);
        if(tree->NInfos == 2){
            printf("%10s | %10s | %10s | %10d | %10d | R$%5.2f\n",tree->cod2, tree->tipo2, tree->marca2, tree->tamanho2, tree->quantidade2, tree->preco2);
            printf("-----------------------------------------------------------------------------------\n");

        }
        mostra(tree->dir);
    }
}
void tabela(Arv23 *tree){
    if(tree != NULL){
        printf("-----------------------------------------------------------------------------------\n");
        printf("%10s | %10s | %10s | %10s | %8s | %5s\n","Codigo", "Tipo", "Marca", "Tamanho", "Quantidade", "Preço");
        printf("-----------------------------------------------------------------------------------\n");
        mostra(tree);
        printf("\n");
    }
}
int main(){
    Arv23 *tree = criaArv23();
    int escolha = 1;
    do{
        printf("BEM-VINDO A SUA LOJA DE CALCADOS\n");
        printf("-->%3sInserir calcado[1]\n-->%3sVender calcado[2]\n-->%3sPesquisar Calcado[3]\n-->%3sCheca estoque[4]\n-->%3sSair[5]\n-->%3sO que desja fazer: ", " "," "," "," "," ");
        scanf("%d", &escolha);
        char codigo[7];
        int quantidade;
        switch (escolha)
        {
            case 1:
                printf("digite o codigo do produto: ");
                scanf("%s", codigo);
                quantidade;
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                insereCalcado(tree, codigo, quantidade);
                break;
            case 2:
                printf("digite o codigo do produto: ");
                scanf("%s", codigo);
                quantidade;
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                insereCalcado(tree, codigo, quantidade);
                vendeCalcado(tree, codigo, quantidade);
                break;
            case 3:
                printf("digite o codigo do produto: ");
                scanf("%s", codigo);
                Arv23 *NO = buscaCalcado(tree, codigo);
                if(NO == NULL)
                    printf("Calcado não registrado!\n");
                else
                    printf("%s %s %s %d %d %f\n", tree->cod, tree->tipo, tree->marca, tree->tamanho, tree->quantidade, tree->preco);
            case 4:
                tabela(tree);
                break;
            default:
                break;
        }
    }while(escolha != 5);
    
    return 0;
}