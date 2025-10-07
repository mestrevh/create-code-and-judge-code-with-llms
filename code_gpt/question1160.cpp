/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int xTantan, zTantan;
    std::cin >> xTantan >> zTantan;

    int xHogsmeade = 34, zHogsmeade = 220;
    int xKakariko = 0, zKakariko = 0;
    int xSolitude = 140, zSolitude = 456;

    double distHogsmeade = std::sqrt(pow(xTantan - xHogsmeade, 2) + pow(zTantan - zHogsmeade, 2));
    double distKakariko = std::sqrt(pow(xTantan - xKakariko, 2) + pow(zTantan - zKakariko, 2));
    double distSolitude = std::sqrt(pow(xTantan - xSolitude, 2) + pow(zTantan - zSolitude, 2));

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Distancia para Hogsmeade: " << distHogsmeade << std::endl;
    std::cout << "Distancia para Kakariko: " << distKakariko << std::endl;
    std::cout << "Distancia para Solitude: " << distSolitude << std::endl;

    return 0;
}
