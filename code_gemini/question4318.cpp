/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

struct Child {
    string name;
    int age;
    double height;
    double diff;
};

int main() {
    int n, m;
    double x;
    cin >> n >> m >> x;

    vector<Child> children(n);
    for (int i = 0; i < n; ++i) {
        cin >> children[i].name >> children[i].age >> children[i].height;
        children[i].diff = abs(x - (children[i].name.length() * children[i].age * children[i].height));
    }

    sort(children.begin(), children.end(), [](const Child& a, const Child& b) {
        return a.diff < b.diff;
    });

    for (int i = 0; i < m; ++i) {
        cout << children[i].name << endl;
    }

    return 0;
}
