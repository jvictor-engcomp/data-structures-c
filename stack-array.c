#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int itens[MAX_SIZE];
    int top;
    int qtd;
} Stack;

void createStack(Stack* s){
    s->top = -1; //o topo não é 0, pois então seria o primeiro elemento
    s->qtd = 0;
    printf("\tpilha criada!!!\n");
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

bool isFull(Stack* s) {
    return s->top == MAX_SIZE-1;
}

int StackSize(Stack* s) {
    return s->qtd;
}

void push(Stack* s, int value) {
    if(isFull(s)){
        printf("\tPilha cheia! Não foi possível inserir!\n\n");
        return;
    }
    s->itens[++(s->top)] = value;//primeiro incrementa dps isere na posição
    s->qtd++;
    printf("\tTarefa %d inserida com sucesso!\n\n", value);
}

int pop(Stack* s) {
    if(isEmpty(s)){
        printf("\tErro!Pilha está vazia!!\n\n");
    }
    s->qtd--;
    return s->itens[(s->top)--];//retorna o elemento decrementado
}

int peek(Stack* s) {
    if(isEmpty(s)) {
        printf("\tErro: Pilha vazia!\n\n");
    }
    return s->itens[s->top];
}

void destroyStack(Stack* s) {
    s->top = -1;
    s->qtd = 0;
    printf("\tLista reiniciada\n\n");
}

int main(){
    Stack* s = (Stack*)malloc(MAX_SIZE * sizeof(Stack));
    createStack(s);
    
    push(s, 7);
    printf("%d", peek(s));
    
    push(s, 10);
    printf("%d", peek(s));
    
    push(s, 11);
    printf("%d", peek(s));
    
    push(s, 13);
    printf("%d", peek(s));
    
    push(s, 21);
    printf("%d", peek(s));
    
    printf("\n\nTamanho da pilha: %d\n\n", StackSize(s));
    printf("Tarefa do topo: %d\n\n",peek(s));
    
    pop(s);
    pop(s);
    
    printf("\n\nTamanho da pilha: %d\n\n", StackSize(s));
    printf("Tarefa do topo: %d\n\n",peek(s));
    
    push(s, 25);
    printf("%d", peek(s));
    
    push(s, 26);
    printf("%d", peek(s));
    
    push(s, 29);
    printf("%d", peek(s));
    
    printf("\n\nTamanho da pilha: %d\n\n", StackSize(s));
    printf("Tarefa do topo: %d\n\n",peek(s));
    
    free(s);
    return 0;
}


