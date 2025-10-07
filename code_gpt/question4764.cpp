/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

pair<double, double> calcularBaricentro(double A1, double A2, double B1, double B2, double C1, double C2) {
    double P1 = (A1 + B1 + C1) / 3.0;
    double P2 = (A2 + B2 + C2) / 3.0;
    return {P1, P2};
}

char deslocarLetra(char letra, int deslocamento) {
    return 'A' + (letra - 'A' + deslocamento + 26) % 26;
}

int main() {
    double A1, A2, B1, B2, C1, C2, D1, D2;
    char M1, M2;

    cin >> A1 >> A2 >> B1 >> B2 >> C1 >> C2 >> M1 >> M2 >> D1 >> D2;

    auto [P1, P2] = calcularBaricentro(A1, A2, B1, B2, C1, C2);
    char F1 = deslocarLetra(M1, D1);
    char F2 = deslocarLetra(M2, D2);

    cout << fixed << setprecision(2);
    cout << "A pista esta na coordenada: (" << P1 << ", " << P2 << ") e o cod e: " << F1 << F2 << endl;

    return 0;
}
