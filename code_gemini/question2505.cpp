/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

int main() {
    fast_io();

    int p, x;
    std::cin >> p >> x;

    std::vector<int> arrayJ(x);
    long long sumJ = 0;
    for (int i = 0; i < x; ++i) {
        std::cin >> arrayJ[i];
        sumJ += arrayJ[i];
    }

    std::vector<int> arrayC(x);
    long long sumC = 0;
    for (int i = 0; i < x; ++i) {
        std::cin >> arrayC[i];
        sumC += arrayC[i];
    }

    if (sumJ >= p || sumC >= p) {
        std::cout << "joey, essas regras estao piores que as do Fireball\n";
        return 0;
    }

    int joey_score = 0;
    int joey_goals = 0;
    int chandler_score = 0;
    int chandler_goals = 0;
    char winner = '\0';

    char goal_char;
    while (std::cin >> goal_char) {
        if (goal_char == 'J') {
            joey_goals++;
            joey_score += arrayJ[(joey_goals - 1) % x];
            if (joey_score >= p) {
                winner = 'J';
                break;
            }
        } else if (goal_char == 'C') {
            chandler_goals++;
            chandler_score += arrayC[(chandler_goals - 1) % x];
            if (chandler_score >= p) {
                winner = 'C';
                break;
            }
        }
    }

    if (winner == 'J') {
        std::cout << "Well, you suck! But at least you suck at a man's game now\n";
        std::cout << "Joey: " << joey_score << " (" << joey_goals << ")\n";
        std::cout << "Chandler: " << chandler_score << " (" << chandler_goals << ")\n";
    } else if (winner == 'C') {
        std::cout << "Good game, good game, good game\n";
        std::cout << "Chandler: " << chandler_score << " (" << chandler_goals << ")\n";
        std::cout << "Joey: " << joey_score << " (" << joey_goals << ")\n";
    }

    return 0;
}
