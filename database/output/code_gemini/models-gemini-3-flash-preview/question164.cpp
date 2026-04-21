/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    long long total_stored = 0;
    for (int i = 0; i < N; ++i) {
        int pieces;
        if (cin >> pieces) {
            total_stored += (pieces - 1);
        }
    }

    cout << total_stored << endl;

    return 0;
}

