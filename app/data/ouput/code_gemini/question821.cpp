/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int L, C;
std::vector<std::string> bitmap;
std::string result;

void solve(int r, int c, int h, int w) {
    if (h <= 0 || w <= 0) {
        return;
    }

    char first = bitmap[r][c];
    bool uniform = true;
    for (int i = r; i < r + h; ++i) {
        for (int j = c; j < c + w; ++j) {
            if (bitmap[i][j] != first) {
                uniform = false;
                break;
            }
        }
        if (!uniform) {
            break;
        }
    }

    if (uniform) {
        result += first;
    } else {
        result += 'D';

        int h1 = (h + 1) / 2;
        int h2 = h / 2;
        int w1 = (w + 1) / 2;
        int w2 = w / 2;

        solve(r, c, h1, w1);
        solve(r, c + w1, h1, w2);
        solve(r + h1, c, h2, w1);
        solve(r + h1, c + w1, h2, w2);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    while (n--) {
        std::cin >> L >> C;
        bitmap.assign(L, std::string(C, ' '));
        for (int i = 0; i < L; ++i) {
            std::cin >> bitmap[i];
        }

        result.clear();
        solve(0, 0, L, C);

        for (size_t i = 0; i < result.length(); ++i) {
            std::cout << result[i];
            if ((i + 1) % 50 == 0) {
                std::cout << "\n";
            }
        }
        if (result.length() % 50 != 0) {
            std::cout << "\n";
        }
    }

    return 0;
}
