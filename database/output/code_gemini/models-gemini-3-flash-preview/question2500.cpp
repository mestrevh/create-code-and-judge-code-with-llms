/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Dinosaur {
    int count;
    string name;

    bool operator<(const Dinosaur& other) const {
        return name < other.name;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    vector<Dinosaur> storage;
    
    // Simulating dynamic storage growth using vector (standard dynamic array in C++)
    while (cin >> n >> s) {
        storage.push_back({n, s});
    }

    if (storage.empty()) {
        cout << "[]" << endl;
        return 0;
    }

    sort(storage.begin(), storage.end());

    cout << "[";
    bool first = true;
    for (const auto& dino : storage) {
        for (int i = 0; i < dino.count; ++i) {
            if (!first) {
                cout << ", ";
            }
            cout << dino.name;
            first = false;
        }
    }
    cout << "]" << endl;

    return 0;
}