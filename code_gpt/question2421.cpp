/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int P;
    cin >> P;

    int moedas[6] = {500, 100, 50, 10, 5, 1};
    int quant[6] = {0};

    for (int i = 0; i < 6; i++) {
        quant[i] = P / moedas[i];
        P %= moedas[i];
    }

    cout << quant[0] << " moedas de 500.\n";
    cout << quant[1] << " moedas de 100.\n";
    cout << quant[2] << " moedas de 50.\n";
    cout << quant[3] << " moedas de 10.\n";
    cout << quant[4] << " moedas de 5.\n";
    cout << quant[5] << " moedas de 1.\n";

    return 0;
}
