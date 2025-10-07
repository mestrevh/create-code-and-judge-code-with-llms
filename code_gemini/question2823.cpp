/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << "Digite a soma dos dados em cada rodada separados por ENTER:" << std::endl;

    int r1, r2, r3;
    if (!(std::cin >> r1 >> r2 >> r3)) {
        return 1;
    }

    int rounds[] = {r1, r2, r3};

    for (int i = 0; i < 3; ++i) {
        if (rounds[i] < 2 || rounds[i] > 12) {
            std::cout << "Valor invalido" << std::endl;
            return 0;
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (rounds[i] == 2) {
            std::cout << "Biu perdeu" << std::endl;
            return 0;
        }
    }

    bool cond1_met = false;
    bool cond2_met = false;

    for (int i = 0; i < 3; ++i) {
        if (rounds[i] >= 10 || rounds[i] <= 4) {
            cond1_met = true;
        }
        if (rounds[i] % 2 == 0) {
            cond2_met = true;
        }
    }

    if (cond1_met && cond2_met) {
        std::cout << "Biu ganhou" << std::endl;
    } else {
        std::cout << "Biu perdeu" << std::endl;
    }

    return 0;
}
