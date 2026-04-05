/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

string AnalisarSituacao(double n1, double n2, double n3, double n4) {
    double media = (n1 * 1.0 + n2 * 2.0 + n3 * 3.0 + n4 * 4.0) / 10.0;
    if (media >= 9.0) return "aprovado com louvor";
    if (media >= 7.0) return "aprovado";
    if (media < 3.0) return "reprovado";
    return "prova final";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double n1, n2, n3, n4;
    if (!(cin >> n1 >> n2 >> n3 >> n4)) return 0;

    cout << AnalisarSituacao(n1, n2, n3, n4) << "\n";
    return 0;
}