/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int SIZE = 4;
const int INF = 1e9;

struct State {
    vector<vector<int>> grid;
    int cost;

    bool operator<(const State& other) const {
        return cost > other.cost;
    }
};

int main() {
    vector<vector<int>> initial(SIZE, vector<int>(SIZE)), final(SIZE, vector<int>(SIZE));
    unordered_map<int, tuple<int, int>> position;

    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j) {
            cin >> initial[i][j];
            position[initial[i][j]] = {i, j};
        }
    
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j) {
            cin >> final[i][j];
        }
    
    int totalCost = 0;
    
    while (true) {
        bool found = false;
        for (int r = 0; r < SIZE; ++r) {
            for (int c = 0; c < SIZE; ++c) {
                if (initial[r][c] != final[r][c]) {
                    auto [fr, fc] = position[final[r][c]];
                    if ((abs(r - fr) == 1 && c == fc) || (r == fr && abs(c - fc) == 1)) {
                        totalCost += initial[r][c] + initial[fr][fc];
                        swap(initial[r][c], initial[fr][fc]);
                        swap(position[initial[r][c]], position[initial[fr][fc]]);
                        found = true;
                    }
                }
            }
        }
        if (!found) break;
    }

    cout << totalCost << endl;
    return 0;
}
