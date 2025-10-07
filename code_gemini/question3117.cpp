/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

double calculate_distance(int x1, int z1, int x2, int z2) {
    long long dx = x1 - x2;
    long long dz = z1 - z2;
    return std::sqrt(dx * dx + dz * dz);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int tantan_x, tantan_z;
    std::cin >> tantan_x >> tantan_z;

    const int hogsmeade_x = 34;
    const int hogsmeade_z = 220;
    const int kakariko_x = 0;
    const int kakariko_z = 0;
    const int solitude_x = 140;
    const int solitude_z = 456;

    double dist_hogsmeade = calculate_distance(tantan_x, tantan_z, hogsmeade_x, hogsmeade_z);
    double dist_kakariko = calculate_distance(tantan_x, tantan_z, kakariko_x, kakariko_z);
    double dist_solitude = calculate_distance(tantan_x, tantan_z, solitude_x, solitude_z);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Distancia para Hogsmeade: " << dist_hogsmeade << std::endl;
    std::cout << "Distancia para Kakariko: " << dist_kakariko << std::endl;
    std::cout << "Distancia para Solitude: " << dist_solitude << std::endl;

    return 0;
}
