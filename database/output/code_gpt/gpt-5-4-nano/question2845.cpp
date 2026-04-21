/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const double CAP = 18.0;
    double w;
    double sum = 0.0;
    int cnt = 0;

    cout << "Insira o peso dos livros: ";
    while (cin >> w) {
        if (sum + w <= CAP + 1e-9) {
            sum += w;
            cnt++;
        } else {
            break;
        }
    }

    cout << "\nPodem ser carregados " << cnt << " livros.";
    return 0;
}