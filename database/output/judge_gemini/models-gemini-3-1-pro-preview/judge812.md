# Modelo do judge: models/gemini-3.1-pro-preview

VEREDITO: APROVADO
COMPLEXIDADE: O(N) tempo, O(1) espaço
FEEDBACK: O código implementa uma variação do Algoritmo de Kadane utilizando Somas de Prefixos (Prefix Sums) de forma elegante. Ele mantêm em tempo constante qual foi o menor prefixo anterior (`minPref`) e seu índice (`minPos`). Isso não só permite determinar de imediato a soma do melhor subsegmento terminando no índice atual (`cur = sum - minPref`), como também quebrar empates de tamanho escolhendo sempre o de maior extensão, pois `minPos` só é atualizado se a soma for estritamente menor (`<`), garantindo que se use o prefixo mais distante possível. 

A formatação de saída com a linha em branco residual mesmo após o último caso de teste cumpre a exigência das regras de maratona (como no URI/Beecrowd). Além disso, os dados (`sum`, `minPref`, `best`) estão tipados seguramente como `long long`, e o `ios::sync_with_stdio(false); cin.tie(nullptr);` é um ótimo hábito para manter a I/O performática. Excelente implementação!