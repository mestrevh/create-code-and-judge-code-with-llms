/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> c(24);
    auto idx = [&](int face, int r, int col) {
        return face * 4 + r * 2 + col;
    };

    for (int f = 0; f < 6; f++)
        for (int r = 0; r < 2; r++)
            for (int col = 0; col < 2; col++)
                c[idx(f, r, col)] = f;

    auto rotCW = [&](int face) {
        int a = idx(face, 0, 0);
        int b = idx(face, 0, 1);
        int d = idx(face, 1, 0);
        int e = idx(face, 1, 1);
        int temp = c[a];
        c[a] = c[d];
        c[d] = c[e];
        c[e] = c[b];
        c[b] = temp;
    };

    auto rotCCW = [&](int face) {
        int a = idx(face, 0, 0);
        int b = idx(face, 0, 1);
        int d = idx(face, 1, 0);
        int e = idx(face, 1, 1);
        int temp = c[a];
        c[a] = c[b];
        c[b] = c[e];
        c[e] = c[d];
        c[d] = temp;
    };

    auto applyMove = [&](char m) {
        bool prime = false;
        if (m == 'D') prime = false;
        int fU = 0, fD = 1, fF = 2, fB = 3, fL = 4, fR = 5;

        if (m == 'U') {
            rotCCW(fU);
            int U0 = c[idx(fU,0,0)], U1 = c[idx(fU,0,1)], U2 = c[idx(fU,1,0)], U3 = c[idx(fU,1,1)];
            (void)U0; (void)U1; (void)U2; (void)U3;

            int F0 = c[idx(fF,0,0)], F1 = c[idx(fF,0,1)];
            int R0 = c[idx(fR,0,0)], R1 = c[idx(fR,0,1)];
            int B0 = c[idx(fB,0,0)], B1 = c[idx(fB,0,1)];
            int L0 = c[idx(fL,0,0)], L1 = c[idx(fL,0,1)];

            c[idx(fF,0,0)] = R0;
            c[idx(fF,0,1)] = R1;

            c[idx(fR,0,0)] = B0;
            c[idx(fR,0,1)] = B1;

            c[idx(fB,0,0)] = L0;
            c[idx(fB,0,1)] = L1;

            c[idx(fL,0,0)] = F0;
            c[idx(fL,0,1)] = F1;
        } else if (m == 'D') {
            rotCW(fD);

            int F0 = c[idx(fF,1,0)], F1 = c[idx(fF,1,1)];
            int L0 = c[idx(fL,1,0)], L1 = c[idx(fL,1,1)];
            int B0 = c[idx(fB,1,0)], B1 = c[idx(fB,1,1)];
            int R0 = c[idx(fR,1,0)], R1 = c[idx(fR,1,1)];

            c[idx(fF,1,0)] = L0;
            c[idx(fF,1,1)] = L1;

            c[idx(fL,1,0)] = B0;
            c[idx(fL,1,1)] = B1;

            c[idx(fB,1,0)] = R0;
            c[idx(fB,1,1)] = R1;

            c[idx(fR,1,0)] = F0;
            c[idx(fR,1,1)] = F1;
        } else if (m == 'F') {
            rotCW(fF);

            int U0 = c[idx(fU,1,0)], U1 = c[idx(fU,1,1)];
            int R0 = c[idx(fR,0,0)], R1 = c[idx(fR,1,0)];
            (void)R0;

            int R00 = c[idx(fR,0,0)], R10 = c[idx(fR,1,0)];
            int R01 = c[idx(fR,0,1)], R11 = c[idx(fR,1,1)];
            (void)R10; (void)R01; (void)R11;

            int R0c0 = c[idx(fR,0,0)];
            int R1c0 = c[idx(fR,1,0)];

            int D0 = c[idx(fD,0,0)], D1 = c[idx(fD,0,1)];
            int L0c1 = c[idx(fL,0,1)], L1c1 = c[idx(fL,1,1)];

            c[idx(fR,0,0)] = U0;
            c[idx(fR,1,0)] = U1;

            c[idx(fD,0,0)] = R1c0;
            c[idx(fD,0,1)] = R0c0;

            c[idx(fL,0,1)] = D0;
            c[idx(fL,1,1)] = D1;

            c[idx(fU,1,0)] = L1c1;
            c[idx(fU,1,1)] = L0c1;
        } else if (m == 'B') {
            rotCCW(fB);

            int U0 = c[idx(fU,0,0)], U1 = c[idx(fU,0,1)];
            int L0c0 = c[idx(fL,0,0)], L1c0 = c[idx(fL,1,0)];
            int D0 = c[idx(fD,1,0)], D1 = c[idx(fD,1,1)];
            int R0c1 = c[idx(fR,0,1)], R1c1 = c[idx(fR,1,1)];

            c[idx(fL,0,0)] = U0;
            c[idx(fL,1,0)] = U1;

            c[idx(fD,1,0)] = L1c0;
            c[idx(fD,1,1)] = L0c0;

            c[idx(fR,0,1)] = D0;
            c[idx(fR,1,1)] = D1;

            c[idx(fU,0,0)] = R1c1;
            c[idx(fU,0,1)] = R0c1;
        } else if (m == 'L') {
            rotCCW(fL);

            int U0 = c[idx(fU,0,0)], U2 = c[idx(fU,1,0)];
            int F0 = c[idx(fF,0,0)], F2 = c[idx(fF,1,0)];
            int D0 = c[idx(fD,0,0)], D2 = c[idx(fD,1,0)];
            int B3 = c[idx(fB,1,1)], B1 = c[idx(fB,0,1)];

            c[idx(fF,0,0)] = U0;
            c[idx(fF,1,0)] = U2;

            c[idx(fD,0,0)] = F0;
            c[idx(fD,1,0)] = F2;

            c[idx(fB,0,1)] = D2;
            c[idx(fB,1,1)] = D0;

            c[idx(fU,0,0)] = B3;
            c[idx(fU,1,0)] = B1;
        } else if (m == 'R') {
            rotCW(fR);

            int U1 = c[idx(fU,0,1)], U3 = c[idx(fU,1,1)];
            int F1 = c[idx(fF,0,1)], F3 = c[idx(fF,1,1)];
            int D1 = c[idx(fD,0,1)], D3 = c[idx(fD,1,1)];
            int B0 = c[idx(fB,0,0)], B2 = c[idx(fB,1,0)];

            c[idx(fF,0,1)] = U1;
            c[idx(fF,1,1)] = U3;

            c[idx(fD,0,1)] = F1;
            c[idx(fD,1,1)] = F3;

            c[idx(fB,0,0)] = D3;
            c[idx(fB,1,0)] = D1;

            c[idx(fU,0,1)] = B0;
            c[idx(fU,1,1)] = B2;
        }
    };

    string s, all;
    while (cin >> s) {
        for (char ch : s) {
            if (ch=='U'||ch=='D'||ch=='L'||ch=='R'||ch=='F'||ch=='B') all.push_back(ch);
            else if (ch=='u'||ch=='d'||ch=='l'||ch=='r'||ch=='f'||ch=='b') {
                all.push_back((char)toupper(ch));
            }
        }
    }

    for (char m : all) applyMove(m);

    for (int f = 0; f < 6; f++) {
        for (int r = 0; r < 2; r++) {
            for (int col = 0; col < 2; col++) {
                cout << c[idx(f,r,col)];
            }
            cout << "\n";
        }
    }

    return 0;
}