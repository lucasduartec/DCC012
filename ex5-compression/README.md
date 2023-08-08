[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/lZpXzTKG)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=11420176)
# Algoritmos de Compressão

Os  métodos de compressão listados a seguir são baseados nas ideias de dicionários e substituição de padrões para alcançar a compressão de dados. Cada um deles tem suas características e é aplicado em diferentes contextos, dependendo das necessidades específicas de compressão e descompressão dos dados.

### Algoritmo de Huffman

O algoritmo de Huffman é um método de compressão sem perdas utilizado para comprimir dados, como texto ou imagens. Ele foi desenvolvido por David A. Huffman em 1952. A ideia básica por trás do algoritmo é atribuir códigos de tamanho variável para cada símbolo em um conjunto de dados, onde os símbolos mais frequentes têm códigos mais curtos e os menos frequentes têm códigos mais longos.
O algoritmo funciona em duas etapas principais:

1. **Construção da árvore de Huffman**: Nesta etapa, é criada uma árvore binária com base nas frequências de ocorrência de cada símbolo no conjunto de dados. Os símbolos menos frequentes são colocados nas folhas mais distantes da raiz, enquanto os símbolos mais frequentes são colocados nas folhas mais próximas da raiz.

2. **Geração dos códigos de Huffman**: A partir da árvore de Huffman construída, são atribuídos códigos binários únicos a cada símbolo. Para obter o código de um símbolo específico, basta percorrer o caminho da raiz até a folha correspondente ao símbolo, registrando 0s para movimentos à esquerda e 1s para movimentos à direita.

O algoritmo de Huffman é eficiente para compressão de dados quando há uma distribuição desigual de símbolos. Isso ocorre porque os símbolos mais frequentes são representados por códigos mais curtos, resultando em uma menor quantidade total de bits necessários para representar o conjunto de dados.

### LZ77 (Lempel-Ziv 77)

O LZ77 é um algoritmo de compressão de dados que utiliza um esquema de dicionário deslizante.
Ele busca por padrões repetitivos em um fluxo de dados e representa esses padrões como uma referência a uma ocorrência anterior.
O algoritmo usa um buffer de tamanho fixo para armazenar o histórico das ocorrências e procura pela maior correspondência com o texto atual.
A representação de uma correspondência consiste em um par de três valores: (offset, length, next), indicando a posição relativa, o comprimento da correspondência e o próximo símbolo após a correspondência.
O LZ77 é um algoritmo simples e eficiente, usado em muitos formatos de compressão, como o formato gzip.

### LZ78 (Lempel-Ziv 78)

O LZ78 é um algoritmo de compressão de dados que utiliza um esquema de dicionário baseado em prefixos.
Ao contrário do LZ77, o LZ78 não possui um buffer de histórico fixo. Em vez disso, ele constrói um dicionário dinamicamente durante a compressão.
O algoritmo mapeia sequências de caracteres em uma tabela de dicionário, usando um código para representar cada sequência encontrada.
Durante a descompressão, o dicionário é reconstruído e as sequências de código são substituídas pelas sequências correspondentes do dicionário.
O LZ78 é mais eficiente do que o LZ77 em termos de taxa de compressão, mas requer mais recursos computacionais.

### LZW (Lempel-Ziv-Welch)

O LZW é um algoritmo de compressão de dados que é uma extensão do LZ78.
Assim como o LZ78, ele constrói um dicionário dinamicamente durante a compressão, mas utiliza uma tabela de dicionário mais eficiente em termos de espaço.
O LZW atribui códigos para sequências de caracteres encontradas, assim como o LZ78, mas também adiciona novas sequências ao dicionário à medida que são encontradas.
O algoritmo é conhecido por sua eficiência na compressão de dados com padrões repetitivos, como arquivos de texto e imagens com áreas de cor uniforme.
O LZW foi amplamente utilizado no formato de compressão de imagens GIF e é um algoritmo popular para compressão sem perdas em várias aplicações.

## Estrutura do repositório

### código-fonte 
include
 - [huffman.h](include/huffman.h): define a classe que implementa a codificação de huffman
 - [lz77.h](include/lz77.h): define a classe que implementa o método LZ77
 - [lz78.h](include/lz78.h): define a classe que implementa o método LZ78
 - [lzw.h](include/lzw.h): define a classe que implementa o método LZW

src
 - [huffman.cpp](src/huffman.cpp): implementa os métodos da classe huffman 
 - [lz77.cpp](src/lz77.cpp): implementa os métodos da classe lz77 
 - [lz78.cpp](src/lz78.cpp): implementa os métodos da classe lz78 
 - [lzw.cpp](src/lzw.cpp): implementa os métodos da classe lzw

### Arquivos de testes:
- [test_huffman.cpp](test_huffman.cpp): testa a compressão e descompressão de cadeia de caracteres usando Huffman. Imprime a tabela de códigod r a taxa de compressão.
- [test_lz77.cpp](test_lz77.cpp): testa a compressão e descompressão de cadeias de caracteres usando LZ77.
- [test_lz78.cpp](test_lz78.cpp): testa a compressão e descompressão de cadeias de caracteres usando LZ78.
- [test_lzw.cpp](test_lzw.cpp): testa a compressão e descompressão de cadeias de caracteres usando LZW.

## Configuração e compilação
```
cmake -B build
cd build
make
```

## Execução dos Testes

Dentro da pasta build, execute os comandos:
```
./test_hufffman -i "cadeia de caracteres"
./test_lz77 -i "cadeia de caracteres"
./test_lz78 -i "cadeia de caracteres"
./test_lzw -i "cadeia de caracteres"
```
onde *cadeia de caracters* é a cadeia de caracteres que será comprimida e descomprimida.

## O que precisa ser feito?

1. **Implementar a taxa de compressão** no arquivo [huffmam.cpp](src/huffman.cpp).
2. **Implementar** apenas o algoritmo de **compressão do [LZ78]**(src/lz78.cpp).
3. **Implementar** o algoritmo de **compressão e descompressão do [LZW]**(src/lzw.cpp).

*Observações:*
- A compressão e descompressão do [LZ77](src/lz77.cpp) já é fornecida. Tente entender a implementação! Poderá ser necessário no futuro! 
- Para as demais implementações, o pseudo-codigo é fornecido nos arquivos .cpp. 
- As rotinas de testes não devem ser alterados. 

## Importante

- **Só serão aceitos implementações que compilam!!!!**