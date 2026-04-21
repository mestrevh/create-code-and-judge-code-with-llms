/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    map<int, long double> priceByCode;

    for (int i = 0; i < n; i++) {
        int code;
        cin >> code;
        string desc;
        cin >> ws;
        getline(cin, desc);
        long double price;
        cin >> price;
        priceByCode[code] = price;
    }

    long double total = 0.0L;

    while (true) {
        int code;
        long long qty;
        if (!(cin >> code)) break;
        if (code == 0) break;
        cin >> qty;
        auto it = priceByCode.find(code);
        if (it != priceByCode.end() && qty >= 0) {
            total += it->second * (long double)qty;
        }
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << (double)total << "\n";
    return 0;
}