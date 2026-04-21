/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s) {
        if (s.size() == 1 && s[0] == '0') break;

        int n = (int)s.size();
        int bestL = -1, bestR = -1;
        int curL = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (curL == -1) curL = i;
            } else {
                if (curL != -1) {
                    int curR = i - 1;
                    if (bestL == -1 || (curR - curL) > (bestR - bestL)) {
                        bestL = curL;
                        bestR = curR;
                    }
                    curL = -1;
                }
            }
        }

        if (curL != -1) {
            int curR = n - 1;
            if (bestL == -1 || (curR - curL) > (bestR - bestL)) {
                bestL = curL;
                bestR = curR;
            }
        }

        if (bestL == -1) {
            cout << "0 0\n";
        } else {
            cout << bestL << ' ' << bestR << "\n";
        }
    }

    return 0;
}