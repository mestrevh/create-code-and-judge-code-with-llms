/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> bag(5);
    for (int i = 0; i < 5; i++) {
        if (!getline(cin, bag[i])) return 0;
        while (bag[i].size() == 0 && cin) getline(cin, bag[i]);
    }

    string line;
    while (getline(cin, line)) {
        if (line.size() == 0) break;
    }

    unordered_set<string> guesses;
    for (int i = 0; i < 6; ) {
        if (!getline(cin, line)) break;
        if (line.size() == 0) continue;
        guesses.insert(line);
        i++;
    }

    for (const auto& item : bag) {
        if (guesses.find(item) == guesses.end()) {
            cout << "It is all just a moo point";
            return 0;
        }
    }
    cout << "Could I be more happy?";
    return 0;
}