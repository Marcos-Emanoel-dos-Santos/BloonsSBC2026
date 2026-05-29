# KMP (Knuth-Morris-Pratt)

O Algoritmo KMP é um método para encontrar ocorrências de um padrão em uma string.

Para entendermos a necessidade do algoritmo KMP, vamos primeiro entender onde falha um algoritmo convencional para então descobrirmos como o KMP resolve o seu problema.

## Algoritmo convencional


Imagine que temos:
- A string S "abcdabcabcdf";
- o padrão P "abcdf".

Um algoritmo convencional – muitas vezes presente na biblioteca padrão de cada linguagem – faria o seguinte procedimento:
Compara-se o índice S[0] com P[0]: temos um match, em ambos os casos temos o valor 'a'. Assim, podemos prosseguir a comparação para o próximo valor: comparamos S[1] com P[1]: novamente, temos um match. E assim temos match até o índice 3, como segue:

> S[0] = P[0] = 'a' <br>
> S[1] = P[1] = 'b' <br>
> S[2] = P[2] = 'c' <br>
> S[3] = P[3] = 'd' <br>

Ao chegar no índice 4 nos deparamos com um contratempo:

> S[4] = 'a' <br>
> P[4] = 'f'

Neste caso, vemos que a sequência não se repete no primeiro índice da string.

Ao contrário do KMP, o algoritmo convencional, que dizemos ser _naive_ (ingênuo), vai começar a comparação novamente, agora iniciando em S[1] e P[0]. Porém, logo na primeira comparação o problema já surge:

> S[1] = 'b' <br>
> P[0] = 'a'

O padrão já falhou na primeira comparação, então agora começamos de novo, mas com S[2] e P[0]. Isso vai se repetir até S[4] e P[0], onde haverão outros matches em sequência:

> S[4] = P[0] = 'a' <br>
> S[5] = P[1] = 'b' <br>
> S[6] = P[2] = 'c' <br>

Porém,

> S[7] = 'a' <br>
> P[3] = 'f'

O algoritmo falha novamente, e só vai encontrar o padrão em S[7]. Quando isso acontecer, o algoritmo compara novamente como segue:

> S[7] = P[0] = 'a' <br>
> S[8] = P[1] = 'b' <br>
> S[9] = P[2] = 'c' <br>
> S[10] = P[3] = 'f'

Neste momento, o algoritmo colocaria em uma lista de soluções o índice 7, que é onde o padrão tem sua primeira ocorrência na string. Ele ainda passa por cada índice seguinte buscando novamente o padrão, fadado ao fracasso.

Resposta final: o padrão existe no índice 7.

Perceba que o algoritmo convencional faz diversas comparações desnecessárias, como quando iniciou a comparação por S[1]: já havíamos passado por S[1] quando começamos em S[0], então não haveria necessidade de passar de novo, o algoritmo poderia simplesmente ver, na primeira passada, que o início do padrão não é um 'b' e pular essa comparação. Aí entra o algoritmo KMP.

Este algoritmo tem complexidade de tempo O(n×m)

<br>

## KMP (Knuth-Morris-Pratt)

Para resolver esse problema, existe o algoritmo KMP. A principal diferença é que ele estuda o padrão antes de iniciar a busca na string para ter uma proteção e não ser necessário voltar na string cada vez que não encontrar o padrão.

Para esta proteção, estudamos os _prefixos_ e os _sufixos_ do padrão.

> Padrão: <b>abcdabc</b> <br>
> Prefixos: a, ab, abc, abcd, abcda, abcdab <br>
> Sufixos: c, bc, abc, dabc, cdabc, bcdabc

Neste caso, não estamos interessados em prefixos ou sufixos que compreendem a palavra inteira. <b>abcdabc</b> é um sufixo de abcdabc, mas não nos interessa para a busca.

A ideia por trás desse estudo é encontrar um match entre prefixos e sufixos. Neste caso, abc é tanto prefixo quanto sufixo do padrão. O que estamos preocupados em saber é se uma parte do padrão está se repetindo dentro de si mesmo. Para tal, criaremos um vetor LPS (Longest proper Prefix which is also a Sufix – sim, o nome é imenso).

Cada índice do LPS é chamado len. A preparação do LPS se dá como nos exemplos a seguir.

Seja P_n um padrão:

P_1 <br>
a b c d a b e a b f <br>
0 0 0 0 1 2 0 1 2 0 <br>
Neste caso, um número 0 indica que não é o início de um padrão, então se a semelhança entre a string e o padrão acabar ali, deve-se começar a verificar o padrão de seu início


P_2 <br>
a b c d e a b f a b c <br>
0 0 0 0 0 1 2 0 1 2 3 <br>
Neste caso, o padrão "ab" do início se repete duas vezes, e uma vez o 'c' também está junto.

P_3 <br>
a a b c a d a a b e <br>
0 1 0 0 1 0 1 2 3 0

P_4 <br>
a a a a b a a a c d <br>
0 1 2 3 0 1 2 3 0 0

Para montar o LPS verificamos se:
1. P[i] = P[len]
- Neste caso, como os valores coincidem, podemos verificar o próximo valor.
2. P[i] != P[len] e P[len] != 0
- Neste caso, como os valores não coincidem mas P[len] é diferente de zero, retrocedemos len para o que há em P[len].
3. P[i] != P[len] e P[len] = 0
- Neste caso, como P[len] é zero, voltamos a comparar o início (índice zero) do padrão, então podemos apenas somar no valor de i.

O LPS é justamente a lista de números abaixo do padrão. Com o LPS montado, vamos para a segunda fase do algoritmo, que trata a string de verdade. <br>
Dada uma string S e um padrão P, começamos comparando S[i] com P[j], onde i = j = 0 e seguimos estas instruções:

Se S[i] = P[j] -> Acrescentamos 1 em i e 1 em j; <br>
Se S[i] != S[j] -> Mudamos o valor de j para seu correspondente em LPS. Por exemplo, LPS[j] = 3, então movemos j para 3; <br>
Se S[i] != S[j] e LPS[j] = 0 -> Neste caso, não adianta buscar padrão na letra atual da string, voltamos j pra 0 e somamos um a i.
