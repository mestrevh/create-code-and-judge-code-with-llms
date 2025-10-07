/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<bool> is_possible(181, false);

    for (int t = 0; t < 720; ++t) {
        int pos_m = t % 60;
        int pos_h = t / 12;

        int diff_marks = std::abs(pos_h - pos_m);
        int min_diff_marks = std::min(diff_marks, 60 - diff_marks);

        int angle = min_diff_marks * 6;
        
        is_possible[angle] = true;
    }

    int A;
    while (std::cin >> A && A != -1) {
        if (is_possible[A]) {
            std::cout << "Y\n";
        } else {
            std::cout << "N\n";
        }
    }

    return 0;
}
