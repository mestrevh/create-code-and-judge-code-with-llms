/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

const long long TARGET = 10000000;

long long solve(long long current_x, long long current_money, int M) {
    if (current_money >= TARGET) {
        return current_x;
    }

    long long next_x = current_x + 1;
    long long next_money;

    if (next_x % 2 != 0) {
        next_money = current_money + M;
    } else {
        next_money = current_money + next_x;
    }

    return solve(next_x, next_money, M);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M;
    std::cin >> M;
    
    long long result = solve(0, 0, M);

    std::cout << result << " pessoas precisam assistir ao jogo.\n";

    return 0;
}
