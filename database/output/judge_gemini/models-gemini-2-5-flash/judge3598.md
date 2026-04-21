# Modelo do judge: models/gemini-2.5-flash

VEREDITO: REPROVADO
COMPLEXIDADE: O(1) tempo, O(1) espaço
FEEDBACK: O código submetido tem uma complexidade de tempo e espaço ótima, O(1) para ambos, pois realiza um número fixo de operações (leitura de 3 inteiros, 2 comparações para encontrar o máximo e uma impressão). No entanto, a lógica implementada (`cout << max({a, b, c}) << endl;`) falha em todos os casos de teste fornecidos, incluindo o exemplo da descrição do problema.

Apesar da ausência de uma descrição textual do problema, as amostras de entrada e saída são a fonte de verdade para a lógica esperada.
Por exemplo:
- Para a entrada `52 14 18` (exemplo do problema), o código produz `52`, mas o esperado é `20`.
- Para a entrada `47 21 9` (test 0), o código produz `47`, mas o esperado é `21`.
- Para a entrada `100 14 25` (test 2), o código produz `100`, mas o esperado é `61`.

A saída do código não corresponde à saída esperada em nenhum dos casos de teste. A funcionalidade de encontrar o máximo entre três números não é o que o problema "Idade" parece solicitar, conforme demonstrado pelas saídas esperadas.