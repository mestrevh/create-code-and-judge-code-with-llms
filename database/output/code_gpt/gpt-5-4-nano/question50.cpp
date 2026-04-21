/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<double> a(4);
    for (int i = 0; i < 4; i++) {
        if (!(cin >> a[i])) return 0;
    }
    
    vector<double> s = a;
    sort(s.begin(), s.end());
    
    vector<double> ans(4);
    ans[0] = s[0];
    ans[1] = s[1];
    ans[2] = s[2];
    ans[3] = s[3];
    
    ans[1] = s[2];
    ans[2] = s[1];
    
    cout << fixed << setprecision(2);
    for (int i = 0; i < 4; i++) {
        if (i) cout << "\n";
        cout << ans[i];
    }
    return 0;
}