# Modelo do judge: gpt-5.4

1. Status: Incorreto
2. Tempo estimado: O(N) por caso de teste
3. Avaliação: O código é eficiente em tempo e memória, usando uma variação do algoritmo de Kadane com complexidade linear, o que é adequado para N até 10000. Porém, a implementação do critério de desempate está incompleta/incorreta: quando há mais de um período com o mesmo saldo máximo, o problema exige escolher o maior período, e isso pode exigir manter um prefixo negativo/zero anterior para ampliar o intervalo. Como o código reinicia apenas quando `current_sum < 0`, ele pode perder intervalos mais longos com a mesma soma máxima em alguns casos. Portanto, embora seja rápido e bem dentro dos limites, não produz sempre a saída esperada.