/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double TVideo, TAudio, TDados, Capacidade;
    if (!(cin >> TVideo)) return 0;
    cin >> TAudio >> TDados >> Capacidade;

    double QDmax = (TVideo * 5.2 + TAudio * 3.4 + TDados * 1.5) / Capacidade;
    cout << fixed << setprecision(2) << QDmax << "\n";
    return 0;
}