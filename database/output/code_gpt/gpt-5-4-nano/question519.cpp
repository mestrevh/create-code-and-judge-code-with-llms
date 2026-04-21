/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int c;
    int t;
};

static bool betterSeq(const vector<int>& a, const vector<int>& b, const int N) {
    // prefer sequences with higher indices when comparing from right to left
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    // compare rightmost elements present in both
    while (i >= 0 && j >= 0) {
        if (a[i] != b[j]) return a[i] > b[j];
        i--; j--;
    }
    // if one is prefix of the other, rightmost differing doesn't exist:
    // then the one with more elements has extra elements to the left; compare those leftmost extras
    // However requirement implies right-to-left greedy emotion regardless of length.
    // For prefix case, compare remaining elements from right to left (i side where one ended):
    while (i >= 0) {
        // b has no corresponding element => treat as smaller
        return true;
    }
    while (j >= 0) {
        return false;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    if (!(cin >> M)) return 0;
    for (int tc = 1; tc <= M; tc++) {
        int N;
        long long K;
        cin >> N >> K;
        vector<Item> items(N + 1);
        for (int i = 1; i <= N; i++) cin >> items[i].c;
        for (int i = 1; i <= N; i++) cin >> items[i].t;

        // We need maximize total time with cost <= K, each item at most once.
        // Tie-break: compare sequences by indices right-to-left, preferring larger indices.
        // Since N<=100, but K can be large. We will use DP by cost up to min(K, 100000) possible too large.
        // Approach: pseudo-polynomial with cost cap using min(K, 100000)?? but K up to 100000 and N up to 100 => 1e7 feasible.
        int costCap = (int)min<long long>(K, 100000);
        // Use dpTime with -inf for impossible, and store choice reconstruction with parent pointers.
        const long long NEG = -(1LL<<60);
        vector<long long> dpT(costCap + 1, NEG);
        vector<int> parentItem(costCap + 1, -1);
        vector<int> parentCost(costCap + 1, -1);

        dpT[0] = 0;
        parentItem[0] = -2;

        for (int i = 1; i <= N; i++) {
            int ci = items[i].c;
            int ti = items[i].t;
            if (ci > costCap) continue;
            for (int w = costCap; w >= ci; w--) {
                if (dpT[w - ci] == NEG) continue;
                long long candT = dpT[w - ci] + ti;
                if (candT > dpT[w]) {
                    dpT[w] = candT;
                    parentItem[w] = i;
                    parentCost[w] = w - ci;
                } else if (candT == dpT[w]) {
                    // Tie-break: compare sequences ending at state w vs current parent pointers.
                    // Build sequences for candidate and current using parent pointers.
                    // Since N is small, reconstruction cost per tie could be acceptable though worst-case large.
                    // We'll limit by caching reconstructed sequences for states visited at equal time:
                    // but implement on-the-fly.
                    auto buildSeq = [&](int wstate)->vector<int>{
                        vector<int> seq;
                        int cur = wstate;
                        while (cur > 0 && parentItem[cur] >= 0) {
                            seq.push_back(parentItem[cur]);
                            cur = parentCost[cur];
                        }
                        reverse(seq.begin(), seq.end());
                        return seq;
                    };

                    // Temporarily candidate state uses parent of dpT[w-ci] plus item i.
                    // We'll compare by actual sequences:
                    // We can build candidate sequence: seq(dp w-ci) + [i]
                    vector<int> curSeq = buildSeq(w);
                    vector<int> baseSeq;
                    {
                        int b = w - ci;
                        baseSeq = buildSeq(b);
                    }
                    baseSeq.push_back(i);
                    vector<int> candSeq = baseSeq;

                    if (betterSeq(candSeq, curSeq, N)) {
                        dpT[w] = candT;
                        parentItem[w] = i;
                        parentCost[w] = w - ci;
                    }
                }
            }
        }

        // choose best among all costs <= costCap with dpT[w] maximal time, tie by sequence.
        long long bestT = NEG;
        int bestW = -1;

        auto buildSeqFromState = [&](int wstate)->vector<int>{
            vector<int> seq;
            int cur = wstate;
            while (cur > 0 && parentItem[cur] >= 0) {
                seq.push_back(parentItem[cur]);
                cur = parentCost[cur];
            }
            reverse(seq.begin(), seq.end());
            return seq;
        };

        for (int w = 0; w <= costCap; w++) {
            if (dpT[w] == NEG) continue;
            if (dpT[w] > bestT) {
                bestT = dpT[w];
                bestW = w;
            } else if (dpT[w] == bestT) {
                vector<int> seqA = buildSeqFromState(w);
                vector<int> seqB = (bestW==-1)?vector<int>() : buildSeqFromState(bestW);
                if (betterSeq(seqA, seqB, N)) {
                    bestW = w;
                }
            }
        }

        cout << "brinquedos caso " << tc << ": ";
        bool found = false;
        if (bestW == -1 || bestT <= 0 || dpT[bestW] == 0 && bestW==0) {
            // possibly no items or only time 0, but times are >=60 so if time 0 then no items.
            // Need determine if cost 0 means empty.
            if (bestW == 0 && dpT[0] == 0) {
                cout << "caso " << tc << ": saldo insuficiente\n\n";
                continue;
            }
        }

        if (bestW == 0 && dpT[0] == 0) {
            cout << "caso " << tc << ": saldo insuficiente\n\n";
            continue;
        }

        vector<int> seq = buildSeqFromState(bestW);
        if (seq.empty()) {
            cout << "caso " << tc << ": saldo insuficiente\n\n";
            continue;
        }
        found = true;
        for (int idx = 0; idx < (int)seq.size(); idx++) {
            if (idx) cout << ' ';
            cout << seq[idx];
        }
        // total cost
        long long totalC = 0;
        long long totalT = 0;
        for (int id : seq) {
            totalC += items[id].c;
            totalT += items[id].t;
        }
        cout << "\n";
        cout << "custo total caso " << tc << ": " << totalC << "\n";
        cout << "tempo total caso " << tc << ": " << totalT << "\n\n";
    }
    return 0;
}