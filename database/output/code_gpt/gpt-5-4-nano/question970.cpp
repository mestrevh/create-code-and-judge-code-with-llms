/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    if (!getline(cin, A)) return 0;
    if (!getline(cin, B)) return 0;

    int n = (int)A.size();
    int m = (int)B.size();

    vector<vector<int>> pos(m + 1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[j] == B[i]) pos[i].push_back(j);
        }
    }

    vector<int> choose(m, -1);
    bool any = false;

    function<void(int,int)> dfs = [&](int i, int start) {
        if (i == m) {
            for (int k = 0; k < m; k++) {
                if (k) cout << ' ';
                cout << choose[k] + 1;
            }
            cout << "\n";
            any = true;
            return;
        }

        for (int j = start; j < n; j++) {
            if (A[j] == B[i]) {
                choose[i] = j;
                dfs(i + 1, j + 1);
            }
        }
    };

    dfs(0, 0);

    if (!any) cout << -1 << "\n";
    return 0;
}