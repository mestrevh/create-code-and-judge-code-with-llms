/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B;
    if (!(cin >> A)) return 0;
    cin >> B;

    long long lo = min(A, B), hi = max(A, B);

    vector<int> arms;
    for (long long n = lo; n <= hi; n++) {
        string s = to_string(n);
        int d = (int)s.size();
        long long sum = 0;
        for (char c : s) {
            int digit = c - '0';
            long long p = 1;
            for (int i = 0; i < d; i++) p *= digit;
            sum += p;
        }
        if (sum == n) arms.push_back((int)n);
    }

    for (size_t i = 0; i < arms.size(); i++) {
        if (i) cout << ' ';
        cout << arms[i];
    }
    if (!arms.empty()) cout << ' ';
    cout << "\n";
    cout << arms.size() << " numeros de Armstrong";
    return 0;
}