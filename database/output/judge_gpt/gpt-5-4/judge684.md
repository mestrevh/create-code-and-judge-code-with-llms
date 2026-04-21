# Modelo do judge: gpt-5.4

1. Status: Correto
2. Tempo estimado: O(M log N)
3. Avaliação: O código produz as saídas esperadas nos testes fornecidos. Ele mapeia cada encomenda para o índice da casa usando `lower_bound` e soma a distância entre índices consecutivos, o que corresponde ao tempo gasto entre casas vizinhas. Com `N, M ≤ 45000`, a complexidade O(M log N) é suficientemente eficiente dentro do limite, e o uso de `long long` para o tempo total é adequado.