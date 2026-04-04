/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p;
    if (!(cin >> n >> p)) return 0;

    int invited_count = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        if (!(cin >> x >> y)) break;
        if (x > 0 && y > 0 && (x + y) >= p) {
            invited_count++;
        }
    }

    cout << invited_count << "\n";

    return 0;
}