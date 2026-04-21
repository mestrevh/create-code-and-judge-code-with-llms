/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

bool is_prime(ll n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool saved = false;
    for (int k = 0; k < 3; ++k) {
        ll n;
        if (!(cin >> n)) break;

        if (saved) {
            cout << "SINAL OFF" << endl;
            continue;
        }

        vector<ll> factors;
        ll temp = n;
        
        while (temp % 2 == 0) {
            factors.push_back(2);
            temp /= 2;
        }
        for (ll i = 3; i * i <= temp; i += 2) {
            while (temp % i == 0) {
                factors.push_back(i);
                temp /= i;
            }
        }
        if (temp > 1) {
            factors.push_back(temp);
        }

        long double sum = 0;
        for (int i = 0; i < (int)factors.size(); ++i) {
            sum += (long double)factors[i] / (i + 1);
        }

        ll C = (ll)sum;
        if (sum - (long double)C > 1e-10) {
            C++;
        }

        if (is_prime(C)) {
            cout << "SHERLIRO SALVOU MULITTLE" << endl;
            saved = true;
        } else {
            cout << "ERRO" << endl;
        }
    }

    return 0;
}