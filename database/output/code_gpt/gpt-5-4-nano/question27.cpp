/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static int rankValue(char c) {
    if (c >= '2' && c <= '9') return c - '0';
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    if (c == 'K') return 13;
    if (c == 'A') return 14;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    for (int tc = 0; tc < n; tc++) {
        deque<int> p1, p2;

        for (int i = 0; i < 26; i++) {
            string s; cin >> s;
            if (s.size() >= 2) p1.push_back(rankValue(s[0]));
        }
        for (int i = 0; i < 26; i++) {
            string s; cin >> s;
            if (s.size() >= 2) p2.push_back(rankValue(s[0]));
        }

        int steps = 0;
        int maxSteps = 100000;
        int winner = 0;
        deque<int> deck1, deck2;
        bool done = false;

        while (!done) {
            if (p1.empty()) { winner = 2; break; }
            if (p2.empty()) { winner = 1; break; }
            if (steps >= maxSteps) break;

            vector<pair<int,int>> face; 
            int c1 = 0, c2 = 0;
            int r1 = -1, r2 = -1;

            while (true) {
                if (p1.empty()) { winner = 2; break; }
                if (p2.empty()) { winner = 1; break; }
                if (steps >= maxSteps) break;

                r1 = p1.front(); p1.pop_front();
                r2 = p2.front(); p2.pop_front();
                steps++;

                face.push_back({r1, r2});
                if (r1 != r2) break;

                if (p1.empty()) { winner = 2; break; }
                if (p2.empty()) { winner = 1; break; }
                if (steps >= maxSteps) break;
            }

            if (winner != 0) {
                done = true;
                break;
            }
            if (steps > maxSteps) break;
            if (steps >= maxSteps) break;

            int last1 = face.back().first;
            int last2 = face.back().second;
            int w = (last1 > last2) ? 1 : 2;

            int addCount = (int)face.size();
            for (int i = 0; i < addCount; i++) {
                if (w == 1) {
                    p1.push_back(face[i].first);
                    p1.push_back(face[i].second);
                } else {
                    p2.push_back(face[i].first);
                    p2.push_back(face[i].second);
                }
            }
            done = false;
            if (p1.empty()) { winner = 2; break; }
            if (p2.empty()) { winner = 1; break; }
            if (steps >= maxSteps) break;
        }

        if (winner == 0) {
            if (steps >= maxSteps) {
                cout << "jogo empatado apos 100000 jogadas. Jogador 1 |" << p1.size()
                     << "| cartas e jogador 2 |" << p2.size() << "|\n";
            } else {
                if (p1.empty() && p2.empty()) {
                    cout << "jogo empatado apos 100000 jogadas. Jogador 1 |" << p1.size()
                         << "| cartas e jogador 2 |" << p2.size() << "|\n";
                } else {
                    if (p1.empty()) winner = 2;
                    else if (p2.empty()) winner = 1;
                    if (winner == 0) {
                        cout << "jogo empatado apos 100000 jogadas. Jogador 1 |" << p1.size()
                             << "| cartas e jogador 2 |" << p2.size() << "|\n";
                    }
                }
            }
        }

        if (winner != 0) {
            cout << "jogador " << winner << " ganhou com " << steps << " passos\n";
        }

        if (tc != n - 1) {
            ;
        }
    }

    return 0;
}