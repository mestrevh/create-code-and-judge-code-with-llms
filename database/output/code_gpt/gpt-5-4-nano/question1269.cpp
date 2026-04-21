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
    if (!(cin >> N)) return 0;
    int L = 2 * N - 1;
    
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            int d1 = j - (L - 1 - i);
            int d2 = j - i;
            if (abs(d1) == 0 || abs(d2) == 0) cout << '.';
            else if (abs(d1) <= 0 || abs(d2) <= 0) cout << '.';
        }
        cout << "\n";
    }
    
    return 0;
}