/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    
    string dummy;
    getline(cin, dummy);

    map<string, long long> inventory;
    vector<string> registration_order;

    while (n--) {
        string cmd;
        if (!getline(cin, cmd)) break;

        if (cmd == "Registro") {
            string name;
            if (!getline(cin, name)) break;
            if (inventory.find(name) != inventory.end()) {
                cout << "Produto ja registrado" << "\n";
            } else {
                inventory[name] = 0;
                registration_order.push_back(name);
                cout << "Produto registrado com sucesso" << "\n";
            }
        } else if (cmd == "Venda") {
            string name;
            if (!getline(cin, name)) break;
            if (inventory.find(name) == inventory.end()) {
                cout << "Produto nao registrado" << "\n";
            } else {
                long long q;
                if (!(cin >> q)) break;
                getline(cin, dummy);
                if (q < 0) {
                    cout << "Comando invalido" << "\n";
                } else if (inventory[name] < q) {
                    cout << "Sem estoque para a Venda" << "\n";
                } else {
                    inventory[name] -= q;
                    cout << "Venda realizada com sucesso" << "\n";
                }
            }
        } else if (cmd == "Recarga") {
            string name;
            if (!getline(cin, name)) break;
            if (inventory.find(name) == inventory.end()) {
                cout << "Produto nao registrado" << "\n";
            } else {
                long long q;
                if (!(cin >> q)) break;
                getline(cin, dummy);
                if (q < 0) {
                    cout << "Comando invalido" << "\n";
                } else {
                    inventory[name] += q;
                    cout << "Recarga realizada com sucesso" << "\n";
                }
            }
        } else {
            cout << "Comando invalido" << "\n";
        }
    }

    for (const string& name : registration_order) {
        cout << name << ": " << inventory[name] << "\n";
    }

    return 0;
}