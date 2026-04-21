/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    if (std::cin >> N) {
        for (int i = 0; i < N; ++i) {
            if (i > 0) {
                std::cout << " ";
            }
            std::cout << "Ho";
        }
        std::cout << "!\n";
    }

    return 0;
}