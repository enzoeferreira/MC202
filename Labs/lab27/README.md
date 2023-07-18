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