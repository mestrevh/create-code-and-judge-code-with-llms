/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void reduzir(int V[], int n) {
    for (int i = 0; i < n; i++) {
        if (V[i] > 10) {
            V[i] = 10;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int V[200];
    for (int i = 0; i < n; i++) {
        cin >> V[i];
    }
    reduzir(V, n);
    for (int i = 0; i < n; i++) {
        cout << V[i] << endl;
    }
    return 0;
}
