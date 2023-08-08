# Relatório: Métodos de Ordenação

**Componentes:**

- Nome e Matricula
  Lucas Duarte Chaves 202176012

## Análise de desempenho:

Descreva aqui como foi feita a analise de desempenho.

Para a análise de desempenho foi utilizada a classe PerformanceTimer para medir o tempo de execução de cada iteração do algoritmo para os diferentes tamanhos do vetor. Além disso foi utilizado a classe PerformanceCounter para medir a quantidade de comparações e trocas de elementos em cada algoritmo de ordenação. Pode-se ainda escolher o preenchimento do vetor com elementos em disposição aleatória ou disposição descendente. Após cada execução, o programa imprime na tela o tempo de execução de cada algoritmo, o número de comparações e trocas para cada tamanho de vetor. Dessa forma, é possível analisar separadamente, caso a caso, o desempenho de cada um dos algoritmos para cada configuração de entrada.

Qual metodologia empregada? Usaram alguma técnica para melhorar o desempenho de alguns dos métodos?

Cada execução requer do usuário a configuração de entrada sobre o tipo de dado: inteiro ou estudante; e disposição dos dados: aleatória ou descendente. Após escolher, o programa realiza uma única execução e exibe os resultados. A média dos tempos foi realizada fisicamente (papel e caneta). Não foi utilizada nenhuma técnica para melhorar o desempenho dos métodos.

Qual o método mais rápido e o mais lento? Qual configuração da máquinas onde o teste de desempenho foi realizado?

O método mais rápido foi o HeapSort e o mais lento foi o BubbleSort.
O teste de desempenho foi realizado em um computador com o processador Intel i5-7400 3.0 GHz e 16GB RAM.

Quantas execuções foram feitas?

Foram feitas 6 execuções do programa para elementos inteiros -> 3 para disposição aleatória e 3 para disposição descendente. A mesma coisa foi feita para elementos do tipo Estudante.

## Conclusões

Descreva aqui suas conclusões pessoals sobre esta atividade e os resultados obtidos

Foi possível concluir que cada um dos algoritmos se sai melhor para cada configuração de entrada, sendo de responsabilidade do usuário fazer a melhor escolha do algoritmo para sua necessidade.
Quanto aos resultados obtidos pode-se citar: O BubbleSort é o menos eficiente dos algoritmos mas pode-se sair bem em vetores pequenos como o de tamanho 100; O MergeSort é estável e por isso pode ser usado para combinar ordenações. Também tem tempo de execução proporcional ao tamanho do vetor a ser ordenado; O QuickSort se saiu bem para o tamanho maior de vetor (5000 elementos) assim como o HeapSort.
