/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    for (int t = 1; t <= T; ++t) {
        int N;
        if (!(cin >> N)) break;

        unordered_map<string, int> dict;
        dict.reserve(N);

        for (int i = 0; i < N; ++i) {
            string w;
            int x;
            cin >> w >> x;
            dict[w] = x;
        }

        int M;
        if (!(cin >> M)) break;

        long long total_time = 0;
        for (int i = 0; i < M; ++i) {
            string s;
            cin >> s;
            auto it = dict.find(s);
            if (it != dict.end()) {
                total_time += it->second;
            }
        }

        cout << "Caso " << t << ": " << total_time << "\n";
    }

    return 0;
}