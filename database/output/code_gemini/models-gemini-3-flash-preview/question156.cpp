/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C, N;
    if (!(cin >> C >> N)) return 0;

    map<int, int> installed;
    for (int i = 0; i < C; ++i) {
        int p, v;
        cin >> p >> v;
        installed[p] = v;
    }

    map<int, int> to_update;
    for (int i = 0; i < N; ++i) {
        int p, v;
        cin >> p >> v;
        
        bool upgrade_needed = false;
        auto it = installed.find(p);
        
        if (it == installed.end()) {
            upgrade_needed = true;
        } else if (v > it->second) {
            upgrade_needed = true;
        }

        if (upgrade_needed) {
            auto ut = to_update.find(p);
            if (ut == to_update.end() || v > ut->second) {
                to_update[p] = v;
            }
        }
    }

    for (auto const& pair : to_update) {
        cout << pair.first << " " << pair.second << "\n";
    }

    return 0;
}