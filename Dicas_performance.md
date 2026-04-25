Quem tiver dicas para melhorar o desempenho de programas para a maratona, coloque aqui! (Só leia se sua dica já não está aqui antes de postar)

### sys.stdin.readline() - Python
- Prefira utilizar essa linha em vez de um simples input(). Este comando lê blocos maiores de dados de uma vez só e os armazena na memória (buffer), enquanto o input() faz chamadas de sistema muito mais frequentes, o que gera um atraso (overhead) quando há milhares de linhas para ler (não queremos atraso em uma competição).

### ios_base::sync_with_stdio(false); - C++
- Por padrão, C++ sincroniza os fluxos (cin/cout) com os de C (stdin/stdout). Essa sincronização garante que você possa usar os dois no mesmo programa, mas consome muito tempo. Essa linha evita buffers de limpeza sem necessidade, o que acelera drásticamente o processamento em problemas com múltiplas entradas e saídas.

### cin.tie(NULL); - C++
- Normalmente, cin é "amarrado" (tied) ao cout, o que significa que o buffer de saída é limpo (flush) toda vez que você pede uma entrada. Desamarrá-los evita buffers desnecessários, novamente acelerando o código.
- O tiro sai pela culatra se desamarrar os dois num problema interativo. Se não usar endl o programa fica esperando o juiz e o juiz fica esperando o programa, o que gera um NO por estourar o tempo limite. FAVOR NUNCA USAR cin.tie(NULL) E ESQUECER DE TROCAR '\n' POR endl DEPOIS!!!