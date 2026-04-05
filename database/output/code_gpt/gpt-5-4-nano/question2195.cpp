/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char N, S;
    long long I;
    double VI;
    if (!(cin >> N >> I >> S >> VI)) return 0;

    if (!(I > 0 && I <= 120)) {
        cout << "idade invalida!";
        return 0;
    }

    auto canSell = [&]() -> bool {
        if (N == 'C' || N == 'F') {
            int ageNeed = 21;
            bool adult = I >= ageNeed;
            return adult;
        }
        return true;
    };

    if (!canSell()) {
        cout << "nao pode comprar";
        return 0;
    }

    bool adult21 = I >= 21;
    bool adult18 = I >= 18;
    bool adult16 = I >= 16;

    double bestDiscount = 0.0;

    if (S == 'F') bestDiscount = max(bestDiscount, 10.0);

    if (N == 'B') bestDiscount = max(bestDiscount, 50.0);

    if (N == 'A') {
        if (adult18) {
            if (S == 'F') bestDiscount = max(bestDiscount, 20.0);
        } else {
            bestDiscount = max(bestDiscount, 20.0);
        }
    }

    if (N == 'F' || N == 'C') {
        if (adult21) bestDiscount = max(bestDiscount, 30.0);
    }

    if (N == 'I' || N == 'R') {
        if (adult16) bestDiscount = max(bestDiscount, 30.0);
        else bestDiscount = max(bestDiscount, 40.0);
    }

    double paid = VI * (1.0 - bestDiscount / 100.0);
    cout << "R$ " << fixed << setprecision(2) << paid;
    return 0;
}