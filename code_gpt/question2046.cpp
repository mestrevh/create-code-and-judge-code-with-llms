/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

bool eh_primo(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int proximo_primo(int y) {
    while (!eh_primo(++y));
    return y;
}

long long fatorial(int z) {
    long long resultado = 1;
    for (int i = 1; i <= z; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    int n;
    cin >> n;

    string serie = "";
    double soma = 0;
    int divisor = 1;

    for (int i = 1; i <= n; i++) {
        if (i > 1) divisor = proximo_primo(divisor);
        soma += static_cast<double>(fatorial(i)) / divisor;
        serie += to_string(i) + "!/" + to_string(divisor);
        if (i < n) serie += " + ";
    }

    cout << serie << endl;
    cout << fixed << setprecision(2) << soma << endl;

    return 0;
}
