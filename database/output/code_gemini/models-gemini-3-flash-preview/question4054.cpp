/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b;
    if (cin >> a >> b) {
        if (a < 0 && b < 0) {
            cout << "NEGATIVOS" << endl;
        } else {
            cout << "NAO SAO AMBOS NEGATIVOS" << endl;
        }
    }

    return 0;
}