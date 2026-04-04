/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Person {
    string name;
    string id;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string name_in, id_in;
    vector<Person> list;
    while (cin >> name_in >> id_in) {
        list.push_back({name_in, id_in});
    }

    while (!list.empty()) {
        string current_name = list[0].name;
        string current_id = list[0].id;
        
        int partner_idx = -1;
        int current_size = (int)list.size();
        for (int j = 1; j < current_size; ++j) {
            if (list[j].id == current_id) {
                partner_idx = j;
                break;
            }
        }

        if (partner_idx != -1) {
            cout << current_name << " seu parceiro esta na posicao " << partner_idx << " e o seu nome e " << list[partner_idx].name << ".\n";
            list.erase(list.begin() + partner_idx);
            list.erase(list.begin());
        } else {
            cout << current_name << " nao existe um parceiro para voce.\n";
            list.erase(list.begin());
        }
    }

    return 0;
}