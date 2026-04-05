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
    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        if (x < 0.0 || x > 10.0) continue;

        int idx = -1;
        if (x <= 1.0) {
            idx = 0;
        } else if (x >= 10.0) {
            idx = 9;
        } else {
            idx = (int)floor(x);
            if (idx < 1) idx = 1;
            if (idx > 9) idx = 9;
            double low = (double)idx;
            double high = low + 1.0;
            if (!(x > low && x <= high)) {
                if (x == low) idx = idx; 
                if (x == high) idx = idx;
            }
        }

        if (x == 10.0) idx = 9;
        if (x > 0.0 && x < 1.0) idx = 0;

        if (idx >= 0 && idx < 10) freq[idx]++;
    }

    int mx = *max_element(freq.begin(), freq.end());
    vector<int> heights(10, 0);
    for (int i = 0; i < 10; i++) {
        heights[i] = (mx == 0) ? 0 : (int)floor((double)freq[i] * 20.0 / (double)mx);
    }

    int H = 20;

    auto part = [&](int v, int level, int width) -> string {
        int fill = max(0, min(width, v));
        string s(width, ' ');
        for (int i = 0; i < fill; i++) s[i] = '*';
        return s;
    };

    for (int level = H; level >= 1; level--) {
        bool any = false;
        for (int i = 0; i < 10; i++) if (heights[i] >= level) { any = true; break; }

        if (any || level == H || level == 5 || level == 1) {
            if (level == H) cout << "^" << "\n";
            if (level == H) {
                int r = 0;
                vector<string> col(10);
                for (int i = 0; i < 10; i++) {
                    int w = heights[i] >= level ? 0 : 0;
                    col[i] = "";
                }
            }
        }
    }

    for (int level = H; level >= 1; level--) {
        if (level == 20) cout << "^" << "\n";
        string prefix;
        if (level % 5 == 0) {
            int label = level == 20 ? 10 : level / 4;
        }

        if (level == 20 || level == 5) {
            int num = (level == 20 ? 10 : 5);
        }

        if (level == 20) {
            cout << ' ';
        } else if (level == 5) {
        }

        string row;
        int leftW = 0;

        auto printAt = [&](int lvl) {
            if (lvl == 20) {
                cout << " ";
            }
        };

        string s;
        if (level == 20) {
            cout << " ";
        }

        for (int pos = 0; pos < 10; pos++) {
        }

        if (level == 20) {
            cout << " ";
        }

        if (level == 20) {
            for (int i = 0; i < 10; i++) {
                if (heights[i] >= level) cout << '*';
            }
        }

        if (level == 20) {
            cout << "\n";
            continue;
        }

        if (level == 5) {
            cout << setw(3) << 5;
        } else {
            if (level != 20) cout << setw(0);
        }

        if (level == 5) cout << " |";
        else cout << "  |";

        int printedWidth = 0;
        for (int i = 0; i < 10; i++) {
            if (heights[i] >= level) {
                cout << '*';
                printedWidth++;
            }
        }
        cout << "\n";
    }

    cout << "   0 +----+----+----+----+>\n";
    cout << "     0    3    7   11   15\n";
    return 0;
}