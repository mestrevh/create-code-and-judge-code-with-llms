/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int Cv, Ce, Cs, Fv, Fe, Fs;
    std::cin >> Cv >> Ce >> Cs >> Fv >> Fe >> Fs;
    int pontosC = Cv * 3 + Ce;
    int pontosF = Fv * 3 + Fe;
    if (pontosC > pontosF) {
        std::cout << "C" << std::endl;
    } else if (pontosF > pontosC) {
        std::cout << "F" << std::endl;
    } else {
        if (Cs > Fs) {
            std::cout << "C" << std::endl;
        } else if (Fs > Cs) {
            std::cout << "F" << std::endl;
        } else {
            std::cout << "=" << std::endl;
        }
    }
    return 0;
}
