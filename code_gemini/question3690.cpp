/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <cstdlib>

int sum_digits(int n) {
    n = std::abs(n);
    int sum = 0;
    if (n == 0) return 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool scores_point(int card_value) {
    int s = sum_digits(card_value);
    if (s <= 0) {
        return false;
    }
    int root = static_cast<int>(sqrt(s));
    return root * root != s;
}

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int scoreA = 0;
    int scoreB = 0;

    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;

        if (scores_point(a)) {
            scoreA++;
        }
        if (scores_point(b)) {
            scoreB++;
        }
    }

    int sum_scoreA = sum_digits(scoreA);
    if (is_prime(sum_scoreA)) {
        if (sum_scoreA % 2 == 0) {
            scoreA -= 4;
        } else {
            scoreA += 3;
        }
    }

    int sum_scoreB = sum_digits(scoreB);
    if (is_prime(sum_scoreB)) {
        if (sum_scoreB % 2 == 0) {
            scoreB -= 4;
        } else {
            scoreB += 3;
        }
    }

    if (scoreA == scoreB) {
        scoreA++;
    }

    std::cout << "Quem ganhou foi aquele time.\n";
    std::cout << std::abs(scoreA - scoreB) << "\n";

    return 0;
}
