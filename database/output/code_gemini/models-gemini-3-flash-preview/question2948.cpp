/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double min_time = 1e18;
    int best_x = -1;
    int best_y = -1;
    char c;

    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x < 10; ++x) {
            if (!(cin >> c)) break;
            if (c == '*') continue;

            double dist = sqrt((double)x * x + (double)y * y);
            double time = dist * 20.0;
            if (c == '0') {
                time += 40.0;
            }

            if (time < min_time - 1e-9) {
                min_time = time;
                best_x = x;
                best_y = y;
            } else if (abs(time - min_time) < 1e-9) {
                if (y < best_y) {
                    best_x = x;
                    best_y = y;
                }
            }
        }
    }

    if (best_x == -1) {
        cout << "Tristemente voce vai ter que aturar os PCs do grad 4" << endl;
    } else {
        cout << "Vai la pro computador " << best_x << " da fileira " << best_y << endl;
    }

    return 0;
}

