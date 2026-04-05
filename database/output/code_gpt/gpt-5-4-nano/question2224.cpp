/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, y, z;
    if (!(cin >> x >> y >> z)) return 0;
    vector<long long> a = {x, y, z};
    sort(a.begin(), a.end(), greater<long long>());
    cout << a[0] << ' ' << a[1] << ' ' << a[2];
    return 0;
}