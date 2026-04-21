/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line1, line2;
    if (!getline(cin, line1)) return 0;
    if (!getline(cin, line2)) line2.clear();

    string s = line1;
    s.erase(remove(s.begin(), s.end(), '\r'), s.end());
    vector<string> tokens;
    string cur;
    for (char c : s) {
        if (c == ',') {
            tokens.push_back(cur);
            cur.clear();
        } else if (!isspace((unsigned char)c)) {
            cur.push_back(c);
        }
    }
    if (!cur.empty() || !tokens.empty()) tokens.push_back(cur);

    long double donation = 0;
    try {
        donation = stold(line2);
    } catch (...) {
        donation = 0;
    }

    vector<long double> prices = {
        2.78L, 1.65L, 4.00L, 1.89L, 2.30L, 1.20L, 3.50L, 1.75L, 2.10L, 2.60L, 1.35L, 2.40L,
        0.00L, 0.00L, 0.00L, 0.00L, 0.00L, 0.00L, 0.00L, 0.00L, 0.00L, 0.00L, 0.00L, 0.00L,
        0.00L, 0.00L, 0.00L
    };

    size_t n = min<size_t>(27, tokens.size());
    long double basketCost = 0.0L;

    for (size_t i = 0; i < n; i++) {
        long long qty = 0;
        try {
            qty = stoll(tokens[i]);
        } catch (...) {
            qty = 0;
        }
        if (qty > 0) {
            long double price = 0.0L;
            if (i < prices.size()) price = prices[i];
            basketCost += (long double)qty * price;
        }
    }

    long long baskets = 0;
    if (basketCost > 0) baskets = (long long)floor(donation / basketCost);

    cout.setf(std::ios::fixed);
    cout << "O valor da cesta básica ficou em: R$" << setprecision(2) << (double)basketCost << "\n";
    cout << "Com o valor doado pode ser comprada " << baskets << " cestas básicas";
    return 0;
}