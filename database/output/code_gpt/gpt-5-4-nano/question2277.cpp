/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<long long> a(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i];

    long long bestSum = LLONG_MIN;
    int bestType = -1; 
    int bestX = 1, bestY = 1;

    auto consider = [&](long long sum, int type, int x, int y) {
        if (sum > bestSum) {
            bestSum = sum;
            bestType = type;
            bestX = x;
            bestY = y;
            return;
        }
        if (sum == bestSum) {
            if (type < bestType) {
                bestType = type;
                bestX = x;
                bestY = y;
                return;
            }
            if (type == bestType) {
                if (type == 0) {
                    int cx = x;
                    int cbx = bestX;
                    if (cx > cbx) {
                        bestX = x;
                        bestY = y;
                    }
                } else {
                    int cx = x, cy = y;
                    int cbx = bestX, cby = bestY;
                    if (cy < cby) {
                        bestX = x;
                        bestY = y;
                    } else if (cy == cby && cx > cbx) {
                        bestX = x;
                        bestY = y;
                    }
                }
            }
        }
    };

    for (int l = 1; l <= N; l++) {
        long long sum = 0;
        for (int r = l; r <= N; r++) {
            sum += a[r];
            consider(sum, 2, l, r);
        }
    }

    long long maxSum = bestSum;
    int outType;
    int X, Y;

    if (maxSum < 0) {
        outType = 0;
    } else {
        outType = 1;
        X = bestX;
        Y = bestY;
        if (X == Y) outType = 1;
    }

    if (maxSum < 0) {
        cout << "E uma armadilha";
    } else {
        if (outType == 1) {
            if (X == Y) {
                cout << "Naruto deve libertar somente a posicao " << X;
            } else {
                cout << "Naruto deve libertar da posicao " << X << " ate a posicao " << Y;
            }
        } else {
            cout << "E uma armadilha";
        }
    }

    return 0;
}