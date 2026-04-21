/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int N;
ll X, K;
vector<string> names;
ll total_M = 0;

ll solve(int x) {
    if (x >= N) return 0;
    
    // First subordinate (left child)
    ll L = solve(2 * x + 1);
    if (2 * x + 1 < N && L > 0) {
        cout << "Estou dando " << L << " euros a " << names[x] << endl;
    }
    
    // Second subordinate (right child) - only if not enough produced so far
    ll R = 0;
    if (total_M < K) {
        R = solve(2 * x + 2);
        if (2 * x + 2 < N && R > 0) {
            cout << "Estou dando " << R << " euros a " << names[x] << endl;
        }
    }
    
    // Own production - only if not enough produced so far
    ll own = 0;
    if (total_M < K) {
        own = X;
        total_M += X;
    }
    
    // Return total production: 2 * left + right + own
    return 2 * L + R + own;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    if (!(cin >> N)) return 0;
    names.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> names[i];
    }
    if (!(cin >> X >> K)) return 0;
    
    if (N == 0) {
        if (K == 0) cout << "Bom trabalho" << endl;
        else cout << "Precisamos acelerar o processo" << endl;
        return 0;
    }
    
    ll final_result = solve(0);
    cout << "Estou dando " << final_result << " euros a Nairobi" << endl;
    
    if (final_result >= K) {
        cout << "Bom trabalho" << endl;
    } else {
        cout << "Precisamos acelerar o processo" << endl;
    }
    
    return 0;
}