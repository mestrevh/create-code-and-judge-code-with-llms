/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, caso = 1;
    while (cin >> n, n) {
        vector<int> grau(7, 0);
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            ++grau[a];
            ++grau[b];
        }
        int impares = 0;
        for (int i = 0; i < 7; ++i) {
            if (grau[i] % 2 != 0) ++impares;
        }
        cout << "Teste " << caso++ << '\n';
        cout << ((impares == 0 || impares == 2) ? "sim" : "nao") << '\n';
        cout << '\n';
    }
    return 0;
}
