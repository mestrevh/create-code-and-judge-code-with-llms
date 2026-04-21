# Modelo do judge: models/gemini-2.5-flash

VEREDITO: APROVADO
COMPLEXIDADE: O(N^3) tempo, O(N^2) espaço

FEEDBACK:
O código implementa uma solução de força bruta que itera sobre todas as combinações únicas de três músicos para encontrar aquela com a maior soma de entrosamento. Em caso de empate na soma, a solução corretamente utiliza a comparação lexicográfica de vetores para selecionar a banda.

**Análise Detalhada:**

1.  **Leitura de Entrada e Estrutura Geral:**
    *   O programa lê `N` e `M` em um loop `while(true)` que termina com `N = 0` e `M = 0`, lidando corretamente com múltiplos casos de teste.
    *   A matriz de adjacência `entrosamento(N + 1, vector<int>(N + 1, 0))` é alocada e inicializada com zeros. O uso de `N+1` e indexação de 1 a `N` está correto, alinhado com a especificação de músicos identificados de 1 a `N`.
    *   As `M` entradas de entrosamento `(X, Y, Z)` são corretamente armazenadas na matriz `entrosamento[x][y] = z` e `entrosamento[y][x] = z`, considerando a simetria da relação de entrosamento.

2.  **Lógica de Busca da Melhor Banda:**
    *   A busca por trios de músicos é realizada por três loops aninhados: `for (int i = 1; i <= N; ++i)`, `for (int j = i + 1; j <= N; ++j)`, `for (int k = j + 1; k <= N; ++k)`. Essa estrutura garante que cada combinação de três músicos distintos seja considerada exatamente uma vez e que os músicos `(i, j, k)` estejam sempre em ordem crescente, o que é fundamental para a comparação lexicográfica.
    *   A soma do entrosamento para cada trio é calculada como `entrosamento[i][j] + entrosamento[i][k] + entrosamento[j][k]`.
    *   A variável `max_soma` e o vetor `melhor_banda` são mantidos para registrar a melhor solução encontrada até o momento.
    *   **Tratamento de Empates (Lexicográfico):** Quando um trio tem uma soma igual a `max_soma`, o código cria um `nova_banda` `{i, j, k}` e a compara com `melhor_banda` usando `nova_banda < melhor_banda`. A sobrecarga do operador `<` para `std::vector` realiza uma comparação lexicográfica, que é o critério de desempate exigido pelo problema. A garantia de `i < j < k` é essencial para que essa comparação funcione corretamente para vetores que já representam trios ordenados.

3.  **Corner Cases e Limites:**
    *   **`N=3` (ou `N>=3`):** Embora a descrição do problema diga `3 < N < 100`, os casos de teste fornecem `N=3`. O código lida corretamente com `N=3`, onde apenas o trio `{1, 2, 3}` é possível.
    *   **`M=0` (ou poucos `M`):** Se não houver entrosamento (M=0) ou se todos os entrosamentos forem 0, `max_soma` permanecerá 0, e a primeira banda testada (que é `{1, 2, 3}` devido à ordem dos loops) será a `melhor_banda`, resultando na saída `1 2 3`, o que está correto.
    *   **Valores de Entrosamento:** `1 <= Z <= 100`. A soma máxima possível para um trio é `3 * 100 = 300`, o que cabe perfeitamente em um `int`. Não há risco de overflow.
    *   **Musicians IDs:** `1` a `N`. A matriz `N+1` por `N+1` e os loops de `1` a `N` gerenciam isso corretamente.

**Complexidade:**

*   **Complexidade de Tempo:**
    *   Para cada caso de teste:
        *   Inicialização da matriz `entrosamento`: O(N^2)
        *   Leitura dos `M` pares: O(M)
        *   Três loops aninhados para encontrar a melhor banda: O(N^3)
    *   A operação dominante é a busca por trios, resultando em O(N^3) por caso de teste. Dado que `N < 100` (max N=99), `N^3` é aproximadamente `99^3 ~ 9.7 x 10^5` operações, o que é extremamente eficiente e bem abaixo do limite de tempo de 5 segundos.
*   **Complexidade de Espaço:**
    *   A matriz `entrosamento` consome O(N^2) de espaço. Para `N=99`, isso é `99^2 ~ 9.8 x 10^3` inteiros, ou seja, cerca de 40KB, o que está muito abaixo dos limites de memória típicos.
    *   O vetor `melhor_banda` consome O(1) espaço (tamanho fixo de 3).
    *   Portanto, a complexidade de espaço total é O(N^2).

**Conclusão:**
O código é correto, eficiente e lida bem com os requisitos do problema e os casos de teste fornecidos, incluindo o desempate lexicográfico. A escolha do algoritmo de força bruta é adequada devido às restrições pequenas de `N`.