/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double D, R, L, P, G;
    if (!(cin >> D >> R >> L >> P >> G)) return 0;

    if (D <= 1e-9) {
        cout << "Pode viajar." << endl;
        cout << "R$: " << (long long)(R + 0.5) << endl;
        return 0;
    }

    double step = D / (P + 1.0);
    double curr_fuel = L;
    double curr_money = R;
    bool possible = true;

    for (int i = 1; i <= (int)P; ++i) {
        curr_fuel -= step / 10.0;
        if (curr_fuel < -1e-9) {
            possible = false;
            break;
        }

        double dist_to_dest = D - ((double)i * step);
        if (curr_fuel * 10.0 < dist_to_dest - 1e-9) {
            double needed_fuel_for_finish = dist_to_dest / 10.0;
            double target_fuel = min(L, needed_fuel_for_finish);
            double amount_to_buy = target_fuel - curr_fuel;

            if (amount_to_buy > 1e-9) {
                if (G > 1e-9) {
                    double cost = amount_to_buy * G;
                    if (cost > curr_money + 1e-9) {
                        double buy = curr_money / G;
                        curr_fuel += buy;
                        curr_money = 0;
                    } else {
                        curr_fuel += amount_to_buy;
                        curr_money -= cost;
                    }
                } else {
                    curr_fuel += amount_to_buy;
                }
            }
        }
    }

    if (possible) {
        curr_fuel -= step / 10.0;
        if (curr_fuel < -1e-9) {
            possible = false;
        }
    }

    if (possible) {
        cout << "Pode viajar." << endl;
        cout << "R$: " << (long long)(curr_money + 0.5) << endl;
    } else {
        cout << "Nao pode viajar." << endl;
    }

    return 0;
}