/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, C;
    std::cin >> N >> C;

    int current_passengers = 0;
    bool capacity_exceeded = false;

    for (int i = 0; i < N; ++i) {
        int S, E;
        std::cin >> S >> E;
        current_passengers -= S;
        current_passengers += E;
        if (current_passengers > C) {
            capacity_exceeded = true;
        }
    }

    if (capacity_exceeded) {
        std::cout << "S\n";
    } else {
        std::cout << "N\n";
    }

    return 0;
}
