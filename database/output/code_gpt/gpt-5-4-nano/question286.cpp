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
    
    vector<int> v = {A, B, C};
    char ans = '*';
    
    if (A != B && A != C) ans = 'A';
    else if (B != A && B != C) ans = 'B';
    else if (C != A && C != B) ans = 'C';
    
    cout << ans << "\n";
    return 0;
}