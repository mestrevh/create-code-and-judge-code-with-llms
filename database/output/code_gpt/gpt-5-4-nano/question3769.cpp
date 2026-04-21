/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    string favName, leastName;
    int favRating = -1, leastRating = 101;

    for (int i = 0; i < n; i++) {
        int rating;
        string name;
        cin >> rating;
        getline(cin, name); // read rest of line (may be empty)
        name.erase(0, name.find_first_not_of(" \t\r\n"));
        if (name.empty()) cin >> name;

        for (char &c : name) c = (char)toupper((unsigned char)c);

        if (rating > favRating) {
            favRating = rating;
            favName = name;
        }
        if (rating < leastRating) {
            leastRating = rating;
            leastName = name;
        }
    }

    cout << "O favorito de Joao eh " << favName << " com " << favRating << " rating!\n";
    cout << "O que Joao menos gosta eh " << leastName << " com " << leastRating << " rating!";

    return 0;
}