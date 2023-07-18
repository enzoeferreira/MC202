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

## <b>Reconstrução de árvores binárias</b>

É sempre possível reconstruir uma árvore enraizada binária com filhos ordenados a partir das seqüências de nós visitados em pré-ordem e em-ordem.

Por exemplo, dadas as cadeias ABCZEF e CBAEZF, resultantes das impressões das chaves em pré-ordem e em-ordem respectivamente, podemos reconstruir a árvore abaixo.
```
	    A
	   / \
	  B   Z
	 /   / \
	C   E   F
```

Como outro exemplo, dadas as cadeias ZADEK e ZAEDK, resultantes das impressões das chaves em pré-ordem e em-ordem respectivamente, podemos reconstruir a árvore abaixo.
```
          Z
           \
	    A
	     \
	      D
	     / \
	    E   K
```

Escreva um programa para reconstruir uma árvore binária na memória a partir das seqüências pré-ordem e em-ordem. Depois imprima as seqüências de nós na ordem de percursos em pós-ordem e em largura.

### <b>Entrada</b>

A entrada para o programa consiste de vários casos-de-teste. Cada caso-de-teste é formado por duas cadeias que são os símbolos nos nós da árvore binária impressos em pré-ordem e em-ordem, respectivamente.

As cadeias são formadas por símbolos ASCII entre 33 e 126 inclusive, distintos.

### <b>Saída</b>

A saída deve ter uma linha com os percursos pós-ordem e largura para cada caso-de-teste separados por um espaço.

### <b>Exemplos</b>

<details><summary>Exemplo 1</summary><p>

- Entrada
```
ABCZEF CBAEZF
ZADEK ZAEDK
A A
ab ba
Yxz xYz
fxy yxf
abc bac
weq qew
abg bga
acd adc
abt bta
poeq eopq
qwte wtqe
cdef fedc
ACBD ABDC
ABCDEF CBAEDF
```
- Saída
```
CBEFZA ABZCEF
EKDAZ ZADEK
A A
ba ab
xzY Yxz
yxf fxy
bca abc
qew weq
gba abg
dca acd
tba abt
eoqp poqe
tweq qwet
fedc cdef
DBCA ACBD
CBEFDA ABDCEF
```

</p></details>

#### <b>Requisitos Adicionais</b>

Seu programa deve reconstruir a árvore em representação explícita.

Toda memória alocada dinamicamente deve ser liberada pelo seu programa (usando free()).