/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double a, b, c, n;
    if (!(cin >> a >> b >> c >> n)) return 0;
    
    double total = a + b + c + n;
    auto pct = [&](double x) -> long long {
        if (total == 0) return 0LL;
        double val = x * 100.0 / total;
        return llround(val);
    };

    cout << "Candidato A: " << pct(a) << "%\n";
    cout << "Candidato B: " << pct(b) << "%\n";
    cout << "Candidato C: " << pct(c) << "%\n";
    cout << "Nulos: " << pct(n) << "%";
    return 0;
}