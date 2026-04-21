/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int MAXV = 2048;
    vector<bool> is_prime(MAXV + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= MAXV; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= MAXV; i += p)
                is_prime[i] = false;
        }
    }

    int N;
    if (!(cin >> N)) return 0;
    while (N--) {
        int M;
        if (!(cin >> M)) break;
        double total_reliability = 0;
        for (int k = 0; k < M; k++) {
            int i_val;
            if (!(cin >> i_val)) break;
            int v = abs(i_val);
            if (v <= MAXV && is_prime[v]) {
                total_reliability += 2.0 * i_val;
            } else {
                int D = 0;
                if (v > 1) {
                    for (int d = 1; d <= v; d++) {
                        if (v % d == 0) D++;
                    }
                    D -= 2;
                }
                total_reliability += (i_val * (double)D) / 2.0;
            }
        }

        if (total_reliability > 2048.0) {
            cout << "Anão Paulo. babado." << endl;
        } else if (total_reliability > 512.0) {
            cout << "Para pow." << endl;
        } else if (total_reliability > 0.0) {
            cout << "Se isso não é mentira eu sou uma brastemp 4 portas" << endl;
        } else {
            cout << "que mentirada" << endl;
        }
    }

    return 0;
}