/*
Código criado pelo models/gemini-2.5-flash
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm> // Para std::lower_bound e std::abs
#include <cmath>     // Também fornece std::abs para diversos tipos numéricos

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> house_numbers(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> house_numbers[i];
    }

    long long total_time = 0;
    // O carteiro começa na primeira casa (menor número), que corresponde ao índice 0.
    int current_house_idx = 0; 

    for (int i = 0; i < M; ++i) {
        int target_house_num;
        std::cin >> target_house_num;

        // Encontra o índice da casa de destino usando busca binária.
        // std::lower_bound retorna um iterador para o primeiro elemento que não é menor que target_house_num.
        // Como house_numbers é estritamente crescente e todas as casas de destino existem na lista,
        // isso encontrará o elemento exato.
        auto it = std::lower_bound(house_numbers.begin(), house_numbers.end(), target_house_num);
        int target_house_idx = std::distance(house_numbers.begin(), it);

        // Calcula o tempo de viagem como a diferença absoluta entre os índices das casas.
        total_time += std::abs(target_house_idx - current_house_idx);

        // Atualiza a posição atual do carteiro.
        current_house_idx = target_house_idx;
    }

    std::cout << total_time << std::endl;

    return 0;
}