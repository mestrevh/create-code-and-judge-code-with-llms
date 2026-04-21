/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Função exigida pela Hello Kitty para calcular a quantidade de sorvetes.
 * Como o problema garante cálculos exatos, uma divisão simples resolve.
 */
inline long long calcularSorvetes(long long tempoTotal, long long tempoPorSorvete) {
    if (tempoPorSorvete == 0) return 0;
    return tempoTotal / tempoPorSorvete;
}

int main() {
    // Otimização de I/O padrão para Programação Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long B, K, T;

    // Leitura dos tempos conforme o formato de entrada
    // B: Badtz-Maru, K: Keroppi, T: Tempo por sorvete
    if (cin >> B >> K >> T) {
        long long sorvetesBadtz = calcularSorvetes(B, T);
        long long sorvetesKeroppi = calcularSorvetes(K, T);

        // Saída formatada exatamente como solicitado
        cout << "Badtz-Maru comeu " << sorvetesBadtz << " sorvetes." << "\n";
        cout << "Keroppi comeu " << sorvetesKeroppi << " sorvetes." << endl;
    }

    return 0;
}