# Modelo do judge: gpt-5.4

1. Status: Correto
2. Tempo estimado: O(N · α(7)) por caso de teste, na prática O(N)
3. Avaliação: O código modela corretamente o conjunto de peças como um multigrafo com vértices 0..6 e verifica a existência de trilha/circuito euleriano: conectividade entre os vértices com grau positivo e quantidade de vértices de grau ímpar igual a 0 ou 2. Isso é suficiente para decidir se todas as peças podem ser organizadas em sequência válida. A implementação com Union-Find é eficiente e muito adequada às restrições, já que N ≤ 100 e há apenas 7 valores possíveis. A saída também segue o formato exigido nos testes apresentados.