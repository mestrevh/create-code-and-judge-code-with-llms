/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int MAX_M = 5000;
bool is_obstacle[MAX_M + 1] = {false};

bool can_pass(int x, int max_obstacle_pos) {
    int jump_dist = x + 1;
    int search_limit = max_obstacle_pos + jump_dist + 5;
    std::vector<bool> visited(search_limit, false);
    std::queue<int> q;

    if (is_obstacle[0]) {
        return false;
    }

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int current_pos = q.front();
        q.pop();

        if (current_pos > max_obstacle_pos) {
            return true;
        }

        int next_walk = current_pos + 1;
        if (next_walk < search_limit && !visited[next_walk]) {
            bool blocked = (next_walk <= MAX_M) && is_obstacle[next_walk];
            if (!blocked) {
                visited[next_walk] = true;
                q.push(next_walk);
            }
        }

        int next_jump = current_pos + jump_dist;
        if (next_jump < search_limit && !visited[next_jump]) {
            bool blocked = (next_jump <= MAX_M) && is_obstacle[next_jump];
            if (!blocked) {
                visited[next_jump] = true;
                q.push(next_jump);
            }
        }
    }

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int max_obstacle_pos = 0;
    for (int i = 0; i < n; ++i) {
        int m;
        std::cin >> m;
        if (m <= MAX_M) {
            is_obstacle[m] = true;
        }
        if (m > max_obstacle_pos) {
            max_obstacle_pos = m;
        }
    }

    for (int i = 0; i <= max_obstacle_pos; ++i) {
        std::cout << (is_obstacle[i] ? '1' : '0');
    }
    std::cout << '\n';

    for (int x = 1; ; ++x) {
        if (can_pass(x, max_obstacle_pos)) {
            std::cout << "Pulo minimo: " << x << '\n';
            break;
        }
    }

    return 0;
}
