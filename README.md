# data-structures-c

Uma códigos que aplicam estruturas de dados fundamentais em C praticados na cadeira Estrutura de Dados do curso de Engenharia de Computação no Instituto Federal de Ciência e Tecnologia do Ceará

* static-array.c

  Vetor estático básico.
  Introduz acesso por índice e noções de limite de memória, sem ponteiros nem alocação dinâmica.

* static-array(1).c

  Variação do vetor estático.
  Explora o mesmo conceito com pequenas diferenças de implementação ou exercícios alternativos.

* stack-array.c

  Pilha implementada com vetor estático.
  Apresenta controle de topo e o conceito LIFO, ainda sem alocação dinâmica.

* static-queue.c

  Fila estática baseada em vetor.
  Introduz FIFO e controle de início e fim, geralmente com vetor circular, aumentando levemente a complexidade.

* dynamic-allocation.c

  Introduz alocação dinâmica de memória (malloc, free).
  Base fundamental para todas as estruturas dinâmicas seguintes.

* linked-list.c

  Lista encadeada simples.
  Primeiro contato real com ponteiros para estruturas e nós encadeados.

* linked-list-stack.c

  Pilha dinâmica usando lista encadeada.
  Aplica lista ligada a uma estrutura abstrata conhecida, aumentando o nível de abstração.

* linked-list-queue.c

  Fila dinâmica com lista encadeada.
  Exige controle de ponteiros para início e fim, tornando a lógica mais cuidadosa.

* double-ended-queue.c

  Deque (fila de duas extremidades).
  Permite operações em ambas as pontas, normalmente com lista duplamente encadeada ou vetor circular.

* priority-queue.c

  Fila de prioridade.
  A mais complexa do conjunto, pois exige manutenção de ordem por prioridade, geralmente usando heap ou lógica de reorganização.
