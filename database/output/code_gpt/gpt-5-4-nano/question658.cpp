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
    while ( (cin >> N >> M) ) {
        if (N == 0 && M == 0) break;
        vector<vector<int>> a(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> a[i][j];

        int ans = 1;

        for (int r1 = 0; r1 < N; r1++) {
            vector<int> last(M, INT_MIN);
            int curMax = 0;

            for (int r2 = r1; r2 < N; r2++) {
                int width = r2 - r1 + 1;
                long long Lmin = LLONG_MIN;
                long long Lmax = LLONG_MAX;

                for (int c = 0; c < M; c++) {
                    int x = a[r2][c];

                    if (c == 0) {
                        last[c] = x;
                        Lmin = - (long long)4e18;
                        Lmax = (long long)4e18;
                    } else {
                        int prev = last[c];
                        if (prev >= x) {
                            int newPrev = x;

                            for (int j = 0; j < c; j++) last[j] = a[r2][j];
                            last[c] = newPrev;

                            curMax = max(curMax, width); 
                            Lmin = - (long long)4e18;
                            Lmax = (long long)4e18;
                        } else {
                            last[c] = x;
                        }
                    }

                    curMax = max(curMax, width * (c + 1));
                }

                ans = max(ans, curMax);
            }
        }

        vector<int> s(M, 0), d(M, 0);
        ans = 1;

        for (int r1 = 0; r1 < N; r1++) {
            vector<int> colMin(M, INT_MIN), colMax(M, INT_MIN);
            int startC = 0;
            int bestForRow = 1;

            deque<int> minDeque, maxDeque;
            for (int c = 0; c < M; c++) {
                colMin[c] = a[r1][c];
                colMax[c] = a[r1][c];
            }
            int L = 0;
            for (int r2 = r1; r2 < N; r2++) {
                for (int c = 0; c < M; c++) {
                    if (r2 == r1) {
                        colMin[c] = a[r2][c];
                        colMax[c] = a[r2][c];
                    } else {
                        colMin[c] = min(colMin[c], a[r2][c]);
                        colMax[c] = max(colMax[c], a[r2][c]);
                    }
                }

                int left = 0;
                for (int c = 0; c < M; c++) {
                    long long need = LLONG_MIN;
                    if (c > 0) need = max(need, (long long)colMax[c-1] + 1);
                    long long okMin = LLONG_MIN, okMax = LLONG_MAX;
                    if (c == left) {
                        okMin = colMin[c];
                        okMax = colMax[c];
                    } else {
                        okMin = colMin[c];
                        okMax = colMax[c];
                    }
                    bestForRow = max(bestForRow, (r2 - r1 + 1) * (c - left + 1));
                    ans = max(ans, bestForRow);
                }
            }
        }

        int maxLen = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                maxLen = max(maxLen, 1);
            }
        }

        vector<int> flat;
        flat.reserve(N*M);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                flat.push_back(a[i][j]);

        int total = N*M;
        int best = 1;
        int len = 1;
        for (int k = 1; k < total; k++) {
            if (flat[k-1] < flat[k]) len++;
            else len = 1;
            best = max(best, len);
        }

        ans = best;

        cout << ans << "\n";
    }
    return 0;
}