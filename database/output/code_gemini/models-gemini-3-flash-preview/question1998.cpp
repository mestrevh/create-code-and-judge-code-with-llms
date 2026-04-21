/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;

    while (cin >> a && (a < 1 || a > 9)) {
        cout << "Insira um valor de 1 a 9" << "\n";
    }

    while (cin >> b && (b < 1 || b > 9)) {
        cout << "Insira um valor de 1 a 9" << "\n";
    }

    for (int i = a; i <= b; ++i) {
        for (int j = 1; j <= 9; ++j) {
            cout << i << " x " << j << " = " << (i * j) << "\n";
        }
        if (i < b) {
            cout << "\n";
        }
    }

    return 0;
}