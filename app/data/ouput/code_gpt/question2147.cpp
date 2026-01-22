/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

struct Person {
    string name;
    string favoriteFood;
};

queue<Person> RUQueue;
queue<Person> Area2Queue;
string RUFood, Area2Food;

void processCommand(const string& command) {
    if (command.substr(0, 4) == "SAIU") {
        if (command[5] == 'R') {
            if (RUQueue.empty()) {
                cout << "Nao ha mais ninguem para comer aqui" << endl;
                return;
            }
            Person p = RUQueue.front();
            RUQueue.pop();
            cout << p.name << " almocou no RU e esta voltando pra aula" << endl;
        } else {
            if (Area2Queue.empty()) {
                cout << "Nao ha mais ninguem para comer aqui" << endl;
                return;
            }
            Person p = Area2Queue.front();
            Area2Queue.pop();
            cout << p.name << " almocou na Area 2 e esta voltando pra aula" << endl;
        }
    } else {
        stringstream ss(command);
        string name, favoriteFood;
        getline(ss, name, ':');
        getline(ss, favoriteFood, ':');
        Person p = {name, favoriteFood};
        if (favoriteFood.empty()) {
            if (RUQueue.size() < Area2Queue.size()) {
                RUQueue.push(p);
                cout << name << " foi para a fila do RU" << endl;
            } else {
                Area2Queue.push(p);
                cout << name << " foi para a fila da Area 2" << endl;
            }
        } else {
            if (favoriteFood == RUFood) {
                RUQueue.push(p);
                cout << name << " foi para a fila do RU" << endl;
            } else if (favoriteFood == Area2Food) {
                Area2Queue.push(p);
                cout << name << " foi para a fila da Area 2" << endl;
            } else {
                if (RUQueue.size() < Area2Queue.size()) {
                    RUQueue.push(p);
                    cout << name << " foi para a fila do RU" << endl;
                } else {
                    Area2Queue.push(p);
                    cout << name << " foi para a fila da Area 2" << endl;
                }
            }
        }
    }
}

int main() {
    string RUline, Area2line;
    getline(cin, RUline);
    getline(cin, Area2line);
    RUFood = RUline.substr(RUline.find(':') + 1);
    Area2Food = Area2line.substr(Area2line.find(':') + 1);
    
    string command;
    while (getline(cin, command)) {
        processCommand(command);
    }
    
    return 0;
}
