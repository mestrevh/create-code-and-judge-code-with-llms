/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, g, p;
    if (!(cin >> a >> g >> p)) return 0;

    long long curr_p = 0;
    long long curr_v = 0;
    long long curr_g = g;
    bool reached = (curr_p >= p);

    while (!reached && curr_g >= 0) {
        curr_v += a;
        if (curr_v > 0) {
            if (curr_g < curr_v) {
                if (curr_g >= p - curr_p) {
                    reached = true;
                }
                curr_p += curr_v;
                curr_g -= curr_v;
                break;
            }
            curr_p += curr_v;
            curr_g -= curr_v;
            if (curr_p >= p) {
                reached = true;
            }
        } else if (a == 0 && curr_v == 0) {
            break;
        }
    }

    cout << curr_p << "\n";
    if (reached) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }

    return 0;
}