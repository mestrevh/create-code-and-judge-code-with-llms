/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int processInstruction(int id, int weight) {
    int originalValue = id * weight;
    if (id % 2 == 0 && (id % 3 == 0 || id % 5 == 0 || id % 7 == 0)) {
        weight *= 2;
    }
    int newValue = id * weight;
    if (newValue % 2 != 0 && (newValue % 11 == 0 || newValue % 13 == 0 || newValue % 17 == 0 || newValue % 19 == 0)) {
        newValue /= 2;
    }
    if (id % 17 == 0 && id % 2 == 0) {
        return 0;
    }
    return newValue;
}

int main() {
    vector<pair<int, int>> instructions(5);
    unordered_set<int> ids;
    int calculatedPoints = 0;

    for (int i = 0; i < 5; ++i) {
        cin >> instructions[i].first >> instructions[i].second;
        ids.insert(instructions[i].first);
        calculatedPoints += processInstruction(instructions[i].first, instructions[i].second);
    }

    int totalPoints;
    cin >> totalPoints;

    if (calculatedPoints > totalPoints || ids.size() < 5) {
        cout << "UEPAAA TEMOS UM RATINHO" << endl;
    } else {
        cout << "barra limpa, khan" << endl;
    }

    return 0;
}
