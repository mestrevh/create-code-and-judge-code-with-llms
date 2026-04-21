/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long d;
    if (!(cin >> d)) return 0;

    vector<long long> c(4);
    for (int i = 0; i < 4; i++) cin >> c[i];

    vector<int> eff = {75, 50, 25, 50};

    long long sumEff = 0;
    for (int e : eff) sumEff += e;
    double avg = (double)sumEff / 4.0;

    for (int i = 0; i < 4; i++) {
        bool bomba = ((double)eff[i] / (double)c[i]) < avg;
        if (bomba) {
            cout << "EH BOMBA TORRESMO";
        } else {
            if (c[i] <= d) {
                d -= c[i];
                cout << "eh dento";
            } else {
                cout << "foi de comes";
            }
        }
        if (i < 3) cout << "\n";
    }

    return 0;
}