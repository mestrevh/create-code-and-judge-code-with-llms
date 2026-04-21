/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Shirt {
    string name;
    string color;
    string size;
};

bool compareShirts(const Shirt& a, const Shirt& b) {
    if (a.color != b.color) {
        return a.color < b.color;
    }
    if (a.size != b.size) {
        return a.size > b.size;
    }
    return a.name < b.name;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    bool first = true;
    while (cin >> N && N != 0) {
        if (!first) {
            cout << "\n";
        }
        first = false;

        string dummy;
        getline(cin, dummy);

        vector<Shirt> shirts(N);
        for (int i = 0; i < N; ++i) {
            getline(cin, shirts[i].name);
            cin >> shirts[i].color >> shirts[i].size;
            getline(cin, dummy);
        }

        sort(shirts.begin(), shirts.end(), compareShirts);

        for (int i = 0; i < N; ++i) {
            cout << shirts[i].color << " " << shirts[i].size << " " << shirts[i].name << "\n";
        }
    }

    return 0;
}