/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double r;
    if (cin >> r) {
        const double pi = 3.14;
        // Formula para o volume de uma esfera: V = (4/3) * pi * r^3
        // Mantendo alta precisao para a divisao 4/3 e o raio
        double volume = (4.0 / 3.0) * pi * r * r * r;
        
        // Formata a saida para 2 casas decimais conforme solicitado
        cout << fixed << setprecision(2) << volume << endl;
    }

    return 0;
}