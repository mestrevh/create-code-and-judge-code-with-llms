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
    while ( (cin >> N) ) {
        if (N == 0) break;
        for (int i = 0; i < N; i++) {
            int v[5];
            for (int j = 0; j < 5; j++) cin >> v[j];
            vector<int> black;
            for (int j = 0; j < 5; j++) {
                if (v[j] <= 127) black.push_back(j);
            }
            if (black.size() == 1) {
                char ans = char('A' + black[0]);
                cout << ans << "\n";
            } else {
                cout << "*\n";
            }
        }
    }
    return 0;
}