/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

bool is_prime(int n) {
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

unsigned long long factorial(int n) {
    unsigned long long res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int dis, tam;
    std::cin >> dis >> tam;

    long long xp = 0;
    int vale_moedas = 0;
    std::vector<int> prime_positions;

    for (int i = 0; i <= dis; ++i) {
        int current_pos = i % tam;

        if (is_prime(current_pos)) {
            xp += current_pos;
            prime_positions.push_back(current_pos);
        }

        if (current_pos == 7) {
            vale_moedas++;
        }
    }

    for (size_t i = 0; i < prime_positions.size(); ++i) {
        std::cout << prime_positions[i] << (i == prime_positions.size() - 1 ? "" : " ");
    }
    std::cout << "\n";

    unsigned long long moedas = 0;
    if (vale_moedas > 0) {
        moedas = factorial(vale_moedas);
    }

    std::cout << "Experiencia = " << xp << " Moedas = " << moedas << "\n";

    if (moedas == 0) {
        std::cout << "Ja que nao achei moedas, vou na Torre\n";

        std::vector<int> tower_floors;
        for (int i = 1; i <= xp; ++i) {
            if (i % 7 == 0) {
                tower_floors.push_back(i);
            }
        }

        for (size_t i = 0; i < tower_floors.size(); ++i) {
            std::cout << tower_floors[i] << (i == tower_floors.size() - 1 ? "" : " ");
        }
        std::cout << "\n";

        long long tower_moedas = tower_floors.size() * 30;

        if (tower_moedas > 0) {
            std::cout << "Consegui " << tower_moedas << " moedas na Torre\n";
        } else {
            std::cout << "Desisto.\n";
        }
    }

    return 0;
}
