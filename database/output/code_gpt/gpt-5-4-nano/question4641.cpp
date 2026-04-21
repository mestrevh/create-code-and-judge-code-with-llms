/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h1, m1, h2, m2;
    if (!(cin >> h1 >> m1)) return 0;
    cin >> h2 >> m2;

    int total1 = h1 * 60 + m1;
    int total2 = h2 * 60 + m2;
    int sum = total1 + total2;

    int endH = (sum / 60) % 24;
    int endM = sum % 60;

    cout << "Terminarei meu treino por volta das " << endH << " horas e " << endM << " minutos!";
    return 0;
}