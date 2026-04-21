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

    long long total_distance = 0;
    for (int i = 0; i < N; ++i) {
        int T, V;
        cin >> T >> V;
        total_distance += (long long)T * V;
    }

    cout << total_distance << endl;

    return 0;
}