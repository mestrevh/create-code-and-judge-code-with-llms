/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<int>> matriz(N, std::vector<int>(M));
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            std::cin >> matriz[i][j];

    int P;
    std::cin >> P;
    std::vector<std::pair<int, int>> pos(P);
    
    for (int i = 0; i < P; i++) {
        int x, y;
        std::cin >> x >> y;
        pos[i] = {x - 1, y - 1};
    }

    int T;
    std::cin >> T;

    int acumulador = 0;
    for (const auto& p : pos) {
        acumulador += matriz[p.first][p.second];
    }

    double pontuacao = static_cast<double>(acumulador) / T;
    std::cout << std::fixed << std::setprecision(2) << pontuacao << std::endl;

    return 0;
}
