/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

double fatorial(int x) {
    double f = 1;
    for (int i = 1; i <= x; i++) {
        f *= i;
    }
    return f;
}

int main() {
    int n;
    cin >> n;
    double soma = 0;

    for (int i = 1; i <= n; i++) {
        soma += static_cast<double>(1) / fatorial(i);
    }

    cout << fixed << setprecision(2) << soma << endl;
    return 0;
}
