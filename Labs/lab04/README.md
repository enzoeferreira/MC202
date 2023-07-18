# <b>Desempenho</b>

<details><summary><b>Testes</b></summary><p>

01:  saída correta.\
02:  saída correta.\
03:  saída correta.\
04:  saída correta.\
05:  saída correta.\
06:  saída incorreta.\
07:  saída correta.\
08:  saída correta.\
09:  saída incorreta.\
10:  saída correta.\
11:  saída correta.\
12:  limite de tempo ou memória excedido.\

Número de casos-de-teste: 12.\
Casos-de-teste bem sucedidos: 9.\
<b>Acerto: 75%</b>

</p></details>

## <b>Celebridade</b>

Uma celebridade é uma pessoa que é conhecida por todos mas que não conhece ninguém.
Escreva um programa em C para determinar se um conjunto de até 1000 pessoas tem uma celebridade.

### <b>Entrada</b>

A entrada é uma lista de frases da forma
```
pessoa conhece pessoa
```
sendo que o nome de uma pessoa tem no máximo 50 caracteres.

### <b>Saída</b>

A saída é uma frase da forma
```
X e' celebridade.
```
ou da forma
```
nao ha' celebridade.
```

### <b>Exemplos</b>

<details><summary>Exemplo 1</summary><p>

- Entrada
```
Joao conhece Teresa
Teresa conhece Raimundo
Raimundo conhece Maria
Maria conhece Joaquim
Joaquim conhece Lili
Lili conhece J. Pinto Fernandes
```
- Saída
```
Nao ha' celebridade.
```

</p></details>

<details><summary>Exemplo 2</summary><p>

- Entrada
```
Joao conhece Teresa
Teresa conhece Raimundo
Raimundo conhece Maria
Maria conhece Joaquim
Joaquim conhece Lili
Lili conhece J. Pinto Fernandes
Joao conhece Nina
Teresa conhece Nina
Raimundo conhece Nina
Maria conhece Nina
Joaquim conhece Nina
Lili conhece Nina
J. Pinto Fernandes conhece Nina
```
- Saída
```
Nina e' celebridade.
```

</p></details>