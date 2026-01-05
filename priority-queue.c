#include <stdio.h>
#include <stdlib.h> 

typedef struct Paciente {
    int codigo;    
    int prioridade;
    struct Paciente *next; 
} Paciente;

typedef struct {
    Paciente *front; 
    int size;   
} Queue;

void createQueue(Queue* queue) {
    queue->front = NULL;
    queue->size = 0;
    printf("\tFila criada\n\n");
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

int enqueue(Queue* queue, int value, int prioridade) {
    Paciente* novoPaciente = (Paciente*)malloc(sizeof(Paciente));
    if(novoPaciente == NULL){
        printf("erro ao alocar memoria\n\n");
        return 0;
    }
    
    novoPaciente->codigo = value;
    novoPaciente->prioridade = prioridade;
    novoPaciente->next = NULL;
    
    if(isEmpty(queue) || prioridade < queue->front->prioridade){
        novoPaciente->next = queue->front;
        queue->front = novoPaciente;
    } else {
        Paciente* temp = queue->front;
        while(temp->next != NULL && temp->next->prioridade <= prioridade){
            temp = temp->next;
        }
        novoPaciente->next = temp->next;
        temp->next = novoPaciente;
    }
    
    queue->size++;
    printf("%d inserido na fila.\n", value);
    return 1; 
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Fila vazia\n");
        return -1; 
    }

    Paciente* temp = queue->front; 
    int removedValue = temp->codigo; 

    queue->front = queue->front->next; 

    free(temp);
    queue->size--;   

    printf("%d removido da fila.\n", removedValue);
    return removedValue; 
}

int peek(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Fila vazia\n");
        return -1; 
    }
    return queue->front->codigo; 
}

int queueSize(Queue *queue) {
    return queue->size;
}

void destroyQueue(Queue *queue) {
    Paciente* temp = queue->front;
    Paciente* next;

    while (temp != NULL) {
        next = temp->next; 
        free(temp);       
        temp = next;       
    }

    queue->front = NULL;
    queue->size = 0;
    printf("Fila destruida\n");
}

void opcoes() {
    printf("[1] Adicionar paciente\n");    
    printf("[2] remover paciente\n");
    printf("[3] verificar proximo paciente\n");
    printf("[4] Verificar fila vazia\n");
    printf("[5] Liberar fila\n");
    printf("[6] Sair\n");
}

void prioridades(){
    printf("[1] Emergencia\n");    
    printf("[2] Muito urgente\n");
    printf("[3] Urgente\n");
    printf("[4] Pouco urgente\n");
    printf("[5] Nao urgente\n");
}

int main() {
    Queue queue;
    createQueue(&queue);
    
    int choice = 0;
    while (choice != 6){
        opcoes();
        scanf("%d", &choice);
        
        switch(choice){
            case 1:{
                int valor, prioridade;
                
                printf("Qual valor? ");
                scanf("%d", &valor);
                
                printf("Qual prioridade? ");
                scanf("%d", &prioridade);
                
                enqueue(&queue, valor, prioridade);
                break;}
            case 2:
                dequeue(&queue);
                break;
            case 3:
                if(isEmpty(&queue)){
                    printf("fila vazia\n\n");
                } else {
                    printf("proximo paciente: %d", peek(&queue));
                }
                break;
            case 4:
                if(isEmpty(&queue)){
                    printf("fila vazia\n\n");
                }
                break;
            case 5:
                destroyQueue(&queue);
                break;
            case 6:
                break;
            default: printf("Opcao invalida\n\n");
        }
    }
    
    return 0;
}
