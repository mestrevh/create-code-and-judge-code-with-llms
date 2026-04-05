/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    char C;
    if (!(cin >> N)) return 0;
    cin >> C;

    if (N < 2) {
        cout << "Fica muito feio, meu senhor.";
        return 0;
    }

    int rows = (int)(N + N - 1); // 2N-1

    auto idx = [&](int a, int b) { return a; };
    (void)idx;

    vector<string> X(rows, "");
    int totalCols = (int)(N * 2 - 1);

    for (int r = 0; r < rows; r++) {
        string row;
        if (r < N) {
            int d = r; // distance from top
            int left = d;
            int right = (int)(N - 1 - d);
            if (N % 2 == 0) {
                int midA = N/2 - 1;
                int midB = N/2;
                if (d == midA) {
                    left = midA;
                    right = midA + 1;
                }
                if (d == midB) {
                    left = midB;
                    right = midB + 1;
                }
                left = r;
                right = (N - 1 - r);
                int L = left;
                int R = right;
                int s = R - L;
                int startLeft = L;
                int startRight = R;
                if (startLeft == startRight) {
                    row.assign(totalCols, ' ');
                    row[startLeft] = C;
                } else {
                    row.assign(totalCols, ' ');
                    row[startLeft] = C;
                    row[startRight] = C;
                    if (s == 1 && (N % 2 == 0)) row[startLeft+1] = C;
                }
            } else {
                left = r;
                right = (N - 1 - r);
                row.assign(totalCols, ' ');
                row[left] = C;
                row[right] = C;
            }
        } else {
            int rr = r - (N - 1);
            int d = rr;
            int left = d;
            int right = (int)(N - 1 - d);
            row.assign(totalCols, ' ');
            row[left] = C;
            row[right] = C;
        }

        int last = -1;
        for (int i = 0; i < totalCols; i++) if (row[i] != ' ') last = i;
        if (last == -1) X[r] = "";
        else X[r] = row.substr(0, last + 1);
    }

    // Above X generation is complex and might not match examples.
    // Let's implement direct based on geometry described:
    // Width between top points is N. Columns coordinates: choose top endpoints at 0 and N-1.
    // Y center depends on parity: not required for X? But shape must match examples.
    // We'll model using X diagonals crossing at middle:
    // For row i from 0..N-1: points are at (i) and (N-1-i), and if N even, at i==N/2-1 and i==N/2-? creates 2 center points -> naturally handled when columns coincide? Actually for even N, (i) and (N-1-i) never coincide; they are adjacent when i = N/2 -1 => positions N/2-1 and N/2.
    // Then bottom part is identical inverted: for row i from 0..N-2: points at (i) and (N-1-i) with rows N..2N-2.
    // This matches examples.
    // Therefore override X construction simply.
    X.assign(rows, "");
    for (int r = 0; r < rows; r++) {
        int i = (r < N) ? r : (rows - 1 - r);
        int left = i;
        int right = (int)(N - 1 - i);
        int maxCol = (int)(N * 2 - 2);
        string row(maxCol + 1, ' ');
        row[left] = C;
        row[right] = C;
        int last = max({left, right});
        row = row.substr(0, last + 1);
        X[r] = row;
    }

    // Y: for top part (rows 0..N-1): diagonals from top endpoints to center.
    // For bottom part (rows N..2N-2): leg goes down from center.
    vector<string> Y(rows, "");
    for (int r = 0; r < rows; r++) {
        int maxCol = (int)(N * 2 - 2);
        string row(maxCol + 1, ' ');
        if (r < N) {
            int i = r;
            int left = i;
            int right = (int)(N - 1 - i);
            row[left] = C;
            row[right] = C;
        } else {
            int k = r - (N - 1); // 1..N-1
            long long leg = N / 2;
            if (k <= leg) {
                if (N % 2 == 1) {
                    int mid = (int)(N / 2);
                    row[mid] = C;
                } else {
                    int midL = (int)(N / 2 - 1);
                    int midR = (int)(N / 2);
                    row[midL] = C;
                    row[midR] = C;
                }
            }
        }
        int last = -1;
        for (int i = 0; i <= maxCol; i++) if (row[i] != ' ') last = i;
        if (last == -1) Y[r] = "";
        else Y[r] = row.substr(0, last + 1);
    }

    for (int r = 0; r < rows; r++) cout << X[r] << "\n";
    cout << "\n";
    for (int r = 0; r < rows; r++) {
        if (!Y[r].empty()) cout << Y[r] << "\n";
    }
    return 0;
}