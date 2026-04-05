/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long tA, tB, tC, tD;
    char c;

    long long oldA = 24, oldB = 45, oldC = 1, oldD = 29;

    array<long long, 256> old{};
    old['A'] = oldA;
    old['B'] = oldB;
    old['C'] = oldC;
    old['D'] = oldD;

    vector<pair<char, long long>> v;
    v.reserve(4);

    vector<string> msgs;

    for (int i = 0; i < 4; i++) {
        long long t;
        char team;
        cin >> t >> team;
        v.push_back({team, t});

        long long prev = old[(unsigned char)team];
        if (t == prev) {
            msgs.push_back("Tem algo estranho aqui...");
        } else if (team == 'A') {
            if (t > prev) msgs.push_back("Se contar direitinho ainda tá faltando uns títulos para o Timba...");
            else msgs.push_back("Isso deve ser coisa do Sport, querem ganhar no tapetão que nem em 87!");
        } else if (team == 'B') {
            if (t > prev) msgs.push_back("Se antes já era grande a diferença, imagine agora...");
            else msgs.push_back("Capaz de recorrerem no STJD e recuperarem os títulos no tapetão.");
        } else if (team == 'C') {
            if (t > prev) msgs.push_back("Finalmente teve justiça sobre que aconteceu em 2017!");
            else msgs.push_back("Foi roubado em 2017 e agora em 2025, existe isso não...");
        } else if (team == 'D') {
            if (t > prev) msgs.push_back("O Santa é gigante e esse ano vai sair da série D");
            else msgs.push_back("É muito azar, nem com a SAF as coisas dão certo.");
        }
    }

    for (auto &s : msgs) cout << s << "\n";

    array<long long, 256> cur{};
    for (auto &p : v) cur[(unsigned char)p.first] = p.second;

    vector<pair<char, long long>> ranked;
    ranked.push_back({'A', cur['A']});
    ranked.push_back({'B', cur['B']});
    ranked.push_back({'D', cur['D']});
    ranked.push_back({'C', cur['C']});

    auto nameOf = [&](char team) -> string {
        if (team == 'A') return "Náutico";
        if (team == 'B') return "Sport";
        if (team == 'C') return "Salgueiro";
        return "Santa Cruz";
    };

    sort(ranked.begin(), ranked.end(), [&](auto &p1, auto &p2){
        return p1.second > p2.second;
    });

    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << (i+1) << "º - " << nameOf(ranked[i].first) << " - " << ranked[i].second << " - títulos\n";
    }

    char maxTeam = ranked[0].first;
    if (maxTeam == 'A') cout << "\nA justiça foi feita, o Timba é o maior do estado, não tem jeito!";
    else if (maxTeam == 'D') cout << "\nÉ o terror do Nordeste, sempre soube!";
    else if (maxTeam == 'B') cout << "\nDeu o óbvio, o papai da cidade é o Leão!";
    else cout << "\nJá era o maior do interior, agora é o maior do estado!";

    return 0;
}