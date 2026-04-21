/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdio>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        int freq[10] = {0};
        int ignored = 0;
        for (int i = 0; i < n; ++i) {
            double x;
            if (!(cin >> x)) break;
            if (x < 0.0 || x > 10.0) {
                ignored++;
            } else if (x <= 1.0) {
                freq[0]++;
            } else if (x <= 2.0) {
                freq[1]++;
            } else if (x <= 3.0) {
                freq[2]++;
            } else if (x <= 4.0) {
                freq[3]++;
            } else if (x <= 5.0) {
                freq[4]++;
            } else if (x <= 6.0) {
                freq[5]++;
            } else if (x <= 7.0) {
                freq[6]++;
            } else if (x <= 8.0) {
                freq[7]++;
            } else if (x <= 9.0) {
                freq[8]++;
            } else if (x <= 10.0) {
                freq[9]++;
            }
        }

        int max_freq = 0;
        for (int i = 0; i < 10; ++i) {
            if (freq[i] > max_freq) max_freq = freq[i];
        }

        int height[10] = {0};
        if (max_freq > 0) {
            for (int i = 0; i < 10; ++i) {
                height[i] = (int)(freq[i] * 20.0 / max_freq);
            }
        }

        cout << "^" << "\n";
        for (int h = 20; h >= 1; --h) {
            if (h == 20) {
                cout << setw(4) << max_freq << " +";
            } else if (h == 15) {
                cout << setw(4) << (max_freq * 3) / 4 << " +";
            } else if (h == 10) {
                cout << setw(4) << max_freq / 2 << " +";
            } else if (h == 5) {
                cout << setw(4) << max_freq / 4 << " +";
            } else {
                cout << "     |";
            }

            for (int b = 0; b < 10; ++b) {
                if (height[b] >= h) {
                    cout << " *";
                } else {
                    cout << "  ";
                }
            }
            cout << "\n";
        }
        cout << "   0 +---------+---------+>" << "\n";
        cout << "    0.0       5.0      10.0" << "\n";
        cout << "Valores ignorados: " << ignored << "\n";
    }

    return 0;
}