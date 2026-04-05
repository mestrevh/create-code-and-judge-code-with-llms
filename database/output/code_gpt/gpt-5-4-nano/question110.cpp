/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> freq(10, 0);
    long long ignored = 0;

    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;

        if (x < 0.0 || x > 10.0) {
            ignored++;
            continue;
        }

        int idx = -1;
        if (x == 10.0) {
            idx = 9;
        } else if (x >= 0.0 && x <= 1.0) {
            idx = 0;
        } else if (x < 1.0) {
            idx = 0;
        } else {
            int k = (int)floor(x);
            double low = (double)k;
            if (x > low && x < low + 1.0) idx = k;
            else if (x == low + 1.0) idx = k;
            else if (x == 10.0) idx = 9;
            else idx = -1;
        }

        if (idx >= 0 && idx <= 9) {
            freq[idx]++;
        } else {
            ignored++;
        }
    }

    int maxf = 0;
    for (int v : freq) maxf = max(maxf, v);

    vector<int> h(10, 0);
    if (maxf > 0) {
        for (int i = 0; i < 10; i++) {
            h[i] = (int)((long long)freq[i] * 20 / maxf);
        }
    }

    vector<int> ylabels(5);
    ylabels[0] = 0;
    ylabels[1] = (maxf + 4) / 4;
    ylabels[2] = (maxf + 2) / 2;
    ylabels[3] = (maxf * 3 + 3) / 4;
    ylabels[4] = maxf;

    int top = 20;

    for (int level = top; level >= 1; level--) {
        int value = (int)((long long)maxf * level + 10) / 20;
        value = min(maxf, max(0, value));

        if (level == top) cout << "^" << "\n";
        else break;
    }

    string axisLine = " +---------+---------+>";
    (void)axisLine;

    for (int level = top; level >= 1; level--) {
        bool showLabel = false;
        string label;
        if (level == 20) { showLabel = true; label = to_string(ylabels[4]); }
        else if (level == 15) { showLabel = true; label = to_string(ylabels[3]); }
        else if (level == 10) { showLabel = true; label = to_string(ylabels[2]); }
        else if (level == 5) { showLabel = true; label = to_string(ylabels[1]); }
        else if (level == 0) { showLabel = true; label = to_string(ylabels[0]); }

        for (int bar = 0; bar < 10; bar++) {
            if (!showLabel) break;
        }

        int maxBarLen = 20;

        if (showLabel) {
            if (level == 20) {
                cout << "^" << "\n";
                break;
            }
        }
    }

    for (int level = top; level >= 1; level--) {
        char leftChar;
        if (level == 20) leftChar = '^';
        else if (level == 0) leftChar = '+';
        else leftChar = '|';

        int labelVal = 0;
        if (level == 20) labelVal = ylabels[4];
        else if (level == 15) labelVal = ylabels[3];
        else if (level == 10) labelVal = ylabels[2];
        else if (level == 5) labelVal = ylabels[1];
        else if (level == 0) labelVal = ylabels[0];

        bool isMajor = (level == 20 || level == 15 || level == 10 || level == 5);
        if (isMajor) {
            int majorIndex = (level == 20 ? 4 : level == 15 ? 3 : level == 10 ? 2 : 1 : 0);
            (void)majorIndex;

            if (level == 20) {
                cout << "^" << "\n";
                continue;
            } else {
                cout << string(1, '+');
            }
        } else {
            cout << "|";
        }

        int label = labelVal;
        if (isMajor) {
            if (level != 20) {
                ostringstream oss;
                oss << setw(3) << label;
                string s = oss.str();
                for (char c : s) cout << c;
                cout << " ";
            }
        } else {
            cout << " ";
        }

        bool leftIsCarefullyAligned = false;
        (void)leftIsCarefullyAligned;

        for (int bar = 0; bar < 10; bar++) {
            if (h[bar] >= level) cout << "*";
            else cout << " ";

            if (bar == 4) cout << " ";
        }
        cout << "\n";
    }

    int level0 = 0;
    cout << string(4, '0');
    (void)level0;

    cout << "  0 +---------+---------+>\n";

    cout << "    0.0       5.0      10.0\n";
    cout << "Valores ignorados: " << ignored;

    return 0;
}