/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <cmath>

int main() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    int team1a = A + B;
    int team1b = C + D;
    int team2a = A + C;
    int team2b = B + D;
    int team3a = A + D;
    int team3b = B + C;

    int diff1 = std::abs(team1a - team1b);
    int diff2 = std::abs(team2a - team2b);
    int diff3 = std::abs(team3a - team3b);

    int minDiff = std::min({diff1, diff2, diff3});
    std::cout << minDiff << std::endl;

    return 0;
}
