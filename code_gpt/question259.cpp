/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>

int main() {
    std::set<int> validAngles;
    for (int m = 0; m < 60; ++m) {
        for (int h = 0; h < 12; ++h) {
            int angle = abs(30 * h - 5.5 * m);
            angle = std::min(angle, 360 - angle);
            validAngles.insert(angle);
        }
    }

    int A;
    while (std::cin >> A && A != -1) {
        if (validAngles.count(A)) {
            std::cout << "Y\n";
        } else {
            std::cout << "N\n";
        }
    }
    return 0;
}
