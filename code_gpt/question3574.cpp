/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

bool isTriangular(int x) {
    int n = (int)((sqrt(8 * x + 1) - 1) / 2);
    return (n * (n + 1)) / 2 == x;
}

bool isSquare(int x) {
    int s = (int)(sqrt(x));
    return s * s == x;
}

bool isPentagonal(int x) {
    int n = (int)((sqrt(24 * x + 1) + 1) / 6);
    return (n * (3 * n - 1)) / 2 == x;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int N, M;
        std::cin >> N >> M;

        int triangularCount = 0, squareCount = 0;
        bool hasPentagonal = false;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int num;
                std::cin >> num;

                if (isTriangular(num)) triangularCount++;
                else if (isSquare(num)) squareCount++;
                if (isPentagonal(num)) hasPentagonal = true;
            }
        }

        std::cout << "Temos " << triangularCount << " crianças\n";
        std::cout << "Temos " << squareCount << " bebês\n";
        if (hasPentagonal) {
            std::cout << "Oba! Kinho vai trabalhar hoje.\n";
        } else {
            std::cout << "Hoje o bebê vai chorar sozinho...\n";
        }
    }

    return 0;
}
