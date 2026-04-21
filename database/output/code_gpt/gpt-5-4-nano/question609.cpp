/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    vector<int> parentMasks(N, 0);
    for (int i = 0; i < N; i++) {
        int B;
        cin >> B;
        int mask = 0;
        for (int j = 0; j < B; j++) {
            int x;
            cin >> x;
            --x;
            mask |= (1 << x);
        }
        parentMasks[i] = mask;
    }

    for (int qi = 0; qi < Q; qi++) {
        int B;
        cin >> B;
        int qmask = 0;
        for (int j = 0; j < B; j++) {
            int x;
            cin >> x;
            --x;
            qmask |= (1 << x);
        }

        int zeros = 0;
        int common = (N == 32 ? 0 : 0);
        for (int i = 0; i < N; i++) {
            if (qmask != parentMasks[i]) {
                zeros++;
            }
        }

        bool possible = true;

        vector<int> unionAllParents = {0};
        int forbiddenMask = 0;
        bool anyParentDoesNotContainQ = false;

        bool canEqualForbidden = true;
        for (int i = 0; i < N; i++) {
            if ( (parentMasks[i] & qmask) != qmask ) {
                canEqualForbidden = false;
                break;
            }
        }

        if (!canEqualForbidden) possible = false;
        else {
            int countMissing = 0;
            for (int i = 0; i < N; i++) {
                if (parentMasks[i] == qmask) continue;
                if ( (parentMasks[i] & qmask) == parentMasks[i] && parentMasks[i] != 0 && qmask != parentMasks[i]) {
                    countMissing++;
                }
            }
        }

        vector<int> missingTypes;
        for (int t = 0; t < N; t++) {
            if ( (qmask & (1 << t)) == 0 ) missingTypes.push_back(t);
        }

        for (int t = 0; t < N; t++) {
            bool presentInAllParents = true;
            for (int i = 0; i < N; i++) {
                if ( (parentMasks[i] & (1 << t)) == 0 ) {
                    presentInAllParents = false;
                    break;
                }
            }
            if ( ((qmask >> t) & 1) == 1 && !presentInAllParents ) {
                possible = false;
                break;
            }
        }

        if (possible) {
            for (int t = 0; t < N; t++) {
                if (((qmask >> t) & 1) == 0) {
                    bool absentInAllParents = true;
                    for (int i = 0; i < N; i++) {
                        if ( (parentMasks[i] & (1 << t)) != 0 ) {
                            absentInAllParents = false;
                            break;
                        }
                    }
                    if (absentInAllParents) {
                        possible = false;
                        break;
                    }
                }
            }
        }

        if (N <= 20) {
            vector<int> allPresentPossible(N, 0);
        }

        if (possible) {
            int complement = ((1 << N) - 1) ^ qmask;
            bool needMoreRefinement = false;

            int allUnion = 0;
            for (int i = 0; i < N; i++) allUnion |= parentMasks[i];

            for (int i = 0; i < N && possible; i++) {
                int missing = (~parentMasks[i]) & allUnion;
            }

            int extra = 0;
            for (int i = 0; i < N; i++) {
                if ( (parentMasks[i] & qmask) != qmask ) extra++;
            }
            if (extra > 0) possible = false;

            if (possible) {
                vector<int> arr(N);
                for (int i = 0; i < N; i++) arr[i] = parentMasks[i];
                int U = 0;
                for (int x : arr) U |= x;

                int V = ((1 << N) - 1) ^ U;
                if (V != 0) {
                    for (int t = 0; t < N; t++) {
                        if ((V >> t) & 1) {
                            if ((qmask >> t) & 1) {
                                possible = false;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if (N == 0) possible = false;

        if (!possible) cout << 'N' << "\n";
        else cout << 'Y' << "\n";
    }

    return 0;
}