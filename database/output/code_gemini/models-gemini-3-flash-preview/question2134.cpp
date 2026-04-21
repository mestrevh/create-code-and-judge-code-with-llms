/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n <= 0 || n > 5) {
        cout << "Numero de notas invalido." << endl;
        return 0;
    }

    vector<double> notas(n);
    double soma = 0.0;
    for (int i = 0; i < n; ++i) {
        if (cin >> notas[i]) {
            soma += notas[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << "Nota " << i + 1 << ": " << fixed << setprecision(1) << notas[i] << endl;
    }

    double media = soma / n;
    cout << "Media: " << fixed << setprecision(2) << media << endl;

    return 0;
}