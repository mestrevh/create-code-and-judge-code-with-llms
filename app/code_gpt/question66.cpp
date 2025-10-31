/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double C, i;
    int anos;
    std::cin >> C >> i >> anos;
    
    int trimestres = anos * 4;
    
    for (int t = 1; t <= trimestres; ++t) {
        double rendimento = C * i;
        C += rendimento;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Rendimento: " << rendimento << " Montante: " << C << std::endl;
    }
    
    return 0;
}
