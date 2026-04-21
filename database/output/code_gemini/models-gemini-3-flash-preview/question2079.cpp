/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

struct Soldier {
    string name;
    int height;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n <= 0) {
        return 0;
    }

    vector<Soldier> soldiers(n);
    for (int i = 0; i < n; ++i) {
        cin >> soldiers[i].name >> soldiers[i].height;
    }

    sort(soldiers.begin(), soldiers.end(), [](const Soldier& a, const Soldier& b) {
        if (a.height != b.height) {
            return a.height < b.height;
        }
        char char_a = (char)tolower((unsigned char)a.name[0]);
        char char_b = (char)tolower((unsigned char)b.name[0]);
        return char_a < char_b;
    });

    for (int i = 0; i < n; ++i) {
        cout << soldiers[i].name;
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}