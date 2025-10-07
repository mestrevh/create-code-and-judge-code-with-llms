/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

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

bool is_perfect_square(int n) {
    if (n < 0) {
        return false;
    }
    if (n == 0) {
        return true;
    }
    int root = round(sqrt(n));
    return root * root == n;
}

struct CinCabeca {
    int idade;
    int id;
    std::string nome;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    CinCabeca p1, p2;

    std::cin >> p1.idade >> p1.id;
    std::cin >> p1.nome;

    std::cin >> p2.idade >> p2.id;
    std::cin >> p2.nome;

    int pontos1 = 0;
    int pontos2 = 0;

    if (p1.nome > p2.nome) {
        pontos1 += 2;
    } else if (p2.nome > p1.nome) {
        pontos2 += 2;
    }

    if (is_prime(p1.idade)) {
        pontos1 += 4;
    }
    if (is_prime(p2.idade)) {
        pontos2 += 4;
    }

    if (is_perfect_square(p1.id)) {
        pontos1 += 3;
    }
    if (is_perfect_square(p2.id)) {
        pontos2 += 3;
    }

    if (pontos1 > pontos2) {
        std::cout << p1.nome << " WINS" << std::endl;
    } else if (pontos2 > pontos1) {
        std::cout << p2.nome << " WINS" << std::endl;
    } else {
        std::cout << "CInCABECAS EMPATADOS" << std::endl;
    }

    return 0;
}
