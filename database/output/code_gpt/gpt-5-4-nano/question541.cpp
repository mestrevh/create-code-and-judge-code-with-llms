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
    vector<long long> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    nth_element(a.begin(), a.begin() + 1, a.end());
    long long menor = *min_element(a.begin(), a.end());

    nth_element(a.begin(), a.begin() + (N/2), a.end());
    long long meio = a[N/2];

    long long ultimo = *max_element(a.begin(), a.end());

    cout << menor << ' ' << meio << ' ' << ultimo << "\n";
    return 0;
}