/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p1, c1, p2, c2;
    if (!(cin >> p1 >> c1 >> p2 >> c2)) return 0;

    if (p1 < 10 || p1 > 100 || c1 < 10 || c1 > 100 ||
        p2 < 10 || p2 > 100 || c2 < 10 || c2 > 100) {
        cout << "Restricao violada" << endl;
    } else {
        int momento1 = p1 * c1;
        int momento2 = p2 * c2;

        if (momento1 == momento2) {
            cout << "Gangorra equilibrada" << endl;
        } else if (momento1 > momento2) {
            cout << "Gangorra desequilibrada para a esquerda" << endl;
        } else {
            cout << "Gangorra desequilibrada para a direita" << endl;
        }
    }

    return 0;
}