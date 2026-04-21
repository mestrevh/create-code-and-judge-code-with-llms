/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mat[605][605];
int is_inc[605][605];
int A[1205];
int L[1205], R[1205], st[1205];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    while (cin >> N >> M && (N != 0 || M != 0)) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> mat[i][j];
            }
        }

        // Precompute the longest increasing sequence length starting at mat[i][j] in row i
        for (int i = 0; i < N; ++i) {
            for (int j = M - 1; j >= 0; --j) {
                if (j == M - 1 || mat[i][j] >= mat[i][j + 1])
                    is_inc[i][j] = 1;
                else
                    is_inc[i][j] = is_inc[i][j + 1] + 1;
            }
        }

        int max_area = 0;
        int K = 2 * N - 1;

        // Iterate over each starting column c1
        for (int c1 = 0; c1 < M; ++c1) {
            // Construct the histogram array A for the current c1
            // A[2*i] = max width of row i starting at c1
            // A[2*i-1] = max width such that the transition from row i-1 to i is valid
            for (int i = 0; i < N; ++i) {
                A[2 * i] = is_inc[i][c1];
                if (i > 0) {
                    int* search_start = mat[i - 1] + c1;
                    int* search_end = search_start + is_inc[i - 1][c1];
                    // Find the largest w such that mat[i-1][c1 + w - 1] < mat[i][c1]
                    int* it = lower_bound(search_start, search_end, mat[i][c1]);
                    A[2 * i - 1] = (int)(it - search_start);
                }
            }

            // Largest Rectangle in Histogram adapted for submatrix rules
            int top = -1;
            for (int i = 0; i < K; ++i) {
                while (top >= 0 && A[st[top]] >= A[i]) top--;
                L[i] = (top < 0) ? 0 : st[top] + 1;
                st[++top] = i;
            }
            top = -1;
            for (int i = K - 1; i >= 0; --i) {
                while (top >= 0 && A[st[top]] >= A[i]) top--;
                R[i] = (top < 0) ? K - 1 : st[top] - 1;
                st[++top] = i;
            }

            for (int i = 0; i < K; ++i) {
                if (A[i] == 0) continue;
                // Identify the effective even indices (rows) in the histogram range
                int l_eff = L[i] + (L[i] % 2);
                int r_eff = R[i] - (R[i] % 2);
                if (l_eff <= r_eff) {
                    int current_h = (r_eff - l_eff) / 2 + 1;
                    int current_area = A[i] * current_h;
                    if (current_area > max_area) max_area = current_area;
                }
            }
        }

        cout << max_area << "\n";
    }

    return 0;
}

