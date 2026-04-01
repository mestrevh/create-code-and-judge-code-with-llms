/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    string dummy;
    getline(cin, dummy);

    vector<string> registration_order;
    map<string, long long> stock;
    map<string, bool> is_registered;

    for (int i = 0; i < N; ++i) {
        string cmd;
        if (!getline(cin, cmd)) break;

        if (cmd == "CADASTRO") {
            string p;
            getline(cin, p);
            if (is_registered[p]) {
                cout << "Produto ja cadastrado" << endl;
            } else {
                is_registered[p] = true;
                stock[p] = 0;
                registration_order.push_back(p);
                cout << "Cadastro efetuado com sucesso" << endl;
            }
        } else if (cmd == "ESTOQUE") {
            string p;
            getline(cin, p);
            long long q;
            cin >> q;
            getline(cin, dummy);
            if (!is_registered[p]) {
                cout << "Produto não foi cadastrado" << endl;
            } else {
                stock[p] += q;
                cout << "Estoque efetuado com sucesso" << endl;
            }
        } else if (cmd == "VENDA") {
            string p;
            getline(cin, p);
            long long q;
            cin >> q;
            getline(cin, dummy);
            if (!is_registered[p]) {
                cout << "Produto não foi cadastrado" << endl;
            } else if (stock[p] < q) {
                cout << "Nao ha estoque para a venda" << endl;
            } else {
                stock[p] -= q;
                cout << "Venda realizada com sucesso" << endl;
            }
        } else {
            cout << "Comando nao reconhecido" << endl;
        }
    }

    for (const string& name : registration_order) {
        string formatted_name = name;
        if (!formatted_name.empty()) {
            formatted_name[0] = toupper(formatted_name[0]);
        }
        cout << formatted_name << ": " << stock[name] << endl;
    }

    return 0;
}