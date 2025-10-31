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
    if (!(std::cin >> n)) {
        return 0;
    }

    std::vector<std::vector<int>> lab(n);
    for (int i = 0; i < n; ++i) {
        int num_computadores;
        std::cin >> num_computadores;
        lab[i].resize(num_computadores);
        for (int j = 0; j < num_computadores; ++j) {
            std::cin >> lab[i][j];
        }
    }

    std::cout << "Pessoal, vai ter aula de IP aqui agora\n";

    int reduction_factor = 0;
    for (int i = 0; i < n; ++i) {
        bool monitor_ligado_na_fileira = false;
        for (int audacia : lab[i]) {
            if (audacia > 0) {
                monitor_ligado_na_fileira = true;
                break;
            }
        }

        if (monitor_ligado_na_fileira) {
            std::cout << "Desliga o monitor...\n";
            reduction_factor++;

            for (int r = 0; r < n; ++r) {
                for (size_t c = 0; c < lab[r].size(); ++c) {
                    if (lab[r][c] > 0) {
                        lab[r][c] -= reduction_factor;
                    }
                }
            }
        }
    }

    int expulsos = 0;
    for (int i = 0; i < n; ++i) {
        for (int audacia : lab[i]) {
            if (audacia > 0) {
                expulsos++;
            }
        }
    }

    if (expulsos > 0) {
        std::cout << "Sergio pistolou e expulsou " << expulsos << " aluno(s) do laboratorio.\n";
    }

    return 0;
}
