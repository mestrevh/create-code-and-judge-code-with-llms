/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <list>
#include <vector>
#include <iterator>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::list<int> balls;
    for (int i = 0; i < n; ++i) {
        int ball_val;
        std::cin >> ball_val;
        balls.push_back(ball_val);
    }

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        int pos;
        int val;
        std::cin >> pos >> val;

        if (balls.empty()) {
            balls.push_back(val);
            continue;
        }

        auto it = balls.begin();
        if (pos > 0) {
            std::advance(it, pos);
        }

        auto new_ball_it = balls.insert(it, val);

        bool should_destroy = false;

        if (new_ball_it != balls.begin()) {
            if (*std::prev(new_ball_it) == val) {
                should_destroy = true;
            }
        }

        auto it_after_new = std::next(new_ball_it);
        if (it_after_new != balls.end()) {
            if (*it_after_new == val) {
                should_destroy = true;
            }
        }

        if (should_destroy) {
            auto start_range = new_ball_it;
            while (start_range != balls.begin() && *std::prev(start_range) == val) {
                --start_range;
            }

            auto end_range = std::next(new_ball_it);
            while (end_range != balls.end() && *end_range == val) {
                ++end_range;
            }

            balls.erase(start_range, end_range);
        }
    }

    if (!balls.empty()) {
        bool first = true;
        for (int ball : balls) {
            if (!first) {
                std::cout << " ";
            }
            std::cout << ball;
            first = false;
        }
    }
    std::cout << std::endl;

    return 0;
}
