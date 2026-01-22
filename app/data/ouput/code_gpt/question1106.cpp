/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Convidado {
    string nome;
    int idade;
    string time;
};

int main() {
    vector<Convidado> convidados;
    string input;

    while (getline(cin, input) && input != "-1") {
        Convidado c;
        size_t pos1 = input.find(' ');
        size_t pos2 = input.rfind(' ');
        c.nome = input.substr(0, pos1);
        c.idade = stoi(input.substr(pos1 + 1, pos2 - pos1 - 1));
        c.time = input.substr(pos2 + 1);
        convidados.push_back(c);
    }

    vector<vector<Convidado>> mesas(4);

    for (const auto &c : convidados) {
        if ((c.time == "FLAMENGO" || c.time == "SPORT" || c.time == "VITORIA") && c.idade >= 30) {
            mesas[0].push_back(c);
        } else if ((c.time == "VASCO" || c.time == "TREZE" || c.time == "SANTOS") && (c.idade >= 18 && c.idade <= 36)) {
            mesas[1].push_back(c);
        } else if ((c.time == "BAHIA" || c.time == "FORTALEZA" || c.time == "GREMY" || c.time == "GREMMIO") && (c.idade >= 10 && c.idade <= 18)) {
            mesas[2].push_back(c);
        } else {
            mesas[3].push_back(c);
        }
    }

    if (convidados.empty()) {
        cout << "JANTAR SEM CONVIDADOS" << endl;
    } else {
        for (int i = 0; i < 4; ++i) {
            cout << "MESA " << (i + 1) << endl;
            if (mesas[i].empty()) {
                cout << "VAZIA" << endl;
            } else {
                for (size_t j = 0; j < mesas[i].size(); ++j) {
                    cout << j + 1 << " " << mesas[i][j].nome << endl;
                }
            }
        }
    }

    return 0;
}
