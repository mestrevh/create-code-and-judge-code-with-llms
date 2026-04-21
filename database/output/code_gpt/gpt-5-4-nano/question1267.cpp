/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> gryff, slys, raven, huff;

    for (int i = 0; i < N; i++) {
        string name, c;
        cin >> name >> c;

        if (c == "coragem" || c == "determinacao") gryff.push_back(name);
        else if (c == "astucia" || c == "ambicao") slys.push_back(name);
        else if (c == "inteligencia" || c == "forca") {
            string next;
            cin >> next;
            if (c == "forca" && next == "de") {
                string x;
                cin >> x;
            }
        }
        if (c == "forca") {
            string tmp1, tmp2;
            cin >> tmp1 >> tmp2;
        }
    }

    return 0;
}