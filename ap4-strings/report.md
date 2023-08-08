# Relatório

O texto escolhido foi um conto de Edgar Allan Poe sobre um barril de vinho chamado Amontillado. A palavra utilizada como padrão a ser procurado foi o nome do vinho. Essa escolha se deu pela palavra ter um tamanho razoável, tornando-se interessante para alguns algoritmos de casamento de padrão devido ao tamanho do deslocamento no processo de busca. Essa circunstância torna mais evidente os contrastes entre os métodos da Força Bruta e o KMP, por exemplo.

=======================================================

Tempo de Execução para o método de Força Bruta:
1ª execução: 1.0320 milissegundos
2ª execução: 9.9436 milissegundos
3ª execução: 6.2478 milissegundos

Média final: 5,7411 milissegundos

=======================================================

Tempo de Execução para o método de Knuth-Morris-Pratt:
1ª execução: 7.9867 milissegundos
2ª execução: 8.2605 milissegundos
3ª execução: 7.9957 milissegundos

Média final: 8.0809 milissegundos

=======================================================

Tempo de Execução para o método de Boyer-Moore:
1ª execução: 3.2299 milissegundos
2ª execução: 3.2447 milissegundos
3ª execução: 3.3241 milissegundos

Média final: 3,2662 milissegundos

=======================================================

Tempo de Execução para o método de Rabin-Karp:
1ª execução: 1.5803 milissegundos
2ª execução: 1.5681 milissegundos
3ª execução: 1.5924 milissegundos

Média final: 1.5802 milissegundos

=======================================================

## Observações

O primeiro comentário é a respeito da quantidade de execuções realizadas. Como foram consideradas apenas 3 execuções de cada algoritmo para este relatório, a média final observada pode não ser fiél à qualidade e superioridade de alguns métodos sobre outros. Por exemplo, para 3 execuções, o método Força Bruta obteve uma média de tempo maior que o método KMP. Entretanto, se levássemos em conta uma quantidade grande de execuções, possivelmente notaríamos uma tradução de resultados diferente, e assim, uma conclusão mais plausível.
Vale ressaltar ainda que, ao longo da realização desta atividade, pudemos observar que cada um dos métodos se comportou de maneira diferente para diferentes textos e padrões.

Entretanto, considerando os resultados do relatório e os resultados obtidos ao longo da execução do código, pudemos verificar uma maior inconstância do método Força Bruta, apresentado alguns tempos bons e outros ruins. Para 3 execuções, o KMP se mostrou da mesma maneira, embora seja um dos métodos mais eficientes. O método Boyer-Moore apresentou um padrão de 3 milissegundos enquanto o Rabin-Karp teve a melhor performance, com uma média de 1,5 milissegundos.

## Dados da Dupla

Lucas Duarte Chaves - 202176012
Lucas Paiva dos Santos - 202176026
