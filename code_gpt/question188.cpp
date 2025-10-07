/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Indian {
    int pos;
    int dir;
};

int main() {
    int N, E;
    cin >> N >> E;
    vector<Indian> indians(E);
    set<pair<int, int>> initial_positions;

    for (int i = 0; i < E; ++i) {
        cin >> indians[i].pos >> indians[i].dir;
        indians[i].pos--; // para 0-index
        initial_positions.insert({indians[i].pos, indians[i].dir});
    }

    int beats = 0;
    while (true) {
        set<pair<int, int>> current_positions;
        vector<int> new_pos(E);
        int collision = 0;

        for (int i = 0; i < E; ++i) {
            new_pos[i] = (indians[i].pos + indians[i].dir + N) % N;

            if (current_positions.count({new_pos[i], indians[i].dir}) || 
                current_positions.count({new_pos[i], -indians[i].dir})) {
                collision = 1;
            }
            current_positions.insert({new_pos[i], indians[i].dir});
        }

        if (collision) {
            for (int i = 0; i < E; ++i) {
                indians[i].dir *= -1;
            }
        }

        for (int i = 0; i < E; ++i) {
            indians[i].pos = new_pos[i];
        }

        beats++;
        set<pair<int, int>> curr_set;
        for (const auto& ind : indians) {
            curr_set.insert({ind.pos, ind.dir});
        }

        if (curr_set == initial_positions) {
            break;
        }
    }

    cout << beats << endl;
    return 0;
}
