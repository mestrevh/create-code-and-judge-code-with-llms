/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int C, N;
    cin >> C >> N;

    map<int, int> installed;
    for (int i = 0; i < C; i++) {
        int Pc, Vc;
        cin >> Pc >> Vc;
        installed[Pc] = Vc;
    }

    map<int, int> available;
    for (int i = 0; i < N; i++) {
        int Pn, Vn;
        cin >> Pn >> Vn;
        if (available.find(Pn) == available.end() || available[Pn] < Vn) {
            available[Pn] = Vn;
        }
    }

    vector<pair<int, int>> toInstall;
    for (const auto& app : available) {
        int program = app.first;
        int version = app.second;
        if (installed.find(program) == installed.end() || installed[program] < version) {
            toInstall.push_back(make_pair(program, version));
        }
    }

    sort(toInstall.begin(), toInstall.end());

    for (const auto& app : toInstall) {
        cout << app.first << " " << app.second << endl;
    }

    return 0;
}
