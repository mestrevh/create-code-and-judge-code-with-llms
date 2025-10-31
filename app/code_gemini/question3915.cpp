/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, b, c;
    std::cin >> a >> b >> c;

    bool found = false;

    if (a * a == c) {
        if (!found) {
            std::cout << "Quadrado Vitoris\n";
            found = true;
        } else {
            std::cout << "tambem Quadrado\n";
        }
    }

    if (b != 0 && a % b == c) {
        if (!found) {
            std::cout << "Resto Vitoris\n";
            found = true;
        } else {
            std::cout << "tambem Resto\n";
        }
    }

    if (a * b == c) {
        if (!found) {
            std::cout << "Multi Vitoris\n";
            found = true;
        } else {
            std::cout << "tambem Multi\n";
        }
    }

    if (b != 0 && a / b == c) {
        if (!found) {
            std::cout << "Div Vitoris\n";
            found = true;
        } else {
            std::cout << "tambem Div\n";
        }
    }

    if (a + b == c) {
        if (!found) {
            std::cout << "Soma Vitoris\n";
            found = true;
        } else {
            std::cout << "tambem Soma\n";
        }
    }

    if (a - b == c) {
        if (!found) {
            std::cout << "Sub Vitoris\n";
            found = true;
        } else {
            std::cout << "tambem Sub\n";
        }
    }

    if (!found) {
        std::cout << "Impossivel vitores\n";
    }

    return 0;
}
