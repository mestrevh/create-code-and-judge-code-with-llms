/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int contarOcorrencias(int v[], int n, int x) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == x) {
            cont++;
        }
    }
    return cont;
}

int main() {
    int x, n;
    cin >> x >> n;
    int v[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << contarOcorrencias(v, n, x) << endl;
    return 0;
}
