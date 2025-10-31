/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int N, L;
    while (std::cin >> N >> L, N || L) {
        std::vector<int> armarios(L);
        for (int i = 0; i < L; ++i) {
            std::cin >> armarios[i];
        }
        
        int min_trocas = INT_MAX;
        
        for (int i = 0; i <= L - N; ++i) {
            int needed = armarios[i + N - 1] - armarios[i] + 1;
            int trocas = needed - N;
            min_trocas = std::min(min_trocas, trocas);
        }
        
        std::cout << min_trocas << std::endl;
    }
    return 0;
}
