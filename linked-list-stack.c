#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char question[50];
    struct Node* next;
} Node;

typedef struct {
    Node* top;
    int size;
} Stack;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void createStack(Stack* s){
    s->top = NULL; 
    s->size = 0;
    printf("\tpilha criada!!!\n");
}

bool isEmpty(Stack* s) {
    return s->top == NULL;
}

int StackSize(Stack* s) {
    return s->size;
}

void push(Stack* s, char question[50]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("\tErro ao alocar memória!\n\n");
        return;
    }
    
    strcpy(newNode->question, question);
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
    
    printf("\tPergunta inserida com sucesso!\n\n");
}

// essa pergunta deve ser criada antes de chamar pop, para poder passrmos a pergunta
void pop(Stack* s) {
    if(isEmpty(s)){
        printf("\tErro!Pilha está vazia!!\n\n");
        return;
    }
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
}

char* peek(Stack* s) {
    if(isEmpty(s)) {
        printf("\tErro: Pilha vazia!\n\n");
        return NULL;
    }
    return s->top->question;
}

void destroyStack(Stack* s) {
    Node* current = s->top;
    Node* next;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    s->top = NULL;
    s->size = 0;
    printf("\tPilha destruida\n\n");
}

void menu(){
    printf("[1]Adicionar pergunta\n");
    printf("[2]Responder pergunta\n");
    printf("[3]Ver proxima pergunta\n");
    printf("[4]Quantas perguntas faltam\n");
    printf("[5]Sair\n");
}

int main(){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    createStack(s);
    
    int option = 0;
    while(option != 5){
        menu();
        scanf("%d", &option);
        switch(option){
            case 1:{
                char pergunta[50];
                limparBuffer();
                fgets(pergunta, sizeof(pergunta), stdin);
                push(s, pergunta);
                break;
            }
            case 2:{
                char* pergunta;
                pergunta = peek(s);
                if(pergunta == NULL) break;
                printf("%s\n", pergunta);
                printf("resposta: ");
                limparBuffer();
                fgets(pergunta, sizeof(pergunta), stdin);
                pop(s);
                printf("\tpergunta respondida com sucesso!!\n\n");
                break;
            }
            case 3:{
                char* pergunta;
                pergunta = peek(s);
                if(pergunta == NULL) break;
                printf("%s\n", pergunta);
                break;
            }
            case 4:{
                printf("\tPerguntas a serem respondidas: %d\n\n", StackSize(s));
            }
            case 5:
                break;
            default:
                printf("\topção inválida\n\n");
        }
    }
    
    
    free(s);
    return 0;
}


