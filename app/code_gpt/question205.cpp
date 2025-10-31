/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> distance;

void bfs(int start, int& farthestNode, int& maxDistance) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    distance[start] = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[node] + 1;
                if (distance[neighbor] > maxDistance) {
                    maxDistance = distance[neighbor];
                    farthestNode = neighbor;
                }
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    
    graph.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    
    visited.assign(N + 1, false);
    distance.assign(N + 1, 0);
    
    int farthestNode = 0, maxDistance = 0;
    bfs(1, farthestNode, maxDistance);
    
    visited.assign(N + 1, false);
    distance.assign(N + 1, 0);
    
    bfs(farthestNode, farthestNode, maxDistance);
    
    cout << maxDistance << endl;
    return 0;
}
