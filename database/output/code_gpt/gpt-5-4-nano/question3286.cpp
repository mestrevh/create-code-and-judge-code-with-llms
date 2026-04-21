/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long area, azulejo;
    if (!(cin >> area >> azulejo)) return 0;

    long long n = (area + azulejo - 1) / azulejo;
    long long total = n * 25 * azulejo;

    cout << n << "\n" << total;
    return 0;
}