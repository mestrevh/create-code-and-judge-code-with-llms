/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, C, M;
    if (!(cin >> A >> C >> M)) return 0;

    int mA = A / M;
    int rA = A % M;
    int mC = C / M;
    int rC = C % M;

    int mMistas = 0;
    int mAm = 0;
    int mCm = 0;

    // A mixed table is formed if the sum of leftovers equals M,
    // or if both leftovers are even, up to two mixed tables can be formed.
    if (rA > 0 && rC > 0) {
        if (rA + rC == M) {
            mMistas = 1;
            rA = 0;
            rC = 0;
        } else if (rA % 2 == 0 && rC % 2 == 0) {
            // Forming up to two mixed tables by rounding up the sum divided by M.
            // Since rA < M and rC < M, (rA+rC)/M will be at most 1.something, rounding to 2.
            mMistas = (rA + rC + M - 1) / M;
            rA = 0;
            rC = 0;
        }
    }

    // Processing leftovers for adults
    if (rA > 0) {
        // If leftovers < 4, they are included in existing tables if possible.
        if (rA < 4 && mA >= rA) {
            mAm = rA;
            mA -= rA;
        } else {
            // Otherwise, create a new table that counts as a full M-sized table for budget.
            mA++;
        }
    }

    // Processing leftovers for children
    if (rC > 0) {
        if (rC < 4 && mC >= rC) {
            mCm = rC;
            mC -= rC;
        } else {
            mC++;
        }
    }

    // Output based on the calculated counts and specific budget rates (qtd = M).
    if (mA > 0) {
        printf("%d mesas com adultos: R$%d\n", mA, mA * 3 * M);
    }
    if (mAm > 0) {
        printf("%d mesas com adultos+1: R$%d\n", mAm, mAm * 4 * M);
    }
    if (mC > 0) {
        printf("%d mesas com criancas: R$%d\n", mC, mC * 2 * M);
    }
    if (mCm > 0) {
        printf("%d mesas com criancas+1: R$%d\n", mCm, mCm * 3 * M);
    }
    if (mMistas > 0) {
        printf("%d mesas mistas: R$%d\n", mMistas, mMistas * 2 * M);
    }

    return 0;
}