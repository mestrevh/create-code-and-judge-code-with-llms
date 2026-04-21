/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, y;
    if (!(cin >> x >> y)) return 0;

    int count = 0;
    for (long long i = 0; i < x; ++i) {
        long long current;
        if (!(cin >> current)) break;
        if (current == y) {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}
