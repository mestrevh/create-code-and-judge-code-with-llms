/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int max_beads = 0;

    for (int i = 0; i < n; ++i) {
        
        int count_right_r = 0;
        for (int j = 0; j < n; ++j) {
            char bead = s[(i + j) % n];
            if (bead == 'b') {
                break;
            }
            count_right_r++;
        }

        int count_right_b = 0;
        for (int j = 0; j < n; ++j) {
            char bead = s[(i + j) % n];
            if (bead == 'r') {
                break;
            }
            count_right_b++;
        }

        int count_left_r = 0;
        for (int j = 1; j <= n; ++j) {
            char bead = s[(i - j + n) % n];
            if (bead == 'b') {
                break;
            }
            count_left_r++;
        }

        int count_left_b = 0;
        for (int j = 1; j <= n; ++j) {
            char bead = s[(i - j + n) % n];
            if (bead == 'r') {
                break;
            }
            count_left_b++;
        }

        int collected = std::max(count_left_r, count_left_b) + std::max(count_right_r, count_right_b);

        if (collected > n) {
            collected = n;
        }

        if (collected > max_beads) {
            max_beads = collected;
        }
    }

    std::cout << max_beads << std::endl;

    return 0;
}
