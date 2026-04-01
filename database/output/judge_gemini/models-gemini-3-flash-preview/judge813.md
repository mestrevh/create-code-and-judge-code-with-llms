# Modelo do judge: models/gemini-3-flash-preview

VEREDITO: REPROVADO

COMPLEXIDADE: O(N) tempo, O(1) espaço.

FEEDBACK: O código apresenta um erro de lógica na ordenação das coordenadas de saída. De acordo com o enunciado, o programa deve imprimir a interseção no formato "X Y U V", onde (X, Y) é o canto superior esquerdo e (U, V) é o canto inferior direito. Em um sistema de coordenadas cartesianas usuais, o canto superior possui um valor de Y maior que o canto inferior.

Rastreando o Exemplo 1 do Teste 0:
Entrada:
3
0 6 8 1
1 5 6 3
2 4 9 0

Simulação do código:
1. Retângulo 1 (0 6 8 1): `l=0, r=8, t=1, b=6`. `left=0, right=8, top=1, bottom=6`.
2. Retângulo 2 (1 5 6 3): `l=1, r=6, t=3, b=5`. `left=max(0,1)=1, right=min(8,6)=6, top=max(1,3)=3, bottom=min(6,5)=5`.
3. Retângulo 3 (2 4 9 0): `l=2, r=9, t=0, b=4`. `left=max(1,2)=2, right=min(6,9)=6, top=max(3,0)=3, bottom=min(5,4)=4`.

Ao final, as variáveis possuem os valores: `left=2, right=6, top=3, bottom=4`.
O comando de saída é: `cout << left << " " << top << " " << right << " " << bottom`.
Saída produzida: `2 3 6 4`
Saída esperada: `2 4 6 3`

O erro ocorre porque o código armazena a coordenada Y superior (máxima) na variável `bottom` e a coordenada Y inferior (mínima) na variável `top`, mas as imprime na ordem `top` e depois `bottom`, invertendo a posição de Y e V exigida pelo problema. Além disso, embora a complexidade seja excelente, a falha em passar nos casos de teste básicos impossibilita a aprovação.