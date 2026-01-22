/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, seed, a, b, c;
    while (cin >> N >> seed >> a >> b >> c) {
        vector<int> conjunto(N);
        conjunto[0] = seed;
        for (int i = 1; i < N; ++i) {
            conjunto[i] = (conjunto[i - 1] * a + b) % c;
        }
        
        long long totalSum = 0;
        for (int num : conjunto) totalSum += num;

        priority_queue<int, vector<int>, greater<int>> minHeap(conjunto.begin(), conjunto.end());
        long long minCost = 0;
        
        while (minHeap.size() > 1) {
            int first = minHeap.top(); minHeap.pop();
            int second = minHeap.top(); minHeap.pop();
            int sum = first + second;
            minCost += sum;
            minHeap.push(sum);
        }

        cout << totalSum << " " << minCost << endl;
    }
    return 0;
}
