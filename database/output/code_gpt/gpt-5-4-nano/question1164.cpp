/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long D;
    if (!(cin >> D)) return 0;

    vector<pair<long long, string>> offers = {
        {10, "Arthur"},
        {30, "Luiz"},
        {100, "Pedro"}
    };

    string ans = "Nenhum";
    for (auto &o : offers) {
        if (o.first >= D) {
            ans = o.second;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}