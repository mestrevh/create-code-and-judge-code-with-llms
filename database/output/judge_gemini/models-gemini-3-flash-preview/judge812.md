# Modelo do judge: models/gemini-3-flash-preview

VEREDITO: REPROVADO

COMPLEXIDADE: O(N) tempo, O(N) espaço

FEEDBACK: O código falha em implementar corretamente a regra de desempate para o "maior período". De acordo com o enunciado, se houver mais de um período com o mesmo saldo de gols, deve-se escolher o período mais longo (onde B - A é maior). No entanto, a lógica de atualização da variável `minPos` no código fornecido faz exatamente o oposto.

No trecho:
```cpp
if (pref[j] < minPref) {
    minPref = pref[j];
    minPos = j;
} else if (pref[j] == minPref) {
    if (j > minPos) minPos = j;
}
```
Quando o programa encontra um prefixo de mesmo valor (`pref[j] == minPref`), ele atualiza `minPos` para o índice mais atual (`j`). Como o saldo de um período é calculado por `pref[j] - minPref`, manter o `minPos` o mais antigo possível (o menor valor) é essencial para garantir que o período `j - minPos` seja o mais longo possível em caso de empate no saldo. Ao atualizar para o `j` mais recente, o código descarta a possibilidade de encontrar um período mais longo que comece no `minPos` anterior.

Exemplo de falha:
Se as diferenças de gols forem `1, -1, 1`, os saldos possíveis de valor 1 são os períodos (1,1), (3,3) e (1,3). O maior período é (1,3).
- No índice `j=1` (pref=1): `best=1, I=1, J=1, minPref=0, minPos=0`.
- No índice `j=2` (pref=0): `pref[2] == minPref`, então o código atualiza `minPos = 2`.
- No índice `j=3` (pref=1): `cur = pref[3] - minPref = 1 - 0 = 1`. Como `minPos` agora é 2, o comprimento `lenCur` é `3 - (2+1) = 0`. O `lenBest` anterior também era 0. A condição `lenCur > lenBest` falha.
O programa retornaria `1 1` em vez de `1 3`. Esse erro de lógica fará com que o código seja reprovado em casos de teste que exijam o desempate por comprimento de período.