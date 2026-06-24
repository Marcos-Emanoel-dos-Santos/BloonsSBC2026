# Binary Exponentiation

Binary Exponentiation é um método de exponenciação em tempo O(log n) em vez do O(n) da operação ingênua.

## Algoritmo
O algoritmo consiste em transformar o expoente em um número binário antes de realizar a operação e, como na base 2 um número n terá, no máximo, floor(log n) + 1 dígitos, o novo expoente demandará O(log n) operações se já soubermos os valores de a¹, a², a⁴, a⁸, ... a^(floor(log n) + 1)

Obs: essa operação depende da *propriedade associativa* dos conjuntos, podendo ser aplicada em outros ramos que não a aritmética, contando que esta propriedade esteja presente.

## Exemplo
Tome como exemplo 3⁹. 9 pode ser expresso como 1001 na base 2, então 3⁹ = 3¹⁰⁰¹. Para realizar esta operação, precisamos das seguintes informações:

- 3¹ = 3
- 3² = (3¹)² = 9
- 3⁴ = (3²)² = 81
- 3⁸ = (3⁴)² = 6561

Como em binário o número era 1001, usaremos 3⁸ e 3¹, pois os dígitos de 3² e 3⁴ são iguais a zero.

Assim, 3⁹ = 3⁸ * 3¹ = 6561 * 3 = 19683
