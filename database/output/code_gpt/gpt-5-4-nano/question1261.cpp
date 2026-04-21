/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static vector<string> splitChar(const string& s, char delim) {
    vector<string> parts;
    string cur;
    for (char c : s) {
        if (c == delim) {
            parts.push_back(cur);
            cur.clear();
        } else cur.push_back(c);
    }
    parts.push_back(cur);
    return parts;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> order = {"Gryffindor", "Slytherin", "Hufflepuff", "Ravenclaw"};
    map<string, int> idx;
    for (int i = 0; i < (int)order.size(); i++) idx[order[i]] = i;

    array<long long, 4> wins{};
    for (int i = 0; i < N; i++) {
        string matchup, score;
        cin >> matchup >> score;
        auto teams = splitChar(matchup, 'x');
        auto pts = splitChar(score, '-');
        string c1 = teams[0], c2 = teams[1];
        long long p1 = stoll(pts[0]), p2 = stoll(pts[1]);

        if (p1 > p2) wins[idx[c1]]++;
        else if (p2 > p1) wins[idx[c2]]++;
    }

    long long best = *max_element(wins.begin(), wins.end());
    bool any = false;
    for (int i = 0; i < 4; i++) if (wins[i] == best) any = true;

    for (int i = 0; i < 4; i++) {
        if (wins[i] == best) {
            cout << order[i] << "\n";
        }
    }
    return 0;
}