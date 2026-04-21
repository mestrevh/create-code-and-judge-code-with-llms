/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Child {
    string name;
    long long score;
};

bool compareChildren(const Child& a, const Child& b) {
    if (a.score != b.score) {
        return a.score > b.score;
    }
    return a.name < b.name;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<Child> children;
    children.reserve(N);

    for (int i = 0; i < N; ++i) {
        string name;
        long long p, o, b, r, pe;
        if (!(cin >> name >> p >> o >> b >> r >> pe)) break;
        
        // Point values: ótima (5), boa (3), ruim (-3), péssima (-5)
        long long finalScore = p + (5 * o) + (3 * b) + (-3 * r) + (-5 * pe);
        children.push_back({name, finalScore});
    }

    sort(children.begin(), children.end(), compareChildren);

    for (int i = 0; i < (int)children.size(); ++i) {
        cout << children[i].name << " " << children[i].score << " \n";
    }

    return 0;
}