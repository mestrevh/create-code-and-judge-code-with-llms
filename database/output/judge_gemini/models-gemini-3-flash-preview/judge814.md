# Modelo do judge: models/gemini-3-flash-preview

VEREDITO: APROVADO
COMPLEXIDADE: O(N) tempo, O(N) espaço
FEEDBACK: O código implementa corretamente a verificação de existência de um Caminho ou Ciclo Euleriano em um multigrafo não direcionado, que é a base teórica para o problema do Dominó. A solução verifica as duas condições necessárias e suficientes:
1. Conectividade: Todos os vértices com grau maior que zero pertencem a uma única componente conectada (verificado via BFS).
2. Paridade dos Graus: O número de vértices com grau ímpar deve ser 0 (Ciclo Euleriano) ou 2 (Caminho Euleriano).
A implementação é eficiente para os limites fornecidos (N <= 100 e valores de 0 a 6), operando com complexidade de tempo linear em relação ao número de peças. A formatação da saída e o tratamento do caso de interrupção (N=0) estão em conformidade com a especificação. A alocação redundante dos vetores `a` e `b` não prejudica o desempenho ou a lógica.