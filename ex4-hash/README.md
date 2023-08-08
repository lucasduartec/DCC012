[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/dvoMsG5F)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=11250018)

# Tabela Hash

## Objetivos 📝

Implementar a tabela hash usando a técnica de encadeamento separado para o tratamento de colisões.
Como visto em sala de aula, a técnica de encadeamento separado usa listas encadeadas para o tratamento de colisões. Nesta atividade,
devemos implementar uma tabela hash com encadeamento separado e comparar as diferentes funções hash em relação a distribuição uniforme nos dados na 
tabela e números de colisões.


## O que deve ser feito? 

Uma estrutura básica para a implementação da tabela hash já foi fornecida: 
 - Os arquivos [hash.h](hash/include/hash.h) e [hash.cc](hash/src/hash.cc) .

1. Implementar um tipo abstrato de dados hash com encadeamento separado, com as seguintes rotinas implementadas:
 - **Hash(m, hash)**: Construtor que cria uma tabela de tamanho m que usa a função hash
 - **insert(key)**: Insere data com chave key na tabela. A função deve retornar um ponteiro para o elemento inserido. Se já existir, retorna-se um ponteiro para ele.
 - **lookup(key)**: Pesquisa se data com chave key está na tabela. Se estiver, retorna ponteiro para ele, caso contrário retorne nullptr.
 - **~Hash()**: Remova a tabela hash da memória.
 
2. Implemente funções hash:
 - Divisão
 - Multiplicação 
 - MyHash (pesquise por um terceira opção de função hash para implementar)
 
A implementação destas funções devem estar no arquivo [hash_function.h](hash/include/hash_function.h).

3. Verifique se sua implementação passe nos testes básicos na pasta tests.

4. Rodar o teste de desempenho [performance.cc](performance.cc)

## Compilação e execução
Configuraçao inicial:

```
cmake -B build 
```
Compilação e execução dos testes:

```
cd build 
make
ctest
```

Teste de Desempenho

```
./performance

```
