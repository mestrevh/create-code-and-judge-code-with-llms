/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

double maiorEntre(double a, double b, double c, double d) {
    return max(max(a, b), max(c, d));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double a, b, c, d;
    if (!(cin >> a)) return 0;
    cin >> b >> c >> d;
    
    cout << fixed << setprecision(2) << maiorEntre(a, b, c, d) << "\n";
    return 0;
}