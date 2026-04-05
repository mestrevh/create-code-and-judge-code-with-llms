/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int,int>> v(4), l(3);
    for (int i = 0; i < 4; i++) {
        int a, b;
        if (!(cin >> a >> b)) return 0;
        v[i] = {a, b};
    }
    for (int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;
        l[i] = {a, b};
    }

    vector<int> C(3);
    for (int i = 0; i < 3; i++) cin >> C[i];

    int currentRight = -1;
    auto normalize = [&](int a, int b, int val, bool &oriented) -> pair<int,int> {
        if (a == val) { oriented = false; return {a,b}; }
        if (b == val) { oriented = true; return {b,a}; }
        return {-1,-1};
    };

    auto findVitorsPiece = [&](int idx, int &left, int &right) -> void {
        left = v[idx].first;
        right = v[idx].second;
    };

    vector<bool> usedV(4,false), usedL(3,false);
    for (int i = 0; i < 3; i++) {
        int idx = C[i];
        usedV[idx] = true;
        int a = v[idx].first, b = v[idx].second;

        int need = (currentRight == -1 ? a : currentRight);
        if (currentRight == -1) {
            currentRight = b;
        } else {
            if (a == need) currentRight = b;
            else currentRight = a;
        }

        int chosen = -1;
        int X = -1, Y = -1;

        for (int j = 0; j < 3; j++) {
            if (usedL[j]) continue;
            int a2 = l[j].first, b2 = l[j].second;
            if (currentRight == -1) {
                chosen = j;
                X = a2; Y = b2;
                usedL[j] = true;
                break;
            } else {
                int need2;
                if (a == v[idx].first && b == v[idx].second) need2 = (currentRight == b ? a : b);
                else need2 = a;
                (void)need2;

                int matchVal = currentRight;
                if (a2 == matchVal) {
                    chosen = j;
                    X = a2; Y = b2;
                    usedL[j] = true;
                    break;
                }
                if (b2 == matchVal) {
                    chosen = j;
                    X = b2; Y = a2;
                    usedL[j] = true;
                    break;
                }
            }
        }

        if (i == 0 && currentRight != -1) {
            int needFirst = v[C[0]].second;
            chosen = -1;
            usedL.assign(3,false);
            (void)chosen;
            (void)needFirst;
        }

        if (chosen == -1) {
            for (int j = 0; j < 3; j++) {
                if (usedL[j]) continue;
                chosen = j;
                X = l[j].first; Y = l[j].second;
                usedL[j] = true;
                break;
            }
        }

        cout << X << "-" << Y << " " << (chosen + 1) << "\n";
        if (currentRight == X) currentRight = Y;
        else currentRight = X;
    }

    return 0;
}