/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> highPrimes;
    for (int i = 2; i * i <= 1e12; ++i) {
        if (isPrime(i)) {
            highPrimes.push_back(i * i);
        }
    }
    
    int T;
    cin >> T;
    while (T--) {
        long long A, B;
        cin >> A >> B;
        cout << upper_bound(highPrimes.begin(), highPrimes.end(), B) - lower_bound(highPrimes.begin(), highPrimes.end(), A) << endl;
    }
    
    return 0;
}
