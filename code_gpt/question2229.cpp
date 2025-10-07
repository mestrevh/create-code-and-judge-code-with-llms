/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<string> pessoas(5);
    for (int i = 0; i < 5; i++) {
        cin >> pessoas[i];
    }

    vector<string> mesa(5);
    mesa[0] = pessoas[0]; // Princesa sempre na posição 1

    // Determinando a posição de Mario
    if (pessoas[1] == "Mario" || pessoas[2] == "Mario") {
        mesa[1] = "Mario";
        if (pessoas[1] != "Mario") mesa[2] = pessoas[1]; // Colocando quem chegou antes
        else mesa[2] = pessoas[2];
    } else {
        mesa[1] = pessoas[1];
        mesa[2] = "Mario";
    }

    // Determinando a posição de Toad
    if (mesa[1] != "Mario" && (pessoas[1] == "Toad" || pessoas[2] == "Toad")) {
        mesa[1] = "Toad";
        if (pessoas[1] != "Toad") mesa[2] = pessoas[1]; // Posição 2 ficaria para Toad
        else mesa[2] = pessoas[2];
    }

    // Colocando Luigi e Yoshi nas posições restantes
    vector<string> restantes;
    for (int i = 3; i < 5; i++) {
        if (pessoas[i] != "Mario" && pessoas[i] != "Toad") {
            restantes.push_back(pessoas[i]);
        }
    }

    if (restantes.size() == 2) {
        if (restantes[0] == "Luigi" && restantes[1] == "Yoshi") {
            mesa[3] = "Luigi";
            mesa[4] = "Yoshi";
        } else {
            mesa[3] = "Yoshi";
            mesa[4] = "Luigi";
        }
    }

    for (const auto& nome : mesa) {
        cout << nome << endl;
    }

    return 0;
}
