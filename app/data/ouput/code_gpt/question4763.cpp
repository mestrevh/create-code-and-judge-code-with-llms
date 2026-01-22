/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    map<char, int> titles = {{'A', 24}, {'B', 45}, {'C', 1}, {'D', 29}};
    char team;
    int new_titles;
    vector<pair<int, char>> ranking;
    
    for (int i = 0; i < 4; i++) {
        cin >> new_titles >> team;
        if (titles[team] < new_titles) {
            if (team == 'A') cout << "Se contar direitinho ainda tá faltando uns títulos para o Timba..." << endl;
            else if (team == 'B') cout << "Se antes já era grande a diferença, imagine agora..." << endl;
            else if (team == 'C') cout << "Finalmente teve justiça sobre que aconteceu em 2017!" << endl;
            else if (team == 'D') cout << "O Santa é gigante e esse ano vai sair da série D" << endl;
        } else if (titles[team] > new_titles) {
            if (team == 'A') cout << "Isso deve ser coisa do Sport, querem ganhar no tapetão que nem em 87!" << endl;
            else if (team == 'B') cout << "Capaz de recorrerem no STJD e recuperarem os títulos no tapetão." << endl;
            else if (team == 'C') cout << "Foi roubado em 2017 e agora em 2025, existe isso não..." << endl;
            else if (team == 'D') cout << "É muito azar, nem com a SAF as coisas dão certo." << endl;
        } else {
            cout << "Tem algo estranho aqui..." << endl;
        }
        titles[team] = new_titles;
    }

    cout << endl;
    
    for (auto& t : titles) {
        ranking.push_back({t.second, t.first});
    }
    sort(ranking.rbegin(), ranking.rend());
    
    for (int i = 0; i < ranking.size(); i++) {
        string name = (ranking[i].second == 'A') ? "Náutico" : (ranking[i].second == 'B') ? "Sport" :
                      (ranking[i].second == 'C') ? "Salgueiro" : "Santa Cruz";
        cout << (i + 1) << "º - " << name << " - " << ranking[i].first << " - títulos" << endl;
    }

    cout << endl;

    if (ranking[0].second == 'A') cout << "A justiça foi feita, o Timba é o maior do estado, não tem jeito!" << endl;
    else if (ranking[0].second == 'D') cout << "É o terror do Nordeste, sempre soube!" << endl;
    else if (ranking[0].second == 'B') cout << "Deu o óbvio, o papai da cidade é o Leão!" << endl;
    else if (ranking[0].second == 'C') cout << "Já era o maior do interior, agora é o maior do estado!" << endl;

    return 0;
}
