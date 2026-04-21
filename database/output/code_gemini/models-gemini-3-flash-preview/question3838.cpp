/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> ids(5);
    vector<long long> weights(5);
    set<long long> seen_ids;
    bool duplicate = false;

    for (int i = 0; i < 5; ++i) {
        if (!(cin >> ids[i] >> weights[i])) break;
        if (seen_ids.find(ids[i]) != seen_ids.end()) {
            duplicate = true;
        }
        seen_ids.insert(ids[i]);
    }

    long long claimed_total;
    if (!(cin >> claimed_total)) {
        claimed_total = 0;
    }

    long long calculated_total = 0;
    for (int i = 0; i < 5; ++i) {
        long long id = ids[i];
        long long w = weights[i];
        long long res = 0;

        if (id % 2 == 0 && (id % 3 == 0 || id % 5 == 0 || id % 7 == 0)) {
            res = id * (w * 2);
        } else if ((id * w) % 2 != 0 && ((id * w) % 11 == 0 || (id * w) % 13 == 0 || (id * w) % 17 == 0 || (id * w) % 19 == 0)) {
            res = (id * w) / 2;
        } else if (id % 2 == 0 && id % 17 == 0) {
            res = 0;
        } else {
            res = id * w;
        }
        calculated_total += res;
    }

    if (duplicate || claimed_total != calculated_total) {
        cout << "UEPAAA TEMOS UM RATINHO" << endl;
    } else {
        cout << "barra limpa, khan" << endl;
    }

    return 0;
}