/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int F;
    if (!(cin >> F)) return 0;
    vector<string> names(F);
    for (int i = 0; i < F; i++) cin >> names[i];

    int maxDR = 0;
    for (int i = 0; i < F; i++) {
        for (int j = i; j < F; j++) {
            int cntD = 0, cntR = 0;
            auto add = [&](const string& s) {
                for (char c : s) {
                    if (c == 'D') cntD++;
                    else if (c == 'R') cntR++;
                }
            };

            add(names[i]);
            if (j != i) add(names[j]);

            int k = 0;
            if (cntD > 0 && cntD > cntR) {
                k = cntR + 1;
            } else {
                k = cntD;
            }
            maxDR = max(maxDR, k);
        }
    }

    cout << maxDR << "\n";
    return 0;
}