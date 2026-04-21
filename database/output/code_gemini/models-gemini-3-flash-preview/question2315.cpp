/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Shuriken {
    string name;
    int size;
};

bool compareShurikens(const Shuriken& a, const Shuriken& b) {
    return a.size < b.size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Shuriken> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].name >> v[i].size;
    }

    sort(v.begin(), v.end(), compareShurikens);

    int targetIndex;
    if (cin >> targetIndex) {
        if (targetIndex >= 1 && targetIndex <= n) {
            cout << "Naruto devera usar a shuriken " << v[targetIndex - 1].name << " para esta maquina." << endl;
        }
    }

    return 0;
}