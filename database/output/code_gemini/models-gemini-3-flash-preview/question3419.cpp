/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n <= 0) return 0;

    if (n >= 1) {
        cout << 0 << "\n";
    }
    if (n >= 2) {
        cout << 1 << "\n";
    }

    long long prev2 = 0;
    long long prev1 = 1;

    for (int i = 2; i < n; ++i) {
        long long current = prev1 + prev2;
        cout << current << "\n";
        prev2 = prev1;
        prev1 = current;
    }

    return 0;
}