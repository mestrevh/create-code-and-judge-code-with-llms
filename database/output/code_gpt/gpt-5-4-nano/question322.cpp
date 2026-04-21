/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    long long minVal;
    int pos = -1;
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        if (i == 0 || x < minVal) {
            minVal = x;
            pos = i;
        }
    }

    cout << "Menor valor: " << minVal << "\n";
    cout << "Posicao: " << pos << "\n";
    return 0;
}