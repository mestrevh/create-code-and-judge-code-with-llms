/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    while (true) {
        if (!(cin >> N >> M)) return 0;
        if (N == 0 && M == 0) break;

        vector<string> img(N);
        string line;
        for (int i = 0; i < N; i++) {
            cin >> ws;
            getline(cin, line);
            while ((int)line.size() < M) {
                string extra;
                if (!getline(cin, extra)) break;
                if (!extra.empty()) line += extra;
            }
            if ((int)line.size() != M) line = line.substr(0, M);
            img[i] = line;
        }

        int A, B;
        cin >> A >> B;

        int repRow = A / N;
        int repCol = B / M;

        for (int i = 0; i < N; i++) {
            for (int r = 0; r < repRow; r++) {
                string out;
                out.reserve(B);
                for (int j = 0; j < M; j++) {
                    out.append(repCol, img[i][j]);
                }
                cout << out << "\n";
            }
        }
        cout << "\n";
    }

    return 0;
}