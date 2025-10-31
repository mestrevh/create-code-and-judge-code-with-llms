/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int d1, d2, m;
    std::cin >> d1 >> d2 >> m;

    double f = (10.0 * m) / (d1 + d2);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Scar conseguiu criar uma frustração " << f << " na turma" << std::endl;

    if (f >= 4.0) {
        std::cout << "Eu matei Mufasa" << std::endl;
    } else if (f > 2.0) {
        std::cout << "Consegui lacaios preciosos" << std::endl;
    } else {
        std::cout << "Mais um fracasso..." << std::endl;
    }

    return 0;
}
