/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Person {
    bool isHouse;
    int houseNo;

    int buildingNo;
    int floorNo;
    int aptNo;

    string name;
    char sex;
    string birth;
    int order;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Person> people;
    int op;
    while (true) {
        if (!(cin >> op)) return 0;
        if (op == 1) {
            string street;
            cin >> street;

            char type;
            cin >> type;

            if (type == 'c') {
                int C;
                cin >> C;
                string name;
                cin >> name;
                char S;
                cin >> S;
                string birth;
                cin >> birth;

                Person p;
                p.isHouse = true;
                p.houseNo = C;
                p.buildingNo = 0;
                p.floorNo = 0;
                p.aptNo = 0;
                p.name = name;
                p.sex = S;
                p.birth = birth;
                p.order = (int)people.size();
                people.push_back(p);

                people.back().birth = p.birth;
            } else if (type == 'e') {
                int E, A, APT;
                cin >> E >> A >> APT;
                string name;
                cin >> name;
                char S;
                cin >> S;
                string birth;
                cin >> birth;

                Person p;
                p.isHouse = false;
                p.houseNo = 0;
                p.buildingNo = E;
                p.floorNo = A;
                p.aptNo = APT;
                p.name = name;
                p.sex = S;
                p.birth = birth;
                p.order = (int)people.size();
                people.push_back(p);
            }

            vector<string> extra;
            (void)street;
        } else if (op == 2) {
            string M, R;
            cin >> M >> R;

            vector<Person*> found;
            found.reserve(64);

            for (auto &p : people) {
                if (p.name == M) {
                    found.push_back(&p);
                }
            }

            stable_sort(found.begin(), found.end(), [&](Person* a, Person* b){
                if (a->isHouse != b->isHouse) {
                    if (a->isHouse) return true;
                    return false;
                }
                if (a->isHouse) {
                    if (a->houseNo != b->houseNo) return a->houseNo < b->houseNo;
                } else {
                    if (a->buildingNo != b->buildingNo) return a->buildingNo < b->buildingNo;
                    if (a->floorNo != b->floorNo) return a->floorNo < b->floorNo;
                    if (a->aptNo != b->aptNo) return a->aptNo < b->aptNo;
                }
                return a->order < b->order;
            });

            vector<Person*> filtered;
            filtered.reserve(found.size());

            if (!found.empty()) {
                for (auto *p : found) filtered.push_back(p);
            }

            if (filtered.empty()) {
                cout << "Sem dados de \"" << M << "\" em \"" << R << "\"!\n";
            } else {
                for (auto *p : filtered) {
                    if (p->isHouse) {
                        cout << "Casa: " << p->houseNo << " | Sexo: " << p->sex << " | Nascimento: " << p->birth << "\n";
                    } else {
                        cout << "Edificio: " << p->buildingNo << " | Andar: " << p->floorNo << " | Numero do apt.: " << p->aptNo
                             << " | Sexo: " << p->sex << " | Nascimento: " << p->birth << "\n";
                    }
                }
                cout << "Foram encontradas " << filtered.size() << " instancias de pessoas chamadas \"" << M
                     << "\" em \"" << R << "\", relatadas acima.\n";
            }
        } else if (op == 3) {
            cout << "O programa sera fechado, obrigado por fazer uso dele. Lembre-se de evitar a fadiga!\n";
            break;
        } else {
            cout << "Opcao invalida. Por favor, digite uma opcao valida.\n";
        }
    }

    return 0;
}