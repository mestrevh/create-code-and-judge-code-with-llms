/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double x, y;
    char l;
    int n;

    if (!(std::cin >> x >> y >> l >> n)) {
        std::cout << "Entrada Invalida\n";
        return 0;
    }

    if (x < 0.0 || x >= 24.0 || y < 0.0 || y >= 24.0 || x >= y || (l != 'A' && l != 'B') || n <= 0) {
        std::cout << "Entrada Invalida\n";
        return 0;
    }

    double time_available = y - x;
    bool possible = false;

    if (l == 'A') {
        double min_time = 1.0;
        double extended_time = 1.5;

        if (time_available > min_time) {
            if (n <= 5) {
                possible = true;
            } else if (n > 5 && n <= 9) {
                if (time_available >= extended_time) {
                    possible = true;
                }
            }
        }
    } else if (l == 'B') {
        double min_time = 0.75;
        double extended_time = 1.125;

        if (time_available > min_time) {
            if (n <= 5) {
                possible = true;
            } else if (n > 5 && n <= 9) {
                if (time_available >= extended_time) {
                    possible = true;
                }
            }
        }
    }

    if (possible) {
        std::cout << "O uninho faz a boa, obrigado querida mae line\n";
    } else {
        std::cout << "Infelizmente o uninho nao tanka, rodamos!\n";
    }

    return 0;
}
