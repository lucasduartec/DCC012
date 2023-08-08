[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/E6UIgIey)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=11361964)
# Casamento de Padrão

## Introdução 
Os algoritmos de casamento de padrões têm influenciado significativamente a ciência da computação e desempenham um papel essencial em diversos problemas do mundo real. 
Dentre eles podemos citar:
 - Filtrar palavras-chave em um mecanismo de busca,
 - Verificar se um determinado gene está presente em uma sequência de DNA
 - Implementar sistemas de detecção de intrusões em redes de computadores
 - Pesquisar palavras em um editor de texto, como um recurso de "Localizar" ou "Substituir", etc

Os algoritmos de casamento de padrões podem ser amplamente classificados em dois tipos de algoritmos
- Algoritmos de Casamento Exato
- Algoritmos de Casamento Aproximado

## Principais algoritmos

### Algoritmos de Casamento Exato 

Os algoritmos de casamento exato de strings têm como objetivo encontrar uma, várias ou todas as ocorrências de uma determinada sequência de caracteres (padrão) em uma sequência grande (texto ou sequências) de forma que cada correspondência seja perfeita. Todos os caracteres do padrão devem corresponder a uma subsequência correspondente na sequência de texto.

Esses algoritmos são projetados para buscar correspondências exatas, ou seja, as sequências de caracteres do padrão devem ser idênticas às sequências correspondentes na sequência de texto. Eles são úteis em situações em que a busca precisa ser precisa e não são toleradas variações ou erros na correspondência.

Alguns exemplos de algoritmos de casamento exato de strings incluem o algoritmo de Força Bruta (Brute-Force), o algoritmo de Knuth-Morris-Pratt (KMP), o algoritmo de Boyer-Moore e o algoritmo de Rabin-Karp. Esses algoritmos diferem em suas abordagens e eficiência, mas todos têm como objetivo encontrar correspondências exatas de padrões em uma sequência de texto.

### Algoritmos de Casamento Aproximado

PJá os algoritmos de casamento aproximado de strings procuram por substrings na string de entrada. Ao contrário do casamento exato de strings, esses algoritmos permitem correspondências aproximadas, onde as sequências de caracteres do padrão podem ter variações, erros de digitação ou outros tipos de diferenças em relação à sequência de texto.

Esses algoritmos são úteis em situações em que é necessário encontrar correspondências mesmo quando há incertezas ou erros nas sequências de caracteres. Eles são aplicados quando a tolerância a erros é necessária ou quando a busca precisa levar em consideração variações na escrita, erros de digitação ou diferenças sutis nas sequências de caracteres.

Alguns exemplos de algoritmos de casamento aproximado de strings incluem o algoritmo de Distância de Edição (Edit Distance), o algoritmo de Levenshtein, o algoritmo de Casamento de Sufixos (Suffix Matching) e o algoritmo de Casamento de Subsequências Comuns Mais Longas (Longest Common Subsequence Matching). Esses algoritmos aplicam diferentes métricas ou técnicas para medir a semelhança ou a distância entre as sequências de caracteres e encontrar correspondências aproximadas.

As aplicações práticas dos algoritmos de casamento aproximado de strings são amplas e incluem:

 - Correção ortográfica: Os algoritmos de casamento aproximado são usados em mecanismos de correção ortográfica para sugerir correções ou palavras semelhantes quando uma palavra digitada contém erros de digitação.

- Busca de palavras-chave: Em mecanismos de busca ou bancos de dados, os algoritmos de casamento aproximado permitem encontrar resultados relevantes mesmo quando as palavras-chave contêm erros de digitação ou variações na escrita.

- Autocompletar: Os algoritmos de casamento aproximado são utilizados em recursos de autocompletar em aplicativos ou sites para sugerir palavras ou frases com base no que o usuário está digitando, mesmo quando há erros ou variações nas sequências de caracteres.

- Análise de similaridade de texto: Os algoritmos de casamento aproximado são aplicados em tarefas de análise de texto para medir a similaridade entre documentos, identificar paráfrases ou encontrar conteúdo semelhante.

## O que deve ser feito

Neste trabalho iremos implementar implementar os seguintes métodos de casamento padrão exato:
 - Algoritmo de Força Bruta
 - Algoritmo de Knuth-Morris-Pratt (KMP)
 - Algoritmo de Boyer-Moore
 - Algoritmo de Rabin-Karp

### Estrutura e funções obrigatórias

Seu código DEVE conter as seguintes rotinas obrigatórias:
1. *std::vector<int> StringMaching(string text, string padrão, int metodo)*: retorna um vetor contendo todas os índices de ocorrencia do padrão no texto. A função utilizará o método especificado no terceiro parâmetro (0 = Força Bruta, 1 = Knuth-Morris-Pratt, 2 = Boyer-Moore, 3 = Rabin-Karp).
2. *void StringMathing(int metodo)*: procura pelo padrão definido no arquivo pattern.txt no conteúdo de um arquivo texto nomeado StringMacthingOrig.txt, utilizando o método especificado o parâmetro (0 = Força Bruta, 1 = Knuth-Morris-Pratt, 2 = Boyer-Moore, 3 = Rabin-Karp). Ambos arquivos estão no diretório files. A função deve salvar a lista de inteiros (referente as ocorrências do padrão no texto) em um arquivo texto StringMatchingOutput.txt. Cada inteiro serapado por um espaço em branco. 

O código-fonte dos algoritmos de casamento de padrão e as funções deve ser colocadas no diretório src.

O programa principal (main.cpp) deve oferecer ao usuário um menu para permitir a escolha de qual método será aplicado e se a entrada de dados será via teclado (uso da função do item 1) ou leitura via arquivo  (uso da função do item 2).

### Medição de Desempenho

Desenvolva também um programa para medir o desempenho dos algoritmos implementado. Para gerar as estatísticas de desempenho, você deverá executar a busca de uma padrão em um texto de tamanho significativo pelo menos M = 3 vezes. Ao final, compute as médias dos tempos de execução obtidas para as M execuções. Salve todos os resultados obtidos em um arquivo desempenho.txt, contendo tanto os resultados individuais quanto a média final.

### Relatório

A dupla deverá confeccionar um relatório (Report.md) contendo todas as análises feita, indicar as escolhas de texto e padrão empregados na comparação
e observações que acharem pertinentes. 





