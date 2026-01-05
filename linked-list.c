#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Pista{
    int codigo;
    char dica[50];
    struct Pista* proximo;
    bool veracidade;
} Pista;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void inicializar(Pista **head){
    *head = NULL;
    printf("\tJogo inicializado com sucesso!\n\n");
}

//criar ela "solta no ar"
Pista* criarPista(int codigo, char* dica, bool veracidade){
    Pista* novaPista = (Pista*)malloc(sizeof(Pista));
    if(novaPista == NULL){
        printf("Erro ao alocar memoria!!");
        return NULL;
    }
    
    novaPista->codigo = codigo;
    strcpy(novaPista->dica, dica);
    novaPista->veracidade = veracidade;
    novaPista->proximo = NULL;
    return novaPista;
}

//inserir pista no final
void inserirNoFinal(Pista** head, int codigo, char* dica, bool veracidade){
    //criar ela "solta no ar"
    Pista* novaPista = criarPista(codigo, dica, veracidade);
    //checa se a lista esta vazia, caso sim, adiciona ela no inicio
    if(*head == NULL){
        *head = novaPista;
        return;
    }
    
    //caso não esteja, percorre até achar o final
    Pista* atual = *head;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }
    atual->proximo = novaPista;
}

//buscar uma pista por codigo, retorna o endereço dele
Pista* buscarPista(Pista* head, int codigo){
    Pista* atual = head;
    while(atual != NULL){
        if(atual->codigo == codigo){
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void removerDoInicio(Pista** head){
    if(*head ==NULL) {
        printf("\tLista vazia!\n\n");
        return;
    }
    Pista* temp = *head;
    *head = (*head)->proximo;
    free(temp);
    printf("\tremovido com sucesso!\n\n");
}

void removerPista(Pista** head, int codigo){
    if(*head == NULL){
        printf("\tLista vazia\n\n");
        return;
    }
    
    Pista* removido = buscarPista(*head, codigo);
    if (removido == NULL){
        printf("\tPista não encontrada\n\n");
        return;
    }
    if(removido == (*head)){
        removerDoInicio(head);
        return;
    }
    
    Pista* anterior = *head;
    while((anterior->proximo) != removido){
        anterior = anterior->proximo;
    }
    anterior->proximo = removido->proximo;
    free(removido);
    printf("\tremovido com sucesso!\n\n");
}

void imprimirPistasEditor(Pista *head){
    printf("=======================================\n\n");
    Pista *atual = head;
    if(atual == NULL){
        printf("\tLista vazia\n\n");
        return;
    }
    
    printf("Caminho do tesouro:\n\n");
    while(atual != NULL){
        printf("Codigo [%d]\nDica: %sVeracidade: %d\n\n", atual->codigo, atual->dica, atual->veracidade);
        
        atual = atual->proximo;
    }
    
    printf("XXXXXX[TESOUTO]XXXXXX\n\n");
    printf("=======================================\n\n");

}

void imprimirPistasJogador(Pista *head){
    printf("=======================================\n\n");
    Pista *atual = head;
    if(atual == NULL){
        printf("\tLista vazia\n\n");
        return;
    }
    
    printf("Caminho do tesouro:\n\n");
    while(atual != NULL){
        printf("Codigo [%d]\nDica: %s\n\n", atual->codigo, atual->dica);
        atual = atual->proximo;
    }
    
    printf("XXXXXX[TESOUTO]XXXXXX\n\n");    
    printf("=======================================\n\n");
}

//ver se o caminho que voce deixou está correto
bool verificarCaminho(Pista* head){
    Pista *atual = head;
    if(atual == NULL){
        printf("\tLista vazia\n\n");
        return false;
    }
    
    while(atual != NULL){
        if(atual->veracidade == false) return false;
        atual = atual->proximo;
    }
    return true;
}

void introducao(){
    printf("=======================================\n\n");
    printf("[1]Modo editor\n");
    printf("[2]Modo jogador\n");
    printf("[3]Sair\n");
}

void introducaoEditor(){
    printf("===================EDITANDO====================\n\n");
    printf("[1]Inserir Pista\n");
    printf("[2]Mostrar caminho\n");
    printf("[3]Remover por código\n");
    printf("[4]Sair\n\n");
}

void introducaoJogador(){
    printf("====================JOGANDO===================\n\n");
    printf("[1]Mostrar caminho\n");
    printf("[2]Remover por código\n");
    printf("[3]Verificar caminho\n");
    printf("[4]Sair\n\n");
}

int main() {
    Pista* head;
    inicializar(&head);
    
    int option = 0;
    
    printf("\t[CAÇA AO TESOURO]\n\n");
    printf("Regras:\n1. Uma pessoa assume papel de editor e cria o caminho do terouso com modo editor.\n");
    printf("2. Outra pessoa assume papel de jogador e tenta acertar quais pistasa são falsas ou verdadeiras.\n");
    printf("3. Use 0 para veracidade false e 1 para veraciade verdadeira.\n");
    printf("4. O jogador so ganha quando todas as pistas restantes são verdadeiras.\n");
    printf("5. Para as pistas, use afirmações como 'a terra eh plana'\n");
    while(option != 3){
        introducao();
        scanf("%d", &option);
        switch(option){
            case 1:
                option = 0;
                while(option != 4){
                    introducaoEditor();
                    scanf("%d", &option);
                    switch(option){
                        case 1:
                            int codigo;
                            char dica[50];
                            int veracidade;
                            printf("Digite as informações.\n");
                            printf("Codigo: ");
                            scanf("%d", &codigo);
                            
                            printf("Dica: ");
                            limparBuffer();
                            fgets(dica, sizeof(dica), stdin);
                            
                            printf("Veracidade: ");
                            scanf("%d", &veracidade);
                            
                            inserirNoFinal(&head, codigo, dica, veracidade);
                            break;
                        case 2:
                            imprimirPistasEditor(head);
                            break;
                        case 3: 
                            {
                            int codigo;
                            printf("Digite as informações.\n");
                            printf("Codigo: ");
                            scanf("%d", &codigo);
                            removerPista(&head, codigo);
                            break;}
                        case 4:
                            break;
                        default:
                            printf("\tOpção inválida!\n\n");
                    }
                }
                break;
            case 2:
                option = 0;
                while(option != 4){
                    introducaoJogador();
                    scanf("%d", &option);
                    switch(option){
                        case 1:
                            imprimirPistasJogador(head);
                            break;
                        case 2:{
                            int codigo;
                            printf("Digite as informações.\n");
                            printf("Codigo: ");
                            scanf("%d", &codigo);
                            removerPista(&head, codigo);
                            break;}
                        case 3:
                            if(verificarCaminho(head)){
                                printf("\t[PARABÉNS VOCÊ GANHOU!!!]\n\n");
                                break;
                            }
                            printf("\to caminho ainda não está correto...\n\n");
                            break;
                        case 4:
                            break;
                        default:
                            printf("\tOpção inválida!\n\n");
                    }
                }
                break;
            case 3:
                break;
            default: printf("\tOpção inválida!\n\n");
        }
    }
    
    return 0;
}