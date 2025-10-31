/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0 || n > 5) {
        cout << "Numero de notas invalido." << endl;
        return 0;
    }

    vector<float> notas(n);
    float soma = 0;

    for (int i = 0; i < n; i++) {
        cin >> notas[i];
        soma += notas[i];
    }

    for (int i = 0; i < n; i++) {
        cout << "Nota " << i + 1 << ": " << notas[i] << endl;
    }

    cout << "Media: " << fixed << setprecision(2) << soma / n << endl;
    return 0;
}
