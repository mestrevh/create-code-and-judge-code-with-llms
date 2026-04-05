/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> a(5);
    for (int i = 0; i < 5; i++) {
        if (!(cin >> a[i])) return 0;
    }
    
    bool inc = true, dec = true;
    for (int i = 1; i < 5; i++) {
        if (a[i] <= a[i-1]) inc = false;
        if (a[i] >= a[i-1]) dec = false;
    }
    
    char ans = (inc ? 'C' : (dec ? 'D' : 'N'));
    cout << ans;
    return 0;
}