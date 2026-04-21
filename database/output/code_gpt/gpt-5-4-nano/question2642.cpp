/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    function<long long(int)> solve = [&](int idx) -> long long {
        if (idx == N) return 0;
        long long X;
        string Y;
        cin >> X >> Y;

        long long tiros = 0;
        long long grupos = X / 2;
        if (Y == "Conseguiu") {
            tiros = grupos * 3 + 6;
        } else {
            tiros = grupos * 3;
        }
        return tiros + solve(idx + 1);
    };

    long long total = solve(0);

    cout << "Foram disparados: " << total << " tiros\n";
    if (total > 50) cout << "Meus alunos estao estragando tudo! Preciso intervir!\n";
    else cout << "Esta tudo sobre controle, posso passar mais tempo com Raquel...\n";

    return 0;
}