/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double fahrenheit;
    cout << "Digite uma temperatura na escala Fahrenheit:" << endl;
    cin >> fahrenheit;
    double celsius = 5.0 * (fahrenheit - 32) / 9.0;
    cout << "Temperatura em Celsius: " << fixed << setprecision(1) << celsius << endl;
    return 0;
}
