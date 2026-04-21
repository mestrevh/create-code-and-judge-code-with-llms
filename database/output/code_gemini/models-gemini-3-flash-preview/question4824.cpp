/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int n, b;
char current[15];

void solve(int idx) {
    if (idx == n) {
        cout << current << "\n";
        return;
    }
    for (int i = 0; i < b; ++i) {
        current[idx] = (char)('0' + i);
        solve(idx + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> b)) return 0;

    current[n] = '\0';
    solve(0);

    return 0;
}