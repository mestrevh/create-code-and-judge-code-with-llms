/*
Código criado pelo models/gemini-2.5-flash
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream> // Para cin e cout

int main() {
    // Otimização padrão para E/S em programação competitiva.
    // Desvincula o C++ stream do C stdio e remove a sincronização.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N; // Lê o número de elementos na sequência

    // Se N for 0, não há elementos, então 0 blocos.
    if (N == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int current_element;
    int previous_element;
    int distinct_blocks_count = 0;

    // O primeiro elemento sempre inicia um novo bloco.
    std::cin >> previous_element;
    distinct_blocks_count = 1; 

    // Itera sobre os N-1 elementos restantes da sequência.
    for (int i = 1; i < N; ++i) {
        std::cin >> current_element; // Lê o elemento atual
        
        // Se o elemento atual for diferente do elemento anterior,
        // um novo bloco de números distintos começou.
        if (current_element != previous_element) {
            distinct_blocks_count++;
        }
        
        // Atualiza o elemento anterior para a próxima iteração.
        previous_element = current_element;
    }

    // Imprime o número total de blocos distintos.
    std::cout << distinct_blocks_count << std::endl;

    return 0;
}