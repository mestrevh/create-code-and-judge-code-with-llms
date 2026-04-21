/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<double> v(30);
    for (int i = 0; i < 30; ++i) {
        if (!(cin >> v[i])) break;
    }

    for (int i = 0; i < 30; ++i) {
        cout << "Digite um numero:" << "\n";
    }

    for (int i = 1; i < 30; i += 2) {
        if (v[i] == floor(v[i])) {
            cout << fixed << setprecision(1) << v[i] << "\n";
        } else {
            cout << defaultfloat << setprecision(6) << v[i] << "\n";
        }
    }

    return 0;
}