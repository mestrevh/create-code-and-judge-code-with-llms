# Modelo do judge: models/gemini-3-flash-preview

VEREDITO: APROVADO

COMPLEXIDADE: O(T * (N^3 + M)) tempo, O(N^2) espaço, onde T é o número de casos de teste.

FEEDBACK: O código implementa uma solução de busca exaustiva (brute-force) que é perfeitamente adequada para os limites do problema (N < 100). A simulação mental e a análise estática confirmam que:

1. **Eficiência Logística**: O uso de uma matriz de adjacência `w[N+1][N+1]` permite consultas de entrosamento em tempo constante O(1). Para N=100, o custo de memória é de aproximadamente 40KB, o que é desprezível.
2. **Correção do Algoritmo**: O triplo loop aninhado percorre todas as combinações $\binom{N}{3}$. Como os músicos são iterados em ordem crescente ($a < b < c$), o algoritmo naturalmente processa as combinações em ordem lexicográfica.
3. **Desempate Lexicográfico**: O problema exige que, em caso de empate na pontuação, seja impresso o trio que aparece primeiro lexicograficamente. O código lida com isso de duas formas: implicitamente, através da ordem dos loops, e explicitamente, com a comparação `if (cur < bestTriple)`.
4. **Tratamento de Jimmy**: Conforme a descrição, Jimmy tem entrosamento zero com todos. Portanto, a soma total do entrosamento da banda de 4 pessoas é simplificada para a soma dos entrosamentos entre os 3 músicos escolhidos, o que o código calcula corretamente: `w[a][b] + w[a][c] + w[b][c]`.
5. **Robustez**: A implementação de `FastInput` com `fread` garante que o programa não seja gargalado por I/O, mesmo com o limite generoso de 5 segundos. O uso de `long long` para a soma previne overflows, embora, com $Z \le 100$, a soma máxima seja 300 (cabendo em um `int`).
6. **Casos de Teste**: O código passou na simulação de todos os cenários, incluindo grafos esparsos, completos, com entrosamento zero e o limite máximo $N=100$.

A implementação é profissional e segue as melhores práticas para competições de programação (OIB/ACM-ICPC).