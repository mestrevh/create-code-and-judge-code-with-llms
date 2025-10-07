/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

int main() {
    int N1;
    cin >> N1;

    vector<string> ids(N1);
    vector<bool> chairs(1 << (32 - __builtin_clz(N1))); // 2^log2(N1)

    for (int i = 0; i < N1; ++i) {
        cin >> ids[i];
    }

    for (int i = 0; i < N1; ++i) {
        int pos = bitset<32>(ids[i].substr(0, 32 - ids[i].length())).to_ulong();
        while (chairs[pos]) pos++;
        chairs[pos] = true;
        ids[pos] = ids[i].substr(32 - ids[i].length());
    }

    int N2;
    cin >> N2;
    for (int i = 0; i < N2; ++i) {
        int query;
        cin >> query;
        if (query >= chairs.size() || !chairs[query]) {
            cout << "Nao tem ninguem" << endl;
        } else {
            cout << ids[query] << endl;
        }
    }

    return 0;
}
