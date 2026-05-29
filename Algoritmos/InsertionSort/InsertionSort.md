# Insertion Sort

Insertion Sort é uma técnica de ordenação de vetores _in place_, ou seja, sem necessidade de espaço extra ou com espaço extra constante.

A intuição por trás desta técnica é bem simples:
Para cada índice do vetor, compare o valor dele com os valores dos índices anteriores arrastando-os para frente até encontrar a posição correta para este número.

<br>

Imagine que você tem a lista [5, 4, 2, 7, 3] e quer ordená-la em ordem crescente. O Insertion Sort começa no segundo índice da lista, que tem valor 4, e o compara com o índice anterior, que tem valor 5.

4 < 5. Desta forma, o 5 é arrastado para frente (onde estava o 4) e o 4 assume a velha posição do 5, deixando a lista como segue:

[4, 5, 2, 7, 3]

<br>

Agora, o índice observa o próximo número da lista, que é o 2. O procedimento se repete para cada valor anterior até encontrarmos a posição correta do número 2:
2 < 5. O 5 é arrastado para frente (onde estava o 2).
2 < 4. O 4 é arrastado para frente (no espaço que o 5 deixou vazio). Como não há mais números, o 2 fica na primeira posição, deixando a lista como segue:

[2, 4, 5, 7, 3]

<br>

Agora, o índice está em 7.

Perceba que desta vez o 7 é comparado com o 5, porém 7 > 5. Assim, o 7 continua onde está, deixando a lista como estava.

[2, 4, 5, 7, 3]

Perceba que a cada passo, toda a lista ANTES do índice atual já está ordenada, então não precisammos comparar o 7 com cada número anterior a ele pois este algoritmo nos dá garantia de que 5 já é o maior entre os anteriores.

<br>

Agora, o último passo é ordenar o 3.

3 < 7. 7 então se move para frente:

[2, 4, 5, _, 7]

3 < 5. 5 então se move para frente:

[2, 4, _, 5, 7]

3 < 4. 4 então se move para frente:

[2, _, 4, 5, 7]

3 > 2. Então a posição atual é a correta para o 3:

[2, 3, 4, 5, 7]

<br>

Fim do algoritmo