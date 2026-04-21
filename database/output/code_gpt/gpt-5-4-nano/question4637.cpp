/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long sum = 0;
    long long x;
    bool any = false;

    string s;
    if (!getline(cin, s)) return 0;
    stringstream ss(s);
    while (ss >> x) {
        sum += x;
        any = true;
    }

    if (any) cout << sum;
    return 0;
}