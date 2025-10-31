/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double N, X, Y;
    int A, B;
    cin >> N >> A >> X >> B >> Y;

    int potsA = 0, potsB = 0;
    double maxGrams = 0.0;
    int totalPots = 0;

    for (int i = 0; i <= N / X; ++i) {
        if (i * X <= N) {
            double remainingMoney = N - i * X;
            int j = remainingMoney / Y;
            double grams = i * A + j * B;
            int potsCount = i + j;
            if (grams > maxGrams || (grams == maxGrams && potsCount < totalPots)) {
                maxGrams = grams;
                potsA = i;
                potsB = j;
                totalPots = potsCount;
            }
        }
    }

    int total = potsA + potsB;
    int remaining = 0;

    if (total % 10 != 0) {
        remaining = 10 - (total % 10);
        double costA = (X / A) * B;
        double costB = (Y / A) * A;

        if (X < Y) {
            potsA += remaining;
        } else if (Y < X) {
            potsB += remaining;
        } else {
            if (potsA > potsB) potsA += remaining;
            else potsB += remaining;
        }
    }

    cout << potsA << " " << potsB << " " << remaining << endl;

    return 0;
}
