/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int contarOcorrencias(unsigned long long n, int x) {
    if (n == 0) return (x == 0) ? 1 : 0;
    return (n % 10 == x) + contarOcorrencias(n / 10, x);
}

int main() {
    unsigned long long n;
    int x;
    cin >> n >> x;
    cout << contarOcorrencias(n, x) << endl;
    return 0;
}
