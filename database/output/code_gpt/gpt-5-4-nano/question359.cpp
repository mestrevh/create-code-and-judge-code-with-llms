/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int A, B, C;
    if (!(cin >> A >> B >> C)) return 0;
    
    int ans = min({A / 2, B / 3, C / 5});
    cout << ans << "\n";
    return 0;
}