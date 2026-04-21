/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a(4);
    while (cin >> a[0] >> a[1] >> a[2] >> a[3]) {
        vector<int> target = a;
        sort(target.begin(), target.end());
        for (int i = 0; i < 4; ++i) {
            cout << target[i] << (i == 3 ? "" : " ");
        }
        cout << "\n";
        if (a == target) {
            cout << "0\n";
            continue;
        }
        queue<vector<int>> q;
        map<vector<int>, int> dist;
        q.push(a);
        dist[a] = 0;
        bool found = false;
        while (!q.empty()) {
            vector<int> curr = q.front();
            int d = dist[curr];
            q.pop();
            for (int i = 0; i < 4; ++i) {
                for (int j = i + 1; j < 4; ++j) {
                    vector<int> next_v = curr;
                    swap(next_v[i], next_v[j]);
                    if (dist.find(next_v) == dist.end()) {
                        dist[next_v] = d + 1;
                        if (next_v == target) {
                            cout << d + 1 << "\n";
                            found = true;
                            break;
                        }
                        q.push(next_v);
                    }
                }
                if (found) break;
            }
            if (found) break;
        }
    }
    return 0;
}