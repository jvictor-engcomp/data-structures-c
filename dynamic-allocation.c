#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *inicializaQuantidade(){
    int *quant = (int*) malloc(sizeof(int));
    printf("Quantos sensores inialmente: ");
    scanf("%d", quant);
    
    return quant;
}
float *inicializaVetor(int *quant){
    float *leituras = (float*) malloc(*quant * sizeof(float));
    printf("Digite as temperatuas de cada sensor.\n\n");
    for(int i = 0 ; i < *quant ; i++){
        printf("Sensor [%d]: ", i + 1);
        scanf("%f", leituras + i);
    }
    
    return leituras;
}

bool mostrarLeituras(int *quant, float *leituras){
    if(!(*quant)){
        printf("sem sensores no vetor");
        return false;
    }
    printf("\n\n---------------------\n\n");
    
    for(int i = 0 ; i < *quant ; i++){
        printf("Sensor [%d]: %.2f\n", i + 1, *(leituras + i));
    }
    
    printf("\n\n---------------------\n");
}

bool adicionarSensor(float **leituras, int **quant){
    float *temp = realloc(*leituras, ((**quant) + 1) *sizeof(float));
    
    if(temp == NULL){
        printf("erro ao reallocar memoria");
        return false;
    }
    
    printf("Sensor [%d]: ", (**quant) + 1);
    scanf("%f", temp + (**quant));
    
    *leituras = temp;
    (**quant)++;
    
    return true;
} 

int main(){
    int choice;
    int * quant = inicializaQuantidade();
    float *leituras = inicializaVetor(quant);
    
    mostrarLeituras(quant, leituras);
    
    while(1){
        printf("adicionar mais sensores?\n[1]Sim\n[2]Nao\n\n");
        scanf("%d", &choice);
        if(choice == 2) return 0;
        
        adicionarSensor(&leituras, &quant);
        mostrarLeituras(quant, leituras);
    }
    
    
    
    free(quant);
    free(leituras);
    return 0;
}