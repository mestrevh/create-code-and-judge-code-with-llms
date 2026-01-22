/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int Q;
    cin >> Q;
    vector<int> results(Q);
    
    for (int q = 0; q < Q; q++) {
        int K;
        cin >> K;
        unordered_map<int, int> remainderCount;
        int pairs = 0;

        for (int i = 0; i < N; i++) {
            int remainder = A[i] % K;
            pairs += remainderCount[(K - remainder) % K];
            remainderCount[remainder]++;
        }
        
        results[q] = pairs;
    }
    
    for (int res : results) {
        cout << res << endl;
    }
    
    return 0;
}
