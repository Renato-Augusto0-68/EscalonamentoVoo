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
    int tempoExec;
    int deadline;
    int isReady;
    int isDone;
    int isDead;
    int aux;
    int cont;
    int burst;
}tarefa; 

// uma struct com 2 valores sempre
// e, dentro dela colocar os dados conforme cada um precisa

int main(/*int argc char *argv[]*/){
    tarefa tarefas[2];
    //50 30 15
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
    
    int periodo2=50;
    int copia2 = periodo2;
    int tempoExec2=15;
    int burst2 = tempoExec2;
    int deadline2 =30;
    int contLost2=0;
    int contCompletas2=0;
    int bufferCompletar2 =0;
    int contKilled2=0;
    int cont2=deadline2;
    int aux2 =periodo;
    
    
    for(int i3=0;i3<2;i3++){
            tarefas[i3].periodo=(i3!=1)? periodo: periodo2;
            tarefas[i3].aux=(i3!=1)? periodo: periodo2;
            tarefas[i3].tempoExec = (i3!=1)? tempoExec: tempoExec2;
            tarefas[i3].tempoTotal= tempoTotal;
            tarefas[i3].isDead=0;
            tarefas[i3].burst=(i3!=1)? burst : burst2;
            tarefas[i3].isReady=0;
            tarefas[i3].deadline = (i3!=1)? deadline : deadline2;
            tarefas[i3].cont=0;
            tarefas[i3].isDone=0;
    }
    
    
    
    
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
    for(i;i<tempoTotal;i++){
        for(int i2=0;i2<2;i2++){
            
            if ((i%periodo)==0 && i<tempoTotal){
            tarefas[i2].cont++;
            tarefas[i2].burst = tarefas[i2].tempoExec;
             tarefas[i2].aux = i+(tarefas[i2].deadline);
             tarefas[i2].isReady=1;
             tarefas[i2].isDead=0;
             tarefas[i2].isDone=0;
            }
            if (tarefas[i2].cont!=0 && tarefas[i2].isReady==1){
                if(tarefas[i2].burst==0){
                    if(i2==0){contCompletas++;}
                    else{contCompletas2++;}
                     tarefas[i2].cont--;
                     tarefas[i2].isDead=0;
                     tarefas[i2].isDone=1;
                     tarefas[i2].isReady=0;
                }
                else{tarefas[i2].burst--;}
            }

        
            //deadline--;
        
            if (i==tarefas[i2].aux){
                if (tarefas[i2].cont>0){
                    if(i2==0){contLost++;}
                    else{contLost2++;};
                    tarefas[i2].isDone=0;
                    tarefas[i2].isDead=0;
                    tarefas[i2].isReady=0;
                    tarefas[i2].cont--;
                }
            }
        }
    }
    for(int i2=0;i2<2;i2++){
    
            if( tarefas[i2].isReady==1 && tarefas[i2].cont>0){
            contKilled++;
             tarefas[i2].isDead=1;
             tarefas[i2].isReady=0;
             tarefas[i2].isDone=0;
             tarefas[i2].cont--;
        }
        
    
    }
    printf("\nStatus1: \nCompletadas: %d\nMortas(Killed):%d \nperdidas: %d\n",contCompletas,contKilled,contLost);
    printf("\nStatus1: \nCompletadas: %d\nMortas(Killed):%d \nperdidas: %d\n",contCompletas2,contKilled2,contLost2);
    return 0;
}