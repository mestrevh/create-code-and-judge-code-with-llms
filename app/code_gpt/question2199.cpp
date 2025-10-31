/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
using namespace std;

long long fatorial(int n) {
    if (n == 0) return 1;
    return n * fatorial(n - 1);
}

int main() {
    int N;
    cin >> N;
    int logBase3 = log(N) / log(3);
    cout << fatorial(logBase3) << endl;
    return 0;
}
