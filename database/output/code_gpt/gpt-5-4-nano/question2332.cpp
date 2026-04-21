/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string S;
    if (!getline(cin, S)) return 0;
    if (!S.empty() && S.back() == '\r') S.pop_back();
    cout << S.size();
    return 0;
}