/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, i;
    if (!(cin >> n >> i)) return 0;
    vector<long long> a(n);
    for (int k = 0; k < n; k++) cin >> a[k];

    int k = n - i;
    nth_element(a.begin(), a.begin() + k, a.end());
    cout << a[k];
    return 0;
}