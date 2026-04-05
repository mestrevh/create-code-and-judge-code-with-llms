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
    cout.setf(std::ios::fixed);
    for (int i = 0; i < N; i++) {
        long double X;
        cin >> X;
        long long days = (long long)ceill(log2(X)) ;
        if (X <= 1.0L) days = 0;
        cout << days << " dias\n";
    }
    return 0;
}