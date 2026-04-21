/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    unordered_map<string, string> gustToPrincess;
    for (auto &g : vector<string>{"mar", "mergulho"}) gustToPrincess[g] = "Ariel";
    for (auto &g : vector<string>{"bailes", "sapatos"}) gustToPrincess[g] = "Cinderela";
    for (auto &g : vector<string>{"florestas", "pacifismo"}) gustToPrincess[g] = "Pocahontas";
    for (auto &g : vector<string>{"desertos", "tapetes"}) gustToPrincess[g] = "Jasmine";

    vector<string> order = {"Ariel", "Cinderela", "Pocahontas", "Jasmine"};
    unordered_map<string, vector<string>> people;

    for (int i = 0; i < N; i++) {
        string name, gust;
        cin >> name;
        if (!(cin >> gust)) continue;
        auto it = gustToPrincess.find(gust);
        if (it != gustToPrincess.end()) people[it->second].push_back(name);
    }

    bool any = false;
    for (auto &prin : order) {
        auto it = people.find(prin);
        if (it != people.end() && !it->second.empty()) {
            any = true;
            cout << prin << ":\n";
            for (auto &p : it->second) cout << "- " << p << "\n";
        }
    }

    if (!any) {
        cout << "Infelizmente nao teremos passeios nessa temporada.\n";
    }

    return 0;
}