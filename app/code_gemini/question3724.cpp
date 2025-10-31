/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

void Calcula(double *concentracaoBase, double *concentracaoTotal, double *pOH, int indiceHidroxilas) {
    double oh_adicionado = (*concentracaoBase) * indiceHidroxilas;
    *concentracaoTotal += oh_adicionado;
    *pOH = -log10(*concentracaoTotal);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << std::fixed << std::setprecision(1);

    double concentracaoBase;
    double concentracaoTotalOH = 0.0;
    double pOH;

    while (std::cin >> concentracaoBase && concentracaoBase != 0) {
        std::string elemento, oh_str;
        int indiceElemento, indiceHidroxilas;
        std::cin >> elemento >> indiceElemento >> oh_str >> indiceHidroxilas;

        Calcula(&concentracaoBase, &concentracaoTotalOH, &pOH, indiceHidroxilas);

        double phFranjinha = 9.0 - pOH;

        std::cout << phFranjinha << std::endl;
    }

    return 0;
}
