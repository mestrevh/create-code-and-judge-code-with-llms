/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::string> matriz(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> matriz[i];
    }

    bool cond1 = false;
    bool cond2 = false;
    bool cond3 = false;
    bool cond4 = false;

    // Condição 1: BRANCO
    bool placement_ok = true;
    bool has_guards_even = false;
    bool has_populars_odd = false;
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            if (j % 2 == 0) { // Coluna par
                if (matriz[i][j] == 'g') {
                    has_guards_even = true;
                } else if (matriz[i][j] != 'x') {
                    placement_ok = false;
                }
            } else { // Coluna ímpar
                if (matriz[i][j] == 'p') {
                    has_populars_odd = true;
                } else if (matriz[i][j] != 'x') {
                    placement_ok = false;
                }
            }
        }
    }
    if (placement_ok && has_guards_even && has_populars_odd) {
        cond1 = true;
    }

    // Condição 2: AMARELO
    for (int i = 0; i < n; ++i) {
        int suspects = 0;
        for (int j = 0; j < n; ++j) {
            if (matriz[i][j] == 's') {
                suspects++;
            }
        }
        if (suspects >= 2) {
            cond2 = true;
            break;
        }
    }

    // Condição 3: LARANJA
    for (int i = 0; i < n; ++i) {
        if (matriz[i][i] == 'i' || matriz[i][n - 1 - i] == 'i') {
            cond3 = true;
            break;
        }
    }

    // Condição 4: VERMELHO
    int threats = 0;
    int guards = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                if (matriz[i][j] == 'i' || matriz[i][j] == 's') {
                    threats++;
                } else if (matriz[i][j] == 'g') {
                    guards++;
                }
            }
        }
    }
    if (threats > guards) {
        cond4 = true;
    }

    if (!cond1 && !cond2 && !cond3 && !cond4) {
        std::cout << "AZUL\n";
    } else {
        std::cout << (cond1 ? "BRANCO" : "TRANSPARENTE") << "\n";
        std::cout << (cond2 ? "AMARELO" : "TRANSPARENTE") << "\n";
        std::cout << (cond3 ? "LARANJA" : "TRANSPARENTE") << "\n";
        std::cout << (cond4 ? "VERMELHO" : "TRANSPARENTE") << "\n";
    }

    return 0;
}
