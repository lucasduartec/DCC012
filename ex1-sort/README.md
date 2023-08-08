[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/R2Of_OEx)
[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-8d59dc4de5201274e310e4c54b9627a8934c3b88527886e3b421487c677d23eb.svg)](https://classroom.github.com/a/R2Of_OEx)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-f4981d0f882b2a3f0472912d15f9806d57e124e0fc890972558857b51b24a6f9.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=10651547)
 # Algoritmos de Ordenação (Parte 1) :mega:

## Objetivos:
Aprender os algoritmos básicos de ordenação. 
Espera-se que ao final desta atividade você seja capaz de classificar informaçoes usando métodos básicos de ordenação e 
compreender os principais conceitos relacionados aos métodos.

## 📝 Métodos de Ordenação Básicos:

Na última aula vimos os seguintes métodos de ordenação
 - Método da Bolha :snail:
 - Método da Seleção
 - Método da Inserção
 - Método MergeSort :checkered_flag:
 
## O que deve ser feito? 

### 1 - Configuração do projeto :gear:

Seu projeto deve ter a seguinte estrutura de arquivos:
```
.
  ./src
  ./include
  ./tests
  CMakeLists.txt
 ```
onde,
 - *src* deve conter todos os arquivos .cpp, .cc , .C, .cxx, etc.
 - *include* deve conter os arquicos .h, *.hpp.
 - *tests* deve conter o código-fonte dos teste. 

Crie um projeto CMake que cria uma biblioteca chamada *libsort* do código-fonte das pastas *src* e *include*

### 2 - Implementação dos métodos de ordenação

Da lista dos métodos acima, você obrigatoriamente deve implementar o *MergeSort*. Você também deve escolher um segundo 
método da lista e implementá-lo. Considere que os métodos irão ordenar vetores de números inteiros de 
tamanho N.

Tente por uma implementação genérica que possa ser utilizada com qualquer tipo de dado.

:mag_right: Dica: [C++ Template](https://cplusplus.com/doc/oldtutorial/templates/)

### 3 - Implementação de testes 

 - Implemente uma função que dado um vetor de tamanho N, preencha-o com inteiros aleatórios entre 0 a N.
 - Para cada método de ordenação, crie um rotina de teste. O teste deve verificar se a ordenação está correta. Você pode comparar a saida do seu código com a [rotina de ordenação do C++](https://cplusplus.com/reference/algorithm/sort/).

### 4 -  Avaliação de desempenho

Implemente uma programa que, para diferentes valores de N avalie o desempenho do método de ordenação em relação ao tempo de processamento.

:mag_right: Dica: use a biblioteca C++ chronos. Veja um exemplo [aqui](https://www.techiedelight.com/measure-elapsed-time-program-chrono-library/).

Avalie para diferentes valores de N. Por exemplo, N=100,500, 1000, 5000, 10000.


## Compilação e execução

Seu projeto deve compilar a biblioteca *libsort* e link-editar com os casos de testes e ao programa de avaliação de desempenho ao 
executar os comandos abaixo:

```
mkdir build
cmake ..
make
```
Se tudo estiver certo, os executáveis deverão estar na pasta ./build/tests e/ou ./build.

:mag_right: Diga: Use CTest para executar a verificação dos testes. Com isso os testes serão rodados na chamada do comando ctest.

**Divirtam-se!!!** :tada: :balloon:

## Extras:

- Caso faça alocação dinâmica, lembre-se de desalocá-los no final. Uma boa ferramenta para fazer essa verificação é o [Valgrind](https://valgrind.org/)

