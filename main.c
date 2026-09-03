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
    int cont;
    int burst;
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
    tarefa x[tempoTotal];
    tarefa x2[tempoTotal];
    
    
    
    for(int i3=0;i3<tempoTotal;i3++){
            x[i3].periodo=periodo;
            x[i3].aux=periodo;
            x[i3].tempoTotal=tempoTotal;
            x[i3].isDead=0;
            x[i3].burst=tempoExec;
            x[i3].isReady=0;
            x[i3].cont=0;
            x[i3].isDone=0;
            
            x2[i3].periodo=periodo;
            x2[i3].aux=periodo;
            x2[i3].tempoTotal=tempoTotal;
            x2[i3].isDead=0;
            x2[i3].burst=tempoExec;
            x2[i3].isReady=0;
            x2[i3].cont=0;
            x2[i3].isDone=0;
            
            
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
    for(int i2=0;i2<2;i2++){
        for(i=0;i<tempoTotal;i++){
           
        if (i2==0){   
           
            if ((i%periodo)==0 && i<tempoTotal){
            printf("vendo agora\n");
            x[i2].cont++;
            x[i2].burst = tempoExec;
             x[i2].aux = i+deadline;
             x[i2].isReady=1;
             x[i2].isDead=0;
             x[i2].isDone=0;
        }
        if (x[i2].cont!=0 && x[i2].isReady==1){
                printf("Fazendo algo\n");
                if(x[i2].burst==0){
                    contCompletas++;
                     x[i2].cont--;
                     x[i2].isDead=0;
                     x[i2].isDone=1;
                     x[i2].isReady=0;
                }
                else{x[i2].burst--;}
        }

        
            //deadline--;
        
        if (i==x[i2].aux){
            if (x[i2].cont>0){
                contLost++;
                 x[i2].isDone=0;
                 x[i2].isDead=0;
                 x[i2].isReady=0;
                 x[i2].cont--;
            }

            
            }   
            
        }else{
            if ((i%periodo)==0 && i<tempoTotal){
            printf("vendo agora\n");
            x2[i2].cont++;
            x2[i2].burst = tempoExec;
             x2[i2].aux = i+deadline;
             x2[i2].isReady=1;
             x2[i2].isDead=0;
             x2[i2].isDone=0;
        }
        if (x2[i2].cont!=0 && x2[i2].isReady==1){
                printf("Fazendo algo\n");
                if(x2[i2].burst==0){
                    contCompletas++;
                     x2[i2].cont--;
                     x2[i2].isDead=0;
                     x2[i2].isDone=1;
                     x2[i2].isReady=0;
                }
                else{x2[i2].burst--;}
        }

        
            //deadline--;
        
        if (i==x2[i2].aux){
            if (x2[i2].cont>0){
                contLost++;
                 x2[i2].isDone=0;
                 x2[i2].isDead=0;
                 x2[i2].isReady=0;
                 x2[i2].cont--;
            }

            
            }
            
        }
        
    }
    }
    for(int i2=0;i2<2;i2++){
    for(i=0;i<tempoTotal;i++){
        if (i2==0){
            if( x[i].isReady==1 && x[i].cont>0){
            contKilled++;
             x[i].isDead=1;
             x[i].isReady=0;
             x[i].isDone=0;
             x[i].cont--;
        }
        }else{
            if( x2[i].isReady==1 && x2[i].cont>0){
            contKilled++;
             x2[i].isDead=1;
             x2[i].isReady=0;
             x2[i].isDone=0;
             x2[i].cont--;
                
            }
        }
    }
    }
    printf("\nStatus: \nCompletadas: %d\nMortas(Killed):%d \nperdidas: %d\n",contCompletas,contKilled,contLost);
    return 0;
}