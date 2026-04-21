/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

struct Vote {
    int p;
    bool s;
};

struct Minister {
    int k, target;
    vector<Vote> votes;
};

int B, M;
Minister ministers[505];
vector<int> adj[105];
int val[105];
bool possibleS[105], possibleN[105];

bool set_variable(int p, int v, queue<int>& q) {
    if (val[p] != -1) return val[p] == v;
    val[p] = v;
    q.push(p);
    return true;
}

bool apply_implications(queue<int>& q) {
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (int m_idx : adj[p]) {
            int m = 0, u = 0;
            for (auto& vt : ministers[m_idx].votes) {
                if (val[vt.p] == -1) u++;
                else if (val[vt.p] == (vt.s ? 1 : 0)) m++;
            }
            if (m + u < ministers[m_idx].target) return false;
            if (m < ministers[m_idx].target && m + u == ministers[m_idx].target) {
                for (auto& vt : ministers[m_idx].votes) {
                    if (val[vt.p] == -1) {
                        if (!set_variable(vt.p, vt.s ? 1 : 0, q)) return false;
                    }
                }
            }
        }
    }
    return true;
}

bool solve(int idx) {
    while (idx <= B && val[idx] != -1) idx++;
    if (idx > B) return true;

    int backup[105];
    memcpy(backup, val, sizeof(val));

    for (int v : {1, 0}) {
        queue<int> q;
        if (set_variable(idx, v, q) && apply_implications(q)) {
            if (solve(idx + 1)) return true;
        }
        memcpy(val, backup, sizeof(val));
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (cin >> B >> M && (B || M)) {
        for (int i = 1; i <= B; ++i) {
            adj[i].clear();
            possibleS[i] = possibleN[i] = false;
        }
        for (int i = 0; i < M; ++i) {
            cin >> ministers[i].k;
            ministers[i].target = ministers[i].k / 2 + 1;
            ministers[i].votes.clear();
            for (int j = 0; j < ministers[i].k; ++j) {
                int p;
                char v;
                cin >> p >> v;
                ministers[i].votes.push_back({p, v == 's'});
                adj[p].push_back(i);
            }
        }

        memset(val, -1, sizeof(val));
        cout << "Caso " << t++ << ": ";
        if (!solve(1)) {
            cout << "impossível" << endl;
        } else {
            for (int i = 1; i <= B; ++i) {
                if (val[i] == 1) possibleS[i] = true;
                else if (val[i] == 0) possibleN[i] = true;
            }

            for (int i = 1; i <= B; ++i) {
                if (!possibleS[i]) {
                    memset(val, -1, sizeof(val));
                    queue<int> q;
                    if (set_variable(i, 1, q) && apply_implications(q)) {
                        if (solve(1)) {
                            for (int j = 1; j <= B; ++j) {
                                if (val[j] == 1) possibleS[j] = true;
                                else if (val[j] == 0) possibleN[j] = true;
                            }
                        }
                    }
                }
                if (!possibleN[i]) {
                    memset(val, -1, sizeof(val));
                    queue<int> q;
                    if (set_variable(i, 0, q) && apply_implications(q)) {
                        if (solve(1)) {
                            for (int j = 1; j <= B; ++j) {
                                if (val[j] == 1) possibleS[j] = true;
                                else if (val[j] == 0) possibleN[j] = true;
                            }
                        }
                    }
                }
            }

            for (int i = 1; i <= B; ++i) {
                if (possibleS[i] && possibleN[i]) cout << "?";
                else if (possibleS[i]) cout << "S";
                else cout << "N";
            }
            cout << endl;
        }
    }
    return 0;
}