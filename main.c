#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//tempo total é x

// ai um deadline TEM QUE TERMINAR AAAAAAAAAAATÈ AQUI
/// Periodo : chega a cada tal tempo
// burst  o tempo q precisa. ou seja: if contador ==deadline){break;}








typedef struct tarefa{
    char nome[3];
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

void readFile(char *argv[], tarefa *x){
    FILE *acesso;

    acesso = fopen(argv[1],"r");
    if (acesso!=NULL){
        fscanf(acesso,"%d",&x[0].tempoTotal);
        x[1].tempoTotal=x[0].tempoTotal;
        fscanf(acesso,"%s %d %d %d",x[0].nome,&x[0].periodo,&x[0].deadline,&x[0].tempoExec);
        fscanf(acesso,"%s %d %d %d",x[1].nome,&x[1].periodo,&x[1].deadline,&x[1].tempoExec);
    }
    fclose(acesso);
}


// uma struct com 2 valores sempre
// e, dentro dela colocar os dados conforme cada um precisa

int main(int argc, char *argv[]){

    tarefa tarefas[2];
    int contLost=0;
    int contCompletas=0;
    int contKilled=0;
    int contCompletas2=0;
    int contLost2=0;
    int contKilled2=0;
    int escolhida=-1;
    int modo =2;
    readFile(argv, tarefas);
    for(int i3=0;i3<2;i3++){
            tarefas[i3].aux=tarefas[i3].periodo;
            tarefas[i3].isDead=0;
            tarefas[i3].burst=tarefas[i3].tempoExec;
            tarefas[i3].isReady=0;
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
   int prioridade= 0;
    int menPriorid=0;
    int maiPriorid=0;
    int  tempoTotal = tarefas[0].tempoTotal; 
   int i2=0;
    if (modo==1){
    int d1 = tarefas[0].periodo;
   int d2 = tarefas[1].periodo;  
   
//RM
    for(int i=0;i<tempoTotal;i++){
        maiPriorid = -1;
        for(int i3=0;i3<2;i3++){
           
        if ((i%(tarefas[i3].periodo))==0 && i!=tempoTotal){
            tarefas[i3].isDone=0; 
            tarefas[i3].isReady=1;
            tarefas[i3].burst = tarefas[i3].tempoExec;
             
            tarefas[i3].aux = i+ (tarefas[i3].deadline);
            
            tarefas[i3].cont++;
            tarefas[i3].isDead=0;
             
            }

            
        if (i>=tarefas[i3].aux && tarefas[i3].isReady == 1 && (tarefas[i3].cont>0 && tarefas[i3].burst>0)){

                    if(i3==0){contLost++;}
                    else{contLost2++;};
                    tarefas[i3].isDone=0;
                    tarefas[i3].isDead=0;
                    tarefas[i3].isReady=0;
                    tarefas[i3].cont--;
                
            }
           
        }
           
            if(tarefas[0].isReady==0 && tarefas[1].isReady==0){
                maiPriorid=-1;
            }
            if(tarefas[0].isReady==1 && tarefas[1].isReady==0 && tarefas[0].burst>=0 ){
                maiPriorid=0;
            }
            if(tarefas[1].isReady==1 && tarefas[1].burst>0){
                if (tarefas[0].isReady==1 && tarefas[0].burst>0){
                    if (d1<=d2)
                        maiPriorid=0;
                    else{
                        maiPriorid=1;
                    }
                }
                else if (tarefas[0].isReady==0){maiPriorid=1;}
            }
            escolhida=maiPriorid;


             if(escolhida!=-1){
             
                if (tarefas[escolhida].cont>0 && tarefas[escolhida].isReady==1){
                    tarefas[escolhida].burst--;
                    if(tarefas[escolhida].burst==0){
                        if(escolhida==0){contCompletas++;}
                        else{contCompletas2++;}
                         tarefas[escolhida].cont--;
                         tarefas[escolhida].isDead=0;
                         tarefas[escolhida].isDone=1;
                         tarefas[escolhida].isReady=0;
                    }
                    
                }
            }
    
        }
    }else{

    for(int i=0;i<tempoTotal;i++){
        escolhida=-1;
        int d1 = tarefas[0].periodo;
        int d2 = tarefas[1].periodo;  

        for(int i3=0;i3<2;i3++){
            
            if ((i%(tarefas[i3].periodo))==0 && i!=tempoTotal ){
            tarefas[i3].cont++;
            tarefas[i3].burst = tarefas[i3].tempoExec;
             tarefas[i3].aux = i+ (tarefas[i3].deadline);
             tarefas[i3].isReady=1;
             tarefas[i3].isDead=0;
             tarefas[i3].isDone=0;           
             
            }
            

            if (i==tarefas[i3].aux && (tarefas[i3].cont>0 && tarefas[i3].burst>0)){
                
                    if(i3==0){contLost++;}
                    else{contLost2++;}
                    tarefas[i3].cont--;
                    tarefas[i3].isDone=0;
                    tarefas[i3].isDead=0;
                    tarefas[i3].isReady=0;
                    
                
            }
           
        } 


            if(tarefas[0].isReady==0 && tarefas[1].isReady==0){
                maiPriorid=-1;
            } 
            if(tarefas[0].isReady==1 && tarefas[1].isReady==0 && tarefas[0].burst>0 ){
                maiPriorid=0;
            }
            if(tarefas[1].isReady==1 && tarefas[1].burst>0){
                if (tarefas[0].isReady==1 && tarefas[0].burst>0){
                    if (tarefas[0].aux<=tarefas[1].aux)
                        maiPriorid=0;
                    else{
                        maiPriorid=1;
                    }
                }
                else if (tarefas[0].isReady==0){maiPriorid=1;}
            }
            

            escolhida=maiPriorid;
            
             if(escolhida!=-1){
                
                if (tarefas[escolhida].cont!=0 && tarefas[escolhida].isReady==1){
                    tarefas[escolhida].burst--;
                    if(tarefas[escolhida].burst==0){
                        if(escolhida==0){contCompletas++;}
                        else{contCompletas2++;}
                         tarefas[escolhida].cont--;
                         tarefas[escolhida].isReady=0;
                         tarefas[escolhida].isDead=0;
                         tarefas[escolhida].isDone=1;
                    }
                }
                
            }
    
        }
    }
     for(int i2=0;i2<2;i2++){
    
            if( tarefas[i2].isReady==1 && tarefas[i2].burst>0){
                if(i2==0){contKilled+=tarefas[i2].cont;}
                else{contKilled2+=tarefas[i2].cont;}
                tarefas[i2].isDead=1;
               // tarefas[i2].isReady=0;
                tarefas[i2].cont=0;
        
        }
    
    }
    printf("\nStatus1: \nCompletadas: %d\nMortas(Killed):%d \nperdidas: %d\n",contCompletas,contKilled,contLost);
    printf("\nStatus2: \nCompletadas: %d\nMortas(Killed):%d \nperdidas: %d\n",contCompletas2,contKilled2,contLost2);
    return 0;
}