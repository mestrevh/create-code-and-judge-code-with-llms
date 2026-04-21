/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    string prefix = "Essas malandra, assanhadinha, que so quer ";
    cout << prefix;
    for (long long i = 0; i < N; i++) {
        if (i) cout << ' ';
        cout << "vrau";
    }
    return 0;
}