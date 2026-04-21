/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double mx = -numeric_limits<double>::infinity();
    double val;
    bool found = false;

    for (int i = 0; i < 50; ++i) {
        cout << "Digite um numero:" << "\n";
        if (cin >> val) {
            if (!found || val > mx) {
                mx = val;
                found = true;
            }
        }
    }

    if (found) {
        cout << "Maior numero: " << mx << endl;
    }

    return 0;
}