/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int V, P;
    cin >> V >> P;

    const double pi = 3.14;
    const double volume_voltorb = (4.0 / 3.0) * pi * pow(0.25, 3); // 0.5m de altura = 0.25m de raio
    const double volume_pokebola = (4.0 / 3.0) * pi * pow(0.035, 3); // 7cm de diâmetro = 0.035m de raio

    double volume_total = V * volume_voltorb + P * volume_pokebola;
    double area_base = 5.0 * 4.0; // área da piscina em m²
    double altura_aumento = (volume_total / area_base) * 100; // em cm

    cout << fixed << setprecision(1);
    cout << "Altura da piscina aumentou: " << altura_aumento << " cm" << endl;

    return 0;
}
