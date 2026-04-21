/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

const int MAXN = 1001007;
int head[MAXN];
int nxt[MAXN];
int val_at[MAXN];
unsigned char ct[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    for (int i = 0; i < MAXN; ++i) {
        head[i] = -1;
    }

    int last_zero_idx = 0;
    ct[0] = 0;

    for (int n = 1; n <= N; ++n) {
        int count_n = 0;
        int first_i = -1;

        if (last_zero_idx != -1 && n - last_zero_idx <= M) {
            first_i = n - last_zero_idx;
            count_n = 1;
        }

        for (int e = head[n]; e != -1; e = nxt[e]) {
            int i = val_at[e];
            if (first_i == -1) {
                first_i = i;
                count_n = 1;
            } else if (first_i != i) {
                count_n = 2;
                break;
            }
        }

        ct[n] = (unsigned char)count_n;
        if (count_n == 0) {
            last_zero_idx = n;
        } else if (count_n == 1) {
            int target = n + first_i;
            if (target < MAXN) {
                val_at[n] = first_i;
                nxt[n] = head[target];
                head[target] = n;
            }
        }
    }

    if (ct[N] > 0) {
        cout << "Paula" << endl;
    } else {
        cout << "Carlos" << endl;
    }

    return 0;
}