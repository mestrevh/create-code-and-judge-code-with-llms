/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    for (int t = 0; t < T; ++t) {
        if (t > 0) cout << "\n";

        int N, H;
        if (!(cin >> N >> H)) break;

        string s = "";
        for (int i = 0; i < N - H; ++i) s += '0';
        for (int i = 0; i < H; ++i) s += '1';

        do {
            cout << s << "\n";
        } while (next_permutation(s.begin(), s.end()));
    }

    return 0;
}