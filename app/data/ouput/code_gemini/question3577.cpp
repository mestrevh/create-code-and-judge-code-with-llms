/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x, y;
    std::cin >> x >> y;

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int countC = 0;
    int countB = 0;
    int countE = 0;
    int countD = 0;

    for (char move : s) {
        if (move == 'C') {
            countC++;
        } else if (move == 'B') {
            countB++;
        } else if (move == 'E') {
            countE++;
        } else if (move == 'D') {
            countD++;
        }
    }

    bool x_possible = false;
    if (x >= 0) {
        if (countE >= x) {
            x_possible = true;
        }
    } else {
        if (countD >= -x) {
            x_possible = true;
        }
    }

    bool y_possible = false;
    if (y >= 0) {
        if (countB >= y) {
            y_possible = true;
        }
    } else {
        if (countC >= -y) {
            y_possible = true;
        }
    }

    if (x_possible && y_possible) {
        std::cout << "S\n";
    } else {
        std::cout << "N\n";
    }

    return 0;
}
