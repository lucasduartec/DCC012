[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/WWHMvcR6)

[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=10900725)

# Heap Esquerdistas

## Objetivos:

Implementar o tipo abstrado de dados heap esquerdistas e a operação de intercalação de de duas heaps.

## 📝 Head Esquerdistas

Heaps são conjuntos ou dicionários que permitem que tenhamos acessos a elementos arbitrários de maneira eficiente.
Algumas vezes, contudo, queremos ter acesso apenas ao elemento mínimo (ou máximo).
Heaps ou filas de prioridades são estruturas de dados especializadas neste tipo de tarefa.

Heaps são utilizados, por exemplo, para:

 - Ordenar um vetor (Heapsort);
 - Implementação de simuladores de eventos discretos (DES);
 - Cálculo de caminhos mínimos (Algoritmo de Djikstra);
 - Cálculo de árvores geradoras de custo mínimo (Algoritmos de Kruskal e Prim);
 - Compressão de arquivos (Algoritmo de Huffman por exemplo).

Existem diversas maneiras de se implementar um heap, pode-se usar um arranjo linear como uma arvore quase completa ou usando árvores com ponteiros como as árvores esquerdistas e binomiais.

Em geral, um heap deve permitir as seguintes operações (se possível eficientemente):
 - *MakeHeap*:  Cria e devolve um novo heap vazio
 - *Insert*: Insere um elemento no heap e devolve o novo heap
 - *FindMax*: Seleciona o elemento maximo do heap
 - *RemoveMax*:  Remove o elemento máximo do heap

 Estamos interessados em **heaps intercaláveis** que além das operações anteriores também oferecem:
  - *Merge(H1,H2)*: cria e devolve um novo heap que contém todos os elementos de H1 e H2

Árvores esquerdistas são árvores binárias nas quais vale a propriedade esquerdista :
 - Para todo no *x* da árvore vale:
 ```math
 dist(Esq(x)) >= dist(Dir(x))
 ```
onde Esq(*x*) e Dir(*x*) são respectivamente, os filhos direito e esquerdo de *x*.

O *dist* de um nó *x* é o comprimento do caminho de *x* até o nó não nulo mais à direita.
 - Vamos considerar que o dist de um nó nulo é 0;

O pseudocodigo para cálculo do dist é apresentado a seguir:

```C
int dist(LeftistNode* node)
{
  if(node == nullptr)
    return 0;
  return 1 + min(dist(node->left),dist(node->right));
 }
```

## O que deve ser feito? 

Uma estrutura básica para a implementação da heap esquerdistas já foi fornecida. 
 - [leftist_heap_node.h](code/include/leftist_heap_node.h) implementa a estrutura de um nó de uma árvore esquerdista.
 - [leftist_heap.h](code/include/leftist_heap.h) tem uma implementação incompleta de heap esquerdistas.

 Nessa atividade, vocês devem implementar as operações **Merge**, **Insert**, **FindMax** e **RemoveMax**.

## Compilação e execução

```
cmake -B build 
cd build 
ctest
...

```
O comando ctest irá executar o conjunto de testes unitaŕios para avaliar sua implementação.

Os testes [1](tests/test1.cc)  ao [4](tests/test4.cc) criam heaps de inteiros para validar as funções implementadas. 


Veja no arquivo [CMakeLists.txt](CMakeLists.txt) o que os testes estão fazendo.

```
Test project /home/camata/git/dcc012/dcc012b-lab04-heap/build
    Start 1: Setup
1/4 Test #1: Setup ............................   Passed    0.02 sec
    Start 2: TestInsert
2/4 Test #2: TestInsert .......................   Passed    0.00 sec
    Start 3: TestFindMax
3/4 Test #3: TestFindMax ......................   Passed    0.00 sec
    Start 4: TestRemoveMax
4/4 Test #4: TestRemoveMax ....................   Passed    0.00 sec
    Start 5: TestMerge


100% tests passed, 0 tests failed out of 4

Total Test time (real) =   0.24 sec
```


## Como seu código será avaliado?

Seu código irá passar por um sistema de autocorreção onde algumas funcionalidades serão testadas.
Passar em todos testes é importante pois indica que você está no caminho certo. No entanto, outros aspectos podem afetar a sua nota, a saber:
 - código desorganizado e/ou sem documentação/comentários
 - detectação de vazamentos de memória
 - Implementação ineficiente


