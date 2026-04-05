/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string lowerStr(string s) {
    for (char &c : s) c = (char)tolower((unsigned char)c);
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string item;
    int years;
    if (!(cin >> item >> years)) return 0;

    unordered_map<string, double> price = {
        {"mural", 200.00},
        {"o coreto", 235.00},
        {"meu lar", 180.00},
        {"sua mesa", 230.00}
    };

    string normalized;
    item = lowerStr(item);
    normalized = item;

    if (price.find(normalized) == price.end()) {
        string rest;
        getline(cin, rest);
        stringstream ss(rest);
        string extra;
        while (ss >> extra) {
            normalized += " " + lowerStr(extra);
        }
    }

    if (price.find(normalized) == price.end()) {
        vector<string> parts;
        stringstream ss(normalized);
        string token;
        while (ss >> token) parts.push_back(token);
        string combined;
        for (size_t i = 0; i < parts.size(); i++) {
            if (i) combined += " ";
            combined += parts[i];
        }
        normalized = combined;
    }

    double unit = 0.0;
    auto it = price.find(normalized);
    if (it != price.end()) unit = it->second;

    string isRevKey;
    bool isRev = false;
    if (normalized == "meu lar" || normalized == "sua mesa") {
        isRev = true;
    }
    if (isRev) unit *= 0.90;

    double total = unit * years;
    cout << fixed << setprecision(2) << total << "\n";
    return 0;
}