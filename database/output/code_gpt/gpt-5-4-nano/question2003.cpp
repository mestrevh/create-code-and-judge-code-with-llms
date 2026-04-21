/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;

    vector<bool> isFib(n + 1, false);
    vector<int> fib;
    fib.push_back(1);
    if (n >= 2) fib.push_back(2);

    long long a = 1, b = 1;
    int idx = 1;
    while (true) {
        if (idx == 1) {
            if (n >= 1) isFib[1] = true;
        }
        if (idx == 2) {
            if (n >= 2) isFib[2] = true;
        }
        long long c = a + b;
        a = b;
        b = c;
        idx++;
        if (c > n) break;
        isFib[(int)c] = true;
    }

    string ans;
    ans.reserve(n);
    for (int i = 1; i <= n; i++) {
        ans.push_back(isFib[i] ? 'O' : 'o');
    }
    cout << ans << "\n";
    return 0;
}