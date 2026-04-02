/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int solve(int n) {
    if (n < 0) {
        if (n > -10) return -n;
        return solve(n / 10);
    }
    int first = (n < 10) ? n : solve(-(n / 10));
    if (first % 2 == 0) {
        return n + 2;
    } else {
        return n + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (cin >> n) {
        cout << solve(n) << endl;
    }
    return 0;
}