# Modelo do judge: models/gemini-3-flash-preview

VEREDITO: REPROVADO

COMPLEXIDADE: O(N²) tempo, O(N) espaço.

FEEDBACK: O código falhou em quase todos os casos de teste (exceto no Caso 1 por coincidência). O erro é de natureza lógica e de interpretação do problema:
1. **Lógica Incorreta**: O problema "Sequência Secreta" (da OBI) solicita o tamanho da maior subsequência onde elementos adjacentes são diferentes (ex: 1, 2, 1, 2...). O código fornecido tenta encontrar o maior subvetor contíguo onde a diferença entre o valor máximo e mínimo seja $\le 1$. Como a entrada contém apenas os números 1 e 2, a condição `mx - mn <= 1` será sempre verdadeira para qualquer intervalo. Consequentemente, o código sempre retornará o valor de $N$ (o tamanho total da sequência de entrada), o que está incorreto.
2. **Eficiência**: A implementação utiliza dois loops aninhados, resultando em uma complexidade de tempo $O(N^2)$. Para o problema original da OBI, onde $N$ pode chegar a $10^5$, esta solução sofreria TLE (Time Limit Exceeded). A solução correta utiliza uma abordagem gulosa (Greedy) em $O(N)$.
3. **Simulação do Teste 0**: Para $N=12$ e a sequência `1 2 1 2 2 2 1 1 2 2 1 1`, o código produz a saída `12`, enquanto o esperado é `7`.