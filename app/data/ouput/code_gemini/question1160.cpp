/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

double calcular_distancia(int x1, int z1, int x2, int z2) {
    double dx = x1 - x2;
    double dz = z1 - z2;
    return std::sqrt(dx * dx + dz * dz);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x_tantan, z_tantan;
    std::cin >> x_tantan >> z_tantan;

    const int x_hogsmeade = 34;
    const int z_hogsmeade = 220;

    const int x_kakariko = 0;
    const int z_kakariko = 0;

    const int x_solitude = 140;
    const int z_solitude = 456;

    double dist_hogsmeade = calcular_distancia(x_tantan, z_tantan, x_hogsmeade, z_hogsmeade);
    double dist_kakariko = calcular_distancia(x_tantan, z_tantan, x_kakariko, z_kakariko);
    double dist_solitude = calcular_distancia(x_tantan, z_tantan, x_solitude, z_solitude);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Distancia para Hogsmeade: " << dist_hogsmeade << std::endl;
    std::cout << "Distancia para Kakariko: " << dist_kakariko << std::endl;
    std::cout << "Distancia para Solitude: " << dist_solitude << std::endl;

    return 0;
}
