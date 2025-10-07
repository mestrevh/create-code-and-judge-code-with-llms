/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> saltos;
    double maior_salto = -1.0;

    for (int i = 0; i < n; ++i) {
        double salto;
        cin >> salto;
        saltos.push_back(salto);
        if (salto > maior_salto) {
            maior_salto = salto;
        }
        cout << fixed << setprecision(1) << maior_salto << endl;
    }

    sort(saltos.begin(), saltos.end());

    cout << "[";
    for (int i = 0; i < n; ++i) {
        cout << fixed << setprecision(1) << saltos[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
