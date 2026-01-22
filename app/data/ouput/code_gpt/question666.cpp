/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <bitset>
#include <iomanip>

using namespace std;

int main() {
    int N, T;
    while (cin >> N >> T, N || T) {
        vector<int> taps(T);
        for (int i = 0; i < T; i++) cin >> taps[i];
        string init_hex, final_hex;
        cin >> init_hex >> final_hex;

        int initial = stoi(init_hex, nullptr, 16);
        int final = stoi(final_hex, nullptr, 16);

        queue<pair<int, int>> q;
        unordered_set<int> visited;
        q.push({initial, 0});
        visited.insert(initial);

        bool found = false;
        while (!q.empty()) {
            auto [current, steps] = q.front(); q.pop();

            if (current == final) {
                cout << steps << endl;
                found = true;
                break;
            }

            int next = (current >> 1) | (((__builtin_popcount(current & ((1 << N) - 1)) & 1) ^ (current & (1 << taps[0]))) << (N - 1));
            for (int i = 1; i < T; i++) {
                next ^= (current >> taps[i]) & 1;
            }
            next = (next & 1) | (current >> 1);
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push({next, steps + 1});
            }
        }

        if (!found) cout << '*' << endl;
    }
    return 0;
}
