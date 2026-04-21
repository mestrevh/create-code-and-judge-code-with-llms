/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int Fd, Bd, Md;
    int Fr, Br, Mr;
    if (!(cin >> Fd >> Bd >> Md)) return 0;
    cin >> Fr >> Br >> Mr;
    
    int ans = max(0, Fr - Fd) + max(0, Br - Bd) + max(0, Mr - Md);
    cout << ans << "\n";
    return 0;
}