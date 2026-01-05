#include <stdio.h>
#include <string.h>
#include "deque.h"

#define MAX_LETRAS 100

Deque deque;
char palavra[MAX_LETRAS];

void guardarPalavra(Deque* deque, char* palavra){
    for(int i = 0 ; i < strlen(palavra) ; i++){
        inserirFim(deque, palavra[i]);
    }
}

int verificarPalindromo(Deque* deque){
    char inicio;
    char fim;
    while(tamanho(deque)){
        if(acessarInicio(deque) != acessarFim(deque)){
            //printf("%c %c\n", acessarInicio(deque), acessarFim(deque));
            return 0;
        }
        removerInicio(deque);
        removerFim(deque);
    }
    return 1;
}

int main() {
    printf("Digite a palavra: ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0';
    
    guardarPalavra(&deque, palavra);
    
    if(verificarPalindromo(&deque)){
        printf("%s eh um palindromo.\n\n", palavra);
    } else {
        printf("%s nao eh um palindromo.\n\n", palavra);    
    }
}