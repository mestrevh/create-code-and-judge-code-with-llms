/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Card {
    int r, s;
    bool operator==(const Card& o) const { return r == o.r && s == o.s; }
};

static int rankFromChar(char c) {
    if (c == 'A') return 0;
    if (c >= '2' && c <= '9') return c - '0' - 1;
    if (c == 'T') return 9;
    if (c == 'J') return 10;
    if (c == 'Q') return 11;
    if (c == 'K') return 12;
    return -1;
}

static int suitFromChar(char c) {
    if (c == 'C') return 0;
    if (c == 'D') return 1;
    if (c == 'H') return 2;
    if (c == 'S') return 3;
    return -1;
}

static bool matches(const Card& a, const Card& b) {
    return a.r == b.r || a.s == b.s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line1;
    while (true) {
        if (!std::getline(cin, line1)) break;
        if (line1.size() && line1[0] == '#') break;
        string line2;
        if (!std::getline(cin, line2)) break;

        auto parseLine = [&](const string& ln) -> vector<Card> {
            vector<Card> v;
            string token;
            istringstream iss(ln);
            while (iss >> token) {
                if (token.size() < 2) continue;
                char c1 = token[0];
                char c2 = token[1];
                v.push_back({rankFromChar(c1), suitFromChar(c2)});
            }
            return v;
        };

        vector<Card> a = parseLine(line1);
        vector<Card> b = parseLine(line2);
        if (a.size() != 26 || b.size() != 26) continue;

        vector<Card> deck;
        deck.reserve(52);
        for (auto &x : a) deck.push_back(x);
        for (auto &x : b) deck.push_back(x);

        int n = 52;
        vector<vector<Card>> stacks;
        stacks.reserve(n);

        for (int i = 0; i < n; i++) stacks.push_back({deck[i]});

        auto top = [&](int idx)->Card& { return stacks[idx].back(); };

        auto canMove = [&](int i, int j) -> bool {
            if (i == j) return false;
            if (i < 0 || j < 0) return false;
            if (i >= (int)stacks.size() || j >= (int)stacks.size()) return false;
            if (stacks[i].empty() || stacks[j].empty()) return false;
            return matches(stacks[i].back(), stacks[j].back());
        };

        auto compact = [&](vector<int>& posMap) {
            vector<vector<Card>> newStacks;
            newStacks.reserve(stacks.size());
            for (auto &st : stacks) {
                if (!st.empty()) newStacks.push_back(std::move(st));
            }
            stacks.swap(newStacks);
        };

        bool moved = true;
        while (moved) {
            moved = false;

            int m = (int)stacks.size();
            for (int i = 0; i < m && !moved; i++) {
                if (stacks[i].empty()) continue;
                int left1 = i - 1;
                int left3 = i - 3;

                bool ok1 = (left1 >= 0) && canMove(i, left1);
                bool ok3 = (left3 >= 0) && canMove(i, left3);

                if (!ok1 && !ok3) continue;

                int moveDist = 0;
                if (ok1 && ok3) {
                    moveDist = 3;
                } else if (ok1) {
                    moveDist = 1;
                } else {
                    moveDist = 3;
                }

                int j = i - moveDist;
                if (j < 0) continue;

                Card c = stacks[i].back();
                stacks[i].pop_back();
                stacks[j].push_back(c);

                if (stacks[i].empty()) {
                    moved = true;
                    compact(*(new vector<int>()));
                } else {
                    moved = true;
                }
            }
        }

        int totalStacks = (int)stacks.size();
        cout << totalStacks << (totalStacks == 1 ? " pilha sobrando:" : " pilhas sobrando:");
        for (auto &st : stacks) {
            cout << " " << st.size();
        }
        cout << "\n";
    }
    return 0;
}