/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main() {
    int n, start;
    cin >> n >> start;
    vector<vector<int>> graph(n);
    set<int> visited;
    queue<int> q;

    int u, v;
    while (cin >> u >> v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << endl;

        for (int neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
    return 0;
}
