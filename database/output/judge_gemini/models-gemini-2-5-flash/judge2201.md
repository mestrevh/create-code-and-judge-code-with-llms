# Modelo do judge: models/gemini-2.5-flash

VEREDITO: REPROVADO
COMPLEXIDADE: O(1) tempo, O(1) espaço
FEEDBACK:
O código submetido implementa as fórmulas `tipo1 = 2 * L * C + L + C` e `tipo2 = L * C`.

Ao simular a execução para o <test 0> (`L=3`, `C=5`):
1.  Leitura de L: `L = 3`
2.  Leitura de C: `C = 5`
3.  Cálculo de tipo1: `tipo1 = 2 * 3 * 5 + 3 + 5 = 30 + 8 = 38`
4.  Cálculo de tipo2: `tipo2 = 3 * 5 = 15`
5.  Saída:
    ```
    38
    15
    ```
O <output test> esperado para este caso é:
```
23
12
```
Há uma clara divergência entre a saída simulada do código e a saída esperada, tanto para `tipo1` quanto para `tipo2`.

Analisando a lógica do problema e os exemplos fornecidos, as fórmulas corretas para o cálculo seriam:
*   Para `tipo1` (lajotas inteiras): `L * C + (L - 1) * (C - 1)`
    *   Esta fórmula pode ser simplificada para `2 * L * C - L - C + 1`.
*   Para `tipo2` (meias lajotas): `2 * (L - 1) + 2 * (C - 1)`
    *   Esta fórmula pode ser simplificada para `2 * (L + C - 2)`.

Vamos testar as fórmulas corretas com `L=3`, `C=5`:
*   `tipo1 = 3 * 5 + (3 - 1) * (5 - 1) = 15 + 2 * 4 = 15 + 8 = 23` (Correto)
*   `tipo2 = 2 * (3 - 1) + 2 * (5 - 1) = 2 * 2 + 2 * 4 = 4 + 8 = 12` (Correto)

O código falha em implementar a lógica correta para as quantidades de lajotas tipo 1 e tipo 2. A complexidade do código é ótima (O(1) tempo, O(1) espaço), mas a correção funcional é inexistente para os casos gerais. O problema não apresenta riscos de overflow de `int` para os valores de L e C fornecidos (1 a 100), pois os resultados máximos (e.g., para L=100, C=100: tipo1=19801, tipo2=396) cabem confortavelmente em um `int`.

Em resumo, o código produz resultados incorretos devido a fórmulas matemáticas erradas.