/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <map>

using namespace std;

class Cemetery {
    int M, L, total_slots;
    vector<vector<bool>> grave;
    map<int, tuple<int, int>> records; // K -> (F, J)

public:
    Cemetery(int m, int l) : M(m), L(l), total_slots(m * l) {
        grave.resize(m, vector<bool>(l, false));
    }

    pair<int, int> add(int K) {
        int H = K % M;

        for (int i = 0; i < M; ++i) {
            int current_floor = (H + i) % M;
            for (int j = 0; j < L; ++j) {
                if (!grave[current_floor][j]) {
                    grave[current_floor][j] = true;
                    records[K] = {current_floor, j};
                    return {current_floor, j};
                }
            }
        }

        extend_cemetery();
        return add(K); // Retry adding after expanding
    }

    void remove(int K) {
        if (records.find(K) == records.end()) {
            cout << "?.?\n";
            return;
        }
        auto [F, J] = records[K];
        grave[F][J] = false;
        records.erase(K);
        cout << F << "." << J << endl;
    }

    void query(int K) {
        if (records.find(K) == records.end()) {
            cout << "?.?\n";
            return;
        }
        auto [F, J] = records[K];
        cout << F << "." << J << endl;
    }

    void extend_cemetery() {
        M = 2 * M + 1;
        total_slots = M * L;
        grave.clear();
        grave.resize(M, vector<bool>(L, false));
        for (const auto &[K, pos] : records) {
            auto [F, J] = pos;
            if (F < L) {
                grave[F][J] = true;
            }
        }
    }
};

int main() {
    int M, L, N;
    cin >> M >> L;
    Cemetery cemetery(M, L);
    string operation;
    int K, idx = 0;

    while (cin >> operation >> K) {
        if (operation == "ADD") {
            auto [F, J] = cemetery.add(K);
            cout << idx++ << " " << F << "." << J << endl;
        } else if (operation == "REM") {
            cemetery.remove(K);
            idx++;
        } else if (operation == "QRY") {
            cemetery.query(K);
            idx++;
        }
    }

    return 0;
}
