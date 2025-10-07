/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<tuple<int, int, int>> pistas(K);
    for (int i = 0; i < K; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        pistas[i] = make_tuple(x, y, d);
    }
    
    set<pair<int, int>> possibilidades;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool valido = true;
            for (const auto& [x, y, d] : pistas) {
                if (abs(x - i) + abs(y - j) != d) {
                    valido = false;
                    break;
                }
            }
            if (valido) {
                possibilidades.insert({i, j});
            }
        }
    }

    if (possibilidades.size() == 1) {
        auto it = possibilidades.begin();
        cout << it->first << " " << it->second << endl;
    } else {
        cout << -1 << " " << -1 << endl;
    }

    return 0;
}
