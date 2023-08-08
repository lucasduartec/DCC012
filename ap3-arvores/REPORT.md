# Relatório: Métodos de Ordenação

**Componentes:**

- Lucas Duarte Chaves | 202176012

## Análise de desempenho:

Descreva aqui como foi feita a analise de desempenho.

Foram preenchidos vetores de inteiros aleatórios e ordenados, que possuíam diferentes tamanhos a cada iteração. Os dados armazenados nos vetores eram inseridos nas árvores. Para medir o desempenho de cada árvore foram adicionados os campos - número de comparações e número de rotações - como atributos das classes. Dessa forma, a cada comparação feita nos métodos de inserção e busca e cada rotação nos métodos de inserção eram incrementados. Ao fim de cada interação por tamanho de base de dados, esses números foram impressos na tela para viabilizar a análise.

Qual metodologia empregada? Usaram alguma técnica para melhorar o desempenho de alguns dos métodos?

A metodologia consistiu na escolha do usuário da configuração dos dados de entrada (aleatórios ou ordenados) e a operação desejada (inserção ou busca). Após a escolha, o computador executou o teste de perfomance e foi observado o resultado para cada uma das árvores, para cada um dos tamanhos da base de dados. Não foi utilizada nenhuma técnica para melhorar o desempenho dos métodos.

Qual o método mais rápido e o mais lento? Qual configuração da máquinas onde o teste de desempenho foi realizado?

As árvores AVL e vermelha e preta são mais eficientes do que a árvore B tanto para busca quanto inserção.
O teste de desempenho foi realizado em um computador com o processador Intel i5-7400 3.0 GHz e 16GB RAM.

Quantas execuções foram feitas?

Foram feitas 2 execuções para inserção e 2 execuções para busca de inteiros ordenados. Já para os inteiros aleatórios, foram executados 3 rotinas de inserção e 3 rotinas de busca.

## Conclusões

Descreva aqui suas conclusões pessoais sobre esta atividade e os resultados obtidos

Em termos de números de comparações e rotações, as rotinas de inserção se mantiveram estáveis e parelhas entre as árvores AVL e RB, sendo a árvore B a que deu mais trabalho para o computador. A busca, por ter sido de um número aleatório, variou bastante em relação ao número de comparações. Algumas vezes os números se encontravam na raíz - que resultava em 1 comparação apenas - e em outras vezes o número se encontrava bem fundo na árvore, resultando em um número enorme de comparações.
Com chaves aleatórias, o computador foi capaz de realizar as inserções nas árvores de forma instantânea. Já com chaves ordenadas, o computador não foi capaz de concluir a inserção a partir dos 10.000 elementos na árvore B.
Por ter relação inversa a altura, a ordem da árvore B se mostrou crucial em termos de eficiência para bases de dados muito grandes. Logo, concluí que para bases de dados maiores é uma boa escolha utilizar uma árvore B de ordem alta.
