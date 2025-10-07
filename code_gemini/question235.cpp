/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int par[5];
    int impar[5];
    int count_par = 0;
    int count_impar = 0;
    int valor;

    for (int i = 0; i < 15; ++i) {
        std::cin >> valor;

        if (valor % 2 == 0) {
            par[count_par] = valor;
            count_par++;
            if (count_par == 5) {
                for (int j = 0; j < 5; ++j) {
                    std::cout << "par[" << j << "] = " << par[j] << '\n';
                }
                count_par = 0;
            }
        } else {
            impar[count_impar] = valor;
            count_impar++;
            if (count_impar == 5) {
                for (int j = 0; j < 5; ++j) {
                    std::cout << "impar[" << j << "] = " << impar[j] << '\n';
                }
                count_impar = 0;
            }
        }
    }

    for (int i = 0; i < count_impar; ++i) {
        std::cout << "impar[" << i << "] = " << impar[i] << '\n';
    }

    for (int i = 0; i < count_par; ++i) {
        std::cout << "par[" << i << "] = " << par[i] << '\n';
    }

    return 0;
}
