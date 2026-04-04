/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct Team {
    string name;
    int pts = 0;
    int vit = 0;
    int e = 0;
    int der = 0;
    int gp = 0;
    int gc = 0;
    int sg = 0;
};

bool compareTeams(const Team& a, const Team& b) {
    if (a.pts != b.pts) return a.pts > b.pts;
    if (a.vit != b.vit) return a.vit > b.vit;
    if (a.sg != b.sg) return a.sg > b.sg;
    if (a.gp != b.gp) return a.gp > b.gp;
    return a.name < b.name;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    map<string, Team> teamMap;

    for (int i = 0; i < N; ++i) {
        string t1, t2, x;
        int g1, g2;
        if (!(cin >> t1 >> g1 >> x >> g2 >> t2)) break;

        if (teamMap.find(t1) == teamMap.end()) {
            teamMap[t1].name = t1;
        }
        if (teamMap.find(t2) == teamMap.end()) {
            teamMap[t2].name = t2;
        }

        teamMap[t1].gp += g1;
        teamMap[t1].gc += g2;
        teamMap[t2].gp += g2;
        teamMap[t2].gc += g1;

        if (g1 > g2) {
            teamMap[t1].pts += 3;
            teamMap[t1].vit++;
            teamMap[t2].der++;
        } else if (g1 < g2) {
            teamMap[t2].pts += 3;
            teamMap[t2].vit++;
            teamMap[t1].der++;
        } else {
            teamMap[t1].pts += 1;
            teamMap[t2].pts += 1;
            teamMap[t1].e++;
            teamMap[t2].e++;
        }
    }

    vector<Team> rank;
    rank.reserve(teamMap.size());
    for (auto& pair : teamMap) {
        pair.second.sg = pair.second.gp - pair.second.gc;
        rank.push_back(pair.second);
    }

    sort(rank.begin(), rank.end(), compareTeams);

    for (int i = 0; i < (int)rank.size(); ++i) {
        cout << i + 1 << ". " << rank[i].name << " " << rank[i].pts << " " << rank[i].vit << " " << rank[i].e << " " << rank[i].der << " " << rank[i].gp << " " << rank[i].gc << " " << rank[i].sg << "\n";
    }

    return 0;
}