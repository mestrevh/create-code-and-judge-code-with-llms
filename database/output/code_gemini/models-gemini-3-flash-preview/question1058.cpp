/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double T, M;
    const double R = 8.31;

    while (cin >> T >> M) {
        // A descrição pede a "velocidade média", porém os casos de teste
        // fornecidos (84.25, 187.01 -> 3.35) correspondem à fórmula da
        // Velocidade Quadrática Média (RMS): v = sqrt(3 * R * T / M).
        // Velocidade Média Real seria sqrt(8 * R * T / (pi * M)).
        // Utilizaremos a fórmula que valida os testes fornecidos.
        double v_rms = sqrt((3.0 * R * T) / M);
        
        cout << fixed << setprecision(2) << v_rms << "\n";
    }

    return 0;
}