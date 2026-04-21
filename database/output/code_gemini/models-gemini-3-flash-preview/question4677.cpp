/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

unsigned long long powers[21][10];

void precompute_powers() {
    for (int d = 0; d < 10; ++d) {
        powers[0][d] = 1; 
        for (int k = 1; k < 21; ++k) {
            powers[k][d] = powers[k - 1][d] * (unsigned long long)d;
        }
    }
}

bool is_armstrong(ll n) {
    if (n < 0) return false;
    if (n == 0) return true;
    
    int k = 0;
    ll temp = n;
    while (temp > 0) {
        k++;
        temp /= 10;
    }
    
    unsigned long long sum = 0;
    temp = n;
    while (temp > 0) {
        sum += powers[k][temp % 10];
        temp /= 10;
    }
    
    return sum == (unsigned long long)n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute_powers();
    
    ll a, b;
    if (!(cin >> a >> b)) return 0;
    
    if (a > b) {
        ll temp = a;
        a = b;
        b = temp;
    }
    
    vector<ll> results;
    for (ll i = a; i <= b; ++i) {
        if (is_armstrong(i)) {
            results.push_back(i);
        }
    }
    
    for (size_t i = 0; i < results.size(); ++i) {
        cout << results[i] << " ";
    }
    cout << "\n";
    
    if (results.size() == 1) {
        cout << "1 numero de Armstrong" << "\n";
    } else {
        cout << results.size() << " numeros de Armstrong" << "\n";
    }
    
    return 0;
}