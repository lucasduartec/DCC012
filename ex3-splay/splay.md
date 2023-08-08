# SPLAY TREES

Uma árvore splay é um tipo de árvore de busca binária balanceada. Estruturalmente, é idêntica a uma árvore de busca binária comum; a única diferença está nos algoritmos para localizar, inserir e excluir entradas.

Todas as operações de splay tree são executadas em tempo O(log n) na média, onde n é o número de entradas na árvore. Qualquer operação única pode levar tempo O(n) no pior caso. Mas qualquer sequência de k operações de splay tree, com a árvore inicialmente vazia e nunca excedendo n itens, leva O(k log n) tempo de pior caso.

As árvores Splay são projetadas para fornecer acesso especialmente rápido às entradas que foram acessadas recentemente, de modo que destacam-se em aplicativos em que uma pequena fração das entradas é o alvo da maioria das operações de localização. Como exemplos de
aplicação podemos citar:

- no Windows, a implementação da memória virtual, rede e código do sistema de arquivos,
- no compilador gcc e a biblioteca GNU C++,
- em algorimos de roteadores (rede),
- implementação do Unix malloc, 
- módulos carregaveis do kernel do linux, e em muitos outros softwares

**Vantagens das Árvores Splay**:

- Útil para implementar caches e algoritmos de coleta de lixo.
- Requer menos espaço, pois não são necessárias informações de balanceamento.
- Árvores Splay fornecem bom desempenho com nós contendo chaves idênticas.

**Desvantagens das Árvores Splay**:

- A altura de uma árvore splay pode ser linear ao acessar elementos em ordem não decrescente.
- O desempenho de uma árvore splay será pior do que uma árvore de busca binária simples balanceada em caso de acesso uniforme.

## Rotações

Como muitos tipos de árvores de busca balanceadas, as árvores de splay são mantidas balanceadas com a ajuda de mudanças estruturais chamadas *rotações*. Existem dois tipos - uma rotação à esquerda e uma rotação à direita - e cada um é o inverso do outro. Suponha que X e Y sejam nós de árvore binária, e T1, T2 e T3 são subárvores. Uma rotação transforma qualquer uma das configurações ilustradas abaixo na outra. Observe que a invariante da árvore de busca binária é preservada: as chaves em T1 são menores ou iguais a X; chaves em T3 são maiores ou iguais a Y; e as chaves em T2 são >= X e <= Y.
```
                y                                     x
               / \         (Right Rotation)          /  \
              x   T3   – - – - – - – - - ->         T1   y 
             / \       < - - - - - - - - -              / \
            T1  T2          (Left Rotation)            T2   T3
```

## Operações

### find(k)

A operação find(k) em uma árvore splay começa exatamente como a operação find() em uma árvore de busca binária comum: descemos a árvore até encontrarmos a entrada com a chave k, ou chegamos a um beco sem saída (um nó a partir do qual o próxima etapa lógica leva a um ponteiro nulo).

No entanto, uma árvore splay não termina seu trabalho aqui. Seja X o nó onde a busca terminou, contendo ou não a chave k. Nós elevaremos (*play*) o nó X na árvore através de uma sequência de rotações, de modo que X se torne a raiz da árvore. Por quê? Uma razão é que as entradas acessadas recentemente estão próximas à raiz da árvore e, se acessarmos as mesmas poucas entradas repetidamente, os acessos serão muito rápidos. Outra razão é porque se X estiver profundamente abaixo de um ramidicação desequilibrada da árvore, a operação de splay melhorará o equilíbrio ao longo desse ramo.

### Splay(X)

Quando elevamos um nó X até a raiz da árvore, existem três casos que determinam as rotações que usamos. A saber:

**Caso 1: Rotação zig-zag**

X é o filho direito de um filho esquerdo (ou o filho esquerdo de um filho direito): seja P o pai de X e seja G o avô de X.
Primeiro giramos X e P para a esquerda e depois giramos X e G para a direita, conforme ilustrado à direita. A imagem espelhada deste caso - onde X é um filho à esquerda e P é um filho à direita - usa as mesmas rotações na imagem espelhada: gire X e P para a direita, depois X e G para a esquerda. Tanto o caso ilustrado acima quanto sua imagem espelhada são chamados de caso "zig-zag".
```
Zag-Zig (Left Right Case):
       G                        G                            X       
      / \                     /   \                        /   \      
     P   T4  leftRotate(P)   X     T4    rightRotate(G)   P     G     
   /  \      ============>  / \          ============>   / \   /  \    
  T1   X                   P  T3                       T1  T2 T3  T4 
      / \                 / \                                       
    T2  T3              T1   T2                                     

Zig-Zag (Right Left Case):
  G                          G                           X       
 /  \                      /  \                        /   \      
T1   P    rightRotate(P)  T1   X     leftRotate(G)    G     P
    / \   =============>      / \    ============>   / \   / \   
   X  T4                    T2   P                 T1  T2 T3  T4
  / \                           / \                
 T2  T3                        T3  T4  

```

A imagem espelhada deste caso - onde X é um filho à esquerda e P é um filho à direita - usa as mesmas rotações na imagem espelhada: gire X e P para a direita, depois X e G para a esquerda. Tanto o caso ilustrado acima quanto sua imagem espelhada são chamados de caso "zig-zag".

**Caso 2: Rotação Zig-Zig**

X é o filho esquerdo de um filho esquerdo (ou o filho direito de um filho direito): a ORDEM das rotações é INVERTIDA do caso 1. Começamos com o avô e giramos G e P para a direita. Então, giramos P e X para a direita.
```
Zig-Zig (Left Left Case):
       G                        P                           X       
      / \                     /   \                        / \      
     P  T4   rightRotate(G)  X     G     rightRotate(P)  T1   P     
    / \      ============>  / \   / \    ============>       / \    
   X  T3                   T1 T2 T3 T4                      T2  G
  / \                                                          / \ 
 T1 T2                                                        T3  T4 

Zag-Zag (Right Right Case):
  G                          P                           X       
 /  \                      /   \                        / \      
T1   P     leftRotate(G)  G     X     leftRotate(P)    P   T4
    / \    ============> / \   / \    ============>   / \   
   T2   X               T1 T2 T3 T4                  G   T3
       / \                                          / \ 
      T3 T4                                        T1  T2

```

A imagem espelhada deste caso - onde X e P são ambos filhos à direita - usa as mesmas rotações na imagem espelhada: gire G e P para a esquerda, depois P e X para a esquerda. Tanto o caso ilustrado acima quanto sua imagem espelhada são chamados de caso "zig-zig".

Aplicamos repetidamente rotações em zig-zag e zig-zig a X; cada par de rotações eleva X dois níveis acima na árvore. Eventualmente, ou X alcançará a raiz (e terminamos), ou X se tornará o filho da raiz. Para esta última situação, aplica-se mais um caso.

**Caso 3: Rotação zig**

O pai de X, Y é a raiz: giramos X e Y para que X se torne a raiz. Isso é chamado de caso "zig". O espelho é chamado de zag.

```
                y                                     x
               / \     Zig (Right Rotation)          /  \
              x   T3   – - – - – - – - - ->         T1   y 
             / \       < - - - - - - - - -              / \
            T1  T2     Zag (Left Rotation)            T2   T3
```

A operação *splay* de um nó é sumarizado a seguir:

```
while X is not the root:
    if X is a child of the root:
        // ZIG:
        Rotate about the root to bring X to the root
    else:
        P := X.parent
        G := P.parent  // the grandparent of N
        if X and P are both left or both right children:
            // ZIG-ZIG:
            Rotate about G then about P to bring X up two levels
        else:
            // ZIG-ZAG:
            Rotate about P then about G to bring X up two levels
```
### Insert(k)

A operação de inserção na árvore do Splay é realizada seguindo os seguintes passos...

 - Passo 1: Verifique se a árvore está vazia.
 - Passo 2: Se a árvore estiver vazia, insira o *newNode* como nó Raiz e saia da operação.
 - Passo 3: Se a árvore não estiver vazia, insira o *newNode* como nó folha usando a lógica de inserção da árvore de pesquisa binária.
 - Passo 4: Após a inserção, *splay* o *newNode*
 -
### Remove(k)

Para excluir um nó em uma *splay tree*, devemos seguir as seguintes etapas:
- Elevamos esse nó com a chave k até a raiz.
- Apontamos as subarvores a esquerda e a direita, para as variáveis R1 e R2, respectivamente
- Deleta o nó com a chave k
- Se R1 for nullptr, a nova raiz da *splay tree* será R2
- Caso contrário:
  - Obtem-se o nó de maior chave de R1
  - Eleva-se esse nó para raiz de R1
  - Faz o filho a direita de R1 ser R2, e R1 raiz da *splay tree*

