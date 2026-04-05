/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Team {
    int titles;
    char id;
    string name;
    int original_order;
};

bool compareTeams(const Team& a, const Team& b) {
    return a.titles > b.titles;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Team> teams(4);
    for (int i = 0; i < 4; ++i) {
        cin >> teams[i].titles >> teams[i].id;
        teams[i].original_order = i;
        if (teams[i].id == 'A') teams[i].name = "Náutico";
        else if (teams[i].id == 'B') teams[i].name = "Sport";
        else if (teams[i].id == 'C') teams[i].name = "Salgueiro";
        else if (teams[i].id == 'D') teams[i].name = "Santa Cruz";
    }

    for (int i = 0; i < 4; ++i) {
        if (teams[i].id == 'A') {
            if (teams[i].titles > 24) cout << "Se contar direitinho ainda tá faltando uns títulos para o Timba...\n";
            else if (teams[i].titles < 24) cout << "Isso deve ser coisa do Sport, querem ganhar no tapetão que nem em 87!\n";
            else cout << "Tem algo estranho aqui...\n";
        } else if (teams[i].id == 'B') {
            if (teams[i].titles > 45) cout << "Se antes já era grande a diferença, imagine agora...\n";
            else if (teams[i].titles < 45) cout << "Capaz de recorrerem no STJD e recuperarem os títulos no tapetão.\n";
            else cout << "Tem algo estranho aqui...\n";
        } else if (teams[i].id == 'C') {
            if (teams[i].titles > 1) cout << "Finalmente teve justiça sobre que aconteceu em 2017!\n";
            else if (teams[i].titles < 1) cout << "Foi roubado em 2017 e agora em 2025, existe isso não...\n";
            else cout << "Tem algo estranho aqui...\n";
        } else if (teams[i].id == 'D') {
            if (teams[i].titles > 29) cout << "O Santa é gigante e esse ano vai sair da série D\n";
            else if (teams[i].titles < 29) cout << "É muito azar, nem com a SAF as coisas dão certo.\n";
            else cout << "Tem algo estranho aqui...\n";
        }
    }

    vector<Team> sorted_teams = teams;
    sort(sorted_teams.begin(), sorted_teams.end(), compareTeams);

    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << (i + 1) << "º - " << sorted_teams[i].name << " - " << sorted_teams[i].titles << " - títulos\n";
    }

    cout << "\n";
    if (sorted_teams[0].id == 'A') cout << "A justiça foi feita, o Timba é o maior do estado, não tem jeito!\n";
    else if (sorted_teams[0].id == 'B') cout << "Deu o óbvio, o papai da cidade é o Leão!\n";
    else if (sorted_teams[0].id == 'C') cout << "Já era o maior do interior, agora é o maior do estado!\n";
    else if (sorted_teams[0].id == 'D') cout << "É o terror do Nordeste, sempre soube!\n";

    return 0;
}