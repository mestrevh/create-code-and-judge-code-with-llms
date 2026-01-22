/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    map<string, int> scores;
    vector<string> knights = {"Shun", "Hyoga", "Seiya", "Shiryu", "Ikki"};
    
    for (int i = 0; i < N; ++i) {
        string cav1, cav2, vencedor;
        cin >> cav1 >> cav2 >> vencedor;

        if (vencedor == cav1) {
            scores[cav1] += 3;
            scores[cav2] -= 1;
        } else {
            scores[cav2] += 3;
            scores[cav1] -= 1;
        }
    }

    vector<pair<string, int>> result;
    for (const auto& knight : knights) {
        if (scores.find(knight) != scores.end()) {
            result.emplace_back(knight, scores[knight]);
        } else {
            result.emplace_back(knight, 0);
        }
    }

    sort(result.begin(), result.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    });

    for (int i = 0; i < 3; ++i) {
        cout << result[i].first << " " << result[i].second << endl;
    }

    return 0;
}
