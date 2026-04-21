/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    string T = "";
    for (int i = 0; i < N; ++i) {
        char D;
        string S;
        cin >> D >> S;
        if (S.length() >= 12) {
            if (D == 'd' || D == 'D') {
                // Right side: indices 0 to 5
                T += S.substr(0, 6);
            } else {
                // Left side: indices 11 down to 6
                string left_half = S.substr(6, 6);
                reverse(left_half.begin(), left_half.end());
                T += left_half;
            }
        }
    }

    string P;
    if (!(cin >> P)) return 0;

    int tn = T.length();
    int pn = P.length();
    int total_count = 0;

    if (tn > 0 && pn > 0) {
        // Search in clockwise direction
        for (int i = 0; i < tn; ++i) {
            bool match = true;
            for (int j = 0; j < pn; ++j) {
                if (T[(i + j) % tn] != P[j]) {
                    match = false;
                    break;
                }
            }
            if (match) total_count++;
        }

        // Search in counter-clockwise direction
        string Trev = T;
        reverse(Trev.begin(), Trev.end());
        for (int i = 0; i < tn; ++i) {
            bool match = true;
            for (int j = 0; j < pn; ++j) {
                if (Trev[(i + j) % tn] != P[j]) {
                    match = false;
                    break;
                }
            }
            if (match) total_count++;
        }
    }

    cout << P << total_count << endl;

    return 0;
}