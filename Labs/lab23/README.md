# <b>Desempenho</b>

<details><summary><b>Testes</b></summary><p>

01:  saída correta.\
02:  saída correta.\
03:  saída correta.\
04:  saída correta.\
05:  saída correta.\
06:  saída correta.\

Número de casos-de-teste: 6.\
Casos-de-teste bem sucedidos: 6.\
<b>Acerto: 100%</b>

</p></details>

## <b>Sublistas</b>

Mais dia menos dia, qualquer pessoa que programa em alguma linguagem que importa vai precisar extrair uma sublista de uma lista encadeada.

### <b>Entrada</b>

A entrada é composta de uma linha que tem a enumeração dos elementos de uma lista encadeada de inteiros A (A não será vazia), seguida de uma ou mais linhas que especificam uma operação na lista encadeada.
Se a linha começar com s então o programa deve extrair uma sublista de A e substituir A pela sublista. O formato da entrada está exemplificado abaixo.

Se a linha começar com + então o programa deve extrair uma sublista de A e inserir essa sublista na posição de A que estiver indicada. A posição em A é a posição que o primeiro elemento da sublista vai ocupar em A, entre 0 e |A|. Os elementos naquela posição e posteriores antes da inserção ficarão depois a sublista após a inserção. O formato da entrada está exemplificado abaixo.

Se a linha começar com f então o programa deve terminar. Antes de terminar, todos os nós da lista devem ser removidos.

Os índices de elementos de uma lista A sempre serão números entre 0 e |A|-1, sendo que a cabeça está no índice 0.

### <b>Saída</b>

A cada linha que especifica uma operação, o programa deve imprimir os elementos de A, da cabeça para o rabo. O formato da saída está exemplificado abaixo.

### <b>Exemplos</b>

<details><summary>Exemplo 1</summary><p>

- Entrada
```
A = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19}
s A[0..9]
s A[9..0]
+ A[6..3] 2
s A[2..10]
s A[4..7]
s A[2..0]
s A[1..1]
f
```
- Saída
```
A: { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 }
A: { 19, 18, 17, 16, 15, 14, 13, 12, 11, 10 }
A: { 19, 18, 13, 14, 15, 16, 17, 16, 15, 14, 13, 12, 11, 10 }
A: { 13, 14, 15, 16, 17, 16, 15, 14, 13 }
A: { 17, 16, 15, 14 }
A: { 15, 16, 17 }
A: { 16 }
```

</p></details>

<details><summary>Exemplo 2</summary><p>

- Entrada
```
A = {6, 7, 0, 5, 2, 3, 1, 9, 8, 4}
+ A[1..4] 1
s A[0..13]
+ A[4..6] 2
s A[7..5]
+ A[0..0] 0
+ A[3..3] 0
+ A[0..1] 3
+ A[2..2] 4
+ A[5..0] 2
f
```
- Saída
```
A: { 6, 7, 0, 5, 2, 7, 0, 5, 2, 3, 1, 9, 8, 4 }
A: { 6, 7, 0, 5, 2, 7, 0, 5, 2, 3, 1, 9, 8, 4 }
A: { 6, 7, 2, 7, 0, 0, 5, 2, 7, 0, 5, 2, 3, 1, 9, 8, 4 }
A: { 2, 5, 0 }
A: { 2, 2, 5, 0 }
A: { 0, 2, 2, 5, 0 }
A: { 0, 2, 2, 0, 2, 5, 0 }
A: { 0, 2, 2, 0, 2, 2, 5, 0 }
A: { 0, 2, 2, 2, 0, 2, 2, 0, 2, 0, 2, 2, 5, 0 }
```

</p></details>

#### <b>Requisitos Adicionais</b>

Seu programa deve usar uma lista encadeada.

Não pode haver vetor algum no programa.