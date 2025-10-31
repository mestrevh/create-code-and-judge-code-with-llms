/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int lab;
    cin >> lab;
    
    int machines[] = {0, 28, 26, 15, 20};
    int x = machines[lab];
    
    unordered_set<int> ids;
    vector<int> available_ids;
    
    for (int i = 0; i < x; i++) {
        int status, id;
        while (true) {
            cin >> status;
            if (status != 0 && status != 1) {
                cout << "Identificador invalido." << endl;
                continue;
            }
            break;
        }
        
        while (true) {
            cin >> id;
            if (ids.find(id) != ids.end()) {
                cout << "ID invalido. Nao pode haver pc's iguais" << endl;
                continue;
            }
            ids.insert(id);
            break;
        }
        
        if (status == 0) {
            available_ids.push_back(id);
        }
    }
    
    cout << "Quantidade de pessoas que podem utilizar os computadores: " << available_ids.size() << endl;
    cout << "Lista de id's:" << endl;
    
    if (available_ids.empty()) {
        cout << "Sem computadores disponiveis nesse laboratorio." << endl;
    } else {
        for (int id : available_ids) {
            cout << id << endl;
        }
    }
    
    return 0;
}
