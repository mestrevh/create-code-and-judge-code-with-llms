/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Team {
    string name;
    int g, s, b;
};

bool compareTeams(const Team& a, const Team& b) {
    if (a.g != b.g) return a.g > b.g;
    if (a.s != b.s) return a.s > b.s;
    if (a.b != b.b) return a.b > b.b;
    return a.name < b.name;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    map<string, Team> counts;
    while (getline(cin, line)) {
        while (!line.empty() && (line.back() == '\r' || line.back() == '\n')) {
            line.pop_back();
        }
        if (line == "*" || line.empty()) {
            if (line == "*") break;
            continue;
        }

        size_t comma = line.find(',');
        if (comma == string::npos) continue;

        string country = line.substr(0, comma);
        string medal = line.substr(comma + 1);

        if (counts.find(country) == counts.end()) {
            counts[country] = {country, 0, 0, 0};
        }

        if (medal == "ouro") counts[country].g++;
        else if (medal == "prata") counts[country].s++;
        else if (medal == "bronze") counts[country].b++;
    }

    vector<Team> results;
    results.reserve(counts.size());
    for (auto it = counts.begin(); it != counts.end(); ++it) {
        results.push_back(it->second);
    }

    sort(results.begin(), results.end(), compareTeams);

    for (int i = 0; i < (int)results.size(); ++i) {
        cout << (i + 1) << ")" << results[i].name << " ouro:" << results[i].g 
             << " prata:" << results[i].s << " bronze:" << results[i].b << "\n";
    }

    return 0;
}