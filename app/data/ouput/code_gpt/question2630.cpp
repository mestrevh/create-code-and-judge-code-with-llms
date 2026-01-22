/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Digite o valor do primeiro ângulo:\n";
    cin >> a;
    cout << "Digite o valor do segundo ângulo:\n";
    cin >> b;
    cout << "Digite o valor do terceiro ângulo:\n";
    cin >> c;

    if (a == 90 || b == 90 || c == 90) {
        cout << "Este e um triangulo retangulo.\n";
    } else if (a > 90 || b > 90 || c > 90) {
        cout << "Este e um triangulo obtusangulo.\n";
    } else {
        cout << "Este e um triangulo acutangulo.\n";
    }

    return 0;
}
