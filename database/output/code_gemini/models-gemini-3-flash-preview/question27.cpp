/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int getRank(string s) {
    char r = s[0];
    if (r == 'A') return 14;
    if (r == 'K') return 13;
    if (r == 'Q') return 12;
    if (r == 'J') return 11;
    if (r == 'T') return 10;
    if (r >= '2' && r <= '9') return r - '0';
    return 0;
}

void solve() {
    deque<int> p1, p2;
    string s;
    for (int i = 0; i < 26; ++i) {
        if (!(cin >> s)) return;
        p1.push_back(getRank(s));
    }
    for (int i = 0; i < 26; ++i) {
        if (!(cin >> s)) return;
        p2.push_back(getRank(s));
    }

    int steps = 0;
    while (steps < 100000) {
        if (p1.empty() || p2.empty()) break;

        steps++;
        vector<int> table;
        int c1 = p1.front(); p1.pop_front();
        int c2 = p2.front(); p2.pop_front();
        table.push_back(c1);
        table.push_back(c2);

        while (c1 == c2) {
            if (p1.empty() || p2.empty()) {
                if (p1.empty()) cout << "jogador 2 ganhou com " << steps << " passos" << endl;
                else cout << "jogador 1 ganhou com " << steps << " passos" << endl;
                return;
            }
            table.push_back(p1.front()); p1.pop_front();
            table.push_back(p2.front()); p2.pop_front();

            if (p1.empty() || p2.empty()) {
                if (p1.empty()) cout << "jogador 2 ganhou com " << steps << " passos" << endl;
                else cout << "jogador 1 ganhou com " << steps << " passos" << endl;
                return;
            }
            steps++;
            if (steps > 100000) {
                cout << "jogo empatado apos 100000 jogadas. Jogador 1 |" << p1.size() << "| cartas e jogador 2 |" << p2.size() << "| cartas" << endl;
                return;
            }
            c1 = p1.front(); p1.pop_front();
            c2 = p2.front(); p2.pop_front();
            table.push_back(c1);
            table.push_back(c2);
        }

        if (c1 > c2) {
            for (int card : table) p1.push_back(card);
        } else {
            for (int card : table) p2.push_back(card);
        }

        if (p1.empty()) {
            cout << "jogador 2 ganhou com " << steps << " passos" << endl;
            return;
        }
        if (p2.empty()) {
            cout << "jogador 1 ganhou com " << steps << " passos" << endl;
            return;
        }
    }

    if (p1.empty() && !p2.empty()) {
        cout << "jogador 2 ganhou with " << steps << " passos" << endl;
    } else if (p2.empty() && !p1.empty()) {
        cout << "jogador 1 ganhou with " << steps << " passos" << endl;
    } else {
        cout << "jogo empatado apos 100000 jogadas. Jogador 1 |" << p1.size() << "| cartas e jogador 2 |" << p2.size() << "| cartas" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    while (n--) {
        solve();
    }
    return 0;
}