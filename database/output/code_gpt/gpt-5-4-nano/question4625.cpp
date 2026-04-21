/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int count = 0;
    vector<int> a(10);
    for (int i = 0; i < 10; i++) {
        if (!(cin >> a[i])) return 0;
    }
    int x;
    if (!(cin >> x)) return 0;
    
    for (int v : a) if (v == x) count++;
    cout << count;
    return 0;
}