/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    int C;
    cin >> C;
    for (int k = 0; k < C; ++k) {
        int N, S;
        cin >> N >> S;
        vector<vector<int>> graph(N);
        for (int i = 0; i < N; ++i) {
            int degree;
            cin >> degree;
            for (int j = 0; j < degree; ++j) {
                int neighbor;
                cin >> neighbor;
                graph[i].push_back(neighbor);
            }
        }

        vector<int> distance(N, -1);
        queue<int> q;
        q.push(S);
        distance[S] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : graph[node]) {
                if (distance[neighbor] == -1) {
                    distance[neighbor] = distance[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        int dmax = 0, Nmax = 0;
        for (int dist : distance) {
            if (dist > dmax) {
                dmax = dist;
                Nmax = 1;
            } else if (dist == dmax) {
                Nmax++;
            }
        }

        cout << k << " " << dmax << " " << Nmax << endl;
    }
    return 0;
}
