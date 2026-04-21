/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    if (!(cin >> q)) return 0;
    string g;
    cin >> g;
    int n;
    cin >> n;
    
    while (n--) {
        string s;
        cin >> s;
        int score = 0;
        for (int i = 0; i < q && i < (int)g.size() && i < (int)s.size(); i++) {
            if (s[i] == g[i]) score++;
        }
        cout << score << "\n";
    }
    return 0;
}