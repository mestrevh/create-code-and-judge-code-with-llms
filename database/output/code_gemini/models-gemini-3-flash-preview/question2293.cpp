/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q, X, C, N, M;
    if (!(cin >> Q >> X >> C >> N >> M)) return 0;

    vector<string> names(C);
    for (int i = 0; i < C; ++i) {
        cin >> names[i];
        for (char &ch : names[i]) {
            ch = (char)tolower((unsigned char)ch);
        }
    }

    int count_keep = 0;
    for (int q = 0; q < Q; ++q) {
        vector<string> grid(N);
        for (int i = 0; i < N; ++i) {
            if (!(cin >> grid[i])) break;
            for (char &ch : grid[i]) {
                ch = (char)tolower((unsigned char)ch);
            }
        }

        int total_occ = 0;
        for (int k = 0; k < C; ++k) {
            const string& name = names[k];
            int nlen = (int)name.length();
            if (nlen == 0) continue;

            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    // Right direction: (0, 1)
                    if (j + nlen <= M) {
                        bool match = true;
                        for (int l = 0; l < nlen; ++l) {
                            if (grid[i][j + l] != name[l]) {
                                match = false;
                                break;
                            }
                        }
                        if (match) total_occ++;
                    }
                    // Left direction: (0, -1)
                    if (j - nlen + 1 >= 0) {
                        bool match = true;
                        for (int l = 0; l < nlen; ++l) {
                            if (grid[i][j - l] != name[l]) {
                                match = false;
                                break;
                            }
                        }
                        if (match) total_occ++;
                    }
                    // Down direction: (1, 0)
                    if (i + nlen <= N) {
                        bool match = true;
                        for (int l = 0; l < nlen; ++l) {
                            if (grid[i + l][j] != name[l]) {
                                match = false;
                                break;
                            }
                        }
                        if (match) total_occ++;
                    }
                    // Up direction: (-1, 0)
                    if (i - nlen + 1 >= 0) {
                        bool match = true;
                        for (int l = 0; l < nlen; ++l) {
                            if (grid[i - l][j] != name[l]) {
                                match = false;
                                break;
                            }
                        }
                        if (match) total_occ++;
                    }
                }
            }
        }

        if (total_occ <= X) {
            count_keep++;
        }
    }

    cout << count_keep << endl;

    return 0;
}