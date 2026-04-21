/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if (!(cin >> N)) return 0;
    
    vector<string> names(N);
    for (int i = 0; i < N; i++) cin >> names[i];
    
    string query;
    cin >> query;
    
    int count = 0;
    for (const auto& s : names) {
        if (s == query) count++;
    }
    
    cout << count;
    return 0;
}