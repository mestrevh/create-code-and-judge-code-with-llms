/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Soldier {
    string name;
    int height;
};

bool compare(const Soldier &a, const Soldier &b) {
    if (a.height == b.height) {
        return a.name < b.name;
    }
    return a.height < b.height;
}

int main() {
    int N;
    cin >> N;
    vector<Soldier> soldiers(N);

    for (int i = 0; i < N; ++i) {
        cin >> ws;
        getline(cin, soldiers[i].name, ' ');
        cin >> soldiers[i].height;
    }

    sort(soldiers.begin(), soldiers.end(), compare);

    for (int i = 0; i < N; ++i) {
        cout << soldiers[i].name;
        if (i < N - 1) cout << " ";
    }
    cout << endl;
    return 0;
}
