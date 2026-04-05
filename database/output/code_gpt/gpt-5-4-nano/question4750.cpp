/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long A, B, C, D;
    if (!(cin >> A)) return 0;
    cin >> B >> C >> D;

    long long s1 = A + D;
    long long s2 = B + C;
    cout << llabs(s1 - s2) << "\n";
    return 0;
}