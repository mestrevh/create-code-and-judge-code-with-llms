/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unsigned long long K;
    unsigned long long B;
    while (cin >> K >> B) {
        unsigned long long sum = 0;
        unsigned long long x = K;
        while (x > 0) {
            sum += x % B;
            x /= B;
        }
        cout << sum;
        if (!cin.eof()) cout << "\n";
    }
    return 0;
}