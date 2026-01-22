/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int N, E;
    cin >> N >> E;
    vector<int> G(N);
    for (int i = 0; i < N; i++) {
        cin >> G[i];
    }
    
    unordered_set<int> seen;
    for (int i = 0; i < N; i++) {
        if (seen.count(E - G[i])) {
            cout << "SIM" << endl;
            return 0;
        }
        seen.insert(G[i]);
    }
    
    cout << "NAO" << endl;
    return 0;
}
