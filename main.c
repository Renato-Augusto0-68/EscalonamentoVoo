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

    /*
    Ok, vamos pensar:
    ele chega a cada 20 segundos... então tem que aumentar o contador de processos p fazer
    precisa de 8 segundos p concluir ...    while(burst>0) burst --
    Até 12 segundos ele tem p terimnar, e tem os 100 totais... ou seja se burstainda for >0, ele pode demorar até deadline
    Se ele torrar esses 12 segundos ele vai ser morto
    contKilleld++ e cont --;
    Uma var auxiliar p repassra deadline + tempoExec. com isso ai fica certo o killed p fazer dps do loop.

    e, claro flags de status...
    */
    
    for(i;i<tempoTotal;i++){

        if ((i%periodo)==0 && i<tempoTotal){
            printf("vendo agora\n");
            cont++;
            burst = tempoExec;
            aux = ((periodo*i)+deadline);
        }
        if (cont!=0){
                printf("Fazendo algo\n");
                if(burst==0){
                    contCompletas++;
                    cont--;
                }
                else{burst--;}
        }

        
            //deadline--;
        
        if (i==aux){
            if (cont>0){
                contLost++;
                cont--;
            }
            
        }    
    }

    for(i=0;i<tempoTotal;i++){
        if(cont>0){
            contKilled++;
            cont--;
        }
    }
    printf("\nStatus: \nCompletadas: %d\nMortas(Killed):%d \nperdidas: %d\n",contCompletas,contKilled,contLost);
    return 0;
}