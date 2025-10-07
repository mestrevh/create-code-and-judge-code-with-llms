/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int mdc(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int mmc(int a, int b) {
    return (a / mdc(a, b)) * b;
}

int main() {
    int a, b;
    string operacao;
    cin >> a >> b >> operacao;

    if (a <= 0 || b <= 0) {
        cout << "digite numeros inteiros positivos!" << endl;
        return 0;
    }

    if (operacao != "mdc" && operacao != "MDC" && operacao != "mmc" && operacao != "MMC") {
        cout << "nao compreendi, tente outra vez" << endl;
        return 0;
    }

    if (operacao == "mdc" || operacao == "MDC") {
        cout << "o mdc eh: " << mdc(a, b) << endl;
    } else {
        cout << "o mmc eh: " << mmc(a, b) << endl;
    }

    return 0;
}
