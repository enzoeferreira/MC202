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

## <b>Playlist</b>

Patrícia vai viajar nas férias. Como ela não consegue dormir durante as viagens, ela planeja ouvir músicas em seu celular.

O tocador de músicas do celular dela executa uma playlist (isto é, uma lista de músicas), que pode ser alterada a partir de comandos dados ao programa. O tocador possui um indicador que mostra o nome da música na posição atual da playlist; caso a lista esteja vazia, como é o caso no início da execução, o indicador exibirá uma cadeia vazia.

As operações que podem ser realizadas sobre a playlist são as seguintes:

- insere X: insere a música de nome X na playlist, logo após a posição atual do cursor. Caso a playlist esteja vazia, a música é inserida na primeira posição da lista e aparece no indicador. Uma música pode aparecer na playlist mais de uma vez. O nome da música será uma cadeia de tamanho máximo 100. Considere que o tocador terá qualquer música que Patrícia queira inserir.
- remove X: remove da playlist a primeira ocorrência da música de nome X. Se a música removida for a música no indicador, este deve ser deslocado, caso haja mais músicas na playlist. Ele sempre é deslocado para a música anterior, a não ser que a música removida tenha sido a primeira da lista; neste caso, o indicador exibirá a música que agora é a primeira. Caso a música não conste da playlist, nada acontece.
- toca: toca a música mostrada pelo indicador. Após o fim da execução, o indicador passa para a próxima música, caso exista. Caso contrário, continuará na mesma posição.
- volta: volta o indicador uma posição na playlist. Caso o indicador esteja na primeira música, ele não é alterado.
- final: começando da posição atual do indicador, esta operação toca todas as músicas subsequentes da lista.
- inverte: inverte a ordem de todas as músicas na playlist. A posição do indicador não é alterada.

Caso alguma das operações que envolvem deslocamento da playlist seja executada quando a lista estiver vazia, não há deslocamento, mas o tocador não retorna nenhum erro.

Sua tarefa será desenvolver um programa que imprime os nomes das músicas tocadas durante a viagem de Patrícia a partir da lista de comandos que ela executou no tocador, ou seja, o conteúdo do indicador a cada vez que é executado o comando toca.

### <b>Entrada</b>

A entrada consiste de um conjunto de casos de teste, cada um deles correspondente a uma playlist possível. A primeira linha de cada caso de teste contém um inteiro N indicando o número de operações realizadas sobre aquela playlist.
Cada uma das N linhas seguintes contém uma das operações descritas acima.

A execução do programa termina quando o número de operações de um caso de teste for zero.

### <b>Saída</b>

Para cada caso de teste, seu programa deve imprimir, na ordem de execução, os nomes de cada música executada. Os nomes de música devem ser separados por uma quebra de linha. As saídas de cada caso devem ser separadas por duas quebras de linha.

### <b>Exemplos</b>

<details><summary>Exemplo 1</summary><p>

- Entrada
```
11
insere Speak to Me
toca
remove Speak to Me
toca
insere Breathe
insere Time
insere On the Run
final
remove On the Run
volta
toca
4
insere Como Nossos Pais
insere Sujeito de Sorte
inverte
final
0
```
- Saída
```
Speak to Me

Breathe
On the Run
Time
Breathe

Como Nossos Pais
```

</p></details>

#### <b>Requisitos Adicionais</b>

Seu programa deve usar uma lista encadeada (com encadeamento simples ou duplo, à sua escolha).

Antes do fim do programa, toda memória alocada dinamicamente deve ser liberada.