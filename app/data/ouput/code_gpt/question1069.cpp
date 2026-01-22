/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    char figura;
    cin >> figura;
    if (figura == 'Q' || figura == 'q') {
        float lado;
        cin >> lado;
        if (lado < 0) {
            cout << "Nenhuma figura selecionada" << endl;
            return 0;
        }
        float area = lado * lado;
        float perimetro = 4 * lado;
        cout << fixed << setprecision(2) << area << endl << perimetro << endl;
    } else if (figura == 'R' || figura == 'r') {
        float altura, largura;
        cin >> altura >> largura;
        if (altura < 0 || largura < 0) {
            cout << "Nenhuma figura selecionada" << endl;
            return 0;
        }
        float area = altura * largura;
        float perimetro = 2 * (altura + largura);
        cout << fixed << setprecision(2) << area << endl << perimetro << endl;
    } else if (figura == 'C' || figura == 'c') {
        float raio;
        cin >> raio;
        if (raio < 0) {
            cout << "Nenhuma figura selecionada" << endl;
            return 0;
        }
        float area = 3.14 * raio * raio;
        float comprimento = 2 * 3.14 * raio;
        cout << fixed << setprecision(2) << area << endl << comprimento << endl;
    } else {
        cout << "Nenhuma figura selecionada" << endl;
    }
    return 0;
}
