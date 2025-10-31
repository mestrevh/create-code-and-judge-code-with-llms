/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int getMove(int n) {
    if (isPrime(n)) {
        return 1; // Papel
    }
    if (n % 2 == 0) {
        return 0; // Pedra
    }
    return 2; // Tesoura
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    int sapo_wins = 0;
    int shuas_wins = 0;

    for (int i = 0; i < N; ++i) {
        int a, b;
        std::cin >> a >> b;

        int move_a = getMove(a);
        int move_b = getMove(b);

        if (move_a == move_b) {
            continue;
        }
        
        // 0: Pedra, 1: Papel, 2: Tesoura
        // Pedra (0) ganha de Tesoura (2)
        // Papel (1) ganha de Pedra (0)
        // Tesoura (2) ganha de Papel (1)
        if ((move_a == 0 && move_b == 2) ||
            (move_a == 1 && move_b == 0) ||
            (move_a == 2 && move_b == 1)) {
            sapo_wins++;
        } else {
            shuas_wins++;
        }
    }

    if (sapo_wins > shuas_wins) {
        std::cout << "Sapo sopa esta de boa na lagoa!\n";
    } else if (shuas_wins > sapo_wins) {
        std::cout << "Testemunhe a verdadeira forca!\n";
    } else {
        std::cout << "Impending doom approaches...\n";
    }

    return 0;
}
