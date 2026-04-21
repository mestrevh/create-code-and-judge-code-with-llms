/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    if (!(cin >> n)) return 0;
    
    __int128 fact = 1;
    for (long long i = 2; i <= n; i++) fact *= i;
    
    string s;
    if (fact == 0) {
        s = "0";
    } else {
        while (fact > 0) {
            int digit = (int)(fact % 10);
            s.push_back(char('0' + digit));
            fact /= 10;
        }
        reverse(s.begin(), s.end());
    }
    
    cout << s << "\n";
    return 0;
}