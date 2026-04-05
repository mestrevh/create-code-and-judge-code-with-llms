/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static int calcular_leds(int d) {
    static const int leds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    if (d < 0 || d > 9) return 0;
    return leds[d];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    while (N--) {
        string s;
        cin >> s;
        long long total = 0;
        for (char c : s) {
            if (c >= '0' && c <= '9') total += calcular_leds(c - '0');
        }
        cout << total << " leds";
        if (N) cout << "\n";
    }
    return 0;
}