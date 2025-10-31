/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Medals {
    int gold = 0, silver = 0, bronze = 0;
};

bool compare(const pair<string, Medals>& a, const pair<string, Medals>& b) {
    if (a.second.gold != b.second.gold) return a.second.gold > b.second.gold;
    if (a.second.silver != b.second.silver) return a.second.silver > b.second.silver;
    return a.second.bronze > b.second.bronze;
}

int main() {
    string input;
    map<string, Medals> medalTable;

    while (getline(cin, input) && input != "*") {
        size_t pos = input.find(',');
        string country = input.substr(0, pos);
        string medalType = input.substr(pos + 1);

        if (medalType == "ouro") medalTable[country].gold++;
        else if (medalType == "prata") medalTable[country].silver++;
        else if (medalType == "bronze") medalTable[country].bronze++;
    }

    vector<pair<string, Medals>> results(medalTable.begin(), medalTable.end());
    sort(results.begin(), results.end(), compare);

    for (int i = 0; i < results.size(); i++) {
        cout << i + 1 << ")" << results[i].first << " ouro:" << results[i].second.gold 
             << " prata:" << results[i].second.silver << " bronze:" << results[i].second.bronze << endl;
    }

    return 0;
}
