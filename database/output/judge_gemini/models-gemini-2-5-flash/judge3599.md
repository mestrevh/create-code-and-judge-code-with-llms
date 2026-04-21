# Modelo do judge: models/gemini-2.5-flash

VEREDITO: REPROVADO
COMPLEXIDADE: O(N) tempo, O(N) espaço
FEEDBACK: O código implementa uma lógica onde a variável `count` acumula a soma dos `1`s que precedem cada `2` na sequência. A variável `current` mantém a contagem de `1`s vistos até o momento.

Realizando a simulação exata da execução do código contra os casos de teste fornecidos, observa-se o seguinte:

-   **Exemplo da Descrição (não é um `test case` numerado, mas é o primeiro exemplo dado):**
    -   Input: `5 1 1 1 2 1`
    -   Simulação:
        -   `n = 5`, `seq = {1, 1, 1, 2, 1}`
        -   `count = 0`, `current = 0`
        -   `seq[0] = 1`: `current = 1`
        -   `seq[1] = 1`: `current = 2`
        -   `seq[2] = 1`: `current = 3`
        -   `seq[3] = 2`: `count += current` (0 + 3 = 3). `count = 3`
        -   `seq[4] = 1`: `current = 4`
        -   Saída do código: `3`
    -   Saída esperada: `3`
    -   **Coincide.**

-   **Test 0:**
    -   Input: `12 \n 1 \n 2 \n 1 \n 2 \n 2 \n 2 \n 1 \n 1 \n 2 \n 2 \n 1 \n 1`
    -   Simulação:
        -   `n = 12`, `seq = {1, 2, 1, 2, 2, 2, 1, 1, 2, 2, 1, 1}`
        -   `count = 0`, `current = 0`
        -   `seq[0] = 1`: `current = 1`
        -   `seq[1] = 2`: `count += current` (0 + 1 = 1). `count = 1`
        -   `seq[2] = 1`: `current = 2`
        -   `seq[3] = 2`: `count += current` (1 + 2 = 3). `count = 3`
        -   `seq[4] = 2`: `count += current` (3 + 2 = 5). `count = 5`
        -   `seq[5] = 2`: `count += current` (5 + 2 = 7). `count = 7`
        -   `seq[6] = 1`: `current = 3`
        -   `seq[7] = 1`: `current = 4`
        -   `seq[8] = 2`: `count += current` (7 + 4 = 11). `count = 11`
        -   `seq[9] = 2`: `count += current` (11 + 4 = 15). `count = 15`
        -   `seq[10] = 1`: `current = 5`
        -   `seq[11] = 1`: `current = 6`
        -   Saída do código: `15`
    -   Saída esperada: `7`
    -   **Falha: A saída do código (15) não corresponde à saída esperada (7).**

-   **Test 1:**
    -   Input: `3 \n 1 \n 2 \n 1`
    -   Simulação:
        -   `n = 3`, `seq = {1, 2, 1}`
        -   `count = 0`, `current = 0`
        -   `seq[0] = 1`: `current = 1`
        -   `seq[1] = 2`: `count += current` (0 + 1 = 1). `count = 1`
        -   `seq[2] = 1`: `current = 2`
        -   Saída do código: `1`
    -   Saída esperada: `3`
    -   **Falha: A saída do código (1) não corresponde à saída esperada (3).**

-   **Test 2, 3, 4, 5:**
    -   Todos esses testes seguem um padrão de `1` seguido por muitos `2`s e então um ou mais `1`s no final (e.g., `1, 2, ..., 2, 1, 1`).
    -   A lógica do código resulta em `count` sendo `1 * (número de 2s)` (porque o `current` será `1` na maioria das vezes, dado que há apenas um `1` antes da maioria dos `2`s). Para um `n` grande (279, 188, 131, 317), o código produzirá `count`s próximos a `n-1` ou `n-2`.
    -   Por exemplo, para o Test 2 (`279` elementos, `1`, `277` `2`s, `1`, `1`):
        -   `current` se torna `1` no primeiro `1`.
        -   Cada um dos `277` `2`s adiciona `1` ao `count`. `count` se torna `277`.
        -   Os últimos dois `1`s incrementam `current`, mas não afetam `count`.
        -   Saída do código: `277` (ou 278, dependendo de como as bordas são contadas, mas definitivamente não 3).
    -   Saída esperada para todos eles: `3`
    -   **Falha: As saídas do código (e.g., 277, 186, 129, 315, respectivamente) não correspondem à saída esperada (3).**

A lógica implementada no código, que soma a contagem de `1`s precedentes a cada `2`, não corresponde ao comportamento esperado pelos casos de teste adicionais, apesar de coincidir com o exemplo inicial da descrição. Isso indica uma interpretação incorreta do problema "Sequência Secreta". A complexidade de tempo é O(N) devido à leitura dos N elementos e uma única iteração sobre eles. A complexidade de espaço é O(N) devido ao armazenamento da sequência em um `std::vector<int>`. Não há problemas de overflow para os tipos `int` com os dados de entrada fornecidos.