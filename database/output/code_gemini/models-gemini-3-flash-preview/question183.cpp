/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    if (!(std::cin >> N)) return 0;

    int total_broken = 0;
    for (int i = 0; i < N; ++i) {
        int L, C;
        std::cin >> L >> C;
        if (L > C) {
            total_broken += C;
        }
    }

    std::cout << total_broken << "\n";

    return 0;
}