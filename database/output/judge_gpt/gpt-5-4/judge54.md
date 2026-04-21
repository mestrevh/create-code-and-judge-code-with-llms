# Modelo do judge: gpt-5.4

1. Status: Correto
2. Tempo estimado: O(T · (N³ + M)), com N < 100; na prática, no máximo cerca de 161.700 trios por caso
3. Avaliação: O código implementa busca completa sobre todos os trios de músicos, usando matriz de adjacência para consultar o entrosamento em O(1). Isso é suficiente e eficiente para as restrições do problema. Como os laços percorrem i < j < k em ordem crescente e a atualização ocorre apenas quando sum > max_sum, em caso de empate permanece o primeiro trio em ordem lexicográfica, como exigido. A leitura de múltiplos casos e a reinicialização da matriz também estão corretas.