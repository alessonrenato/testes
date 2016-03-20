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
        tokens[MAXTAB],
        habtransicao[MAXTAB][MAXTAB],
        arcovailug[MAXTAB],
        arcovemlug[MAXTAB],
        arcovaitra[MAXTAB],
        arcovemtra[MAXTAB],
        maxpos,
        maxtra,
        arcos,
        i,j,
        maxarc,
        estabilizou;
    char opt;

    do
    {
        /* reset de variaveis */
        opt='x';
        arcos=maxarc=maxtra=maxpos=0;
        
        for(i=0;i<MAXTAB;i++)
        {
            /* posicoes, transicoes e arcos inexistentes = -1 */
            posicao[i]=-1; 
            rotulo[i]=1; /* valor padrao de custo */
            arcovaitra[i] = arcovemtra[i] = arcovailug[i] = arcovemlug[i] = -1;
        }   
        /*fim reset */

        /*inicializacao da rede */
        printf("Digite o numero de posicoes da rede de petri\n");/* qtd de lugares */
        scanf("%d",&maxpos);
        printf("Digite o numero de transicoes da rede de petri\n"); /* qtd de transicoes */
        scanf("%d",&maxtra);
        for(i=0;i<maxpos;i++) /* preencher tokens */
        {
            printf("Digite o numero de tokens em L%d\n",i);
            scanf("%d",&posicao[i]);
        }
        for(i=0;i<maxpos;i++) /* preencher arcos vindo de lugares */
        {
            printf("Quantos arcos saem de L%d?\n",i);
            scanf("%d",&arcos);
            for(j=maxarc;j<arcos+maxarc;j++)
            {
                arcovemlug[j]=i;
                printf("Digite o rotulo de A%d\n",j);
                scanf("%d",&rotulo[j]);
                printf("Arco (A%d) sai de L%d para qual transicao?\n",j,i);
                scanf("%d",&arcovaitra[j]);
            }
            maxarc+=arcos;
        }
        for(i=0;i<maxtra;i++) /* preencher arcos vindo de transicoes */
        {
            printf("Quantos arcos saem de T%d?\n",i);
            scanf("%d",&arcos);
            for(j=maxarc;j<arcos+maxarc;j++)
            {
                arcovemtra[j]=i;
                printf("Digite o rotulo de A%d\n",j);
                scanf("%d",&rotulo[j]);
                printf("Arco (A%d) sai de T%d para qual lugar?\n",j,i);
                scanf("%d",&arcovailug[j]);
            }
            maxarc+=arcos;
        }

        /* impressao da rede completa */
        printf("L(X): Tk(Y) X=lugar/Y=tokens do lugar\n");
        for(i=0;i<maxpos;i++)
            printf("L%d : Tk%d\n",i,posicao[i]);
        printf("QTD de Transicoes:%d\n",maxtra);
        printf("Arcos:\n");
        for(i=0;i<maxarc;i++)
            if(arcovemlug[i]!=-1)                
                printf("Arco A%d, de rotulo %d, de L%d p/ T%d\n",i,rotulo[i],arcovemlug[i],arcovaitra[i]);
            else
                printf("Arco A%d, de rotulo %d, de T%d p/ L%d\n",i,rotulo[i],arcovemtra[i],arcovailug[i]);                
        /* fim impressao */
        /* confirmar dados */
        printf("Os dados estao corretos?\n(S/N)\n");
        do{opt=getchar();} while(opt!='s' && opt!='S' && opt!='n' && opt!='N');
    } while(opt!='s' && opt!='S'); /* do-while de configuracao da rede */
    /*disparar cronometro aqui*/
    printf("iniciando simulacao\n");
    do
    {
        estabilizou=1;
        for(i=0;i<maxarc;i++)        
            if(arcovemlug[i]!=-1) /* arcos pre transicao */
                if(posicao[arcovemlug[i]] >= rotulo[i])
                    habtransicao[arcovaitra[i]][i]=1;
                else               
                    habtransicao[arcovaitra[i]][i]=0;
            else                  /* arcos pos transicao */
                for(j=0;j<maxarc;j++)                
                    if(habtransicao[arcovemtra[i]][j]==0)
                        break;
                    else if(j==maxarc-1)
                    {
                        tokens[arcovailug[i]]+=rotulo[i];
                        estabilizou=0;
                    }
        for(i=0;i<maxpos;i++) /* distribui os tokens gerados nessa rodada aos lugares */
            posicao[i]+=tokens[i];
        for(i=0;i<maxtra;i++) /* desabilita transicoes para nova rodada */
            for(j=0;j<maxarc;j++)
                habtransicao[i][j]=-1;
    }while(estabilizou);        
 
    return EXIT_SUCCESS;
}

