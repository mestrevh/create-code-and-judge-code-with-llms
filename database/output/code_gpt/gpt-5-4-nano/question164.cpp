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
    long long stored = 0;
    for (int i = 0; i < N; i++) {
        int I;
        cin >> I;
        stored += (I - 1);
    }
    cout << stored << "\n";
    return 0;
}