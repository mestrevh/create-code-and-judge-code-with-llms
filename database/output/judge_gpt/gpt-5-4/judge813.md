# Modelo do judge: gpt-5.4

1. Status: Incorreto
2. Tempo estimado: O(N) por caso de teste
3. Avaliação: A complexidade é eficiente e adequada para N até 10000, pois apenas varre os retângulos uma vez. Porém, a implementação erra na condição de existência da interseção: usa `max_x < min_u && min_y > max_v`, descartando casos em que a interseção é degenerada em linha ou ponto, que pelos testes devem ser considerados válidos. O correto seria aceitar também igualdade, isto é, `max_x <= min_u && min_y >= max_v`. Assim, o código falha em casos como o teste 2 do conjunto 2 (`-10 1 1 0`) e vários outros.