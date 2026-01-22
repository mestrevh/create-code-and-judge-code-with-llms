/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

void derivada(int *coeficiente, int *expoente) {
    if (*expoente > 0) {
        *coeficiente = (*coeficiente) * (*expoente);
        (*expoente)--;
    } else {
        *coeficiente = 0;
        *expoente = -1;
    }
}

struct Monomial {
    int coeff;
    int exp;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != 0) {
        std::vector<Monomial> derivative_poly;
        char main_var = 'x';
        bool var_found = false;

        for (int i = 0; i < n; ++i) {
            int c, e;
            char v;
            std::cin >> c >> v >> e;

            if (!var_found && v != '0') {
                main_var = v;
                var_found = true;
            }

            derivada(&c, &e);

            if (c != 0) {
                derivative_poly.push_back({c, e});
            }
        }

        std::cout << "f'(" << main_var << ")=";

        if (derivative_poly.empty()) {
            std::cout << "0";
        } else {
            for (const auto& term : derivative_poly) {
                if (term.coeff > 0) {
                    std::cout << "+";
                }
                std::cout << term.coeff;

                if (term.exp > 0) {
                    std::cout << main_var << "^" << term.exp;
                }
            }
        }

        std::cout << "\n";
    }

    return 0;
}
