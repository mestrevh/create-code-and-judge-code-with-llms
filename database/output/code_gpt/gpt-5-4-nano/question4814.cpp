/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    string s;
    getline(cin, s);

    if (!getline(cin, s)) s = "";

    vector<long long> primes;
    long long x = N;
    if (x < 0) x = -x;
    for (long long p = 2; p * p <= x; ++p) {
        while (x % p == 0) {
            primes.push_back(p);
            x /= p;
        }
    }
    if (x > 1) primes.push_back(x);

    int key = (int)primes.size();

    if (s.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") == string::npos) {
        cout << key << "\n" << s;
        return 0;
    }

    if (key == 0) {
        cout << 0 << "\n" << s;
        return 0;
    }

    long long offset = key; 
    string out = s;
    long long shift = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        unsigned char uc = static_cast<unsigned char>(s[i]);
        if (isalpha(uc)) {
            int inc = (int)offset;
            int k = (int)(shift % inc);

            if (s[i] >= 'A' && s[i] <= 'Z') {
                out[i] = char('A' + (s[i] - 'A' + k) % 26);
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                out[i] = char('a' + (s[i] - 'a' + k) % 26);
            }
            shift++;
        }
    }

    cout << key << "\n" << out;
    return 0;
}