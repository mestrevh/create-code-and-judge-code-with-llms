/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double xA, yA, xB, yB;
    if (!(cin >> xA >> yA >> xB >> yB)) return 0;
    double dx = xA - xB;
    double dy = yA - yB;
    double d = sqrt(dx * dx + dy * dy);
    cout << d;
    return 0;
}