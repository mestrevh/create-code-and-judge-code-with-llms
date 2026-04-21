/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, long double> priceSum;

    string line;
    while (true) {
        if (!getline(cin, line)) return 0;
        if (line.size() == 0) continue;

        if (line == "*") break;

        stringstream ss(line);
        string word;
        vector<string> words;
        while (ss >> word) words.push_back(word);
        if (words.size() < 2) continue;

        long double x = 0;
        try {
            x = stold(words.back());
        } catch (...) {
            continue;
        }
        words.pop_back();
        string name;
        for (size_t i = 0; i < words.size(); i++) {
            if (i) name += ' ';
            name += words[i];
        }
        priceSum[name] += x;
    }

    long double total = 0;
    for (auto &kv : priceSum) total += kv.second;

    while (true) {
        if (!getline(cin, line)) break;
        if (line.size() == 0) continue;

        if (line == "total") {
            cout.setf(std::ios::fixed);
            cout << setprecision(2) << (double)total << "\n";
            break;
        }

        if (line == "quantidade") {
            cout << priceSum.size() << "\n";
            continue;
        }

        if (line.rfind("retire ", 0) == 0) {
            string name = line.substr(7);
            auto it = priceSum.find(name);
            if (it != priceSum.end()) {
                total -= it->second;
                priceSum.erase(it);
            }
            continue;
        }
    }

    return 0;
}