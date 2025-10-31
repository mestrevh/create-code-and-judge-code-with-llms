/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

struct Brinquedo {
    string nome;
    long long d;
    long long a;
    int id;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Brinquedo> brinquedos(3);
    for (int i = 0; i < 3; ++i) {
        getline(cin, brinquedos[i].nome);
        cin >> brinquedos[i].d >> brinquedos[i].a;
        cin.ignore();
        brinquedos[i].id = i;
    }

    long long max_diversao = -1;
    vector<pair<int, int>> best_combo;

    // Caso 1: 3x no mesmo brinquedo
    for (int i = 0; i < 3; ++i) {
        long long current_fun = (brinquedos[i].d) + (brinquedos[i].d - brinquedos[i].a) + (brinquedos[i].d - 4 * brinquedos[i].a);
        if (current_fun > max_diversao) {
            max_diversao = current_fun;
            best_combo.clear();
            best_combo.push_back({i, 3});
        }
    }

    // Caso 2: 2x em um, 1x em outro
    for (int i = 0; i < 3; ++i) { // Brinquedo para ir 2 vezes
        for (int j = 0; j < 3; ++j) { // Brinquedo para ir 1 vez
            if (i == j) continue;
            long long current_fun = (brinquedos[i].d) + (brinquedos[i].d - brinquedos[i].a) + brinquedos[j].d;
            if (current_fun > max_diversao) {
                max_diversao = current_fun;
                best_combo.clear();
                best_combo.push_back({i, 2});
                best_combo.push_back({j, 1});
            }
        }
    }

    // Caso 3: 1x em cada
    long long fun_111 = brinquedos[0].d + brinquedos[1].d + brinquedos[2].d;
    if (fun_111 > max_diversao) {
        max_diversao = fun_111;
        best_combo.clear();
        best_combo.push_back({0, 1});
        best_combo.push_back({1, 1});
        best_combo.push_back({2, 1});
    }

    cout << "a maior diversao foi: " << max_diversao << endl;
    cout << "indo nos brinquedos: ";

    if (best_combo.size() == 1) {
        cout << brinquedos[best_combo[0].first].nome << " 3 vezes." << endl;
    } else if (best_combo.size() == 2) {
        if (best_combo[0].second < best_combo[1].second) {
            swap(best_combo[0], best_combo[1]);
        }
        cout << brinquedos[best_combo[0].first].nome << " 2 vezes, "
             << brinquedos[best_combo[1].first].nome << " 1 vez." << endl;
    } else if (best_combo.size() == 3) {
        sort(best_combo.begin(), best_combo.end());
        cout << brinquedos[best_combo[0].first].nome << " 1 vez, "
             << brinquedos[best_combo[1].first].nome << " 1 vez, "
             << brinquedos[best_combo[2].first].nome << " 1 vez." << endl;
    }

    return 0;
}
