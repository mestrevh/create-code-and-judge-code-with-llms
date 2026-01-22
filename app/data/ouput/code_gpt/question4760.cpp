/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int P1, C1, P2, C2;
    cin >> P1 >> C1 >> P2 >> C2;

    if ((P1 < 10 || P1 > 100) || (C1 < 10 || C1 > 100) || (P2 < 10 || P2 > 100) || (C2 < 10 || C2 > 100)) {
        cout << "Restricao violada" << endl;
    } else {
        int left = P1 * C1;
        int right = P2 * C2;
        if (left == right) {
            cout << "Gangorra equilibrada" << endl;
        } else if (left < right) {
            cout << "Gangorra desequilibrada para a esquerda" << endl;
        } else {
            cout << "Gangorra desequilibrada para a direita" << endl;
        }
    }

    return 0;
}
