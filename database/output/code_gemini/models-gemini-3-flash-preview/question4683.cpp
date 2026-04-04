/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> mat(n, vector<int>(m));
    vector<bool> active(m, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!(cin >> mat[i][j])) break;
            if (mat[i][j] == 1) {
                active[j] = true;
            }
        }
    }

    struct Segment {
        int s, e;
    };

    vector<Segment> segs;
    for (int j = 0; j < m; j++) {
        if (active[j]) {
            int start = j;
            while (j < m && active[j]) {
                j++;
            }
            segs.push_back({start, j - 1});
        }
    }

    int count = (int)segs.size();
    if (count == 0) {
        cout << "Foram encontrados 0 simbolos!" << endl;
        return 0;
    }

    vector<int> L(count), R(count);
    L[0] = 0;
    R[count - 1] = m - 1;

    for (int i = 0; i < count - 1; i++) {
        int e_curr = segs[i].e;
        int s_next = segs[i + 1].s;
        R[i] = e_curr + (s_next - e_curr) / 2;
        L[i + 1] = R[i] + 1;
    }

    for (int i = 0; i < count; i++) {
        for (int r = 0; r < n; r++) {
            for (int c = L[i]; c <= R[i]; c++) {
                cout << mat[r][c] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    cout << "Foram encontrados " << count << " simbolos!" << endl;

    return 0;
}