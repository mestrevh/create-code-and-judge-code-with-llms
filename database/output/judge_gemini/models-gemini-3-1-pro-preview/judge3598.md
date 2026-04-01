# Modelo do judge: models/gemini-3.1-pro-preview

VEREDITO: REPROVADO
COMPLEXIDADE: O(1) tempo, O(1) espaço
FEEDBACK: O código falha porque interpreta o problema de forma incorreta. A lógica implementada ordena as três entradas e imprime o valor do meio (a mediana dos três números lidos). No entanto, o problema clássico "Idade de Dona Mônica" fornece a idade da mãe e as idades de dois dos filhos, solicitando a idade do filho mais velho. A idade do terceiro filho deve ser calculada subtraindo as idades dos dois filhos da idade da mãe (`m - a - b`), e a resposta final deve ser o valor máximo entre os três filhos. 

O erro de lógica fica evidente ao simular o Teste 2:
Entrada: 100 14 25 (Mãe: 100, Filho 1: 14, Filho 2: 25)
O filho 3 teria: 100 - 14 - 25 = 61 anos. O filho mais velho tem 61 anos (saída esperada).
Porém, o código submetido cria o vetor `{100, 14, 25}`, ordena para `{14, 25, 100}` e imprime `v[1]`, resultando em 25. Como 25 != 61, a submissão é reprovada.