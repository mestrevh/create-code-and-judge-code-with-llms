/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double b1, b2, h;
    if (!(cin >> b1 >> b2 >> h)) return 0;
    double area = (b1 + b2) * h / 2.0;
    cout << fixed << setprecision(1) << area;
    return 0;
}