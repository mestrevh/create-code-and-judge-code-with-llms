/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <list>

using namespace std;

void trim(string &s) {
    while (!s.empty() && (s.back() == '\r' || s.back() == '\n' || s.back() == ' ')) s.pop_back();
    while (!s.empty() && (s.front() == ' ')) s.erase(0, 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    string foodRU = "", foodArea2 = "";

    if (!getline(cin, line)) return 0;
    trim(line);
    if (line.empty()) {
        if (!getline(cin, line)) return 0;
        trim(line);
    }

    size_t posA2 = line.find("Area 2:");
    if (posA2 != string::npos) {
        string partRU = line.substr(0, posA2);
        trim(partRU);
        if (partRU.size() >= 3) foodRU = partRU.substr(3);
        trim(foodRU);
        foodArea2 = line.substr(posA2 + 7);
        trim(foodArea2);
    } else {
        if (line.size() >= 3) foodRU = line.substr(3);
        trim(foodRU);
        if (!getline(cin, line)) return 0;
        trim(line);
        if (line.size() >= 7) foodArea2 = line.substr(7);
        trim(foodArea2);
    }

    list<string> qRU, qA2;

    while (getline(cin, line)) {
        trim(line);
        if (line.empty()) continue;

        if (line == "SAIU:RU") {
            if (qRU.empty()) {
                cout << "Nao ha mais ninguem para comer aqui" << endl;
            } else {
                cout << qRU.front() << " almocou no RU e esta voltando pra aula" << endl;
                qRU.pop_front();
            }
        } else if (line == "SAIU:AREA2") {
            if (qA2.empty()) {
                cout << "Nao ha mais ninguem para comer aqui" << endl;
            } else {
                cout << qA2.front() << " almocou na Area 2 e esta voltando pra aula" << endl;
                qA2.pop_front();
            }
        } else {
            string name, fav = "";
            size_t pos = line.find(':');
            if (pos != string::npos) {
                name = line.substr(0, pos);
                fav = line.substr(pos + 1);
            } else {
                name = line;
            }
            trim(name);
            trim(fav);

            bool matchRU = (!fav.empty() && fav == foodRU);
            bool matchA2 = (!fav.empty() && fav == foodArea2);

            if (matchRU && !matchA2) {
                qRU.push_back(name);
                cout << name << " foi para a fila do RU" << endl;
            } else if (matchA2 && !matchRU) {
                qA2.push_back(name);
                cout << name << " foi para a fila da Area 2" << endl;
            } else {
                if (qRU.size() < qA2.size()) {
                    qRU.push_back(name);
                    cout << name << " foi para a fila do RU" << endl;
                } else {
                    qA2.push_back(name);
                    cout << name << " foi para a fila da Area 2" << endl;
                }
            }
        }
    }

    return 0;
}