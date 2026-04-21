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
    while ( (cin >> N) ) {
        if (N == 0) break;
        long long left = LLONG_MIN, top = LLONG_MIN;
        long long right = LLONG_MAX, bottom = LLONG_MAX;

        for (int i = 0; i < N; i++) {
            long long X, Y, U, V;
            cin >> X >> Y >> U >> V;
            long long l = min(X, U);
            long long r = max(X, U);
            long long t = min(Y, V);
            long long b = max(Y, V);

            left = max(left, l);
            right = min(right, r);
            top = max(top, t);
            bottom = min(bottom, b);
        }

        cout << "Teste " << tc++ << "\n";
        if (left <= right && top <= bottom) {
            cout << left << " " << top << " " << right << " " << bottom << "\n\n";
        } else {
            cout << "nenhum\n\n";
        }
    }
    return 0;
}