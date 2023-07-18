# <b>Desempenho</b>

<details><summary><b>Testes</b></summary><p>

Atividade não realizada.

</p></details>

## <b>Belo Horizonte</b>

Belo Horizonte foi projetada com traçado quase ortogonal. A região central de hoje corresponde ao projeto original da cidade e aparece na imagem abaixo. Também é uma cidade que tem uma sigla de duas letras bem estabelecida; além de BH, tem LA e NY. E tem a forma recursiva "Be Happy in BH".

Além de BH, há várias cidades com traçado ortogonal e variações dele. Este laboratório consistem em escrever um programa para determinar o número mínimo de quarteirões que separam uma pessoa de algum ponto-de-interesse em uma cidade ortogonal, evitando quarteirões muito aglomeradaos.

### <b>Entrada</b>

A cidade está modelada como uma matriz de duas dimensões, sendo que cada elemento representa um quarteirão. Cada elemento da matriz é um número em {0,1,2,3}. O número 3 indica o quarteirão onde a pessoa está inicialmente. O número 2 indica um quarteirão muito aglomerado. O número 0 indica que o quarteirão tem um ponto-de-interesse. O número 1 indica um quarteirão comum.

A primeira linha da entrada contém dois números naturais n e m que indicam o número de linhas e o número de colunas da representação da cidade. Cada uma das n linhas seguintes contém m números inteiros, descrevendo os tipos dos quarteirões.

Haverá apenas um valor 3, no máximo 10 valores 0 e os valores de n e m não serão maiores que 10 mil. Sempre haverá pelo menos um caminho entre a pessoa e algum ponto-de-interesse.

### <b>Saída</b>

A saída deve ter uma única linha contendo a quantidade mínima de quarteirões em um trajeto ortogonal entre a pessoa e um ponto-de-interesse, sem contar o quarteirão onde ela está.

### <b>Exemplos</b>

<details><summary>Exemplo 1</summary><p>

- Entrada
```
4 5
0 1 1 1 1
0 2 2 2 1
2 1 1 1 1
1 1 3 1 1
```
- Saída
```
9
```

</p></details>

<details><summary>Exemplo 2</summary><p>

- Entrada
```
5 4
0 1 1 1 
1 2 1 3 
1 2 1 1 
1 2 1 1 
1 0 1 1 
```
- Saída
```
4
```

</p></details>