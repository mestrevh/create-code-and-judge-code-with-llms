/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

/**
 * Calcula a velocidade final em km/h.
 * Formula: V = V0 + A*T (m/s)
 * Conversão: Vkm/h = Vm/s * 3.6
 */
double velkmh(double v0, double a, double t) {
    return (v0 + (a * t)) * 3.6;
}

int main() {
    // Otimização de I/O para competições de programação
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double v0, a, t;
    
    // Processa entradas enquanto houver dados (suporta múltiplos casos de teste)
    while (cin >> v0 >> a >> t) {
        double v1 = velkmh(v0, a, t);
        
        // Lê dados do segundo carro
        if (!(cin >> v0 >> a >> t)) break;
        double v2 = velkmh(v0, a, t);
        
        // Lê dados do terceiro carro
        if (!(cin >> v0 >> a >> t)) break;
        double v3 = velkmh(v0, a, t);
        
        // Determina o menor entre os três valores
        double menor_velocidade = min({v1, v2, v3});
        
        // Exibe o resultado com uma casa decimal conforme solicitado
        cout << fixed << setprecision(1) << menor_velocidade << "\n";
    }

    return 0;
}