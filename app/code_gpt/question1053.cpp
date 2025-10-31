/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    float altura, raio;
    cin >> altura >> raio;

    const float pi = 3.14;
    float volume = pi * pow(raio, 2) * altura;
    float area = 2 * pi * raio * (altura + raio);

    cout << fixed << setprecision(2) << volume << endl;
    cout << fixed << setprecision(2) << area << endl;

    return 0;
}
