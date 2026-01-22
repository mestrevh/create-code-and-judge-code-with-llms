/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

double Calcula_tempo(int x0, int z0, int xf, int zf, int v) {
    double dx = xf - x0;
    double dz = zf - z0;
    double distancia = std::sqrt(dx * dx + dz * dz);
    double tempo = distancia / v;
    return tempo;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x0, z0, xf, zf, v;
    std::cin >> x0 >> z0 >> xf >> zf >> v;

    double tempo_viagem = Calcula_tempo(x0, z0, xf, zf, v);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Milos esta no ponto (" << x0 << ", " << z0
              << ") indo para (" << xf << ", " << zf
              << ") e provavelmente ira chegar em " << tempo_viagem
              << " horas." << std::endl;

    return 0;
}
