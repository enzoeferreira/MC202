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

#### <b>Requisitos Adicionais</b>

Seu programa deve usar uma lista encadeada.

Não pode haver vetor algum no programa.