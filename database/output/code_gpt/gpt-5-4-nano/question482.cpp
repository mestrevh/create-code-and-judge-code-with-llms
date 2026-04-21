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
    int days = 0;
    int countMeet = 0;

    for (int i = 0; i < 7; i++) {
        long long x;
        if (!(cin >> x)) return 0;
        sum += x;
        if (x >= 100) countMeet++;
    }

    long long avg = sum / 7;
    cout << countMeet << "\n" << avg << "\n";
    return 0;
}