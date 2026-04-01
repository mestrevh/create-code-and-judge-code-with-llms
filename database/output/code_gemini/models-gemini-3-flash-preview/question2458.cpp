/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_S = 1000001;
bool is_p[MAX_S];
vector<int> primes;

void sieve() {
    for (int i = 2; i < MAX_S; i++) is_p[i] = true;
    for (ll i = 2; i < MAX_S; i++) {
        if (is_p[i]) {
            primes.push_back((int)i);
            for (ll j = i * i; j < MAX_S; j += i)
                is_p[j] = false;
        }
    }
}

ll count_divisors(ll n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    ll ans = 1;
    ll temp = n;
    for (int p : primes) {
        if (1LL * p * p > temp) break;
        if (temp % p == 0) {
            int expo = 0;
            while (temp % p == 0) {
                expo++;
                temp /= p;
            }
            ans *= (expo + 1);
        }
    }
    if (temp > 1) {
        ans *= 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    ll num;
    while (cin >> num) {
        cout << count_divisors(num) << "\n";
    }
    return 0;
}