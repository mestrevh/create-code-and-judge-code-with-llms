/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    for (int c = 1; c <= T; ++c) {
        int N;
        std::cin >> N;
        long long first_odd = (long long)N * N - N + 1;
        std::cout << "caso " << c << ":";
        for (int i = 0; i < N; ++i) {
            std::cout << " " << first_odd;
            first_odd += 2;
        }
        std::cout << "\n";
    }
    return 0;
}
