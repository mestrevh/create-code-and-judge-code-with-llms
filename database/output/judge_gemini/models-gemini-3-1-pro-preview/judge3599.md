# Modelo do judge: models/gemini-3.1-pro-preview

VEREDITO: REPROVADO
COMPLEXIDADE: O(N) tempo, O(1) espaço
FEEDBACK: O código falha por um erro de lógica ao confundir a busca por uma "subsequência alternada" com a de um "sub-array contíguo alternado". O problema (Sequência Secreta) pede a quantidade máxima de números que podem ser marcados de forma que não haja dois adjacentes iguais, o que se traduz apenas em contar o número total de vezes que o valor muda ao longo de toda a sequência lida. 

No entanto, a sua implementação reinicia o contador (`else cur = 1;`) sempre que encontra dois números consecutivos iguais. Realizando a simulação exata do Teste 0 (cuja saída esperada é 7):
- Ao ler `1, 2, 1, 2`, a variável `cur` atinge 4, e `best` se torna 4.
- Ao ler o próximo `2`, a condição `x != prev` é falsa. O código executa `cur = 1`, perdendo todo o progresso da subsequência construída até ali.
- Como o restante da sequência não possui mais de dois valores alternados em sequência perfeita, `best` não passa de 4, e o código imprime `4` em vez de `7`.

Para corrigir o problema, remova a lógica de reiniciar o contador e a variável `best`. Basta utilizar apenas uma variável de contagem que é incrementada (`cur++`) toda vez que `i == 0 || x != prev`. Ao final, imprima essa contagem. A complexidade O(N) de tempo e O(1) de espaço está excelente e deve ser mantida.