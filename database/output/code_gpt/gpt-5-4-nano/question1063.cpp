/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b, c;
    if (!(cin >> a >> b >> c)) return 0;
    vector<int> v = {a, b, c};
    sort(v.begin(), v.end());
    cout << v[0] << "\n" << v[1] << "\n" << v[2];
    return 0;
}