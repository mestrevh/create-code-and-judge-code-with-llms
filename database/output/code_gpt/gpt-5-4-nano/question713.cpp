/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N, A, B;
    if (!(cin >> N >> A >> B)) return 0;

    if (A > B) swap(A, B);

    long long first = ((A + N - 1) / N) * N;
    if (first < A) first += N;

    vector<long long> res;
    if (first <= B) {
        for (long long x = first; x <= B; x += N) res.push_back(x);
    }

    if (res.empty()) {
        cout << "INEXISTENTE";
    } else {
        for (size_t i = 0; i < res.size(); i++) {
            if (i) cout << "\n";
            cout << res[i];
        }
    }
    return 0;
}