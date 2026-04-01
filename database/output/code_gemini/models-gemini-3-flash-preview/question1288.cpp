/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

typedef long long ll;

ll solve(ll X, ll Q, ll N) {
    if (X >= N) {
        return (X - N) + (X * Q);
    } else {
        return solve(X * Q, Q, N - X);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll X, Q, N;
    if (cin >> X >> Q >> N) {
        cout << solve(X, Q, N) << endl;
    }

    return 0;
}