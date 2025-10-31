/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string figura;
    cin >> figura;
    
    if (figura == "retangulo") {
        double base, altura;
        cin >> base >> altura;
        cout << fixed << setprecision(2) << base * altura << endl;
    } else if (figura == "triangulo") {
        double base, altura;
        cin >> base >> altura;
        cout << fixed << setprecision(2) << (base * altura) / 2 << endl;
    } else if (figura == "trapezio") {
        double basemaior, basemenor, altura;
        cin >> basemaior >> basemenor >> altura;
        cout << fixed << setprecision(2) << ((basemaior + basemenor) * altura) / 2 << endl;
    } else if (figura == "circulo") {
        double raio;
        cin >> raio;
        cout << fixed << setprecision(2) << 3.1415 * raio * raio << endl;
    }
    
    return 0;
}
