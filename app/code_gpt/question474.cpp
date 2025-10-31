/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <limits>

using namespace std;

int main() {
    int D;
    cin >> D;
    cout << "SHIPPING ROUTES OUTPUT" << endl;

    for (int caseNum = 1; caseNum <= D; ++caseNum) {
        int M, N, P;
        cin >> M >> N >> P;

        unordered_map<string, int> portIndex;
        vector<string> ports(M);
        for (int i = 0; i < M; ++i) {
            cin >> ports[i];
            portIndex[ports[i]] = i;
        }

        vector<vector<int>> graph(M, vector<int>(M, 0));
        for (int i = 0; i < N; ++i) {
            string portA, portB;
            cin >> portA >> portB;
            graph[portIndex[portA]][portIndex[portB]] = 1;
            graph[portIndex[portB]][portIndex[portA]] = 1;
        }

        cout << "DATA SET  " << caseNum << endl;

        for (int i = 0; i < P; ++i) {
            int Z;
            string origin, destination;
            cin >> Z >> origin >> destination;

            int src = portIndex[origin];
            int dest = portIndex[destination];

            vector<int> dist(M, numeric_limits<int>::max());
            dist[src] = 0;

            queue<int> q;
            q.push(src);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v = 0; v < M; ++v) {
                    if (graph[u][v] && dist[u] + 1 < dist[v]) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }

            if (dist[dest] == numeric_limits<int>::max()) {
                cout << "NO SHIPMENT POSSIBLE" << endl;
            } else {
                int cost = Z * dist[dest] * 100;
                cout << "$" << cost << endl;
            }
        }
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}
