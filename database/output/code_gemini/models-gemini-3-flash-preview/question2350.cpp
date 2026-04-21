/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int encontrar_maximo(const vector<int>& L, int n) {
    int max_val = L[0];
    for (int i = 1; i < n; ++i) {
        if (L[i] > max_val) {
            max_val = L[i];
        }
    }
    return max_val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> L(n);
    for (int i = 0; i < n; ++i) {
        cin >> L[i];
    }

    int resultado = encontrar_maximo(L, n);
    cout << resultado << endl;

    return 0;
}