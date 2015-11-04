//trabalho mercado
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 3
#define MAXS 30
#define MAXP 40


typedef struct {
    char pessoas[MAXN][MAXS];
    float precos[MAXN][MAXP];
    int saldo[MAXN];
    float total;
    int pagou;
} dados;

dados recebeDados();
void calculaSaldo(dados d);

int main(void){
    
    dados d = recebeDados();
    calculaSaldo(d);

    return EXIT_SUCCESS;
}

dados recebeDados(){
    
    dados d;
    char *p;
    float preco;
    int i, 
        opt,
        it0=0,
        it1=0,
        it2=0;

    printf("Digite o Nome das pessoas que foram ao mercado\n");
    for(i=0;i<MAXN;i++){
        printf("Pessoa %d: ",i+1);
        fgets(d.pessoas[i],MAXS,stdin);
        if((p=strchr(d.pessoas[i],'\n'))) *p='\0';
        printf("\n");
    }
    printf("Quem pagou a conta? (selecione opcao)\n1- %s\n2- %s\n3- %s\n",d.pessoas[0],d.pessoas[1],d.pessoas[2]);
    do{
        scanf("%d",&d.pagou);
    }while(d.pagou<1 || d.pagou>3);

    d.pagou--;
    
    printf("Quanto foi no total?\n");
    scanf("%f",&d.total);
   
    do{
        printf("\nSelecione uma opcao\n\n1-%s comprou sozinho?\n2-%s comprou sozinho?\n3-%s comprou sozinho?\n4-%s e %s compraram juntos\n5-%s e %s compraram juntos\n6-%s e %s compraram juntos\n7-Os tres compraram juntos\n8-Encerrar\n",d.pessoas[0],d.pessoas[1],d.pessoas[2],d.pessoas[0],d.pessoas[1],d.pessoas[0],d.pessoas[2],d.pessoas[1],d.pessoas[2]);

        do{
            scanf("%d",&opt);
        }while(opt<1 || opt>8);

        switch(opt)
        {
            case 1:
                printf("Digite o preco da compra\n");
                scanf("%f",&preco);
                d.precos[0][it0] = preco;
                it0++;
                break;
            case 2:
                printf("Digite o preco da compra\n");
                scanf("%f",&preco);
                d.precos[1][it1] = preco;
                it1++;
                break;
            case 3:
                printf("Digite o preco da compra\n");
                scanf("%f",&preco);
                d.precos[2][it2] = preco;
                it2++;
                break;
            case 4:
                printf("Digite o preco da compra\n");
                scanf("%f",&preco);
               d.precos[1][it1] = d.precos[0][it0] = preco / 2.0;
               it0++;
               it1++;
               break;
            case 5:
                printf("Digite o preco da compra\n");
                scanf("%f",&preco);
               d.precos[2][it2] = d.precos[0][it0] = preco / 2.0;
               it0++;
               it2++;
               break;
            case 6:
                printf("Digite o preco da compra\n");
                scanf("%f",&preco);
               d.precos[2][it2] = d.precos[1][it1] = preco / 2.0;
               it2++;
               it1++;
               break;
            case 7:
                printf("Digite o preco da compra\n");
                scanf("%f",&preco);
               d.precos[2][it2] = d.precos[1][it1] = d.precos[0][it0] = preco / 3.0;
               it0++;
               it1++;
               it2++;
               break;
            case 8:
               printf("Calculando\n");
               break;
            }

    }while(opt!=8);
    d.saldo[0]=it0;
    d.saldo[1]=it1;
    d.saldo[2]=it2;

    return d;
}

                 
void calculaSaldo(dados d){
    float soma0=0,
          soma1=0,
          soma2=0;
    int i;

    for(i=0;i<d.saldo[0];i++) soma0 += d.precos[0][i];
    for(i=0;i<d.saldo[1];i++) soma1 += d.precos[1][i];
    for(i=0;i<d.saldo[2];i++) soma2 += d.precos[2][i];

    switch(d.pagou)
    {
        case 0:
            printf("%s pagou tudo (R$%.2f), comprou R$%.2f e deve receber R$%.2f\nR$%.2f de %s e\nR$%.2f de %s\n",d.pessoas[0],d.total,soma0,d.total-soma0,soma1,d.pessoas[1],soma2,d.pessoas[2]);
            break;
        case 1:
            printf("%s pagou tudo (R$%.2f), comprou R$%.2f e deve receber R$%.2f\nR$%.2f de %s e\nR$%.2f de %s\n",d.pessoas[1],d.total,soma1,d.total-soma1,soma0,d.pessoas[0],soma2,d.pessoas[2]);
            break;
        case 2:
            printf("%s pagou tudo (R$%.2f), comprou R$%.2f e deve receber R$%.2f\nR$%.2f de %s e\nR$%.2f de %s\n",d.pessoas[2],d.total,soma2,d.total-soma2,soma0,d.pessoas[0],soma1,d.pessoas[1]);
            break;
    }
    return;
}  
