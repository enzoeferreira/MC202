# <b>Desempenho</b>

<details><summary><b>Testes</b></summary><p>

01:  saída correta.\
02:  saída correta.\
03:  saída correta.\
04:  saída correta.\
05:  saída correta.\
06:  saída correta.\
07:  saída correta.\
08:  saída correta.\
09:  saída correta.\
10:  saída correta.\

Número de casos-de-teste: 10.\
Casos-de-teste bem sucedidos: 10.\
<b>Acerto: 100%</b>

</p></details>

## <b>Street Fighter</b>
Street Fighter é um jogo de luta desenvolvido pela empresa Capcom que teve sua primeira versão lançada em 1987. O jogo é famoso e faz sucesso até hoje, tendo inclusive servido de inspiração para filmes. O jogo tem vários personagens com poderes especiais que podem ser escolhidos para a luta, sendo Ryu e Ken os dois lutadores mais conhecidos de Street Fighter.

Esta tarefa consiste em escrever um programa para analisar uma luta entre Ryu e Ken, informando qual dos dois lutadores saiu vitorioso.

Cada lutador começa a luta com uma quantidade de pontos de vida (hp, do inglês Health Points) e realiza uma sequência de golpes que geram decréscimo no hp do adversário.

### <b>Entrada</b>

As primeiras duas linhas da entrada têm dois valores inteiros que indicam a quantidade inicial de hp de Ryu e Ken, respectivamente.

As linhas seguintes têm uma seqüência de golpes, um por linha. Um golpe é um valor inteiro, sendo que um golpe com valor positivo indica que o golpe foi realizado por Ryu e um golpe com valor negativo indica que o golpe foi realizado por Ken. O valor absoluto de um golpe indica a quantidade de hp que deve ser diminuída do adversário.

### <b>Saída</b>

Para cada golpe, seu programa deve imprimir três linhas, como ilustradas abaixo. A primeira linha deve informar quem aplicou o golpe e o valor absoluto dele. A segunda e terceira linha devem informar o hp dos lutadores Ryu e Ken, respectivamente.

O hp de cada lutador nunca será negativo. No momento que o hp de um dos lutadores chega a zero ele é derrotado e a luta termina. Seu programa deve imprimir o nome do lutador que venceu a luta seguido do número de golpes aplicados por cada lutador como ilustrado abaixo.