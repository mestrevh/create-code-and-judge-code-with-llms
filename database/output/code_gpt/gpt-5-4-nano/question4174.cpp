/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<unordered_map<int,int>> pos; 
    pos.assign(n, unordered_map<int,int>());

    vector<queue<int>> freeQueues;
    freeQueues.resize(n);
    vector<set<int>> freeSet(n);

    vector<int> nextFree;
    nextFree.assign(n, -1);

    vector<vector<int>> carsAt(n);
    vector<unordered_map<int,int>> carCount(n);

    int v;
    char c;
    int K, m;
    while (cin >> c >> K >> v >> m) {
        if (c == 'o') break;
        if (c == 'i') {
            if (v < 0 || v >= n) continue;
            if (pos[v].find(K) != pos[v].end()) continue;

            int target = v;
            if (!freeSet[target].empty()) {
                while (!freeSet[target].empty() && carsAt[target].empty()) {}
            }

            if (!carsAt[target].empty() && (int)freeSet[target].size() == 0) {}

            if (carsAt[target].size() == 0) {
                carsAt[target].push_back(K);
                carCount[target][K]++;
            } else {
                int cur = target;
                bool moved = false;
                for (int i = cur; i < n; ++i) {
                    if (carsAt[i].empty()) {
                        cout << "Not empty\n";
                        carsAt[i].push_back(K);
                        carCount[i][K]++;
                        moved = true;
                        break;
                    }
                }
                if (!moved) {
                    cout << "FULL\n";
                }
            }

            if (!carsAt[v].empty() && carsAt[v].front() != K) {
                int found = -1;
                for (int i = v; i < n; ++i) {
                    if (carsAt[i].empty()) { found = i; break; }
                }
                (void)found;
            }
        } else if (c == 'r') {
            if (v < 0 || v >= n) continue;
            auto it = pos[v].find(K);
            if (it == pos[v].end()) {
                cout << "Not Found\n";
            } else {
                carCount[v].erase(K);
                pos[v].erase(K);
                carsAt[v].clear();
            }
        } else if (c == 'm') {
            if (v < 0 || v >= n || m < 0 || m >= n) continue;
            auto it = pos[v].find(K);
            if (it == pos[v].end()) {
                cout << "Not Found\n";
            } else {
                pos[v].erase(K);
                carCount[v].erase(K);
                carsAt[v].clear();

                if (carsAt[m].empty()) {
                    carsAt[m].push_back(K);
                    pos[m][K] = 1;
                    carCount[m][K] = 1;
                } else {
                    bool moved = false;
                    for (int i = m; i < n; ++i) {
                        if (carsAt[i].empty()) {
                            cout << "Not empty\n";
                            carsAt[i].push_back(K);
                            pos[i][K] = 1;
                            carCount[i][K] = 1;
                            moved = true;
                            break;
                        }
                    }
                    if (!moved) cout << "FULL\n";
                }
            }
        } else {
            if (c == 'o') break;
            int a,b;
            (void)a; (void)b;
        }
    }

    vector<int> final(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!carsAt[i].empty()) final[i] = carsAt[i][0];
    }

    for (int i = 0; i < n; ++i) {
        if (final[i] != -1) {
            cout << "Vaga " << i << " -> " << final[i] << "\n";
        }
    }
    return 0;
}