/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    int tc = 1;
    while (cin >> N) {
        if (N == 0) break;
        vector<long long> a(N);
        for (int i = 0; i < N; i++) cin >> a[i];
        
        long long winner = -1;
        for (int i = 0; i < N; i++) {
            long long pos = i + 1;
            if (a[i] == pos) {
                winner = a[i];
                break;
            }
        }
        
        cout << "Teste " << tc++ << "\n";
        cout << winner << "\n\n";
    }
    return 0;
}