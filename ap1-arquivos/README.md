[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-8d59dc4de5201274e310e4c54b9627a8934c3b88527886e3b421487c677d23eb.svg)](https://classroom.github.com/a/zs-Hcqvz)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-f4981d0f882b2a3f0472912d15f9806d57e124e0fc890972558857b51b24a6f9.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=10567490)
# Manipulando arquivos em C/C++

# :wave: Manipulaçao de Arquivos binários

## 🤓 Resumo

Objetivo dessa atividade é praticar a manipulaçao de arquivos em C++ 🚀

Espera-se que ao final desta atividade você seja capaz de criar, editar, buscar informaçoes e 
fechar arquivos e compreender os principais conceitos por tras dessas açoes. 

## Atividade :

Nesta atividades, desejamos criar um embrião do nosso sistema SIGA. 
Iremos manipular o cadastro de informações de estudantes em um arquivo binário.
Nosso projeto está organizado na seguinte estrutura de arquivos:

src
  - [estudante.h](src/estudante.h) e [estudante.cc](src/estudante.cpp) : Implementa a entidade estudante
  - [siga.h](src/siga.h) e [siga.cc](src/siga.cc): Implementa um sistema simplista de gerenciamento de estudante.
  
test
  - [test1.cc](tests/test1.cc):  Testa a abertura do arquivo e a leitura de estudantes  
  - [test2.cc](tests/test2.cc):  Insere dado de estudante no gerencia_siga
  - [test3.cc](tests/test3.cc):  Pesquisa estudante na base de dados
  - [test4.cc](tests/test4.cc):  Inprime Informações de um estudante na base de dados 
  - [test5.cc](tests/test5.cc):  Altera os dados de cadastro de uma aluno.
  - [test6.cc](tests/test6.cc):  Imprime a base de dados em um arquivo texto no formato CSV. 

**IMPORTANTE**
 - Detalhes do que deve ser feito encontram-se no arquivos fontes [siga.cc](src/siga.cc) sob a tag **TODO**.
 - Os arquivos da pasta tests não devem ser modificados.
 - Os arquivos serão lidos ou criados na pasta [tests/data](tests/data)

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
  - Compile os testes:
  
  ```
    make ../.
  ```
  
  - Rode os testes:
   
  ```
    ctest
  ```

*Importante:* Entre uma chamadas do ctest, remova o arquivo estudantes.bin da pasta tests/data.

## 📝 Importante

Você deve implementar em C++ usando fstream.

## 📝 Procure saber mais...

Consulte as referêmcias abaixos:

* ["Referencia cplusplus"](https://www.cplusplus.com/reference/fstream/fstream/).

* ["Tutorial sobre Arquivos"](https://www.cplusplus.com/reference/fstream/fstream/)



