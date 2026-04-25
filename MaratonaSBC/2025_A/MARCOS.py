from sys import stdin, stdout

inp_data = stdin.read().split()
tokens = iter(inp_data)
N = int(next(tokens))
M = int(next(tokens))

max_turma = [1] * M

for _ in range(N):
    current_line = [int(next(tokens)) for _ in range(M)]
    max_turma = [max(a, b) for a, b in zip(max_turma, current_line)]
total_alunos = sum(val for val in max_turma)

stdout.write(str(total_alunos))
