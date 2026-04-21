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

    vector<string> animals = {"Sapos", "Cobras", "Lesmas", "Macacos", "Caes"};
    unordered_map<string, int> animalIndex;
    for (int i = 0; i < (int)animals.size(); i++) animalIndex[animals[i]] = i;

    vector<vector<string>> traits(5);
    traits[0] = {"Coragem", "Determinacao", "Conviccao"};
    traits[1] = {"Ambicao", "Astucia", "Expertise"};
    traits[2] = {"Analise", "Suporte", "Tecnica"};
    traits[3] = {"Agilidade", "Inteligencia", "Destreza"};
    traits[4] = {"Experiencia", "Perspicacia", "Pericia"};

    unordered_map<string, string> traitToAnimal;
    for (int i = 0; i < 5; i++) {
        for (auto &t : traits[i]) traitToAnimal[t] = animals[i];
    }

    vector<vector<string>> matched(5);
    for (int i = 0; i < N; i++) {
        string name, trait;
        cin >> name;
        if (!(cin >> trait)) break;
        auto it = traitToAnimal.find(trait);
        if (it != traitToAnimal.end()) {
            matched[animalIndex[it->second]].push_back(name);
        }
    }

    bool any = false;
    for (int i = 0; i < 5; i++) if (!matched[i].empty()) any = true;

    if (!any) {
        cout << "Nao havera Jounins forte esse ano";
        return 0;
    }

    for (int i = 0; i < 5; i++) {
        if (matched[i].empty()) continue;
        cout << animals[i] << ":\n";
        for (auto &nm : matched[i]) cout << "- " << nm << "\n";
    }

    return 0;
}