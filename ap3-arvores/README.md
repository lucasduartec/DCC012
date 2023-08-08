[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/Aah9uBSm)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=11158291&assignment_repo_type=AssignmentRepo)
# Indexação de Dados em C++

## 🤓 Resumo

Objetivo dessa atividade é implementar as estruturas de árvores balanceadas  🚀

Espera-se que ao final desta atividade você seja capaz de indexar e recuperar informaçoes usando diferentes estruturas e compreender os principais conceitos e analisar o desempenho deles ao serem empregados em uma base de dados reais.

## Atividade :

Nesta atividades, continuaremos a aprimorar o nosso sistema SIGA. 
Além de manipular o cadastro de informações de estudantes em um arquivo binário, iremos agora indexá-lo 
baseado em uma determinada chave de comparação. Nosso objetivo aqui é melhorar nosso algoritmo de busca que atualmente
tem custo linear para um versão com custo logaritmico usando árvores balanceadas.
### O que deve ser feito:

1. Implementar árvore AVL
1. Implementar árvore Vermelho-Preto
2. Implementar árvore B de ordem k.

Nas três estruturas, as seguintes rotinas devem ser implementadas:
* Inserção
* Busca
* Remoção

### Etapas:

1. Copiar as rotinas do ordenação no arquivo [sort.h](include/sort.h) que foram desenvolvidas na atividada prática anterior.
2. Implementar no arquivo [rb_tree.h](include/rb_tree.h) o tipo abstrato de dados árvore vermelho-preto.
3. Implementar no arquivo [b_tree.h](include/b_tree.h) o tipo abstrato de dados árvore B.
4. Implementar rotinas de testes definidos na pasta tests. 
5. Implementar o programa de análise de desempenho [desempenho.cc](app/performance.cc). Seguir as indicações nas marcações **TODO** no arquivo.
6. Implementar a indexação indexação dos estudantes por nome e turma, no [siga.cc](src/siga.cc). Novamente, vocês devem seguir as marcações **TODO** no arquivo. A indexação deve permitir realizar a busca tanto por nome quanto por matricula.

## Organização do Projeto 

O projeto está organizado na seguinte estrutura de arquivos:

src
  - [estudante.h](src/estudante.h) e [estudante.cc](src/estudante.cpp) : Implementa a entidade estudante
  - [siga.h](include/siga.h) e [siga.cc](src/siga.cc): Implementa um sistema simplista de gerenciamento de estudante.
  - [sort.h](include/sort.h): Implementa as rotinas de ordenação usando templates c++.
  - [rb_tree.h](include/rb_tree.h): Implementa as rotinas da árvore vermello-preta  usando templates c++.
  - [b_tree.h](include/b_tree.h):  Implementa as rotinas da árvore B  usando templates c++.
  - [tools.h](include/tools.h) e [tools.cc](src/tools.cc):  Implementa rotinas auxiliares para a verificação dos casos de testes e na medição de desempenho.
  
test
  - [test1.cc](tests/test1.cc):  Testa se a inserção da árvore vermelho-preta está correta.
  - [test2.cc](tests/test2.cc):  Testa se a busca da árvore vermelho-preta está correta.
  - [test3.cc](tests/test3.cc):  Testa se a remoção da árvore vermelho-preta está correta.
  - [test4.cc](tests/test4.cc):  Testa se a inserção da árvore B está correta.
  - [test5.cc](tests/test5.cc):  Testa se a busca da árvore B está correta.
  - [test6.cc](tests/test6.cc):  Testa se a remoção da árvore B está correta.

app
  - [performance.cc](app/performance.cc): Gera um relatório de performance entre os métodos.
  - [pesquisa.cc](app/pesquisa.cc): Permite a busca por nome e matricula.

**IMPORTANTE**
 - Detalhes do que deve ser feito encontram-se no arquivos fontes sob a tag **TODO**.
 - Os arquivos serão lidos ou criados na pasta [tests/data](tests/data)
 - Fiquem a vontade para alterar ou adicionar outras ferramentas nos arquivos [tools.h](include/tools.h) e [tools.cc](src/tools.cc)

### Compilação e Execução: 

Para a compilação em ambiente Unix/linux, use o comando:

 - Crie um diretório build
  ```
    mkdir build
  ```
 - Entre no diretório

  ```
    cd build
  ```
  - Chame o cmake
 
  ```
    cmake ../.
  ```
  - Compile o código:
  
  ```
    make 
  ```
  
  - Rode os testes:
   
  ```
    ctest
  ```
  
  - Para rodar o estudo de desempenho:
   ```
    ./performance

  ```
  
  - Para rodar a busca:
   ```
    ./pesquisa
    
  ```

## 📝 Entrega

Além do código, um relatório com a análise da atividade deverá ser entregue. Para tanto, basta editar o arquivo [REPORT.md](REPORT.md) e submeté-lo junto com o código-fonte. O relatório faz parte dos critérios avaliativos desta atividade. A não submissão dele, ocasionará em penalidades na nota final.

## 📝 Importante

- **Não será permita o envio de código-fonte vai upload de arquivos** no github!! Todos os
envios devem ser via *commits* e *push* ao repositório.
- **Trabalhos iguais -> nota 0!!** Logo não copie do colega!!! 





