/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    std::vector<int> pedras(N + 1, 0);
    for (int i = 0; i < M; ++i) {
        int P, D;
        std::cin >> P >> D;
        for (int j = P; j <= N; j += D) {
            pedras[j] = 1;
        }
        for (int j = P; j >= 1; j -= D) {
            pedras[j] = 1;
        }
    }
    for (int i = 1; i <= N; ++i) {
        std::cout << pedras[i] << "\n";
    }
    return 0;
}
