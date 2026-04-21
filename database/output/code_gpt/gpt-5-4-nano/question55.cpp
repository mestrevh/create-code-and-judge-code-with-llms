/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int last = 0;
    int x;
    unordered_map<int,int> cnt;
    for (int i = 0; i < 10; i++) {
        if (!(cin >> x)) return 0;
        last = x;
        cnt[last]++;
    }

    cout << "O numero " << last << " apareceu " << cnt[last] << " vezes\n";
    return 0;
}