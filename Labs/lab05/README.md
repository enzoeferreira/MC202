# <b>Desempenho</b>

<details><summary><b>Testes</b></summary><p>

01:  saída correta.\
02:  saída correta.\
03:  saída correta.\
04:  limite de tempo ou memória excedido.\
05:  saída correta.\
06:  saída correta.\
07:  limite de tempo ou memória excedido.\
08:  saída incorreta.\

Número de casos-de-teste: 8.\
Casos-de-teste bem sucedidos: 5.\
<b>Acerto: 62%</b>

</p></details>

## <b>Matriz esparsa em vetor de coordenadas</b>

Uma matriz é <b>esparsa</b> se tem proporcionalmente muitos zeros. "Muitos" não é uma quantidade definida claramente, mas em geral se uma matriz com m linhas e n colunas tem um número de entradas não-zero da ordem de m+n então ela é considerada esparsa.
Quando uma matriz esparsa é colocada na memória, uma parte significativa do espaço é usada para armazenar zeros, que em muitos casos é simplesmente ausência de informação.

Estruturas de dados para matrizes esparsas não armazenam os zeros. Elas sacrificam o tempo de acesso constante a qualquer elemento oferecido pelas matrizes para usar menos memória. Algumas estruturas de dados para matrizes esparsas são melhores para percorrer os elementos de uma mesma linha ou coluna da matriz. Algumas são boas para recuperação, mas piores para atualização da matriz.

Uma dessas representações é o vetor de coordenadas: cada elemento não-zero em i,j é colocado em um vetor em que cada posição armazena uma tripla (i,j,elemento).

Para permitir a recuperação mais eficiente dos elementos da matriz, o vetor é mantido ordenado por i e, para o mesmo i, por j. Por outro lado, quando a matriz é atualizada e algum elemento deixa de ser zero ou passa a ser zero, a atualização do vetor de coordenadas mantendo-o ordenado é mais custosa.

Por exemplo, a matriz
```
0 0 0 0
7 0 0 0
0 0 9 0  
0 0 0 0
0 8 0 5
```
pode ser representada em um vetor de coordenadas da forma:
```
| 1,0,7 | 2,2,9 | 4,1,8 | 4,3,5 |
```
Neste trabalho você deve implementar um vetor de coordenadas com operações de recuperação e atualização dos elementos de uma matriz esparsa. Inicialmente a matriz terá k elementos não zero, k ≤ m+n. Depois será atualizada e consultada por comandos que são dados na entrada.

### <b>Entrada</b>

A entrada para o programa começa com uma linha com as dimensões m e n de uma matriz de números inteiros. Vamos chamá-la de M. O vetor de coordenadas deve armazenar até m+n elementos não-zero de M.
Depois vem uma linha com o número k de linhas que serão as próximas na entrada e têm elementos em M que são diferentes de zero. k é menor ou igual a m+n.

Em seguida vêm k triplas com a forma [i,j] x, indicando que M[i,j] = x. Essas triplas estão ordenadas por i e por j.

As próximas linhas têm uma das seguintes formas:

- a [i,j] x\
Ao ler uma linha dessa forma, se M[i,j] já estiver no vetor de coordenadas então o valor desse elemento deve ser atualizado tornando-se igual a x, mas se x for igual a zero então M[i,j] deve ser removido do vetor de coordenadas. Se M[i,j] não estiver no vetor de coordenadas e x for diferente de zero, esse elemento deve ser inserido.

    Se o vetor de coordenadas já estiver cheio (i.e. com n+m elementos) e uma inserção for necessária então ela não deve ser feita e a mensagem "O VC esta' cheio." deve ser impressa, como ilustrado abaixo.

- r [i,j]\
Linhas dessa forma indicam que M[i,j] deve ser recuperado e impresso com o formato ilustrado no exemplo a seguir.

- p\
Ao ler uma linha dessa forma seu programa deve imprimir o conteúdo do vetor de coordenadas na forma de uma lista de triplas ordenadas por linha e coluna, com um espaço depois de cada elemento, em uma linha, como exemplificado abaixo.

    Se o vetor de coordenadas estiver vazio, o programa deve imprimir "O VC esta' vazio." em uma linha.

- t\
Ao ler uma linha dessa forma seu programa deve terminar.

### <b>Saída</b>

A saída do seu programa deve conter a saída dos comandos a, r e p.

#### <b>Requisitos Adicionais</b>

Seu programa deve usar um vetor de structs de tamanho máximo m+n. Não deve haver qualquer outra estrutura que use memória maior que uma constante em seu programa.