/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Person {
    string name;
    char sex;
    string dob;
    bool active = false;
};

struct Dwelling {
    Person residents[4];
    int resident_count = 0;
};

struct Floor {
    Dwelling apartments[2];
};

struct Building {
    Floor floors[20];
};

struct Street {
    string name;
    Dwelling houses[50];
    Building buildings[10];
};

Street city[5];
int street_count = 0;

int find_or_create_street(const string& street_name) {
    for (int i = 0; i < street_count; ++i) {
        if (city[i].name == street_name) {
            return i;
        }
    }
    if (street_count < 5) {
        city[street_count].name = street_name;
        return street_count++;
    }
    return -1;
}

void handle_insertion() {
    string street_name;
    getline(cin, street_name);

    int street_idx = find_or_create_street(street_name);
    if (street_idx == -1) {
        string temp;
        getline(cin, temp); 
        getline(cin, temp);
        return;
    }

    char type;
    cin >> type;

    string name, dob;
    char sex;

    if (type == 'c') {
        int C;
        cin >> C;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        cin >> sex >> dob;

        C--; 
        if (C >= 0 && C < 50) {
            Dwelling& house = city[street_idx].houses[C];
            if (house.resident_count < 4) {
                Person& p = house.residents[house.resident_count];
                p.name = name;
                p.sex = sex;
                p.dob = dob;
                p.active = true;
                house.resident_count++;
            }
        }
    } else {
        int E, A, APT;
        cin >> E >> A >> APT;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        cin >> sex >> dob;

        E--; A--; APT--; 
        if (E >= 0 && E < 10 && A >= 0 && A < 20 && APT >= 0 && APT < 2) {
            Dwelling& apt = city[street_idx].buildings[E].floors[A].apartments[APT];
            if (apt.resident_count < 4) {
                Person& p = apt.residents[apt.resident_count];
                p.name = name;
                p.sex = sex;
                p.dob = dob;
                p.active = true;
                apt.resident_count++;
            }
        }
    }
}

void handle_search() {
    string M, R;
    getline(cin, M);
    getline(cin, R);

    int street_idx = -1;
    for (int i = 0; i < street_count; ++i) {
        if (city[i].name == R) {
            street_idx = i;
            break;
        }
    }

    if (street_idx == -1) {
        cout << "Sem dados de \"" << M << "\" em \"" << R << "\"!" << endl;
        return;
    }

    vector<string> results;
    Street& street = city[street_idx];

    for (int c = 0; c < 50; ++c) {
        for (int p = 0; p < street.houses[c].resident_count; ++p) {
            if (street.houses[c].residents[p].active && street.houses[c].residents[p].name == M) {
                string line = "~Casa: " + to_string(c + 1) + " | Sexo: ";
                line += street.houses[c].residents[p].sex;
                line += " | Nascimento: " + street.houses[c].residents[p].dob;
                results.push_back(line);
            }
        }
    }

    for (int e = 0; e < 10; ++e) {
        for (int a = 0; a < 20; ++a) {
            for (int apt = 0; apt < 2; ++apt) {
                for (int p = 0; p < street.buildings[e].floors[a].apartments[apt].resident_count; ++p) {
                    if (street.buildings[e].floors[a].apartments[apt].residents[p].active && street.buildings[e].floors[a].apartments[apt].residents[p].name == M) {
                        string line = "Edificio: " + to_string(e + 1) + " | Andar: " + to_string(a + 1) + " | Numero do apt.: " + to_string(apt + 1) + " | Sexo: ";
                        line += street.buildings[e].floors[a].apartments[apt].residents[p].sex;
                        line += " | Nascimento: " + street.buildings[e].floors[a].apartments[apt].residents[p].dob;
                        results.push_back(line);
                    }
                }
            }
        }
    }

    if (results.empty()) {
        cout << "Sem dados de \"" << M << "\" em \"" << R << "\"!" << endl;
    } else {
        for (const auto& res : results) {
            cout << res << endl;
        }
        cout << "Foram encontradas " << results.size() << " instancias de pessoas chamadas \"" << M << "\" em \"" << R << "\", relatadas acima." << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (N == 1) {
            handle_insertion();
        } else if (N == 2) {
            handle_search();
        } else if (N == 3) {
            cout << "O programa sera fechado, obrigado por fazer uso dele. Lembre-se de evitar a fadiga!" << endl;
            break;
        } else {
            cout << "Opcao invalida. Por favor, digite uma opcao valida." << endl;
        }
        
        string dummy;
        if(cin.peek() != EOF && cin.peek() != '\n') {
            // This handles cases where some input might be left before the blank line
        } else {
           getline(cin, dummy);
        }
    }

    return 0;
}
