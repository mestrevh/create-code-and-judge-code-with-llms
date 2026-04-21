/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Club {
    string name;
    double score;
};

bool compareClubs(const Club& a, const Club& b) {
    return a.score > b.score;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Club> clubs;
    clubs.reserve(n);

    for (int i = 0; i < n; ++i) {
        string name;
        // Skip leading whitespace (including newline from previous entry) and read full line for the name
        getline(cin >> ws, name);
        
        double marketValue;
        int bigPlayers, titles;
        string hasNeymar, isFlamengo2019;

        if (!(cin >> marketValue >> bigPlayers >> titles)) break;
        if (!(cin >> hasNeymar >> isFlamengo2019)) break;

        double score = marketValue;
        score += (double)bigPlayers * 100.0;
        score += (double)titles * 2000.0;
        
        if (hasNeymar == "sim") {
            score += 10000.0;
        }
        if (isFlamengo2019 == "sim") {
            score += 20000.0;
        }

        clubs.push_back({name, score});
    }

    // Use stable_sort to preserve order in case of identical scores
    stable_sort(clubs.begin(), clubs.end(), compareClubs);

    for (const auto& club : clubs) {
        cout << club.name << " " << fixed << setprecision(2) << club.score << "\n";
    }

    return 0;
}