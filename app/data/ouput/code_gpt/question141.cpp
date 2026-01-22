/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int G, P;
    while (cin >> G >> P, G || P) {
        vector<vector<int>> results(G, vector<int>(P));
        for (int i = 0; i < G; ++i) 
            for (int j = 0; j < P; ++j) 
                cin >> results[i][j];

        int S;
        cin >> S;
        while (S--) {
            int K;
            cin >> K;
            vector<int> points(K);
            for (int i = 0; i < K; ++i) 
                cin >> points[i];

            vector<int> scores(P + 1, 0);
            for (const auto& race : results) {
                for (int i = 0; i < P; ++i) {
                    if (race[i] <= K) {
                        scores[i + 1] += points[race[i] - 1];
                    }
                }
            }

            int max_score = *max_element(scores.begin() + 1, scores.end());
            set<int> champions;
            for (int i = 1; i <= P; ++i) {
                if (scores[i] == max_score) {
                    champions.insert(i);
                }
            }

            for (auto it = champions.begin(); it != champions.end(); ++it) {
                if (it != champions.begin()) cout << " ";
                cout << *it;
            }
            cout << endl;
        }
    }
    return 0;
}
