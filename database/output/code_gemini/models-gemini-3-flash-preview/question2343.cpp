/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

void exibir_multiplos(int i, int f, int x) {
    if (x <= 0) return;
    long long start;
    if (i % x == 0) {
        start = (long long)i;
    } else {
        start = (long long)i + (x - (i % x));
    }
    for (long long val = start; val <= (long long)f; val += x) {
        cout << val << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i, f, x;
    if (cin >> i >> f >> x) {
        exibir_multiplos(i, f, x);
    }
    return 0;
}