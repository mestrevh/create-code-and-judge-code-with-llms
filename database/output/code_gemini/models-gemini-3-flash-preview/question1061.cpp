/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double r1, r2;
    if (!(cin >> r1 >> r2)) return 0;

    // Use pi = 3.14 as specified in the problem description
    const double pi = 3.14;
    double area1 = pi * r1 * r1;
    double area2 = pi * r2 * r2;

    if (area1 > area2) {
        cout << "Primeiro circulo" << endl;
    } else if (area2 > area1) {
        cout << "Segundo circulo" << endl;
    } else {
        cout << "Iguais" << endl;
    }

    return 0;
}