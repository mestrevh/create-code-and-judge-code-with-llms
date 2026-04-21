# Modelo do judge: models/gemini-3.1-pro-preview

VEREDITO: APROVADO
COMPLEXIDADE: O(N) tempo, O(1) espaço
FEEDBACK: O código implementa uma solução extremamente eficiente e matematicamente sólida para encontrar a interseção de retângulos. A lógica central de sobreposição está perfeita: a interseção de um conjunto de retângulos, se existir, é dada pelo máximo das coordenadas esquerdas (`left = max(left, X)`), o mínimo das coordenadas superiores (`top = min(top, Y)`), o mínimo das coordenadas direitas (`right = min(right, U)`) e o máximo das coordenadas inferiores (`bottom = max(bottom, V)`). 

A simulação estática confirma que o programa lida muito bem com as restrições:
1. **Otimização de Memória:** O código consome a entrada em "streaming" contínuo, sem a necessidade de armazenar os dados dos retângulos em arrays/vetores. Isso garante uma complexidade de espaço O(1) rigorosa.
2. **Inicialização de Limites Segura:** Os valores extremos definidos como `1000000000` e `-1000000000` previnem perfeitamente qualquer falso-positivo ou falso-negativo, cobrindo com vasta margem os limites coordenados de restrição do problema (-10000 a 10000) e cabendo em segurança no tipo primitivo `int` sem causar "integer overflow".
3. **Validação de Interseção:** O bloco condicional `if (left <= right && bottom <= top)` está impecável ao checar a existência de uma área de interseção válida, retornando adequadamente a string "nenhum" para intersecções nulas/vazias.
4. **Formatação OBI:** As requisições de saída estrita do problema foram devidamente acatadas, com atenção correta às quebras de linha (`\n`) exigidas até mesmo após a última resposta de teste. Lógica e sintaxe irrepreensíveis. Eficiência de tempo ótima em O(N) por caso de teste.