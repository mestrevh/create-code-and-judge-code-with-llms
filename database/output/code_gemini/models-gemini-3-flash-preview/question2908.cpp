/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Knight {
    string name;
    int score;
};

bool compareKnights(const Knight& a, const Knight& b) {
    if (a.score != b.score) {
        return a.score > b.score;
    }
    return a.name < b.name;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    map<string, int> scores;
    scores["Shun"] = 0;
    scores["Hyoga"] = 0;
    scores["Seiya"] = 0;
    scores["Shiryu"] = 0;
    scores["Ikki"] = 0;

    for (int i = 0; i < n; ++i) {
        string c1, c2, win;
        cin >> c1 >> c2 >> win;
        
        if (scores.find(win) != scores.end()) {
            scores[win] += 3;
        }
        
        string loser = (win == c1 ? c2 : c1);
        if (scores.find(loser) != scores.end()) {
            scores[loser] -= 1;
        }
    }

    vector<Knight> ranking;
    for (auto const& [name, score] : scores) {
        ranking.push_back({name, score});
    }

    sort(ranking.begin(), ranking.end(), compareKnights);

    for (int i = 0; i < 3 && i < (int)ranking.size(); ++i) {
        cout << ranking[i].name << " " << ranking[i].score << "\n";
    }

    return 0;
}