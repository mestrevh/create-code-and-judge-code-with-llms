# Modelo do judge: models/gemini-3.1-pro-preview

VEREDITO: APROVADO
COMPLEXIDADE: O(N + M) tempo, O(N) espaço
FEEDBACK: O código submetido é excelente e atende a todos os requisitos do problema com alta eficiência e segurança de tipos. A lógica foi perfeitamente implementada. Na simulação exata: 
- Teste 0: O mapeamento das casas ocorre corretamente, e a travessia (0 -> 2 -> 3 -> 2 -> 4 -> 0) soma distâncias (2+1+1+2+4) = 10, batendo perfeitamente com a saída esperada.
- Teste 1: A travessia (0 -> 1 -> 1 -> 2 -> 0) soma distâncias (1+0+1+2) = 4, também batendo exatamente.

Destaco como pontos muito positivos na sua engenharia de software:
1. Otimização de I/O com `ios::sync_with_stdio(false)` e `cin.tie(nullptr)`.
2. Uso do `unordered_map` com a chamada de `reserve(N * 2)`, o que previne o rehashing custoso durante as inserções, garantindo a complexidade de tempo de O(N) para leitura e O(M) para as consultas. *Nota de engenheiro: Como a entrada já é estritamente crescente, o uso de `std::lower_bound` (Busca Binária) dispensaria a necessidade de memória extra do Hash Map rodando em O(M log N), o que também seria validíssimo, mas o uso do Hash Map entrega O(N + M) de forma elegante.*
3. Uso seguro de `long long` para a variável `ans` e o método `llabs()`. Embora a distância máxima teórica do problema some algo próximo a 2 * 10^9 (cabendo no limite do int32 padrão), o uso de 64-bits previne qualquer tipo de overflow silently, uma excelente prática em programação competitiva e sistemas reais. O estado inicial `cur = 0` também satisfaz o critério de iniciar na menor casa. Código robusto, limpo e aprovado.