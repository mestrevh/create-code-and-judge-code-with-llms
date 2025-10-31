/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> fatorPrimo(int n) {
    vector<int> fatores;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            fatores.push_back(i);
            n /= i;
        }
    }
    if (n > 1) fatores.push_back(n);
    return fatores;
}

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
    } else {
        vector<int> fatores = fatorPrimo(n);
        for (int fator : fatores) {
            cout << fator << " ";
        }
    }
    return 0;
}
