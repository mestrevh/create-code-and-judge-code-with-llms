/*
Código criado pelo models/gemini-2.5-flash
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm> // Para std::max e std::min

int main() {
    // Otimização padrão de I/O em C++
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    // Se N for 0, nenhuma seção pode estar coberta.
    // Embora as restrições indiquem N >= 1, é uma boa prática.
    if (N == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> H[i];
    }

    // prefix_max[i] armazena a altura máxima da seção 0 até a seção i.
    std::vector<int> prefix_max(N);
    prefix_max[0] = H[0];
    for (int i = 1; i < N; ++i) {
        prefix_max[i] = std::max(prefix_max[i-1], H[i]);
    }

    int covered_sections = 0;
    // current_suffix_max_val armazena a altura máxima da seção i até a seção N-1,
    // calculada dinamicamente à medida que iteramos de trás para frente.
    int current_suffix_max_val = 0; 

    // Itera da direita para a esquerda.
    for (int i = N - 1; i >= 0; --i) {
        // Atualiza current_suffix_max_val para incluir H[i].
        // Após esta linha, current_suffix_max_val representa max(H[i], ..., H[N-1]).
        current_suffix_max_val = std::max(current_suffix_max_val, H[i]);
        
        // O nível máximo de água que a seção i pode acumular é o mínimo
        // entre a altura máxima à sua esquerda (incluindo H[i]) e a altura máxima à sua direita (incluindo H[i]).
        int effective_water_level = std::min(prefix_max[i], current_suffix_max_val);
        
        // Uma seção é considerada coberta se houver água com pelo menos 1m de profundidade.
        // Isso significa que o nível de água efetivo deve ser estritamente maior que a altura da seção.
        if (effective_water_level > H[i]) {
            covered_sections++;
        }
    }

    std::cout << covered_sections << std::endl;

    return 0;
}