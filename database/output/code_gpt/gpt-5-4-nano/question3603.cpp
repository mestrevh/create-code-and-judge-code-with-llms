/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isSortedNonDecreasing(const vector<long long>& a) {
    for (size_t i = 1; i < a.size(); i++) {
        if (a[i] < a[i - 1]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line1, line2;
    if (!getline(cin, line1)) return 0;
    if (!getline(cin, line2)) line2 = "";

    auto parseLine = [](const string& s) {
        vector<long long> v;
        stringstream ss(s);
        long long x;
        while (ss >> x) v.push_back(x);
        return v;
    };

    vector<long long> x = parseLine(line1);
    vector<long long> y = parseLine(line2);

    if (!isSortedNonDecreasing(x) || !isSortedNonDecreasing(y)) {
        cout << -1 << "\n";
        return 0;
    }

    vector<long long> z;
    z.reserve(x.size() + y.size());

    size_t i = 0, j = 0;
    while (i < x.size() && j < y.size()) {
        if (x[i] <= y[j]) z.push_back(x[i++]);
        else z.push_back(y[j++]);
    }
    while (i < x.size()) z.push_back(x[i++]);
    while (j < y.size()) z.push_back(y[j++]);

    for (size_t k = 0; k < z.size(); k++) {
        if (k) cout << ' ';
        cout << z[k];
    }
    cout << "\n";
    return 0;
}