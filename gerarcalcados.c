#include <stdio.h>
#include <time.h>

typedef struct list list;

struct list{
    char cod[7];
    char tipo[30];
    char marca[30];
    int tamanho;
    int quantidade;
    float preco;
    list *prox;
};

int verifica(list *lista, char *cod){
    int repetido = 0;
    if(lista != NULL){
        if(strcmp(lista->cod, cod) == 0)
            repetido = 1;
        else
            verifica(lista->prox, cod);
    }
    return repetido;
}

int insere(list **lista, char *cod, char *tipo, char *marca, int tamanho, int quantidade, float preco){
    int inseriu = 0;
    if((*lista) == NULL){
        if(verifica((*lista), cod) == 0){
            (*lista) = (list *) malloc(sizeof(list));
            strcpy((*lista)->cod, cod);
            strcpy((*lista)->tipo, tipo);
            strcpy((*lista)->marca, marca);
            (*lista)->tamanho = tamanho;
            (*lista)->quantidade = quantidade;
            (*lista)->preco = preco;
            (*lista)->prox = NULL;
            inseriu = 1;
        }
    }
    else
        inseriu = insere(&(*lista)->prox, cod,tipo, marca, tamanho, quantidade,preco);
    return inseriu;
}


int main(){
    char *tipos[] = {"sapatenis", "social", "esporte", "bota", "rasteiro"};
    char *marcas[] = {"nike", "adidas", "puma", "olympikus", "colcci", "fila", "oakley"};
    char *nums[] = {'0', '1','2','3','4','5','6','7','8','9'};
    int *tamanhos = {33,34,35,36,37,38,39,40};
    list *lista = NULL;
    FILE *fp = fopen("calcados.txt","w");
    char codigo[7];
    char tipo[20];
    char marca[20];
    int quantidade;
    int tamanho;
    float preco;
    srand(time(NULL));
    for(int i = 0; i < 100; i ++){
        int j;
        for(j = 0; j < 6; j++)
            codigo[j] = nums[rand()%5];
        codigo[j] = '\0';
        strcpy(tipo, tipos[rand()%5]);
        strcpy(marca, marcas[rand()%7]);
        quantidade = rand()%20+30;
        tamanho = rand()%10+23;
        preco = rand()%1000+100;
        // printf("%s %s %s %d %d %.2f\n",codigo, tipo, marca, tamanho, quantidade, preco );
        insere(&lista, codigo, tipo, marca, tamanho, quantidade, preco);
    }

    for(list *p = lista; p != NULL; p = p->prox){
        fprintf(fp,"%s %s %s %d %d %.2f\n",p->cod,p->tipo,p->marca,p->tamanho,p->quantidade,p->preco);
    }

    close(fp);
    return 0;
}