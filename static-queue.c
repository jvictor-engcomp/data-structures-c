#include <stdio.h>

#define MAX_PESSOAS 10

typedef struct {
    int password[MAX_PESSOAS];
    int front;
    int tail;
    int size;
} Queue;

void createQueue (Queue* queue) {
    queue->front = 0;
    queue->tail = -1;
    queue->size = 0;
    printf("Fila criada com sucesso\n");
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

int isFull(Queue* queue) {
    return (queue->size == MAX_PESSOAS);
}

int enqueue(Queue* queue, int value){
    if(isFull(queue)){
        printf("\tLista cheia\n\n");
        return 0;
    }
    queue->tail = (queue->tail + 1) % MAX_PESSOAS;
    queue->password[queue->tail] = value;
    queue->size++;
    printf("\tadicionado com sucesso\n\n");
    return 1;
}

int dequeue(Queue* queue) {
    if(isEmpty(queue)) {
        printf("\tLista vazia\n\n");
        return 0;
    }
    printf("valor removido %d\n", queue->password[queue->front]);
    queue->front = (queue->front + 1) % MAX_PESSOAS;
    queue->size--;
}

int peek(Queue* queue) {
    if(isEmpty(queue)) {
        printf("\tfila vazia\n\n");
        return -1;
    }
    return queue->password[queue->front];
}

int queueSize(Queue* queue){
    return queue->size;
}

void menu(){
    printf("[1] inserir na fila\n");
    printf("[2] atender proximo\n");
    printf("[3] mostrar proximo\n");
    printf("[4] verificar fila vazia\n");
    printf("[5] verificar fila cheia\n");
    printf("[6] quantos na fila\n");
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
                printf("digite a senha do pessoa: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;}
            case 2:
                dequeue(&queue);
                break;
            case 3:
                printf("proxima pessoa: %d\n", peek(&queue));
                break;
            case 4:
                if(isEmpty(&queue)) printf("esta vazia\n");
                else printf("nao esta vazia\n");
                break;
            case 5:
                if(isFull(&queue)) printf("esta cheia\n");
                else printf("nao esta cheia\n");
                break;
            case 6:
                printf("faltam %d pessoas na fila\n", queueSize(&queue));
                break;
            case 7:
                break;
            default: printf("\topcao invalida\n");
        }
    }
}