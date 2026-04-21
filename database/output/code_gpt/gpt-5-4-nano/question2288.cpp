/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    if (!(cin >> M)) return 0;
    int N;
    cin >> N;
    vector<vector<long long>> A(M, vector<long long>(M));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) cin >> A[i][j];
    }

    vector<vector<char>> selected(M, vector<char>(M, 0));

    vector<vector<long long>> prefRight(M, vector<long long>(M, 0));
    vector<vector<long long>> prefDown(M, vector<long long>(M, 0));
    vector<vector<long long>> diagDownRight(M, vector<long long>(M, 0));

    for (int i = 0; i < M; i++) {
        long long run = 0;
        for (int j = M - 1; j >= 0; j--) {
            if (A[i][j] == -1) run = 0;
            else run += A[i][j];
            prefRight[i][j] = run;
        }
    }

    for (int j = 0; j < M; j++) {
        long long run = 0;
        for (int i = M - 1; i >= 0; i--) {
            if (A[i][j] == -1) run = 0;
            else run += A[i][j];
            prefDown[i][j] = run;
        }
    }

    for (int i = M - 1; i >= 0; i--) {
        for (int j = M - 1; j >= 0; j--) {
            if (A[i][j] == -1) diagDownRight[i][j] = 0;
            else {
                long long v = A[i][j];
                if (i + 1 < M && j + 1 < M) diagDownRight[i][j] = v + diagDownRight[i + 1][j + 1];
                else diagDownRight[i][j] = v;
            }
        }
    }

    auto recomputeAll = [&]() {
        for (int i = 0; i < M; i++) {
            long long run = 0;
            for (int j = M - 1; j >= 0; j--) {
                if (A[i][j] == -1) run = 0;
                else run += A[i][j];
                prefRight[i][j] = run;
            }
        }

        for (int j = 0; j < M; j++) {
            long long run = 0;
            for (int i = M - 1; i >= 0; i--) {
                if (A[i][j] == -1) run = 0;
                else run += A[i][j];
                prefDown[i][j] = run;
            }
        }

        for (int i = M - 1; i >= 0; i--) {
            for (int j = M - 1; j >= 0; j--) {
                if (A[i][j] == -1) diagDownRight[i][j] = 0;
                else {
                    long long v = A[i][j];
                    if (i + 1 < M && j + 1 < M) diagDownRight[i][j] = v + diagDownRight[i + 1][j + 1];
                    else diagDownRight[i][j] = v;
                }
            }
        }
    };

    bool lost = false;
    for (int k = 0; k < N; k++) {
        int x, y;
        cin >> x >> y;

        if (selected[x][y]) {
            cout << "Essa casa ja foi selecionada.\n";
            continue;
        }

        selected[x][y] = 1;

        recomputeAll();

        long long s1 = prefRight[x][y];
        long long s2 = prefDown[x][y];
        long long s3 = diagDownRight[x][y];

        if (s1 == s2 && s2 == s3) {
            cout << "Bomba encontrada.\n";
            cout << "Voce perdeu.\n";
            lost = true;
            break;
        } else {
            cout << "Boa jogada, a casa (" << x << "," << y << ") nao tinha bomba.\n";
            A[x][y] = -1;
        }
    }

    if (!lost) cout << "Voce e uma pessoa de sorte.\n";
    return 0;
}