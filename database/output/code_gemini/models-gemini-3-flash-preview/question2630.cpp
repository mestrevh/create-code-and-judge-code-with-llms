/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b, c;
    while (cin >> a >> b >> c) {
        cout << "Digite o valor do primeiro ângulo:" << "\n";
        cout << "Digite o valor do segundo ângulo:" << "\n";
        cout << "Digite o valor do terceiro ângulo:" << "\n";

        if (a == 90.0 || b == 90.0 || c == 90.0) {
            cout << "Este e um triangulo retangulo." << "\n";
        } else if (a > 90.0 || b > 90.0 || c > 90.0) {
            cout << "Este e um triangulo obtusangulo." << "\n";
        } else {
            cout << "Este e um triangulo acutangulo." << "\n";
        }
    }

    return 0;
}