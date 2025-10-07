/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> adj(N);
    vector<int> in_degree(N, 0);
    
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        in_degree[B]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < N; i++) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> order;
    
    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        order.push_back(curr);
        
        for (int neighbor : adj[curr]) {
            if (--in_degree[neighbor] == 0) {
                pq.push(neighbor);
            }
        }
    }

    if (order.size() != N) {
        cout << "*";
    } else {
        for (int i = 0; i < N; i++) {
            cout << order[i] << endl;
        }
    }
    
    return 0;
}
