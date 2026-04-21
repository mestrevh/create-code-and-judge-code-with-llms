/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double R, H;
    if (!(cin >> R >> H)) return 0;
    
    double volume = M_PI * R * R * H;
    cout << fixed << setprecision(2) << volume;
    return 0;
}