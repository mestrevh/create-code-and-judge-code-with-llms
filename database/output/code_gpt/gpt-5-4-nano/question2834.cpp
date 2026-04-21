/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Entry {
    string name;
    bool yes;
    long long order;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Entry> yesEntries;
    vector<Entry> noEntries;

    string name, opt;
    long long ord = 0;
    while (cin >> name >> opt) {
        if (name == "FIM") break;
        bool yes = (opt == "YES");
        if (yes) {
            yesEntries.push_back({name, true, ord++});
        } else {
            noEntries.push_back({name, false, ord++});
        }
    }

    vector<string> resultYesNo;
    resultYesNo.reserve(yesEntries.size() + noEntries.size());

    sort(yesEntries.begin(), yesEntries.end(), [](const Entry& a, const Entry& b){
        if (a.name.size() != b.name.size()) return a.name.size() < b.name.size();
        return a.order < b.order;
    });

    vector<string> uniqueYes;
    uniqueYes.reserve(yesEntries.size());
    for (auto &e : yesEntries) {
        if (uniqueYes.empty() || uniqueYes.back() != e.name) uniqueYes.push_back(e.name);
    }

    vector<string> uniqueNo;
    uniqueNo.reserve(noEntries.size());
    sort(noEntries.begin(), noEntries.end(), [](const Entry& a, const Entry& b){
        return a.name < b.name;
    });
    for (auto &e : noEntries) {
        if (uniqueNo.empty() || uniqueNo.back() != e.name) uniqueNo.push_back(e.name);
    }

    for (auto &s : uniqueYes) resultYesNo.push_back(s);
    for (auto &s : uniqueNo) resultYesNo.push_back(s);

    string winner;
    if (!yesEntries.empty()) {
        vector<Entry> yesDedup = yesEntries;
        sort(yesDedup.begin(), yesDedup.end(), [](const Entry& a, const Entry& b){
            if (a.name != b.name) return a.name < b.name;
            return a.order < b.order;
        });

        vector<Entry> perNameFirst;
        for (auto &e : yesDedup) {
            if (perNameFirst.empty() || perNameFirst.back().name != e.name) perNameFirst.push_back(e);
        }

        sort(perNameFirst.begin(), perNameFirst.end(), [](const Entry& a, const Entry& b){
            if (a.name.size() != b.name.size()) return a.name.size() > b.name.size();
            return a.order < b.order;
        });

        winner = perNameFirst.front().name;
    }

    for (auto &s : resultYesNo) cout << s << "\n";
    cout << "\n";
    cout << "Amigo do Habay:\n";
    cout << winner << "\n";
    return 0;
}