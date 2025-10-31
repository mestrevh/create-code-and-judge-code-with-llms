/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Dinosaur {
    string name;
    int size;
};

bool compare(const Dinosaur &a, const Dinosaur &b) {
    return a.name < b.name;
}

int main() {
    vector<Dinosaur> dinosaurs;
    string name;
    int size;

    while (cin >> size >> name) {
        dinosaurs.push_back({name, size});
    }

    sort(dinosaurs.begin(), dinosaurs.end(), compare);

    vector<string> result;
    for (const auto &dino : dinosaurs) {
        for (int i = 0; i < dino.size; ++i) {
            result.push_back(dino.name);
        }
    }

    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
