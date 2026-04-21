/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double ph;
    while (cin >> ph && ph != -1.0) {
        if (ph < 7.0) {
            cout << "ACIDA\n";
        } else if (ph > 7.0) {
            cout << "BASICA\n";
        } else {
            cout << "NEUTRA\n";
        }
    }

    return 0;
}