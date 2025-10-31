/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <iomanip>
#include <sstream>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to, dist;
};

vector<vector<Edge>> graph;
vector<vector<int>> distances;
vector<int> terminals;

void dijkstra(int start) {
    vector<int> dist(graph.size(), INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (current_dist > dist[node]) continue;

        for (const auto& edge : graph[node]) {
            int new_dist = dist[node] + edge.dist;
            if (new_dist < dist[edge.to]) {
                dist[edge.to] = new_dist;
                pq.emplace(new_dist, edge.to);
            }
        }
    }
    distances.push_back(dist);
}

int main() {
    string line;
    int caseNum = 0;

    while (getline(cin, line)) {
        if (line.empty()) {
            continue;
        }

        istringstream iss(line);
        int N, M;
        iss >> N >> M;

        graph.assign(N, vector<Edge>());
        distances.clear();
        terminals.clear();

        vector<int> terminalIndices;
        for (int i = 0; i < M; ++i) {
            int u, v, d;
            cin >> u >> v >> d;
            graph[u].push_back({v, d});
            graph[v].push_back({u, d});
        }
        getline(cin, line); // read the empty line

        for (int i = 0; i < N; ++i) {
            int count = 0;
            for (const auto& edge : graph[i]) {
                count++;
            }
            if (count > 1) {
                terminalIndices.push_back(i);
            }
        }

        for (int terminal : terminalIndices) {
            dijkstra(terminal);
            terminals.push_back(terminal);
        }

        cout << "caso " << caseNum++ << endl;
        for (size_t i = 0; i < distances.size(); ++i) {
            for (size_t j = 0; j < terminalIndices.size(); ++j) {
                cout << distances[i][terminalIndices[j]] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
