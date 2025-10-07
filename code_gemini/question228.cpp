/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int n;
std::vector<std::vector<int>> piles;
std::vector<int> block_location;

void find_pos(int block, int& p_idx, size_t& h_idx) {
    p_idx = block_location[block];
    for (size_t i = 0; i < piles[p_idx].size(); ++i) {
        if (piles[p_idx][i] == block) {
            h_idx = i;
            return;
        }
    }
}

void clear_above(int block) {
    int p_idx;
    size_t h_idx;
    find_pos(block, p_idx, h_idx);

    for (size_t i = piles[p_idx].size() - 1; i > h_idx; --i) {
        int block_to_return = piles[p_idx].back();
        piles[p_idx].pop_back();
        piles[block_to_return].push_back(block_to_return);
        block_location[block_to_return] = block_to_return;
    }
}

void move_stack(int block_a, int dest_pile_idx) {
    int p_a_idx;
    size_t h_a_idx;
    find_pos(block_a, p_a_idx, h_a_idx);

    for (size_t i = h_a_idx; i < piles[p_a_idx].size(); ++i) {
        int b = piles[p_a_idx][i];
        block_location[b] = dest_pile_idx;
    }

    piles[dest_pile_idx].insert(piles[dest_pile_idx].end(),
                               piles[p_a_idx].begin() + h_a_idx,
                               piles[p_a_idx].end());

    piles[p_a_idx].resize(h_a_idx);
}

void print_piles() {
    for (int i = 0; i < n; ++i) {
        std::cout << i << ":";
        for (int block : piles[i]) {
            std::cout << " " << block;
        }
        std::cout << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;

    piles.resize(n);
    block_location.resize(n);
    for (int i = 0; i < n; ++i) {
        piles[i].push_back(i);
        block_location[i] = i;
    }

    std::string cmd1, cmd2;
    int a, b;
    while (std::cin >> cmd1 && cmd1 != "final") {
        std::cin >> a >> cmd2 >> b;

        if (a == b || block_location[a] == block_location[b]) {
            continue;
        }

        if (cmd1 == "mover") {
            clear_above(a);
        }
        if (cmd2 == "sobre") {
            clear_above(b);
        }

        int dest_pile = block_location[b];
        move_stack(a, dest_pile);
    }

    print_piles();

    return 0;
}
