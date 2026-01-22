/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int x, z;
    std::cin >> x >> z;
    
    int hogsmeadeX = 34, hogsmeadeZ = 220;
    int kakarikoX = 0, kakarikoZ = 0;
    int solitudeX = 140, solitudeZ = 456;
    
    double distanceHogsmeade = sqrt(pow(x - hogsmeadeX, 2) + pow(z - hogsmeadeZ, 2));
    double distanceKakariko = sqrt(pow(x - kakarikoX, 2) + pow(z - kakarikoZ, 2));
    double distanceSolitude = sqrt(pow(x - solitudeX, 2) + pow(z - solitudeZ, 2));
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Distancia para Hogsmeade: " << distanceHogsmeade << "\n";
    std::cout << "Distancia para Kakariko: " << distanceKakariko << "\n";
    std::cout << "Distancia para Solitude: " << distanceSolitude << "\n";
    
    return 0;
}
