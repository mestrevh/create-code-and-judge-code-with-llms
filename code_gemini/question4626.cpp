/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int lab;
    cin >> lab;

    int num_machines;
    if (lab == 1) {
        num_machines = 28;
    } else if (lab == 2) {
        num_machines = 26;
    } else if (lab == 3) {
        num_machines = 15;
    } else {
        num_machines = 20;
    }

    vector<int> working_ids;
    unordered_set<int> used_ids;

    for (int i = 0; i < num_machines; ++i) {
        int status, id;
        cin >> status;
        while (status != 0 && status != 1) {
            cout << "Identificador invalido." << endl;
            cin >> status;
        }
        cin >> id;
        while (used_ids.count(id)) {
            cout << "ID invalido. Nao pode haver pc's iguais" << endl;
            cin >> id;
        }
        used_ids.insert(id);

        if (status == 0) {
            working_ids.push_back(id);
        }
    }

    cout << "Quantidade de pessoas que podem utilizar os computadores: " << working_ids.size() << endl;
    cout << "Lista de id's:" << endl;
    if (working_ids.empty()) {
        cout << "Sem computadores disponiveis nesse laboratorio." << endl;
    } else {
        for (int id : working_ids) {
            cout << id << endl;
        }
    }

    return 0;
}
