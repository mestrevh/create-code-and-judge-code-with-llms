/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

void maior_numero(double a, double b) {
    if (a == b) {
        cout << "iguais" << endl;
    } else {
        if (a > b) {
            cout << a << endl;
        } else {
            cout << b << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n1, n2;
    if (cin >> n1 >> n2) {
        maior_numero(n1, n2);
    }

    return 0;
}