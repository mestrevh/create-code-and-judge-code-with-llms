/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    for (int t = 1; t <= T; ++t) {
        int N;
        if (!(cin >> N)) break;

        long long start_odd = (long long)N * N - N + 1;

        cout << "caso " << t << ":";
        for (int i = 0; i < N; ++i) {
            cout << " " << start_odd + 2LL * i;
        }
        cout << "\n";
    }

    return 0;
}