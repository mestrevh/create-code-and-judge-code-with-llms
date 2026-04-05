/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a;
    int x;
    int N = -1;
    long long sum = 0;

    while (cin >> x) {
        if (N == -1) N = x;
        else a.push_back(x);
        sum += x;
    }

    if (N == -1) return 0;

    vector<int> freq((size_t)N, 0);
    for (int i = 0; i < N; i++) {
        if (i < (int)a.size()) {
            int v = a[i];
            if (v >= 0 && v < N) freq[v]++;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < freq[i]; k++) cout << i << "\n";
    }
    return 0;
}