/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

const double PI = 3.14;
const double BASE_AREA = 5.0 * 4.0;

double volumeVoltorb() {
    double radius = 0.25; // 0.5m diâmetro / 2
    return (4.0 / 3.0) * PI * radius * radius * radius;
}

double volumePokebola() {
    double radius = 0.035; // 7cm diâmetro / 2
    return (4.0 / 3.0) * PI * radius * radius * radius;
}

int main() {
    int V, P;
    cin >> V >> P;

    double totalVolume = V * volumeVoltorb() + P * volumePokebola();
    double heightIncrease = totalVolume / BASE_AREA * 100; // convert to cm

    cout << fixed << setprecision(1);
    cout << "Altura da piscina aumentou: " << heightIncrease << " cm" << endl;

    return 0;
}
