/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

void Calcula(double *concentracaoBase, double *concentracaoTotal, double *pOH, int indiceHidroxilas) {
    *concentracaoTotal += (*concentracaoBase) * indiceHidroxilas;
    *pOH = -log10(*concentracaoTotal);
}

int main() {
    double concentracaoBase, concentracaoTotal = 0, pOH;
    std::string elemento;
    int indiceHidroxilas;

    while (true) {
        std::cin >> concentracaoBase;
        if (concentracaoBase == 0) break;

        std::cin >> elemento >> indiceHidroxilas >> elemento >> indiceHidroxilas;
        Calcula(&concentracaoBase, &concentracaoTotal, &pOH, indiceHidroxilas);
        
        double pH = 9 - pOH;
        std::cout << std::fixed << std::setprecision(1) << pH << std::endl;
    }
    return 0;
}
