/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include <cmath>

using namespace std;

struct Person {
    string name;
    double score;
    bool removed;
    bool used;

    Person(string n, double s) : name(n), score(s), removed(false), used(false) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double initial_score;
    if (!(cin >> initial_score)) return 0;

    list<Person> people;
    string name;
    double score;
    while (cin >> name >> score) {
        people.emplace_back(name, score);
    }

    double current_score = initial_score;
    double target_score = 4.5;
    double limit = initial_score * 0.9;

    for (auto it = people.begin(); it != people.end(); ++it) {
        if (it->score < limit - 0.00001) {
            cout << it->name << " nao serve para aumentar minha nota." << endl;
            it->removed = true;
        }
    }

    bool reached = false;
    double total_aumento = 0.0;

    auto it = people.begin();
    while (it != people.end()) {
        if (!it->removed) {
            if (!reached) {
                double aumento = 0.0;
                double ps = it->score;
                double cs = current_score;
                double lm = limit;

                if (ps >= 5.0) {
                    aumento = (ps - lm) * 0.11 + (ps - cs) * (-0.067);
                } else if (ps >= 4.6) {
                    aumento = (ps - lm) * 0.11 + (ps - cs) * 0.01;
                } else if (ps >= 4.5) {
                    aumento = (ps - lm) * 0.11 + (ps - cs) * 0.075;
                } else if (ps >= 4.1) {
                    aumento = (ps - lm) * 0.11 + (ps - cs) * (-0.0289);
                } else if (ps >= 4.0) {
                    aumento = (ps - lm) * 0.11 + (ps - cs) * (-0.0492);
                } else {
                    aumento = (ps - lm) * 0.05;
                }

                if (aumento < 0) aumento = 0;

                current_score += aumento;
                total_aumento += aumento;
                it->used = true;

                cout << "Minha nota aumentou em " << fixed << setprecision(4) << aumento << " por causa de " << it->name << "!" << endl;

                if (current_score >= target_score - 0.00001) {
                    reached = true;
                    cout << "Consegui a nota sonhada, ja posso comprar a casa dos meus sonhos, nao preciso de mais ninguem." << endl;
                } else {
                    cout << "Ja consegui aumentar " << fixed << setprecision(4) << total_aumento << " na minha nota" << endl;
                    cout << "Atualmente estou com " << fixed << setprecision(4) << current_score << " e ainda falta " << fixed << setprecision(4) << (target_score - current_score) << " para conseguir a nota sonhada." << endl;
                }
            }
        }
        if (reached) break;
        ++it;
    }

    if (reached) {
        bool first_unused = true;
        if (it != people.end()) ++it; 
        while (it != people.end()) {
            if (!it->removed && !it->used) {
                if (first_unused) {
                    cout << "Pessoas que nao preciso cativar:" << endl;
                    first_unused = false;
                }
                cout << it->name << endl;
            }
            ++it;
        }
    } else {
        cout << "Mesmo com tantos amigos nao consegui minha casa dos sonhos :(" << endl;
    }

    return 0;
}

