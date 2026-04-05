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

    string dummy;
    getline(cin, dummy);

    unordered_map<string, unordered_set<string>> store;
    store.reserve(n * 4);

    for (int i = 0; i < n; i++) {
        string section;
        getline(cin, section);
        while (section.size() == 0 && !cin.eof()) getline(cin, section);
        string itemsLine;
        getline(cin, itemsLine);
        if (itemsLine.size() == 0) itemsLine = "";

        istringstream iss(itemsLine);
        string item;
        while (iss >> item) {
            store[section].insert(item);
        }
        if (!store.count(section)) store[section] = unordered_set<string>();
    }

    string line;
    while (getline(cin, line)) {
        if (line == "FIM") break;
        if (line.empty()) continue;

        size_t commaPos = line.find(',');
        if (commaPos == string::npos) continue;

        string section = line.substr(0, commaPos);
        string item = line.substr(commaPos + 1);

        if (!store.count(section) || !store[section].count(item)) {
            cout << "Indisponivel\n";
        } else {
            cout << "Tem\n";
        }
    }

    return 0;
}