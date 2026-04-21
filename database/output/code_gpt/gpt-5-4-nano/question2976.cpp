/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unsigned long long n;
    if (!(cin >> n)) return 0;

    unsigned __int128 sum = 0;
    unsigned long long x = n;

    while (true) {
        sum += (unsigned __int128)x;
        if (x == 1) break;
        if ((x & 1ULL) == 0) x /= 2;
        else x = 3 * x + 1;
    }

    string out;
    while (sum > 0) {
        unsigned int digit = (unsigned int)(sum % 10);
        out.push_back(char('0' + digit));
        sum /= 10;
    }
    if (out.empty()) out = "0";
    reverse(out.begin(), out.end());
    cout << out << "\n";
    return 0;
}