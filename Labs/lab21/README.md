# <b>Desempenho</b>

<details><summary><b>Testes</b></summary><p>

01:  erro de execução (6).\
```
munmap_chunk(): invalid pointer
```
02:  violação de memória.\
03:  violação de memória.\
04:  violação de memória.\
05:  violação de memória.\
06:  violação de memória.\
07:  violação de memória.\

Número de casos-de-teste: 7.\
Casos-de-teste bem sucedidos: 0.\
<b>Acerto: 0%</b>

</p></details>

## <b>Deque em vetor dinâmico</b>

Uma deque (double ended queue, fila com duas extremidades) é uma estrutura de dados que armazena dados em seqüência. Seqüência quer dizer que a ordem relativa entre eles é importante, não quer dizer que os dados estejam ordenados. Em outras palavras, quer dizer que existe o primeiro, o segundo, o terceiro etc., mas não quer dizer que o primeiro seja menor que o segundo, que o segundo seja menor que o terceiro etc.

Uma deque tipicamente permite as seguintes operações de atualização

- push(D,x): adicionar o elemento x ao fim da deque D.
- pop(D): extrair o último elemento da deque D e retoná-lo.
- inject(D,x): adicionar o elemento x ao início da deque D.
- eject(D): extrair o primeiro elemento da deque D e retorná-lo.

e permite recuperar o primeiro e o último elementos sem removê-los.
Uma forma de armazenar uma deque é colocando os elementos dela consecutivamente em um vetor de forma "circular", isto é, o primeiro elemento da deque poderá estar em qualquer posição do vetor.

Por exemplo, se a deque de inteiros D = [12,19,15,17] estiver armazenada de forma circular em um vetor de tamanho 8, ela poderá estar em qualquer das configurações abaixo, onde __ significa um elemento do vetor que não está em D:
```
12 19 15 17 __ __ __ __
__ 12 19 15 17 __ __ __ 
__ __ 12 19 15 17 __ __
__ __ __ 12 19 15 17 __
__ __ __ __ 12 19 15 17
17 __ __ __ __ 12 19 15
15 17 __ __ __ __ 12 19 
19 15 17 __ __ __ __ 12 
```

Como pode-se ver, em qualquer delas, o primeiro elemento da deque é o 12 e o último é o 17, mas a posição dos elementos de D dentro do vetor é diferente.
Para manter uma deque de forma circular, além do vetor é necessário registrar a posição do primeiro elemento e o tamanho da deque. (Equivalentemente podemos registrar a posição do primeiro elemento e a posição do último elemento da deque.)

As operações de inserção e remoção nas extremidades da deque podem ser realizadas facilmente, em tempo contante.

Por exemplo, se um vetor de tamanho 8 contiver a deque D = [12,19,15,17] na configuração circular
```
12 19 15 17 __ __ __ __  primeiro=0 tamanho=4
```
e o número 16 for adicionado ao início de D então o vetor ficará assim:
```
12 19 15 17 __ __ __ 16  primeiro=7 tamanho=5
```
Depois, se o número 18 for adicionado ao início de D o vetor ficará assim:
```
12 19 15 17 __ __ 18 16  primeiro=6 tamanho=6
```
Se o número no fim da deque for removido então o vetor deverá ficar assim:
```
12 19 15 __ __ __ 18 16  primeiro=6 tamanho=5
```
E se o número 11 for adicionado ao fim da deque, o vetor deverá ficar assim:
```
12 19 15 11 __ __ 18 16  primeiro=6 tamanho=6
```

Neste trabalho você deve implementar uma deque de floats armazenada de forma circular em um vetor dinâmico. O vetor deve aumentar quando estiver cheio e deve diminuir quando estiver com muitas posições não-ocupadas por elementos da deque.

Uma deque implementada em um vetor dinâmico também permite a recuperação de qualquer elemento em tempo constante, não apenas os elementos nas pontas. As sequintes operações também deverão ser implementadas:

- get(D,k): recuperar o k-ésimo elemento de D.
- set(D,k,x): atualizar o valor do k-ésimo elemento de D para x.

O vetor dinâmico deve ser criado com uma certa capacidade inicial. O fator de redimensionamento r, r>1, será definido na criação da deque.

A política de redimensionamento do vetor dinâmico deve ser aumentar o tamanho de t para t*r quando a deque estiver cheia e reduzir de t para t/r quando a deque estiver com t/(r^2) elementos. O vetor dinâmico não deverá ficar com capacidade menor que a capacidade inicial.

Dessa forma, durante o processamento, o número de posições vazias do vetor não será maior que t((r^2 - 1)/r^2), onde t é o tamanho do vetor.

### <b>Entrada</b>

A entrada é composta por uma sucessão de comandos, um por linha. Os possíveis comandos são:

- create t r\
O programa deve criar uma deque vazia com capacidade para t floats e razão de redimensionamento r. Se o programa já estiver operando uma deque então ela deve ser liberada da memória antes da criação de uma nova deque. t é inteiro e r é fracionário.

- push x\
Inserir o fracionário x no fim da deque. Se um redimensionamento for necessário e falhar, o programa deve terminar com a mensagem "Unable to resize."

- pop\
Remover o último elemento da deque. Se a deque estiver vazia, não deve fazer nada.

- inject x\
Inserir o fracionário x no início da deque. Se um redimensionamento for necessário e falhar, o programa deve terminar com a mensagem "Unable to resize."

- eject\
Remover o primeiro elemento da deque. Se a deque estiver vazia, não deve fazer nada.

- get i\
Recuperar o elemento na posição i da deque e imprimir. Se i não estiver no intervalo [0,|deque|-1] então não deve fazer nada.

- set i x\
Atualizar o elemento na posição i da deque para x. Se i não estiver no intervalo [0,|deque|-1] então não deve fazer nada.

- is-empty?\
Imprime "empty" se a deque estiver vazia e "non-empty" se não estiver.

- print\
Imprimir os elementos da deque em ordem, do primeiro ao último, em uma única linha, separados por espaços e com 1 dígito depois do ponto decimal, no formato ilustrado abaixo.

- exit\
Terminar o programa.

A entrada sempre começará com um comando create.

### <b>Saída</b>

A saída deve conter as linhas geradas pelos comandos get, is-empty e print.

#### <b>Requisitos Adicionais</b>

Seu programa deve implementar a deque em um vetor dinâmico que começa com o tamanho indicado e aumenta e diminui.

Todas as operações sobre a deque devem executar um número constante de operações.

Antes de terminar o programa deve liberar a memória que foi alocada dinamicamente.