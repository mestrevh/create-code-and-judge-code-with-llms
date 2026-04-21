/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long printed;
    double percent;
    if (!(cin >> printed)) return 0;
    if (!(cin >> percent)) return 0;

    double totalPages = printed * 100.0 / percent;

    long long total = llround(totalPages);
    long long missing = total - printed;

    cout << "O documento possui " << total << " paginas\n";
    cout << "Ja foram impressas " << printed << " paginas\n";
    cout << "Faltam " << missing << " paginas";
    return 0;
}