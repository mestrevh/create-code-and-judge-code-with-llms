/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> v1, v2;
    int val;

    cout << "Digite o vetor 1: " << endl;
    while (cin >> val && val >= 0) {
        v1.insert(val);
    }

    cout << "Digite o vetor 2: " << endl;
    while (cin >> val && val >= 0) {
        v2.insert(val);
    }

    cout << endl;

    cout << "Vetor 1 (ordenado): ";
    for (int x : v1) {
        cout << x << " ";
    }
    cout << "\n";

    cout << "Vetor 2 (ordenado): ";
    for (int x : v2) {
        cout << x << " ";
    }
    cout << "\n";

    cout << "Vetor interseção (ordenado): ";
    vector<int> inter;
    for (int x : v1) {
        if (v2.count(x)) {
            inter.push_back(x);
        }
    }
    for (size_t i = 0; i < inter.size(); ++i) {
        cout << inter[i];
        if (i < inter.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}

