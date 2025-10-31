/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

struct Node {
    string name;
    string period;
    Node* next;
    Node(string n, string p) : name(n), period(p), next(nullptr) {}
};

class TimeTraveler {
public:
    TimeTraveler() {
        head = nullptr;
        current_period = "Presente";
    }

    void travel(const string& name, int year) {
        string new_period;
        if (year < 0) {
            if (year >= -3100 && year <= -30) new_period = "Egito Antigo";
            else if (year >= 794 && year <= 1185) new_period = "Japao Feudal";
            else {
                cout << "Cuidado pra nao ficar preso no reino quantico, " << name << ".\n";
                return;
            }
        } else if (year == 2019) {
            new_period = "Presente";
        } else if (year >= 2235) {
            new_period = "Brasil Futurista";
        } else {
            cout << "Cuidado pra nao ficar preso no reino quantico, " << name << ".\n";
            return;
        }

        if (!head) {
            head = new Node(name, current_period);
            cout << name << " foi de " << current_period << " para " << new_period << ".\n";
            head->next = nullptr;
            current_period = new_period;
        } else {
            Node* traveler = head;
            while (traveler) {
                if (traveler->name == name) {
                    cout << name << " foi de " << traveler->period << " para " << new_period << ".\n";
                    traveler->period = new_period;
                    current_period = new_period;
                    return;
                }
                traveler = traveler->next;
            }
            Node* new_traveler = new Node(name, current_period);
            cout << name << " foi de " << current_period << " para " << new_period << ".\n";
            new_traveler->next = head;
            head = new_traveler;
            current_period = new_period;
        }
    }

    void display() {
        unordered_map<string, vector<string>> periods;
        Node* traveler = head;
        while (traveler) {
            periods[traveler->period].push_back(traveler->name);
            traveler = traveler->next;
        }

        cout << "\n";
        for (const auto& pair : periods) {
            if (!pair.second.empty()) {
                cout << pair.first << ":\n";
                for (const string& name : pair.second) {
                    cout << name << "\n";
                }
            }
        }
    }

private:
    Node* head;
    string current_period;
};

int main() {
    TimeTraveler tt;
    string name;
    int year;
    while (cin >> name >> year) {
        tt.travel(name, year);
    }
    tt.display();
    return 0;
}
