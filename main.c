#include <stdio.h>
#include <stdlib.h>




//tempo total é x

// ai um deadline TEM QUE TERMINAR AAAAAAAAAAATÈ AQUI
/// Periodo : chega a cada tal tempo
// burst  o tempo q precisa. ou seja: if contador ==deadline){break;}

typedef struct tarefa{
    char *nome;
    int periodo;
    int tempoTotal;
    int isReady;
    int isDone;
    int isDead;
    int aux;
}tarefa;

// uma struct com 2 valores sempre
// e, dentro dela colocar os dados conforme cada um precisa

int main(/*int argc char *argv[]*/){
    int periodo=20;
    int copia = periodo;
    int tempoTotal=100;
    int tempoExec=8;
    int burst = tempoExec;
    int deadline =12;
    int contLost=0;
    int contCompletas=0;
    int bufferCompletar =0;
    int contKilled=0;
    int cont=deadline;
    int i=0;
    int aux =periodo;
    tarefa x[2][tempoTotal];
    /*
    Ok, vamos pensar:
    ele chega a cada 20 segundos... então tem que aumentar o contador de processos p fazer
    precisa de 8 segundos p concluir ...    while(burst>0) burst --
    Até 12 segundos ele tem p terimnar, e tem os 100 totais... ou seja se burst ainda for >0, ele pode demorar até deadline(aux)
    Se ele torrar esses 12 segundos ele vai ser morto, ou separado p morrer dps...
    contKilleld++ e cont --;
    Uma var auxiliar p repassra deadline + tempoExec. com isso ai fica certo o killed p fazer dps do loop.

    e, claro flags de status...
    */
    for(int i1=0;i1<2;i1++){
    for(i;i<tempoTotal;i++){

        if ((i%periodo)==0 && i<tempoTotal){
            printf("vendo agora\n");
            cont++;
            burst = tempoExec;
            aux = i+deadline;
            x[i1][i].isReady=1;
            x[i1][i].isDead=0;
            x[i1][i].isDone=0;
        }
        if (cont!=0 && x[i1][i].isReady==1){
                printf("Fazendo algo\n");
                if(burst==0){
                    contCompletas++;
                    cont--;
                    x[i1][i].isDead=0;
                    x[i1][i].isDone=1;
                    x[i1][i].isReady=0;
                }
                else{burst--;}
        }

        
            //deadline--;
        
        if (i==aux){
            if (cont>0){
                contLost++;
                x[i1][i].isDone=0;
                x[i1][i].isDead=0;
                x[i1][i].isReady=0;
                cont--;
            }

            
            }    
        }
    }
    for(i=0;i<tempoTotal;i++){
        if(x[i].isReady==1 && cont>0){
            contKilled++;
            x[i].isDead=1;
            x[i].isReady=0;
            x[i].isDone=0;
            cont--;
        }
    }
    printf("\nStatus: \nCompletadas: %d\nMortas(Killed):%d \nperdidas: %d\n",contCompletas,contKilled,contLost);
    return 0;
}