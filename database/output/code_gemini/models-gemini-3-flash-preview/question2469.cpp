/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int I;
    if (!(cin >> I)) return 0;

    vector<string> chandler, phoebe, joey, monica, ross, others;

    for (int i = 0; i < I; ++i) {
        string food, type;
        if (!(cin >> food >> type)) break;
        if (type == "Cafe") {
            chandler.push_back(food);
        } else if (type == "Cha") {
            phoebe.push_back(food);
        } else if (type == "Cerveja") {
            joey.push_back(food);
        } else if (type == "Refrigerante") {
            monica.push_back(food);
        } else if (type == "Suco") {
            ross.push_back(food);
        } else {
            others.push_back(food);
        }
    }

    if (chandler.empty() && phoebe.empty() && joey.empty() && monica.empty() && ross.empty()) {
        cout << "Nenhum dos meus amigos veio, não vou trabalhar hoje." << endl;
    } else {
        // Output for Chandler
        if (chandler.empty()) {
            cout << "Chandler não pediu nada.";
        } else {
            cout << "Chandler:";
            for (const string& f : chandler) {
                cout << "\n-" << f;
            }
        }

        // Output for Phoebe
        cout << "\n\n";
        if (phoebe.empty()) {
            cout << "Phoebe não pediu nada.";
        } else {
            cout << "Phoebe:";
            for (const string& f : phoebe) {
                cout << "\n-" << f;
            }
        }

        // Output for Joey
        cout << "\n\n";
        if (joey.empty()) {
            cout << "Joey não pediu nada.";
        } else {
            cout << "Joey:";
            for (const string& f : joey) {
                cout << "\n-" << f;
            }
        }

        // Output for Monica
        cout << "\n\n";
        if (monica.empty()) {
            cout << "Monica não pediu nada.";
        } else {
            cout << "Monica:";
            for (const string& f : monica) {
                cout << "\n-" << f;
            }
        }

        // Output for Ross
        cout << "\n\n";
        if (ross.empty()) {
            cout << "Ross não pediu nada.";
        } else {
            cout << "Ross:";
            for (const string& f : ross) {
                cout << "\n-" << f;
            }
        }

        // Output for Others
        if (!others.empty()) {
            cout << "\n\nOutros Clientes:";
            for (const string& f : others) {
                cout << "\n-" << f;
            }
        }
        cout << endl;
    }

    return 0;
}