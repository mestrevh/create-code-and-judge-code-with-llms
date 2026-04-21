# Modelo do judge: models/gemini-2.5-flash

VEREDITO: REPROVADO
COMPLEXIDADE: O(1) tempo, O(1) espaço
FEEDBACK: Engenheiro de Software Sênior aqui, implacável como sempre. Seu código falhou miseravelmente na lógica fundamental do problema.

A premissa do problema é que um retângulo é dividido em quatro sub-retângulos por duas linhas perpendiculares. Se as áreas desses sub-retângulos são A, B, C e D (dispostos em um grid 2x2), a propriedade matemática que deve ser satisfeita é `A * D == B * C`. Isso significa que o produto das áreas das zonas diagonais deve ser igual.

Seja `w1, w2` as larguras dos dois pedaços em que o retângulo é dividido horizontalmente e `h1, h2` as alturas dos dois pedaços em que é dividido verticalmente. As quatro áreas seriam:
`Area1 = w1 * h1`
`Area2 = w2 * h1`
`Area3 = w1 * h2`
`Area4 = w2 * h2`

Verifica-se que `(w1 * h1) * (w2 * h2) == (w2 * h1) * (w1 * h2)`, ou seja, `Area1 * Area4 == Area2 * Area3`.
Para que *qualquer* arranjo das quatro áreas dadas satisfaça essa condição, basta que, após ordenar as áreas de forma não decrescente (`areas[0], areas[1], areas[2], areas[3]`), a seguinte condição seja verdadeira: `areas[0] * areas[3] == areas[1] * areas[2]`. O maior e o menor valor devem ser multiplicados, e os dois valores intermediários também.

Seu código, no entanto, implementa a condição `areas[0] + areas[3] == areas[1] + areas[2]` (soma das extremidades igual à soma dos meios). Esta é uma propriedade para verificar se quatro números formam uma progressão aritmética, não se eles podem formar as áreas de um grid retangular 2x2. Essa é uma falha lógica crítica.

A simulação exata contra os casos de teste revela os erros:

*   **Teste 0 (`1 2 4 8`)**:
    *   Áreas ordenadas: `{1, 2, 4, 8}`
    *   Seu código verifica: `1 + 8 == 2 + 4` -> `9 == 6` -> `false`. Saída: `N`.
    *   **Esperado: `S`** (Pois `1 * 8 == 2 * 4` -> `8 == 8`, verdadeiro).
    *   **Resultado: REPROVADO**

*   **Teste 1 (`15 14 6 35`)**:
    *   Áreas ordenadas: `{6, 14, 15, 35}`
    *   Seu código verifica: `6 + 35 == 14 + 15` -> `41 == 29` -> `false`. Saída: `N`.
    *   **Esperado: `S`** (Pois `6 * 35 == 14 * 15` -> `210 == 210`, verdadeiro).
    *   **Resultado: REPROVADO**

*   **Teste 2 (`1 2 3 4`)**:
    *   Áreas ordenadas: `{1, 2, 3, 4}`
    *   Seu código verifica: `1 + 4 == 2 + 3` -> `5 == 5` -> `true`. Saída: `S`.
    *   **Esperado: `N`** (Pois `1 * 4 == 2 * 3` -> `4 == 6`, falso).
    *   **Resultado: REPROVADO**

*   **Teste 5 (`18 6 19 57`)**:
    *   Áreas ordenadas: `{6, 18, 19, 57}`
    *   Seu código verifica: `6 + 57 == 18 + 19` -> `63 == 37` -> `false`. Saída: `N`.
    *   **Esperado: `S`** (Pois `6 * 57 == 18 * 19` -> `342 == 342`, verdadeiro).
    *   **Resultado: REPROVADO**

*   **Teste 7 (`12 3 92 23`)**:
    *   Áreas ordenadas: `{3, 12, 23, 92}`
    *   Seu código verifica: `3 + 92 == 12 + 23` -> `95 == 35` -> `false`. Saída: `N`.
    *   **Esperado: `S`** (Pois `3 * 92 == 12 * 23` -> `276 == 276`, verdadeiro).
    *   **Resultado: REPROVADO**

Apesar de ser `O(1)` em tempo e espaço (ótimo para a complexidade do algoritmo), o erro lógico o torna inútil para resolver o problema proposto. Não há problemas de overflow com `int`, já que `10^4 * 10^4 = 10^8`, que cabe confortavelmente em um `int` de 32 bits.