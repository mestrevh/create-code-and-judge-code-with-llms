/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * Calcula o tempo de viagem entre dois pontos (x0, z0) e (xf, zf)
 * dada uma velocidade média v.
 */
double Calcula_tempo(double x0, double z0, double xf, double zf, double v) {
    double dx = xf - x0;
    double dz = zf - z0;
    double distancia = sqrt(dx * dx + dz * dz);
    return distancia / v;
}

int main() {
    // Otimização de I/O padrão para Programação Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double x0, z0, xf, zf, v;

    // Leitura dos dados: localização atual (x0, z0), final (xf, zf) e velocidade v
    while (cin >> x0 >> z0 >> xf >> zf >> v) {
        double tempo = Calcula_tempo(x0, z0, xf, zf, v);

        // Saída formatada conforme o exemplo fornecido
        // Note: As coordenadas são impressas sem fixação de precisão decimal,
        // enquanto o tempo é formatado com 2 casas decimais.
        cout << "Milos esta no ponto (" << x0 << ", " << z0 << ") "
             << "indo para (" << xf << ", " << zf << ") "
             << "e provavelmente ira chegar em " 
             << fixed << setprecision(2) << tempo << " horas." << endl;
    }

    return 0;
}