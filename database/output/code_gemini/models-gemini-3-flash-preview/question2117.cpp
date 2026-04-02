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

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<vector<int>> mat(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> mat[i][j];
        }
    }

    long long harvested = 0;
    long long insecticide = 0;
    string cmd;

    while (cin >> cmd) {
        if (cmd == "Plantar") {
            while (cin >> ws && isdigit(cin.peek())) {
                int r;
                if (!(cin >> r)) break;
                if (r >= 0 && r < N) {
                    bool empty = true;
                    for (int j = 0; j < M; ++j) {
                        if (mat[r][j] != 0) {
                            empty = false;
                            break;
                        }
                    }
                    if (empty) {
                        for (int j = 0; j < M; ++j) {
                            mat[r][j] = 1;
                            insecticide += 2;
                        }
                    }
                }
            }
        } else if (cmd == "Temporada") {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    if (mat[i][j] == 1) {
                        mat[i][j] = 2;
                        insecticide += 2;
                    } else if (mat[i][j] == 2) {
                        mat[i][j] = 3;
                    }
                }
            }
        } else if (cmd == "Colher") {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    if (mat[i][j] == 3) {
                        harvested++;
                        mat[i][j] = 0;
                    } else if (mat[i][j] == -1) {
                        mat[i][j] = 0;
                    }
                }
            }
        } else if (cmd == "Ataque") {
            int k, w;
            if (cin >> k >> w) {
                if (k >= 0 && k < N && w >= 0 && w < M) {
                    if (mat[k][w] != 0) {
                        mat[k][w] = -1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << mat[i][j] << (j == M - 1 ? "" : " ");
        }
        cout << "\n";
    }

    cout << "\nForam colhidos " << harvested << " morangos.\n";
    cout << "Foram utilizados " << insecticide << "ml de inseticida.\n";

    return 0;
}

