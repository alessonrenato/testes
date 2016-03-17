/*Simulador de rede de petri*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>

#define MAXTAB 100
int main(void)
{
    srand(time(NULL));
    int posicao[MAXTAB],
        rotulo[MAXTAB],
        transicao[MAXTAB],
        arcovailug[MAXTAB],
        arcovemlug[MAXTAB],
        arcovaitra[MAXTAB],
        arcovemtra[MAXTAB],
        maxpos,
        maxtok,
        maxtra,
        arcos,
        i,j,
        maxarc;
    char opt;

    do
    {
        printf("Digite o numero de posicoes da rede de petri\n");
        scanf("%d",&maxpos);
        printf("Digite o numero de transicoes da rede de petri\n");
        scanf("%d",&maxtra);
        for(i=0;i<maxpos;i++)
        {
            printf("Digite o numero de tokens em L%d\n",i);
            scanf("%d",&posicao[i]);
        }
        for(i=0;i<maxpos;i++)
        {
            printf("Quantos arcos saem de L%d?\n",i);
            scanf("%d",&arcos);
            for(j=maxarc;j<arcos+maxarc;j++)
            {
                arcovemlug[j]=i;
                printf("Digite o rotulo de A%d\n",j);
                scanf("%d",rotulo[j]);
                printf("Arco (A%d) sai de L%d para qual transicao?\n",j,i);
                scanf("%d",&arcovaitra[j]);
            }
            maxarc+=arcos;
        }
        for(i=0;i<maxtra;i++)
        {
            printf("Quantos arcos saem de T%d?\n",i);
            scanf("%d",&arcos);
            maxarc+=arcos;
            for(j=maxarc;j<arcos+maxarc;j++)
            {
                arcovemtra[j]=i;
                printf("Digite o rotulo de A%d\n",j);
                scanf("%d",&rotulo[j]);
                printf("Arco (A%d) sai de T%d para qual lugar?\n",j,i);
                scanf("%d",&arcovailug);
            }
            maxarc+=arcos;
        }
        printf("Os dados estao corretos?\n(S\N)\n");
        do{opt=getchar()} while(opt!='s' && opt!='S' && opt!='n' && opt!='N');
    } while(opt!='s' && opt!='S');
    return EXIT_SUCCESS;
}

