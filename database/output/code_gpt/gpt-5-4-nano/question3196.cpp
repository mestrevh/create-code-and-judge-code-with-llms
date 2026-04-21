/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long price;
    if (!(cin >> price)) return 0;

    vector<int> notes = {100, 50, 20, 10, 5, 2, 1};
    for (int v : notes) {
        long long cnt = price / v;
        price %= v;
        cout << cnt << "\n";
    }
    return 0;
}