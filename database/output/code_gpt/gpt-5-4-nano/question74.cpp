/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<long long> a(101);
    for (int i = 0; i < 101; i++) {
        if (!(cin >> a[i])) return 0;
    }
    
    long long last = a[100];
    bool first = true;
    for (int i = 0; i < 100; i++) {
        if (a[i] == last) {
            if (!first) cout << "\n";
            cout << i;
            first = false;
        }
    }
    return 0;
}