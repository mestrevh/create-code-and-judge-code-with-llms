# Modelo do judge: models/gemini-2.5-flash

VEREDITO: REPROVADO
COMPLEXIDADE: O(N) tempo, O(1) espaço
FEEDBACK: O código implementa corretamente a lógica para encontrar a interseção de múltiplos retângulos. A inicialização das coordenadas da caixa delimitadora do universo (`x1 = -10000, y1 = -10000, x2 = 10000, y2 = 10000`) é adequada para os limites de entrada (-10000 a 10000). A atualização dos limites da interseção usando `max` para as coordenadas inferiores (X do canto superior esquerdo e V do canto inferior direito) e `min` para as coordenadas superiores (U do canto inferior direito e Y do canto superior esquerdo) também está correta. A condição para verificar se a interseção é vazia (`x1 < x2 && y1 < y2`) é precisa.

No entanto, o código falha no formato de saída para os casos de teste onde a interseção não é vazia. A especificação do problema pede a saída no formato "X Y U V", onde (X, Y) são as coordenadas do canto superior esquerdo e (U, V) são as coordenadas do canto inferior direito do retângulo de interseção.

As variáveis do seu código, após o loop, representam:
*   `x1`: Coordenada X do canto superior esquerdo da interseção (correto para o X de saída).
*   `y1`: Coordenada V do canto inferior direito da interseção (correto para o V de saída).
*   `x2`: Coordenada U do canto inferior direito da interseção (correto para o U de saída).
*   `y2`: Coordenada Y do canto superior esquerdo da interseção (correto para o Y de saída).

A linha de saída do seu código é `cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;`. Isso significa que você está imprimindo na ordem `res_X, res_V, res_U, res_Y`.
A ordem correta, de acordo com o formato da entrada e saída do problema (X Y U V, onde X e Y são do canto superior esquerdo, U e V do canto inferior direito), deveria ser `res_X, res_Y, res_U, res_V`.

Portanto, o teste 0 falha no primeiro e terceiro caso de teste devido à ordem incorreta das coordenadas Y e V na saída.

**Exemplo do Teste 0, Caso 1:**
*   Cálculo: `x1=2, y1=3, x2=6, y2=4`
    *   Isto significa: `res_X = 2`, `res_V = 3`, `res_U = 6`, `res_Y = 4`.
*   Saída do seu código: `2 3 6 4` (i.e., `res_X` `res_V` `res_U` `res_Y`)
*   Saída esperada: `2 4 6 3` (i.e., `res_X` `res_Y` `res_U` `res_V`)

Para corrigir, a linha de impressão deve ser modificada para:
`cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;`

A complexidade de tempo é O(N) por conjunto de teste, pois o programa processa cada um dos N retângulos com operações de tempo constante. A complexidade de espaço é O(1), pois apenas um número fixo de variáveis é usado independentemente de N. Ambas são eficientes para os limites de N.