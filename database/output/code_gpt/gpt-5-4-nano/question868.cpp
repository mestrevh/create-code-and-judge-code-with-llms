/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    if (!(cin >> N >> D)) return 0;

    vector<long long> ans;
    ans.reserve(5);

    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        if (x % 10 == D) {
            ans.push_back(x);
            sort(ans.begin(), ans.end());
            if (ans.size() > 5) ans.erase(ans.begin());
        }
    }

    vector<long long> out = ans;
    while (out.size() < 5) out.push_back(-1);

    for (long long v : out) {
        cout << v << "\n";
    }
    return 0;
}