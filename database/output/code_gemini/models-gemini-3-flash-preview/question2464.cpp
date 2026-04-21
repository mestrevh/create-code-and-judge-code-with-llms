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

    int N;
    if (!(cin >> N)) return 0;

    vector<int> M(N);
    int max_M = 0;
    for (int i = 0; i < N; ++i) {
        cin >> M[i];
        if (M[i] > max_M) max_M = M[i];
    }

    vector<bool> is_obs(max_M + 1, false);
    for (int i = 0; i < N; ++i) {
        if (M[i] >= 0 && M[i] <= max_M) {
            is_obs[M[i]] = true;
        }
    }

    for (int i = 0; i <= max_M; ++i) {
        if (is_obs[i]) cout << '1';
        else cout << '0';
    }
    cout << "\n";

    for (int X = 1; ; ++X) {
        vector<bool> reachable(max_M + 1, false);
        reachable[0] = true;
        bool possible = false;
        
        for (int i = 0; i <= max_M; ++i) {
            if (reachable[i]) {
                // Try walking 1 casa
                int next_walk = i + 1;
                if (next_walk > max_M) {
                    possible = true;
                    break;
                }
                if (!is_obs[next_walk]) {
                    reachable[next_walk] = true;
                }

                // Try jumping X casas (distance X + 1)
                int next_jump = i + X + 1;
                if (next_jump > max_M) {
                    possible = true;
                    break;
                }
                if (!is_obs[next_jump]) {
                    reachable[next_jump] = true;
                }
            }
        }
        
        if (possible) {
            cout << "Pulo minimo: " << X << "\n";
            break;
        }
    }

    return 0;
}