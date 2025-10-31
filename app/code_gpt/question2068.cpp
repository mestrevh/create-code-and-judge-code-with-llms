/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

long long FactSoma(int n, int k) {
    if (n <= 0) return 0;
    return n + FactSoma(n - k, k);
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << FactSoma(n, k) << endl;
    return 0;
}
