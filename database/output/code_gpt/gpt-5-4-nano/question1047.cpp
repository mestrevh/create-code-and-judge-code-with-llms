/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double n1, n2, n3;
    double w1, w2, w3;
    if (!(cin >> n1 >> n2 >> n3 >> w1 >> w2 >> w3)) return 0;

    double a = (n1 + n2 + n3) / 3.0;

    double p = (n1 * w1 + n2 * w2 + n3 * w3) / (w1 + w2 + w3);

    double denom = (1.0 / n1) + (1.0 / n2) + (1.0 / n3);
    double h = 3.0 / denom;

    cout << fixed << setprecision(1);
    cout << "a: " << a << "\n";
    cout << "p: " << p << "\n";
    cout << "h: " << h << "\n";
    return 0;
}