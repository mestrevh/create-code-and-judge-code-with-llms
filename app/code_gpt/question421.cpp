/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

bool hasUniqueDigits(int a, int b) {
    set<char> digits;
    stringstream ss;
    ss << a << b;
    string combined = ss.str();
    for (char ch : combined) {
        if (digits.count(ch) || ch == '0') return false;
        digits.insert(ch);
    }
    return true;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        bool found = false;
        vector<pair<int, int>> results;

        for (int f = 10000; f < 100000; f++) {
            int a = f * n;
            if (a < 10000 || a > 99999) continue;
            if (hasUniqueDigits(a, f)) {
                results.emplace_back(a, f);
                found = true;
            }
        }

        sort(results.begin(), results.end());

        if (found) {
            int lastN = -1;
            for (auto &[a, f] : results) {
                if (a / f != n) continue;
                if (lastN != n) {
                    if (lastN != -1) cout << endl;
                    lastN = n;
                }
                cout << a << " / " << f << " = " << n << endl;
            }
        } else {
            cout << "There are no solutions for " << n << "." << endl;
        }
    }
    return 0;
}
