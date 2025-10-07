/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

struct Edge {
    int to, type;
};

bool bfs(const vector<vector<Edge>>& graph, int n, int start, int end) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == end) return true;

        for (const auto& edge : graph[curr]) {
            if (!visited[edge.to]) {
                visited[edge.to] = true;
                q.push(edge.to);
            }
        }
    }
    return false;
}

int main() {
    int N, M;
    while (cin >> N >> M, N != -1 && M != -1) {
        vector<vector<Edge>> graph(N + 1);
        vector<pair<int, int>> oneWayEdges;
        int closedEdgeA, closedEdgeB;

        for (int i = 0; i < M; ++i) {
            int A, B, T;
            cin >> A >> B >> T;
            if (i == 0) {
                closedEdgeA = A;
                closedEdgeB = B;
            }
            if (T == 1) {
                graph[A].push_back({B, 1});
                oneWayEdges.push_back({A, B});
            } else {
                graph[A].push_back({B, 2});
                graph[B].push_back({A, 2});
            }
        }

        if (bfs(graph, N, closedEdgeA, closedEdgeB)) {
            cout << "-" << endl;
            continue;
        }

        graph[closedEdgeA].erase(remove_if(graph[closedEdgeA].begin(), graph[closedEdgeA].end(),
            [closedEdgeB](Edge e) { return e.to == closedEdgeB; }), graph[closedEdgeA].end());

        bool canByOneWay = bfs(graph, N, closedEdgeA, closedEdgeB);
        if (canByOneWay) {
            cout << "1" << endl;
            continue;
        }

        graph[closedEdgeB].push_back({closedEdgeA, 2});
        canByOneWay = bfs(graph, N, closedEdgeA, closedEdgeB);
        if (canByOneWay) {
            cout << "2" << endl;
        } else {
            cout << "*" << endl;
        }
    }
    return 0;
}
