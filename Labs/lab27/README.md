# <b>Desempenho</b>

<details><summary><b>Testes</b></summary><p>

01:  saída correta.\
02:  saída correta.\
03:  limite de tempo ou memória excedido.\
04:  saída incorreta.\

Número de casos-de-teste: 4.\
Casos-de-teste bem sucedidos: 2.\
<b>Acerto: 50%</b>

</p></details>

## <b>Heap de mínimo</b>

Várias aplicações processam dados na ordem dada por uma fila de prioridades, de máximo ou de mínimo. As operações essenciais em uma fila de prioridades de mínimo são inserir uma chave, recuperar uma chave mínima e remover uma chave mínima.

O heap é uma boa estrutura de dados para implementar uma fila de prioridades: para n chaves, as operações de inserção e remoção de mínimo levam tempo O(log n) cada, cada recuperação de mínimo leva tempo O(1) e a estrutura usa pouca memória.

Neste trabalho deve-se implementar um heap de mínimo em representação seqüencial com capacidade para n pares {chave,prioridade}. As chaves serão números naturais (no intervalo de unsigned) e as prioridades serão números inteiros (no intervalo de int). O heap deve ser minimo nas prioridades.

### <b>Entrada</b>

Seu programa deve interpretar comandos da seguinte forma:
- c n\
O programa deve criar um heap vazio com capacidade para n pares {chave,prioridade}. Se já houver um heap sendo mantido pelo programa, ele deve ser removido e um novo heap vazio deve ser criado.
- i chave prioridade\
O programa deve inserir o par {chave,prioridade} no heap.
- r\
O programa deve remover um mínimo do heap. Se houver mais de um mínimo, o par {chave,prioridade} que mais antigamente foi adicionado ao heap deve ser removido. Se o heap estiver vazio então o programa não deve fazer nada.
- m\
O programa deve recuperar um mínimo do heap e imprimir os dados em uma linha. Se o heap estiver vazio então o programa deve imprimir "fila de prioridades vazia". Veja o exemplo abaixo. Se houver mais de um mínimo, o par {chave,prioridade} que mais antigamente foi adicionado ao heap deve ser recuperado.
- t\
Terminar o programa. Antes de terminar, toda memória alocada dinamicamente deve ser liberada.

### <b>Saída</b>

A saída deve conter o resultado da execução dos comandos m.

### <b>Exemplos</b>

<details><summary>Exemplo 1</summary><p>

- Entrada
```
c 13
i 6 4
i 2 8
m
r
m
r
m
i 10 15
i 12 9
i 21 7
i 0 5
i 15 7
i 5 30
i 6 5
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
t
```
- Saída
```
prioridade minima 4, chave 6
prioridade minima 8, chave 2
fila de prioridades vazia
prioridade minima 5, chave 0
prioridade minima 5, chave 6
prioridade minima 7, chave 21
prioridade minima 7, chave 15
prioridade minima 9, chave 12
prioridade minima 15, chave 10
prioridade minima 30, chave 5
fila de prioridades vazia
```

</p></details>

<details><summary>Exemplo 2</summary><p>

- Entrada
```
c 32
i 31 310
i 30 300
i 29 290
i 28 280
i 27 270
i 26 260
i 25 250
i 24 240
i 23 230
i 22 220
i 21 210
i 20 200
i 19 190
i 18 180
i 17 170
i 16 160
i 15 150
i 14 140
i 13 130
i 12 120
i 11 110
i 10 100
i 9 90
i 8 80
i 7 70
i 6 60
i 5 50
i 4 40
i 3 30
i 2 20
i 1 10
i 0 0
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
m
r
t
```
- Saída
```
prioridade minima 0, chave 0
prioridade minima 10, chave 1
prioridade minima 20, chave 2
prioridade minima 30, chave 3
prioridade minima 40, chave 4
prioridade minima 50, chave 5
prioridade minima 60, chave 6
prioridade minima 70, chave 7
prioridade minima 80, chave 8
prioridade minima 90, chave 9
prioridade minima 100, chave 10
prioridade minima 110, chave 11
prioridade minima 120, chave 12
prioridade minima 130, chave 13
prioridade minima 140, chave 14
prioridade minima 150, chave 15
prioridade minima 160, chave 16
prioridade minima 170, chave 17
prioridade minima 180, chave 18
prioridade minima 190, chave 19
prioridade minima 200, chave 20
prioridade minima 210, chave 21
prioridade minima 220, chave 22
prioridade minima 230, chave 23
prioridade minima 240, chave 24
prioridade minima 250, chave 25
prioridade minima 260, chave 26
prioridade minima 270, chave 27
prioridade minima 280, chave 28
prioridade minima 290, chave 29
prioridade minima 300, chave 30
prioridade minima 310, chave 31
fila de prioridades vazia
```

</p></details>