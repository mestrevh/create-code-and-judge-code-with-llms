# Modelo do judge: gpt-4o-mini

1. **Status:** Incorreto  
2. **Tempo estimado:** O(N) - onde N é o número de entradas (neste caso fixo em 3, mas O(1) é o mesmo que O(N) aqui)  
3. **Avaliação:** O código sempre imprime o valor da variável `a`, independentemente das demais entradas ou da lógica do problema. O enunciado parece exigir que o programa calcule a idade restante, que é a diferença entre a idade máxima `m` e a soma das idades `a` e `b` (ou seja, `m - (a + b)`). Portanto, o programa falha em atender ao problema, produzindo sempre uma saída errada. Para corrigir, o código deve ser alterado para calcular e imprimir `m - (a + b)`. Enquanto a complexidade de tempo no contexto do problema é aceitável, a implementação atual não está correta e não atende ao que foi pedido.