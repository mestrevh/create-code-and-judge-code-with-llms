/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Film {
    string name;
    int roteiro, direcao, atuacao;

    Film(string n, int r, int d, int a) : name(n), roteiro(r), direcao(d), atuacao(a) {}
};

vector<Film> films;

void customSortR() {
    for (size_t i = 1; i < films.size(); i++) {
        Film key = films[i];
        int j = i - 1;
        while (j >= 0 && films[j].roteiro > key.roteiro) {
            films[j + 1] = films[j];
            j--;
        }
        films[j + 1] = key;
    }
}

void customSortD() {
    for (size_t i = 1; i < films.size(); i++) {
        Film key = films[i];
        int j = i - 1;
        while (j >= 0 && films[j].direcao > key.direcao) {
            films[j + 1] = films[j];
            j--;
        }
        films[j + 1] = key;
    }
}

void customSortA() {
    for (size_t i = 1; i < films.size(); i++) {
        Film key = films[i];
        int j = i - 1;
        while (j >= 0 && films[j].atuacao > key.atuacao) {
            films[j + 1] = films[j];
            j--;
        }
        films[j + 1] = key;
    }
}

void showFilms(char category) {
    vector<Film> sortedFilms = films;

    if (category == 'R') customSortR();
    else if (category == 'D') customSortD();
    else if (category == 'A') customSortA();

    for (auto& film : sortedFilms) {
        if (category == 'R') cout << film.name << ": R " << film.roteiro << ", D " << film.direcao << ", A " << film.atuacao << endl;
        else if (category == 'D') cout << film.name << ": R " << film.roteiro << ", D " << film.direcao << ", A " << film.atuacao << endl;
        else cout << film.name << ": R " << film.roteiro << ", D " << film.direcao << ", A " << film.atuacao << endl;
    }
}

void firstFilm(char category, int note) {
    for (auto& film : films) {
        if ((category == 'R' && film.roteiro == note) || 
            (category == 'D' && film.direcao == note) ||
            (category == 'A' && film.atuacao == note)) {
            cout << film.name << ": R " << film.roteiro << ", D " << film.direcao << ", A " << film.atuacao << endl;
            return;
        }
    }
    cout << "Nenhum" << endl;
}

void lastFilm(char category, int note) {
    for (int i = films.size() - 1; i >= 0; i--) {
        auto& film = films[i];
        if ((category == 'R' && film.roteiro == note) || 
            (category == 'D' && film.direcao == note) ||
            (category == 'A' && film.atuacao == note)) {
            cout << film.name << ": R " << film.roteiro << ", D " << film.direcao << ", A " << film.atuacao << endl;
            return;
        }
    }
    cout << "Nenhum" << endl;
}

void deleteFilm(string name) {
    for (auto it = films.end() - 1; it >= films.begin(); it--) {
        if (it->name == name) {
            films.erase(it);
            return;
        }
    }
}

int main() {
    string command, name;
    while (cin >> command) {
        if (command == "END") break;
        if (command == "ADD") {
            int r, d, a;
            cin >> name >> r >> d >> a;
            films.emplace_back(name, r, d, a);
        } else if (command == "SHOW") {
            char category;
            cin >> category;
            showFilms(category);
        } else if (command == "DEL") {
            cin >> name;
            deleteFilm(name);
        } else if (command == "FIRST") {
            char category;
            int note;
            cin >> category >> note;
            firstFilm(category, note);
        } else if (command == "LAST") {
            char category;
            int note;
            cin >> category >> note;
            lastFilm(category, note);
        }
    }
    return 0;
}
