/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string Nstr;
    if (!(cin >> Nstr)) return 0;
    string s;
    cin >> s;

    const int MOD = 1000000;

    // Determine N as an integer in 1..N where N may be huge up to 10^100.
    // We only need to compare up to 6-digit substrings, because N mod not enough.
    // For comparisons, use digit-length and lexicographic against Nstr.
    auto cmpToN = [&](int len, const string& sub) -> int {
        if ((int)sub.size() != len) return 0;
        if (len < (int)Nstr.size()) return -1;
        if (len > (int)Nstr.size()) return 1;
        if (sub < Nstr) return -1;
        if (sub > Nstr) return 1;
        return 0;
    };

    int L = (int)s.size();
    vector<int> dp(L + 1, 0), ndp(L + 1, 0);
    dp[0] = 1;

    // Precompute for each position i: which lengths l produce valid numbers in [1..N] with no leading zeros.
    // Only lengths up to min(L-i, 100000) but N can be huge; still limited by N's digit length.
    // We can cap lengths by 18 because dp is modulo 1e6 and we only store counts; but validity depends on N.
    // Need correct lengths, so we cap at digit length of N, which can be up to 101.
    int maxLenN = (int)Nstr.size();
    int maxLen = min(L, maxLenN);

    for (int i = 0; i < L; i++) {
        if (dp[i] == 0) continue;
        if (s[i] == '0') continue;
        for (int len = 1; len <= maxLen && i + len <= L; len++) {
            if (s[i] == '0') break;
            // substring s[i..i+len-1]
            // Extract without heavy cost: build string for compare; len up to 101 but L up to 1e5 -> ok if optimized.
            // We'll compare using digits without constructing substring by using lexicographic with Nstr.
            bool ok;
            if (len < (int)Nstr.size()) {
                ok = true;
            } else if (len > (int)Nstr.size()) {
                ok = false;
            } else {
                // len == Ndigits
                // Compare s[i..i+len-1] with Nstr
                bool less = false, greater = false;
                for (int k = 0; k < len; k++) {
                    char a = s[i + k];
                    char b = Nstr[k];
                    if (a < b) { less = true; break; }
                    if (a > b) { greater = true; break; }
                }
                ok = less || (!greater);
                // if equal ok, if greater not ok. But the loop breaks on less/greater, otherwise equal.
                if (!less && !greater) ok = true;
            }
            if (!ok) break;
            // also ensure number between 1 and N; leading zeros already excluded by s[i]!='0'
            int j = i + len;
            dp[j] += dp[i];
            dp[j] %= MOD;
        }
    }

    cout << (dp[L] % MOD) << "\n";
    return 0;
}