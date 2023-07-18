# <b>Desempenho</b>

<details><summary><b>Testes</b></summary><p>

01:  saída correta.\
02:  violação de memória.\
03:  saída correta.\
04:  saída incorreta.\
05:  violação de memória.\
06:  violação de memória.\
07:  saída correta.\

Número de casos-de-teste: 7.\
Casos-de-teste bem sucedidos: 3.\
<b>Acerto: 43%</b>

</p></details>

## <b>Árvore binária de busca</b>

Escreva um programa que lê comandos da entrada e manipula registros de dados de clientes armazenando-os em uma árvore binária de busca.

Os comandos que seu programa deve interpretar são da seguinte forma:

- criar\
Ao ler o comando criar o programa deve criar uma árvore binária de busca vazia. Se já houver uma árvore sendo processada, todos os nós dela devem ser removidos.
- inserir k, nome, pontos\
Ao ler o comando inserir, onde k é um inteiro, nome é uma cadeia e pontos é um fracionário, o programa deve inserir o registro do cliente com nome, pontos e chave k na árvore de busca binária. Se k já estiver na árvore então o programa não deve fazer nada. Se não houver memória para essa operação, o programa deve imprimir "memoria insuficiente" em uma linha e deve continuar a execução.
- remover k\
Ao ler o comando remover, onde k é um inteiro, o programa deve remover o registro do cliente com chave x da árvore binária de busca. Se k não estiver na árvore o programa não deve fazer nada.
- buscar k\
Ao ler o comando buscar, onde k é um inteiro, o programa deve buscar o registro com chave k na árvore e imprimir "cliente k: nome, z pontos", sendo os pontos com duas casas decimais, ou "nao ha cliente k" em uma linha.
- imprimir\
Ao ler esse comando o programa deve imprimir os nomes e chaves dos clientes na ordem em que forem visitadas por um percurso em profundidade em-ordem. O formato está exemplificado abaixo. Se a árvore estiver vazia então o programa deve imprimir "arvore vazia" em uma linha.
- minimo / maximo\
Ao ler um desses comandos o programa deve imprimir a menor chave ou a maior chave na árvore, respectivamente, no formato "minimo: k" ou "maximo: k". Se a árvore estiver vazia então o programa deve imprimir "arvore vazia" em uma linha.
- sucessor k / predecessor k\
Ao ler um desses comandos, onde k é um inteiro, o programa deve imprimir "sucessor de k: z" ou "predecessor de k: z", respectivamente. Se k não tiver sucessor ou predecessor o programa deve imprimir "sucessor de k: nao ha" ou "predecessor de k: nao ha" em uma linha. Se k não estiver na árvore então o programa deve imprimir "nao ha cliente k" em uma linha.
- buscar-intervalo x y\
Ao ler um comando buscar-intervalo, onde x e y são inteiros, o programa deve imprimir todas as chaves na árvore que estiverem contidas no intervalo [x,y]. A linha deve começar com a expressão "clientes no intervalo [x,y]: ", que deve ser seguida das chaves em ordem crescente, separadas por um espaço. Se não houver chaves no intervalo o programa deve imprimir "nenhum".
- terminar\
Ao ler esse comando o programa deve desalocar a árvore e todos os nós dela e terminar.

Cada registro de cliente tem uma chave do tipo int de 32 bits, um nome de até 100 caracateres ASCII e uma pontuação do tipo float.

### <b>Exemplos</b>

<details><summary>Exemplo 1</summary><p>

- Entrada
```
criar
inserir 70, Joao, 3.14
inserir 30, Teresa, 6.28
inserir 10, Raimundo, 0.00
inserir 80, Maria, 13.13
inserir 90, Joaquim, 0.01
inserir 20, Lili, 9.99
inserir 40, J. Pinto Fernandes, 1.99
buscar 70
buscar 50
imprimir
terminar
```
- Saída
```
cliente 70: Joao, 3.14 pontos
nao ha cliente 50
clientes: Raimundo (10) Lili (20) Teresa (30) J. Pinto Fernandes (40) Joao (70) Maria (80) Joaquim (90)
```

</p></details>

<details><summary>Exemplo 2</summary><p>

- Entrada
```
criar
inserir 40, Juca, 5.00
inserir 10, Lia, 2.00
inserir 70, Pedro, 8.00
inserir 30, Paulo, 4.00
inserir 80, Dora, 9.00
inserir 0, Carlos, 1.00
inserir 20, Lea, 3.00
inserir 50, Rita, 6.00
inserir 60, Dito, 7.00
inserir 90, Fulano de Tal, 10.00
imprimir
buscar 50
buscar 25
buscar-intervalo 25 85
remover 40
remover 90
remover 70
imprimir
predecessor 10
predecessor 0
predecessor 15
minimo
maximo
terminar
```
- Saída
```
clientes: Carlos (0) Lia (10) Lea (20) Paulo (30) Juca (40) Rita (50) Dito (60) Pedro (70) Dora (80) Fulano de Tal (90) 
cliente 50: Rita, 6.00 pontos
nao ha cliente 25
clientes no intervalo [25,85]: 30 40 50 60 70 80 
clientes: Carlos (0) Lia (10) Lea (20) Paulo (30) Rita (50) Dito (60) Dora (80) 
predecessor de 10: 0
predecessor de 0: nao ha
nao ha cliente 15
minimo: 0
maximo: 80
```

</p></details>

#### <b>Requisitos Adicionais</b>

Seu programa deve armazenar os dados e realizar as operações em uma árvore binária de busca representada de forma explícita.