/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

typedef __int128 int128;

int sum_digits(int128 n) {
    if (n < 0) n = -n;
    int s = 0;
    while (n > 0) {
        s += (int)(n % 10);
        n /= 10;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X_ll;
    int N;
    if (!(cin >> X_ll >> N)) return 0;
    int128 X = X_ll;

    int128 best_diff = -1;
    int best_channel = -1;
    int best_minute = -1;
    int128 best_val = -1;

    for (int c = 1; c <= N; ++c) {
        long long f1_ll, f2_ll;
        if (!(cin >> f1_ll >> f2_ll)) break;
        int128 a = f1_ll;
        int128 b = f2_ll;

        int128 chan_best_diff = -1;
        int chan_best_minute = -1;
        int128 chan_best_val = -1;

        int128 prev_a = 0, prev_b = 0;

        for (int i = 1; i <= 150; ++i) {
            int128 val;
            if (i == 1) {
                val = a;
            } else if (i == 2) {
                val = b;
                prev_a = a;
                prev_b = b;
            } else {
                val = prev_a + prev_b;
                prev_a = prev_b;
                prev_b = val;
            }

            int128 cur_diff = (val > X) ? (val - X) : (X - val);

            if (chan_best_diff == -1 || cur_diff < chan_best_diff) {
                chan_best_diff = cur_diff;
                chan_best_minute = i;
                chan_best_val = val;
            } else if (cur_diff == chan_best_diff) {
                if (val < chan_best_val) {
                    chan_best_val = val;
                    chan_best_minute = i;
                }
            }

            if (i > 2 && val > X && cur_diff > chan_best_diff) break;
            if (i > 2 && val > (int128)4e18 + X) break;
        }

        if (best_channel == -1 || chan_best_diff < best_diff) {
            best_diff = chan_best_diff;
            best_channel = c;
            best_minute = chan_best_minute;
            best_val = chan_best_val;
        } else if (chan_best_diff == best_diff) {
            if (c > best_channel) {
                best_channel = c;
                best_minute = chan_best_minute;
                best_val = chan_best_val;
            }
        }
    }

    bool vip = (sum_digits(best_val) > 10);

    cout << "Xupenio, para ir ao lulupalooza vc deve entrar no canal " << best_channel 
         << " e sera chamado mais ou menos no minuto " << best_minute;
    if (vip) {
        cout << " e com o VIP garantido!!!" << endl;
    } else {
        cout << ", mas o ingresso VIP não vai rolar :(" << endl;
    }

    return 0;
}