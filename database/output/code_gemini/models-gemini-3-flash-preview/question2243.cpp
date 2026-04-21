/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    if (n <= 0) return 0;

    map<string, int> counts;
    for (int i = 0; i < n; ++i) {
        string s;
        if (cin >> s) {
            counts[s]++;
        }
    }

    if (counts.empty()) return 0;

    int max_v = 0;
    for (auto const& p : counts) {
        if (p.second > max_v) {
            max_v = p.second;
        }
    }

    vector<string> winners;
    for (auto const& p : counts) {
        if (p.second == max_v) {
            winners.push_back(p.first);
        }
    }

    if (winners.size() > 1) {
        cout << "Houve um empate entre: ";
        for (size_t i = 0; i < winners.size(); ++i) {
            if (i > 0) cout << ", ";
            cout << winners[i];
        }
    } else {
        string w = winners[0];
        set<string> known = {"Anitta", "Ludmilla", "Jojo", "Kevinho", "Livinho"};
        if (known.count(w)) {
            cout << "As pessoas estao esperando por " << w << ".";
        } else {
            cout << "As pessoas querem ver outra pessoa";
        }
    }
    cout << endl;

    return 0;
}