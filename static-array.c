#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 15

void introducao(){
    printf("[1]Listar produtos com menos de 20\n");
    printf("[2]Comprar 5 produtos (106)\n");
    printf("[3]Valor total do estoque\n");
    printf("[4]Profuto com maior estoque\n");
    printf("[5]Mostrar Estoque\n");
    printf("[6]Sair\n");
}

int main(){
    
    srand(time(NULL));   
    int r = rand();    
    int quant[MAX];
    int cod[MAX];
    float price[MAX];
    int choice;
    int soma = 0;
    int maior = 0;
    int indice = 0;
    
    
    for(int i = 0 ; i < MAX ; i++){
        quant[i] = rand() % 100;
        cod[i] = 101 + i;
        price[i] = (rand() % 100);
    }//população
    
    
   
    while(1){
        introducao();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                for(int i = 0 ; i < MAX ; i++){
                    if(!(quant[i] < 20)) continue;
                    printf("Produto: %d\n", cod[i]);
                }
                break;
            
            case 2:
            
                if(quant[5] < 5) {
                    printf("nao ha mais do que 5 produtos\n");
                    break;
                }
                quant[5] = quant[5] - 5;
                printf("Voce comprou 5 produtos 106 e gastou %f.\n", 5 * price[5]);
                break;
            
            case 3:
                soma = 0;
                for(int i = 0 ; i < MAX; i++){
                    soma += quant[i] * price[i];
                }
                printf("VALOR TOTAL DO STOQUE: %d\n", soma);    
                break;
            case 4:
                maior = quant[0];
                for(int i = 0 ; i < MAX; i++){
                    if(quant[i] > maior){
                        maior = quant[i];
                        indice = i;                       
                    } 
                }
                printf("PRODUTO MAIOR ESTOQUE: %d %d\n", maior, cod[indice]);    
                break;
            
            case 5:
                for(int i = 0 ; i < MAX ; i++){
                    printf("\t%d %d %.2f\n", quant[i], cod[i], price[i]);
                }
                break;
            case 6: 
                return 0;
            default: printf("escolha opcao valida");
        }
        
    }
    
}