/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int solve(int n, int t, int step) {
    if (step >= t) {
        return n;
    }
    if (step % 2 == 0) {
        return solve(n + 3, t, step + 1);
    } else {
        return solve(n + (n % 5), t, step + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    if (cin >> n >> t) {
        cout << solve(n, t, 0) << "\n";
    }
    return 0;
}