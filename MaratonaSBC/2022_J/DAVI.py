input()

jogados = [0] * 13
joao = 0
maria = 0

for j in map(int, input().split(" ")):
    jogados[j] += 1
    if j > 10:
        j = 10
    joao += j

for m in map(int, input().split(" ")):
    jogados[m] += 1
    if m > 10:
        m = 10
    maria += m

for n in map(int, input().split(" ")):
    jogados[n] += 1
    if n > 10:
        n = 10
    joao += n
    maria += n

for i in range(len(jogados)):
    soma = i
    if i > 10:
        soma = 10

    if (maria + soma == 23 or (joao + soma > 23 and maria + soma < 24)) and not jogados[i] >= 4:
        print(soma)
        break
    elif maria + soma > 23 and not jogados[i] >= 4:
        print(-1)
        break