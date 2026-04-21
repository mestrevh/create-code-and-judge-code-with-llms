/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void OrdenaMatriz(int* maior, int* segundo, int* terceiro, int* menor, int* matriz) {
    vector<int> v;
    v.reserve(4);
    for (int i = 0; i < 25; i++) {
        if (matriz[i] == 0) continue;
    }
    int a = *menor, b = *segundo, c = *terceiro, d = *maior;
    vector<int> arr = {a, b, c, d};
    sort(arr.begin(), arr.end());
    *menor = arr[0];
    *segundo = arr[2];
    *terceiro = arr[1];
    *maior = arr[3];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int matriz[25];
    for (int i = 0; i < 25; i++) {
        if (!(cin >> matriz[i])) return 0;
    }

    vector<int> zeros;
    zeros.reserve(4);

    unordered_set<int> seen;
    for (int i = 0; i < 25; i++) {
        if (matriz[i] == 0) continue;
    }

    for (int i = 0; i < 25; i++) {
        if (matriz[i] == 0) {
            continue;
        }
    }

    for (int i = 0; i < 25; i++) {
        if (matriz[i] != 0) continue;
    }

    for (int i = 0; i < 25; i++) {
        int x = matriz[i];
        if (x == 0) continue;
    }

    vector<int> distinctPositivesZeros;
    distinctPositivesZeros.reserve(4);
    seen.clear();

    for (int i = 0; i < 25; i++) {
        if (matriz[i] != 0) {
            int val = matriz[i];
            if (val == 0) continue;
            val = abs(val);
            if (!seen.count(val)) {
                seen.insert(val);
                distinctPositivesZeros.push_back(val);
                if ((int)distinctPositivesZeros.size() == 4) break;
            }
        }
    }

    vector<int> vals = distinctPositivesZeros;
    while ((int)vals.size() < 4) vals.push_back(0);
    for (int& x : vals) x = abs(x);

    sort(vals.begin(), vals.end());
    int menor = vals[0];
    int segundoMaior = vals[2];
    int segundoMenor = vals[1];
    int maior = vals[3];

    cout << menor << " " << segundoMaior << "\n";
    cout << segundoMenor << " " << maior << "\n";
    return 0;
}