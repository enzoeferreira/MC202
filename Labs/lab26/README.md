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

## <b>Hashing de cadeias</b>

Uma aplicação quer manter um glossário que registra a ordem em que um conjunto de cadeias foram adicionadas a ele.

Implemente uma tabela de hashing para armazenar o glossário dessa aplicação. A tabela deve armazenar pares formados por uma cadeia e um timestamp. Um timestamp é um número natural único e seqüencial, a partir de 0 e sem reuso que indica o momento que em a cadeia foi inserida na tabela.

As colisões devem ser resolvidas usando sondagem com incremento por hashing dupla.

Escolha uma função de transformação de cadeias de caracteres em naturais. Não importa a forma como você faça para este trabalho, mas algumas funções são muito piores que outras em termos de espalhamento. Um exemplo de uma função que funciona bem na prática é a função djb2:
```c
unsigned long djb2(unsigned char *str) {
  unsigned long hash = 5381;
  int c;
  
  while ((c = *str++))
    hash = ((hash << 5) + hash) ^ c; // hash * 33 XOR c
  
  return hash;
}
```

A djb2 faz um mapeamento bem espalhado de strings em unsigned long. Observe que o retorno da djb2 pode ser um número muito maior que o tamanho da tabela de hashing.

### <b>Entrada</b>

Cada linha da entrada para o programa é um comando. Os comandos podem ser
- c n\
Seu programa deve criar uma tabela vazia para armazenar n. O tamanho da tabela deve ser tal que a tabela não fique mais que 70% ocupada quando tiver n cadeias. Se já houver uma tabela, ela deve ser descartada e deve dar lugar à nova tabela vazia e o timestamp deve ser reiniciado com zero.
- i cadeia\
Seu programa deve inserir a cadeia na tabela com o timestamp corrente. Cada cadeia deve ser inserida uma única vez na tabela. Se houver um comando de inserção para uma cadeia que já está na tabela, a tabela deve permanecer como estiver.

    Depois de um comando i o timestamp deve ser incrementado de uma unidade.
- r cadeia\
Seu programa deve remover a cadeia da tabela.
- b cadeia\
Se a cadeia estiver na tabela, seu programa deve imprimir o timestamp dela, senão deve imprimir -1, no formato exemplificado abaixo.
- f\
Seu programa deve terminar. Qualquer memória alocada dinamicamente deve ser liberada antes do término.

Nos comandos, o caractere é separado do próximo parâmetro por um único espaço.

As cadeias são formadas por pelo menos 1 e até 250 caracteres do alfabeto ASCII entre 33 e 126 inclusive. Observe que uma cadeia pode começar ou terminar com um ou mais espaços e nesses casos os espaços fazem parte da cadeia.

### <b>Saída</b>

A saída do programa é formada pela saída dos comandos b.