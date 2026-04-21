/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a;
    string s, line;
    if (!getline(cin, line)) return 0;
    s = line;

    for (char &c : s) {
        if (c == '[' || c == ']' || c == ',' ) c = ' ';
    }
    stringstream ss(s);
    long long x;
    while (ss >> x) a.push_back(x);

    bool found = false;
    long long best = 0;
    for (long long v : a) {
        if (v % 2 == 0) {
            if (!found || v > best) {
                best = v;
                found = true;
            }
        }
    }

    if (found) cout << best;
    return 0;
}