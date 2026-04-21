/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long totalSeconds = 0;
    for (int i = 0; i < 5; i++) {
        long long m, s;
        if (!(cin >> m)) return 0;
        cin >> s;
        totalSeconds += m * 60 + s;
    }

    long long hours = totalSeconds / 3600;
    totalSeconds %= 3600;
    long long minutes = totalSeconds / 60;
    long long seconds = totalSeconds % 60;

    cout << hours << "\n" << minutes << "\n" << seconds << "\n";
    return 0;
}