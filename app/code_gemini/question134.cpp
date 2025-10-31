/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    while (std::cin >> N && N != -1) {
        std::vector<int> left_boots(61, 0);
        std::vector<int> right_boots(61, 0);

        for (int i = 0; i < N; ++i) {
            int M;
            char L;
            std::cin >> M >> L;
            if (L == 'E') {
                left_boots[M]++;
            } else {
                right_boots[M]++;
            }
        }

        int total_pairs = 0;
        for (int i = 30; i <= 60; ++i) {
            total_pairs += std::min(left_boots[i], right_boots[i]);
        }

        std::cout << total_pairs << "\n";
    }

    return 0;
}
