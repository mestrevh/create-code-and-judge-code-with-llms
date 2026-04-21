/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double angulo1, angulo2;
    if (cin >> angulo1 >> angulo2) {
        cout << "Digite o 1° ângulo:" << "\n";
        cout << "Digite o 2° ângulo:" << "\n";
        double angulo3 = 180.0 - (angulo1 + angulo2);
        cout << "O terceiro ângulo é: " << angulo3 << "\n";
    }

    return 0;
}