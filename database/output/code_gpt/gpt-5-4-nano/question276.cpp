/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n0, n;
    if (!(cin >> n0)) return 0;
    cin >> n;
    
    __int128 a = (__int128)n0;
    __int128 b = (__int128)n;
    __int128 sum = (b * (b + 1) - (a - 1) * a) / 2;
    
    string s;
    if (sum == 0) {
        s = "0";
    } else {
        bool neg = sum < 0;
        if (neg) sum = -sum;
        while (sum > 0) {
            int digit = (int)(sum % 10);
            s.push_back('0' + digit);
            sum /= 10;
        }
        if (neg) s.push_back('-');
        reverse(s.begin(), s.end());
    }
    
    cout << s;
    return 0;
}