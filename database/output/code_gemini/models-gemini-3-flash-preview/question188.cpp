/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, E;
    if (!(cin >> N >> E)) return 0;

    vector<int> P(E), D(E);
    vector<int> S(E);

    for (int i = 0; i < E; ++i) {
        cin >> P[i] >> D[i];
        S[i] = P[i];
    }

    sort(S.begin(), S.end());

    vector<int> candidates;
    for (int j = 0; j < E; ++j) {
        int t;
        if (D[0] == 1) {
            t = (S[j] - P[0] + N) % N;
        } else {
            t = (P[0] - S[j] + N) % N;
        }
        if (t == 0) t = N;
        candidates.push_back(t);
    }

    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    vector<int> new_pos(E);
    for (int t : candidates) {
        for (int i = 0; i < E; ++i) {
            long long cur = P[i] + (long long)D[i] * t;
            int p = (cur - 1) % N;
            if (p < 0) p += N;
            new_pos[i] = p + 1;
        }
        sort(new_pos.begin(), new_pos.end());

        bool match = true;
        for (int i = 0; i < E; ++i) {
            if (new_pos[i] != S[i]) {
                match = false;
                break;
            }
        }

        if (match) {
            cout << t << endl;
            break;
        }
    }

    return 0;
}

