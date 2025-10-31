/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();
    
    unordered_map<string, vector<string>> contracts;
    vector<string> animals = {"Sapos", "Cobras", "Lesmas", "Macacos", "Caes"};
    unordered_map<string, vector<string>> characteristics = {
        {"Sapos", {"Coragem", "Determinação", "Convicção"}},
        {"Cobras", {"Ambição", "Astúcia", "Expertise"}},
        {"Lesmas", {"Análise", "Suporte", "Técnica"}},
        {"Macacos", {"Agilidade", "Inteligência", "Destreza"}},
        {"Caes", {"Experiência", "Perspicácia", "Perícia"}}
    };
    
    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        size_t pos = line.find(' ');
        string name = line.substr(0, pos);
        string trait = pos == string::npos ? "" : line.substr(pos + 1);
        for (const auto& animal : animals) {
            if (find(characteristics[animal].begin(), characteristics[animal].end(), trait) != characteristics[animal].end()) {
                contracts[animal].push_back(name);
                break;
            }
        }
    }
    
    bool hasContracts = false;
    for (const auto& animal : animals) {
        if (!contracts[animal].empty()) {
            hasContracts = true;
            cout << animal << ":\n";
            for (const string& name : contracts[animal]) {
                cout << "- " << name << "\n";
            }
        } else {
            cout << animal << ":\n";
        }
    }
    
    if (!hasContracts) {
        cout << "Nao havera Jounins forte esse ano.\n";
    }
    
    return 0;
}
