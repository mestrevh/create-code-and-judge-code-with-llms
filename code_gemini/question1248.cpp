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

    int l, c;
    std::cin >> l >> c;

    std::vector<std::vector<std::string>> terreno(l, std::vector<std::string>(c));
    int gasto = 0;

    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cin >> terreno[i][j];
            if (terreno[i][j] == "vermelho") {
                gasto += 3;
                terreno[i][j] = "amarelo";
            }
        }
    }

    int s;
    std::cin >> s;

    for (int i = 0; i < s; ++i) {
        int x, y;
        std::cin >> x >> y;
        if (terreno[x - 1][y - 1] == "amarelo") {
            terreno[x - 1][y - 1] = "verde";
        }
    }

    int ganho = 0;
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            if (terreno[i][j] == "verde") {
                ganho += 4;
            }
        }
    }

    int lucro = ganho - gasto;

    if (lucro < 0) {
        std::cout << "prejuizo" << std::endl;
    } else {
        std::cout << lucro << std::endl;
    }

    return 0;
}
