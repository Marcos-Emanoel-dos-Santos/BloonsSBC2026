### sys.stdin.readline() - Python
- Prefira utilizar essa linha em vez de um simples input(). Este comando lê blocos maiores de dados de uma vez só e os armazena na memória (buffer), enquanto o input() faz chamadas de sistema muito mais frequentes, o que gera um atraso (overhead) quando há milhares de linhas para ler (não queremos atraso em uma competição).

### ios_base::sync_with_stdio(false) - C++
- Por padrão, C++ sincroniza os fluxos (cin/cout) com os de C (stdin/stdout). Essa sincronização garante que você possa usar os dois no mesmo programa, mas consome muito tempo. Essa linha evita buffers de limpeza sem necessidade, o que acelera drásticamente o processamento em problemas com múltiplas entradas e saídas.
