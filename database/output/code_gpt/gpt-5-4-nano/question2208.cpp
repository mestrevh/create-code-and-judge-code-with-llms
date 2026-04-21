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

    long double sum = 0.0L;
    long double term = 1.0L; 

    for (long long i = 0; i < n; i++) {
        if (i == 0) {
            term = 1.0L;
        } else {
            term /= (long double)i;
        }
        sum += term;
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(15) << (double)sum << "\n";
    return 0;
}