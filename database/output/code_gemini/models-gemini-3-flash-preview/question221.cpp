/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, D;
    if (!(cin >> N >> D)) return 0;

    vector<Point> trees(N);
    for (int i = 0; i < N; ++i) {
        cin >> trees[i].x >> trees[i].y;
    }

    if (N == 0) {
        cout << "S" << endl;
        return 0;
    }

    vector<bool> visited(N, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;
    int reachable_count = 0;

    long long D2 = (long long)D * D;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        reachable_count++;

        for (int v = 0; v < N; ++v) {
            if (!visited[v]) {
                long long dx = trees[u].x - trees[v].x;
                long long dy = trees[u].y - trees[v].y;
                if (dx * dx + dy * dy <= D2) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    if (reachable_count == N) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}