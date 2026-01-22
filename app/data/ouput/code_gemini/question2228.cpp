/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int I, D, P;
    double A;
    std::string S;

    std::cin >> I >> A >> D >> P >> S;

    if (S == "Sim") {
        I += 5;
        P += 50;
    }

    double jump_height = (static_cast<double>(I) * A) + (static_cast<double>(D) * D / P);

    if (jump_height >= 100) {
        std::cout << "Voce consegue" << std::endl;
    } else {
        std::cout << "Isso e perda de tempo" << std::endl;
    }

    return 0;
}
