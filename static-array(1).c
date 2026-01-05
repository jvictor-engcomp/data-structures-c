#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titulo[100];
    char autor[50];
    int ano;
} livro;

void inserirLivros(int *qtd, livro **ponteiro){
    livro *temp = realloc(*ponteiro, (*qtd + 1) * sizeof(livro));
    if(temp == NULL){
        printf("erro ao reallocar memoria");
        free(temp);
        return;
    }
    *ponteiro = temp;
    
    printf("--------------------------------------------------------\n");
    printf("Digite as informações.\nTitulo: ");
    while (getchar() != '\n');//limpando buffer
    fgets((*ponteiro)[*qtd].titulo, sizeof((*ponteiro)[*qtd].titulo), stdin);
    (*ponteiro)[*qtd].titulo[strcspn((*ponteiro)[*qtd].titulo, "\n")] = '\0';//tira o /n da string
    
    printf("Autor: ");
    fgets((*ponteiro)[*qtd].autor, sizeof((*ponteiro)[*qtd].autor), stdin);
    (*ponteiro)[*qtd].autor[strcspn((*ponteiro)[*qtd].autor, "\n")] = '\0';//tira o /n da string
    
    printf("Ano: ");
    scanf("%d", &((*ponteiro) + *qtd)->ano);
    
    (*qtd)++;
    
    printf("--------------------------------------------------------\n");
    // free(temp); tirar dúvida com a professora o motivo de isso dar errado
}

void listarLivros(int qtd, livro *ponteiro){
    printf("--------------------------------------------------------\n");
        if(qtd == 0){
            printf("\n\n\t[Sem livros!]\n\n");
        }
        else{
            for(int i = 0 ; i < qtd ; i++){
                printf("\n");
                printf("\t%s\n", ponteiro[i].titulo);
                printf("\tAutor: %s\n", ponteiro[i].autor);
                printf("\tAno: %d\n", ponteiro[i].ano);
            }
        }

    printf("\n--------------------------------------------------------\n\n");
}

int findForTitulo(char titulo[100], int qtd, livro *ponteiro){
    for (int i = 0 ; i < qtd ; i++){
        if(!strcmp(titulo,ponteiro[i].titulo)) return i;
    }
    
    return -1;
}

void removerLivro(int *qtd, livro *ponteiro){
    int indice;
    int choose;
    char titulo[100];
    printf("--------------------------------------------------------\n");
    printf("Digite o titulo do livro: ");

    while (getchar() != '\n');//limpando buffer
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0';
    
    indice = findForTitulo(titulo, *qtd, ponteiro);
    if(indice == -1) {
        printf("\n\t[Livro nao encontrado!!!]\n\n");
        return;
    }
    printf("\t%s\n", ponteiro[indice].titulo);
    printf("\t%s\n", ponteiro[indice].autor);
    printf("\t%d\n\n", ponteiro[indice].ano);
    
    printf("Exluir?\n[1]Sim\n[2]Nao\n");
    scanf("%d", &choose);
    
    if(choose == 1){
        ponteiro[indice] = ponteiro[*qtd - 1];
        (*qtd)--;
    }
    printf("Livro apagado com sucesso\n");
    printf("--------------------------------------------------------\n");
}


void intro(){
    printf("O que deseja fazer?\n\n");
    printf("[1]Listar livros\n");
    printf("[2]Inserir livro\n");
    printf("[3]Remover livro\n");
    printf("[4]Buscar livro\n");
    printf("[5]Sair\n");
}



int main(){
    int qtd = 5; //so para iniciar
    livro *biblioteca = malloc(qtd * sizeof(livro));
    int choice;
    
    strcpy(biblioteca[0].titulo, "Senhor dos Aneis");
    strcpy(biblioteca[1].titulo, "Jogos Vorazes");
    strcpy(biblioteca[2].titulo, "Herry Potter");
    strcpy(biblioteca[3].titulo, "Diário de Um Banana");
    strcpy(biblioteca[4].titulo, "Eleanor e Gray");
    
    strcpy(biblioteca[0].autor, "Rafael Maia");
    strcpy(biblioteca[1].autor, "Ruan Rato");
    strcpy(biblioteca[2].autor, "Maurino Muller");
    strcpy(biblioteca[3].autor, "Otavio Oteivius");
    strcpy(biblioteca[4].autor, "El natan");
    
    biblioteca[0].ano = 2025;
    biblioteca[1].ano = 2018;
    biblioteca[2].ano = 2046;
    biblioteca[3].ano = 2016;
    biblioteca[4].ano = 2017;
    
    printf("\nOBS: programa sensivel a letras maiusculas e espacos\n\n");
    printf("\t[Bem-Vindo!]\n\n");
    while(1) {
        intro();
        
        fflush(stdin);
        scanf("%d", &choice);
        switch(choice){
            case 1:
                listarLivros(qtd, biblioteca);
                break;
            case 2:
                inserirLivros(&qtd, &biblioteca);
                break;
                
            case 3:
                removerLivro(&qtd, biblioteca);
                break;
            case 4:{
                char titulo[100];
                int indice;
                printf("--------------------------------------------------------\n");
                printf("Digite o titulo do livro: ");
                
                while (getchar() != '\n');//limpando buffer
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0';
                
                indice = findForTitulo(titulo, qtd, biblioteca);
                if(indice == -1) {
                printf("\n\t[Livro nao encontrado!!!]\n\n");
                break;
                }
                
                printf("\t%s\n", biblioteca[indice].titulo);
                printf("\tAutor: %s\n", biblioteca[indice].autor);
                printf("\tAno: %d\n", biblioteca[indice].ano);
                
                printf("--------------------------------------------------------\n");
                break;
            }
            case 5:
                return 0;
            
            default: printf("\tDigite opcao valida!!!\n\n");
        }
        
    }
    
    free(biblioteca);
    
    return 0;
}