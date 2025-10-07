/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    int p1, c1, p2, c2;
    cin >> p1 >> c1 >> p2 >> c2;

    if (p1 < 10 || p1 > 100 || c1 < 10 || c1 > 100 || p2 < 10 || p2 > 100 || c2 < 10 || c2 > 100) {
        cout << "Restricao violada" << endl;
    } else {
        if (p1 * c1 == p2 * c2) {
            cout << "Gangorra equilibrada" << endl;
        } else if (p1 * c1 > p2 * c2) {
            cout << "Gangorra desequilibrada para a esquerda" << endl;
        } else {
            cout << "Gangorra desequilibrada para a direita" << endl;
        }
    }

    return 0;
}
