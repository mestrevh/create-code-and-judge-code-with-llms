/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static vector<string> tokenize(const string& s) {
    vector<string> tokens;
    string cur;
    auto push = [&]() {
        if (!cur.empty()) {
            tokens.push_back(cur);
            cur.clear();
        }
    };
    for (unsigned char ch : s) {
        if (isalnum(ch)) cur.push_back((char)tolower(ch));
        else push();
    }
    push();
    return tokens;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    if (!getline(cin, a)) return 0;
    if (!getline(cin, b)) return 0;

    vector<string> t1 = tokenize(a);
    vector<string> t2 = tokenize(b);

    unordered_map<string, int> c1, c2;
    for (auto &x : t1) c1[x]++;
    for (auto &x : t2) c2[x]++;

    long long uniqueMatches = 0;
    for (auto &p : c1) {
        auto it = c2.find(p.first);
        if (it != c2.end()) uniqueMatches++;
    }

    long long totalWords = (long long)t1.size() + (long long)t2.size();
    double idx = 0.0;
    if (totalWords > 0) idx = (double)uniqueMatches / (double)totalWords * 100.0;

    cout.setf(std::ios::fixed); 
    cout << setprecision(1) << idx;
    return 0;
}