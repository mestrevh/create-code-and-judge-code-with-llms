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
    while (cin >> N) {
        if (N == 0) break;
        int scoreA = 0, scoreB = 0;
        for (int i = 0; i < N; i++) {
            int A, B;
            cin >> A >> B;
            if (A > B) scoreA++;
            else if (B > A) scoreB++;
        }
        cout << scoreA << ' ' << scoreB << "\n";
    }
    return 0;
}