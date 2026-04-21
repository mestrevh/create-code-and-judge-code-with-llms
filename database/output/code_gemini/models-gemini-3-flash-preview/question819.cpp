/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    if (!(cin >> a >> b)) return 0;

    auto get_id = [](const string& s) {
        if (s == "norte") return 0;
        if (s == "leste") return 1;
        if (s == "sul") return 2;
        if (s == "oeste") return 3;
        return -1;
    };

    int i1 = get_id(a);
    int i2 = get_id(b);

    if (i1 == -1 || i2 == -1) return 0;

    int diff = i1 - i2;
    if (diff < 0) diff = -diff;

    if (diff == 0) {
        cout << 0 << "\n";
    } else if (diff == 2) {
        cout << 180 << "\n";
    } else {
        cout << 90 << "\n";
    }

    return 0;
}