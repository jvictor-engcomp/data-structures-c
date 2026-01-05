#include <stdio.h>
#include <stdlib.h>

typedef struct Carro {
    int placa;
    struct Carro* next;
} Carro;

typedef struct {
    Carro* front;
    Carro* tail;
    int size;
} Queue;

void createQueue (Queue* queue) {
    queue->front = NULL;
    queue->tail = NULL;
    queue->size = 0;
    printf("Fila criada com sucesso\n");
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

int enqueue(Queue* queue, int value){
    Carro* newCarro = (Carro*)malloc(sizeof(Carro));
    if (newCarro == NULL){
        printf("erro ao alocar memória, erro ao inserir %d ", value);
        return 0;
    }
    
    newCarro->placa = value;
    newCarro->next = NULL;
    
    if(isEmpty(queue)){
        queue->front = newCarro;
        queue->tail = newCarro;
    } else {
        queue->tail->next = newCarro;
        queue->tail = newCarro;
    }
    queue->size++;
    printf("\tadicionado com sucesso\n\n");
    return 1;
}

int dequeue(Queue* queue) {
    if(isEmpty(queue)) {
        printf("\tLista vazia\n\n");
        return 0;
    }
    
    Carro* temp = queue->front;
    int removedValue = temp->placa;
    
    queue->front = queue->front->next;
    
    if(queue->front == NULL)//fila ficou vazia
        queue->tail = NULL;
    
    free(temp);
    queue->size--;
    printf("%d removido da fila.\n", removedValue);
    return removedValue;
}

int peek(Queue* queue) {
    if(isEmpty(queue)) {
        printf("\tfila vazia\n\n");
        return -1;
    }
    return queue->front->placa;
}

int queueSize(Queue* queue){
    return queue->size;
}

void destroyQueue(Queue* queue) {
    Carro* current = queue->front;
    Carro* next;
    
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    
    queue->front = NULL;
    queue->tail = NULL;
    queue->size = 0;
    printf("\tfila destruida\n\n");
}

void menu(){
    printf("[1] inserir carro na fila\n");
    printf("[2] atravessar carro\n");
    printf("[3] mostrar proximo carro\n");
    printf("[4] verificar fila vazia\n");
    printf("[5] quantos na fila\n");
    printf("[6] quanto tempo para todos passarem\n");
    printf("[7] sair\n");  
    
}

int main() {
    Queue queue;
    createQueue(&queue);
    int choice = 0;
    
    while(choice != 7){
        menu();
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                int value;
                printf("digite a placa do carro: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;}
            case 2:
                dequeue(&queue);
                break;
            case 3:
                printf("proximo carro: %d\n", peek(&queue));
                break;
            case 4:
                if(isEmpty(&queue)) printf("esta vazia\n");
                else printf("nao esta vazia\n");
                break;
            case 5:
                printf("faltam %d carros na fila\n", queueSize(&queue));
                break;
                break;
            case 6:
                printf("\t%d minutos\n\n", queueSize(&queue));
                break;
            case 7:
                destroyQueue(&queue);
                break;
            default: printf("\topcao invalida\n");
        }
    }
}