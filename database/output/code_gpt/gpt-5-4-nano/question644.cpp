/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, J;
    while ( (cin >> N >> J) ) {
        if (N == 0 && J == 0) break;
        vector<int> cards(N);
        for (int i = 0; i < N; i++) cin >> cards[i];

        vector<int> sz(J + 1, 0);
        vector<int> top(J + 1, 0);
        vector<int> stealAt(J + 1, 0);

        unordered_map<int, vector<int>> positionsByValue;
        positionsByValue.reserve(16);

        for (int p = 0; p < N; p++) {
            positionsByValue[cards[p]].push_back(p);
        }

        for (auto &kv : positionsByValue) {
            kv.second.shrink_to_fit();
        }

        vector<int> usedPos(N, 0);

        int remaining = N;
        int winnerMax = 0;

        int player = 1;
        int idx = 0;

        while (remaining > 0) {
            int v = cards[idx];
            int curPlayer = player;

            bool moved = true;
            while (moved && remaining > 0) {
                moved = false;

                int matchDiscard = 0;
                (void)matchDiscard;

                int target = 0;

                if (top[target] == v) {}

                for (int p = 1; p <= J; p++) {
                    if (p == curPlayer) continue;
                    if (top[p] == v) {
                        target = p;
                        break;
                    }
                }

                if (target != 0) {
                    sz[curPlayer] += sz[target];
                    top[curPlayer] = v;
                    sz[target] = 0;
                    top[target] = 0;
                    remaining--;
                    idx++;
                    moved = (idx < N || remaining > 0);
                    if (remaining <= 0) break;
                    v = cards[idx];
                    continue;
                }

                if (top[curPlayer] == v) {
                    sz[curPlayer]++;
                    top[curPlayer] = v;
                    remaining--;
                    idx++;
                    moved = (idx < N || remaining > 0);
                    if (remaining <= 0) break;
                    v = cards[idx];
                    continue;
                }

                {
                    top[curPlayer] = v;
                    sz[curPlayer]++;
                    remaining--;
                    idx++;
                    player = player == J ? 1 : (player + 1);
                    break;
                }
            }
        }

        for (int p = 1; p <= J; p++) winnerMax = max(winnerMax, sz[p]);

        vector<int> ans;
        for (int p = 1; p <= J; p++) if (sz[p] == winnerMax) ans.push_back(p);

        cout << winnerMax << " ";
        for (size_t i = 0; i < ans.size(); i++) {
            if (i) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}