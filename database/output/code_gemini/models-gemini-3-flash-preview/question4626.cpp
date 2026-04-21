/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int lab;
    if (!(cin >> lab)) return 0;

    int total_machines = 0;
    if (lab == 1) total_machines = 28;
    else if (lab == 2) total_machines = 26;
    else if (lab == 3) total_machines = 15;
    else if (lab == 4) total_machines = 20;

    vector<int> working_ids;
    set<int> seen_ids;
    int valid_count = 0;

    while (valid_count < total_machines) {
        int status;
        if (!(cin >> status)) break;

        if (status != 0 && status != 1) {
            cout << "Identificador invalido." << endl;
            continue;
        }

        int id;
        if (!(cin >> id)) break;

        if (seen_ids.count(id)) {
            cout << "ID invalido. Nao pode haver pc's iguais" << endl;
            continue;
        }

        seen_ids.insert(id);
        if (status == 0) {
            working_ids.push_back(id);
        }
        valid_count++;
    }

    if (working_ids.empty()) {
        cout << "Sem computadores disponiveis nesse laboratorio." << endl;
    } else {
        cout << "Quantidade de pessoas que podem utilizar os computadores: " << working_ids.size() << endl;
        cout << "Lista de id's:" << endl;
        for (int id : working_ids) {
            cout << id << endl;
        }
    }

    return 0;
}