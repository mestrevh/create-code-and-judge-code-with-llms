# Modelo do judge: models/gemini-2.5-flash

VEREDITO: REPROVADO
COMPLEXIDADE: O(N + M log N) tempo, O(N + M) espaço
FEEDBACK:

Prezado(a) Engenheiro(a),

Sua implementação foi submetida a uma análise estática rigorosa e a uma simulação passo a passo contra os casos de teste fornecidos. Infelizmente, o código foi REPROVADO.

**Causa da Reprovação:**

O erro fundamental reside na interpretação da regra de cálculo de tempo. A descrição do problema afirma claramente: "você pode assumir que o carteiro leva uma unidade de tempo para caminhar de uma casa até a casa imediatamente vizinha". Isso implica que o tempo de deslocamento entre duas casas é a diferença absoluta entre seus *índices* no vetor `casas` (que está ordenado e representa a sequência física das casas na rua), e **não** a diferença absoluta entre os *números* das casas.

Seu código utiliza a linha `tempo += std::abs(pos_atual - pos_entrega);` para calcular o tempo. Aqui, `pos_atual` e `pos_entrega` armazenam os *números* das casas. Esta abordagem está incorreta e falha em reproduzir o comportamento esperado pelo problema.

**Exemplo de Falha (Baseado no Teste 0):**

*   **Casas:** `[1 (idx 0), 5 (idx 1), 10 (idx 2), 20 (idx 3), 40 (idx 4)]`
*   **Carteiro começa em:** Casa `1` (índice `0`)
*   **Primeira encomenda para:** Casa `10` (índice `2`)

*   **Seu código calcula:** `std::abs(1 - 10) = 9` unidades de tempo.
*   **O problema espera:** `std::abs(0 - 2) = 2` unidades de tempo (duas "passagens" entre casas vizinhas: de índice 0 para 1, e de 1 para 2).

Essa discrepância leva a resultados incorretos em todos os casos de teste onde a diferença entre os números das casas não corresponde à diferença entre seus índices.

**Resultados da Simulação nos Casos de Teste:**

1.  **<test 0>**
    *   **Input:**
        ```
        5 5
        1 5 10 20 40
        10 20 10 40 1
        ```
    *   **Simulação do seu código:**
        *   Início: `pos_atual = 1`, `tempo = 0`
        *   Encomenda 10: `tempo += abs(1 - 10) = 9`. `pos_atual = 10`. `tempo = 9`.
        *   Encomenda 20: `tempo += abs(10 - 20) = 10`. `pos_atual = 20`. `tempo = 19`.
        *   Encomenda 10: `tempo += abs(20 - 10) = 10`. `pos_atual = 10`. `tempo = 29`.
        *   Encomenda 40: `tempo += abs(10 - 40) = 30`. `pos_atual = 40`. `tempo = 59`.
        *   Encomenda 1: `tempo += abs(40 - 1) = 39`. `pos_atual = 1`. `tempo = 98`.
    *   **Saída do seu código:** `98`
    *   **Saída esperada:** `10`
    *   **Resultado:** Falhou

2.  **<test 1>**
    *   **Input:**
        ```
        3 4
        50 80 100
        80 80 100 50
        ```
    *   **Simulação do seu código:**
        *   Início: `pos_atual = 50`, `tempo = 0`
        *   Encomenda 80: `tempo += abs(50 - 80) = 30`. `pos_atual = 80`. `tempo = 30`.
        *   Encomenda 80: `tempo += abs(80 - 80) = 0`. `pos_atual = 80`. `tempo = 30`.
        *   Encomenda 100: `tempo += abs(80 - 100) = 20`. `pos_atual = 100`. `tempo = 50`.
        *   Encomenda 50: `tempo += abs(100 - 50) = 50`. `pos_atual = 50`. `tempo = 100`.
    *   **Saída do seu código:** `100`
    *   **Saída esperada:** `4`
    *   **Resultado:** Falhou

**Sugestão de Correção:**

Para corrigir o problema, você deve:
1.  Armazenar o *índice* da casa atual (`pos_atual_idx`), em vez do número da casa.
2.  Quando uma encomenda chega para um determinado `pos_entrega` (número da casa), você deve encontrar o *índice* correspondente a esse número no vetor `casas`. O `std::lower_bound` já retorna um iterador para a posição correta. Você pode usar `std::distance(casas.begin(), it)` para obter o índice.
3.  Então, adicione `std::abs(pos_atual_idx - novo_indice_da_entrega)` ao `tempo`.
4.  Atualize `pos_atual_idx` para `novo_indice_da_entrega`.

A complexidade de tempo `O(N + M log N)` e de espaço `O(N + M)` é eficiente e está dentro dos limites para os dados fornecidos, se a lógica fosse implementada corretamente. Observe que, embora o `int` para `tempo` seja teoricamente suficiente para as restrições (`2,024,955,000` < `2,147,483,647`), usar `long long` para somas acumuladas de tempo é uma prática mais segura para evitar qualquer risco de overflow em contextos ligeiramente diferentes.