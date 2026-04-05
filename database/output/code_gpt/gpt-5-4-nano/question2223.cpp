/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    if (!(cin >> s)) return 0;
    
    unordered_map<string, int> mp = {
        {"Zero", 0}, {"Um", 1}, {"Dois", 2}, {"Tres", 3}, {"Quatro", 4},
        {"Cinco", 5}, {"Seis", 6}, {"Sete", 7}, {"Oito", 8}, {"Nove", 9}
    };
    
    cout << mp[s] << "\n";
    return 0;
}