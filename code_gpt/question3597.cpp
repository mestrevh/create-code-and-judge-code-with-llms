/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
vector<int> dist;
int diameter = 0;

void bfs(int start) {
    fill(dist.begin(), dist.end(), -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int farthestNode = start;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : tree[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                if (dist[neighbor] > dist[farthestNode]) {
                    farthestNode = neighbor;
                }
                q.push(neighbor);
            }
        }
    }
    diameter = dist[farthestNode];
}

long long calculateSum(int n) {
    long long totalSum = 0;
    vector<long long> prefixSum(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + dist[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j : tree[i]) {
            if (j > i) {
                int distance = dist[j] - dist[i];
                if (distance < diameter) {
                    totalSum += distance;
                }
            }
        }
    }
    return totalSum;
}

int main() {
    int n;
    cin >> n;
    tree.resize(n + 1);
    dist.resize(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    bfs(1);
    int farthestFromFirst = max_element(dist.begin() + 1, dist.end()) - dist.begin();
    bfs(farthestFromFirst);
    
    long long result = calculateSum(n);
    cout << result << endl;

    return 0;
}
