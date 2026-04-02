/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int contar_ocorrencias(int x, const vector<int>& L, int n) {
    int contador = 0;
    for (int i = 0; i < n; ++i) {
        if (L[i] == x) {
            contador++;
        }
    }
    return contador;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    if (!(cin >> x)) return 0;

    int n;
    if (!(cin >> n)) return 0;

    if (n < 0) {
        return 0;
    }

    vector<int> L(n);
    for (int i = 0; i < n; ++i) {
        cin >> L[i];
    }

    cout << contar_ocorrencias(x, L, n) << "\n";

    return 0;
}