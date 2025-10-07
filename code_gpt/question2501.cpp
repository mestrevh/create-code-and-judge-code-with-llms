/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int D1, D2, M;
    std::cin >> D1 >> D2 >> M;

    double F = 10.0 * M / (D1 + D2);
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Scar conseguiu criar uma frustração " << F << " na turma" << std::endl;

    if (F >= 4) {
        std::cout << "Eu matei Mufasa" << std::endl;
    } else if (F > 2) {
        std::cout << "Consegui lacaios preciosos" << std::endl;
    } else {
        std::cout << "Mais um fracasso..." << std::endl;
    }

    return 0;
}
