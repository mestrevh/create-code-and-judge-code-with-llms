/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

class Graph {
    int V;
    vector<int>* adj;
    void criticalLinksUtil(int u, int disc[], int low[], vector<pair<int, int>>& criticalLinks, int parent);

public:
    Graph(int V);
    void addEdge(int u, int v);
    void findCriticalLinks();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::criticalLinksUtil(int u, int disc[], int low[], vector<pair<int, int>>& criticalLinks, int parent) {
    static int time = 0;
    disc[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (v == parent) continue;
        if (disc[v] == -1) {
            criticalLinksUtil(v, disc, low, criticalLinks, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                criticalLinks.push_back({min(u, v), max(u, v)});
            }
        } else {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void Graph::findCriticalLinks() {
    int* disc = new int[V];
    int* low = new int[V];
    memset(disc, -1, sizeof(int) * V);
    memset(low, -1, sizeof(int) * V);
    vector<pair<int, int>> criticalLinks;

    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            criticalLinksUtil(i, disc, low, criticalLinks, -1);
        }
    }
    sort(criticalLinks.begin(), criticalLinks.end());

    cout << criticalLinks.size() << " critical links" << endl;
    for (auto &link : criticalLinks) {
        cout << link.first << " - " << link.second << endl;
    }
    cout << endl;

    delete[] disc;
    delete[] low;
}

int main() {
    int no_of_servers;
    while (cin >> no_of_servers) {
        if (no_of_servers == 0) {
            cout << "0 critical links" << endl << endl;
            continue;
        }

        Graph g(no_of_servers);
        for (int i = 0; i < no_of_servers; i++) {
            int connections;
            cin >> connections;
            for (int j = 0; j < connections; j++) {
                int server;
                cin >> server;
                g.addEdge(i, server);
            }
        }
        g.findCriticalLinks();
    }
    return 0;
}
