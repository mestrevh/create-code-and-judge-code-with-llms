/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int contaOcorrencias(const vector<int>& v, int x) {
    int cnt = 0;
    for (int a : v) if (a == x) cnt++;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    if (!(cin >> x)) return 0;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    cout << contaOcorrencias(v, x);
    return 0;
}