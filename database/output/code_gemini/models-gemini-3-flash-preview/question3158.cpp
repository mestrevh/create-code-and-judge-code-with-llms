/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double N, X, Y;
    int A, B;

    if (!(cin >> N >> A >> X >> B >> Y)) return 0;

    int gramS = min(A, B);
    double priceS, priceL;

    if (A < B) {
        priceS = X;
        priceL = Y;
    } else {
        priceS = Y;
        priceL = X;
    }

    long long boughtA = (long long)(N / X + 1e-9);
    long long bonusA = boughtA / 5;
    long long totalGramsA = (long long)boughtA * A + (long long)bonusA * gramS;
    long long totalPotsA = boughtA + bonusA;

    long long boughtB = (long long)(N / Y + 1e-9);
    long long bonusB = boughtB / 5;
    long long totalGramsB = (long long)boughtB * B + (long long)bonusB * gramS;
    long long totalPotsB = boughtB + bonusB;

    bool chooseA = true;
    if (totalGramsA > totalGramsB) {
        chooseA = true;
    } else if (totalGramsB > totalGramsA) {
        chooseA = false;
    } else {
        if (totalPotsA < totalPotsB) {
            chooseA = true;
        } else {
            chooseA = false;
        }
    }

    long long curS = 0, curL = 0;
    bool majorityIsSmall = false;

    if (chooseA) {
        if (A < B) {
            curS = boughtA + bonusA;
            curL = 0;
            majorityIsSmall = true;
        } else {
            curL = boughtA;
            curS = bonusA;
            majorityIsSmall = (curS > curL);
        }
    } else {
        if (B < A) {
            curS = boughtB + bonusB;
            curL = 0;
            majorityIsSmall = true;
        } else {
            curL = boughtB;
            curS = bonusB;
            majorityIsSmall = (curS > curL);
        }
    }

    long long currentTotal = curS + curL;
    long long E = (10 - (currentTotal % 10)) % 10;

    if (E > 0) {
        if (priceS < priceL) {
            curS += E;
        } else if (priceL < priceS) {
            curL += E;
        } else {
            if (majorityIsSmall) {
                curS += E;
            } else {
                curL += E;
            }
        }
    }

    cout << curS << " " << curL << " " << E << endl;

    return 0;
}