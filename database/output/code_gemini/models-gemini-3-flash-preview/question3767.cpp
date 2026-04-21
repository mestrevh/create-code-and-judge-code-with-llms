/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Person {
    string street;
    char type; 
    int house_num;
    int bld_num, floor_num, apt_num;
    string name;
    char sex;
    string birth;
    int id;

    bool operator<(const Person& other) const {
        if (type != other.type) return type < other.type;
        if (type == 'c') {
            if (house_num != other.house_num) return house_num < other.house_num;
        } else {
            if (bld_num != other.bld_num) return bld_num < other.bld_num;
            if (floor_num != other.floor_num) return floor_num < other.floor_num;
            if (apt_num != other.apt_num) return apt_num < other.apt_num;
        }
        return id < other.id;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Person> db;
    int order_count = 0;
    int op;

    while (cin >> op) {
        if (op == 1) {
            Person p;
            p.id = order_count++;
            getline(cin >> ws, p.street);
            if (!(cin >> p.type)) break;
            if (p.type == 'c') {
                cin >> p.house_num;
                getline(cin >> ws, p.name);
                cin >> p.sex >> p.birth;
            } else {
                cin >> p.bld_num >> p.floor_num >> p.apt_num;
                getline(cin >> ws, p.name);
                cin >> p.sex >> p.birth;
            }
            db.push_back(p);
        } else if (op == 2) {
            string m, r;
            getline(cin >> ws, m);
            getline(cin >> ws, r);
            
            vector<Person> found;
            for (const auto& p : db) {
                if (p.name == m && p.street == r) {
                    found.push_back(p);
                }
            }

            if (found.empty()) {
                cout << "Sem dados de \"" << m << "\" em \"" << r << "\"!" << "\n";
            } else {
                sort(found.begin(), found.end());
                for (const auto& p : found) {
                    if (p.type == 'c') {
                        cout << "Casa: " << p.house_num << " | Sexo: " << p.sex << " | Nascimento: " << p.birth << "\n";
                    } else {
                        cout << "Edificio: " << p.bld_num << " | Andar: " << p.floor_num << " | Numero do apt.: " << p.apt_num << " | Sexo: " << p.sex << " | Nascimento: " << p.birth << "\n";
                    }
                }
                cout << "Foram encontradas " << found.size() << " instancias de pessoas chamadas \"" << m << "\" em \"" << r << "\", relatadas acima." << "\n";
            }
        } else if (op == 3) {
            cout << "O programa sera fechado, obrigado por fazer uso dele. Lembre-se de evitar a fadiga!" << "\n";
            break;
        } else {
            cout << "Opcao invalida. Por favor, digite uma opcao valida." << "\n";
        }
    }

    return 0;
}