/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long sum = 0;
    long long cnt = 0;
    long long x;
    while (cin >> x && x != 0) {
        sum += x;
        cnt++;
    }

    if (cnt == 0) return 0;

    double avg = (double)sum / (double)cnt;

    if (avg < 110.0) cout << "Glicose Normal";
    else if (avg >= 200.0) cout << "Glicose Muito Alta";
    else cout << "Glicose Alterada";

    return 0;
}