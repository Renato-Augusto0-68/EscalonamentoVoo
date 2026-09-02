#include <stdio.h>
#include <stdlib.h>




//tempo total é x

// ai um deadline TEM QUE TERMINAR AAAAAAAAAAATÈ AQUI
/// Periodo : chega a cada tal tempo
// burst  o tempo q precisa. ou seja: if contador ==deadline){break;}



int main(/*int argc char *argv[]*/){
    int periodo=20;
    int copia = periodo;
    int tempoTotal=100;

    int deadline =12;
    int contLost=0;

    int cont=deadline;
    for(int i=0;i<tempoTotal;i++){

        if ((i%periodo)==0 && i<tempoTotal){
            printf("vendo\n");
            cont++;
        }
        
        if (cont!=0){
            printf("Fazendo algo\n");
            cont--;
            deadline--;
        }

        if (i==tempoTotal)
            contLost++;
            
        if (deadline==0){
            printf("Cabou\n");
            break;
        }

    }



}