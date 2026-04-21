/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string line;
    getline(cin, line);

    for (int i = 0; i < n; ++i) {
        string name;
        if (!getline(cin, name)) break;

        double ab1, ab2;
        if (!(cin >> ab1 >> ab2)) break;
        getline(cin, line);

        double media = (ab1 + ab2) / 2.0;

        cout << "Nome:  " << name << "\n";
        cout << fixed << setprecision(2);
        cout << "AB1: " << ab1 << "\n";
        cout << "AB2: " << ab2 << "\n";
        cout << "Media: " << media << "\n";
        cout << "Situacao:  " << (media >= 7.0 ? "AP" : "RP") << "\n";
    }

    return 0;
}