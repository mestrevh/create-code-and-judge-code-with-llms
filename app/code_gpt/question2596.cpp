/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double altura, raio, custo_lata;
    cin >> altura >> raio >> custo_lata;

    double area_base = M_PI * raio * raio;
    double area_cilindro = 2 * area_base + 2 * M_PI * raio * altura;
    double litros_tinta = area_cilindro / 3;
    double latas_tinta = ceil(litros_tinta / 5);
    double custo_total = latas_tinta * custo_lata;

    cout << fixed << setprecision(6);
    cout << area_cilindro << "m2\n";
    cout << litros_tinta << "l\n";
    cout << latas_tinta << "\n";
    cout << "R$" << custo_total << endl;

    return 0;
}
